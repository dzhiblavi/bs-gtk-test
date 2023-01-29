#include "app/ui/MainWindow.h"

namespace app::gtk {

MainWindow::MainWindow(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder)
  : Gtk::ApplicationWindow(obj)
  , builder{builder}
{
  builder->get_widget("/MainWindow/Panel/Text", text_view);
  builder->get_widget("/MainWindow/Panel/Box/StartButton", start_button);
  builder->get_widget("/MainWindow/Panel/Box/CancelButton", cancel_button);
  builder->get_widget("/MainWindow/Panel/Box/Search", search_entry);
  builder->get_widget("/MainWindow/Panel/Box/SelectDir", dir_selector);
  builder->get_widget("/MainWindow/Panel/Box/List", list_box);

  start_button->signal_clicked().connect(sigc::mem_fun(this, &MainWindow::StartSearch));
  cancel_button->signal_clicked().connect(sigc::mem_fun(this, &MainWindow::CancelSearch));
  list_box->signal_row_selected().connect(sigc::mem_fun(this, &MainWindow::FillTextView));

  update_ui_slot_ = sigc::mem_fun(this, &MainWindow::UpdateUI);
  Glib::signal_timeout().connect(update_ui_slot_, 250 /* ms */);
}

void MainWindow::StartSearch() {
  for (auto* child : list_box->get_children()) {
    list_box->remove(*child);
  }

  worker_.Start(
      dir_selector->get_filename(),
      search_entry->get_text());
}

void MainWindow::CancelSearch() { worker_.Cancel(); }

void MainWindow::FillTextView(Gtk::ListBoxRow* row_selected) {
  if (row_selected == nullptr) {
    text_view->get_buffer()->set_text("");
    return;
  }
  auto* box = dynamic_cast<Gtk::Box*>(row_selected->get_child());
  auto* label = dynamic_cast<Gtk::Label*>(box->get_children().front());
  std::filesystem::path path(label->get_label().c_str());
  std::ifstream ifs(path);

  auto tag = text_view->get_buffer()->create_tag();
  tag->property_background() = "yellow";

  text_view->get_buffer()->set_text(
      std::string(
        (std::istreambuf_iterator<char>(ifs)),
        std::istreambuf_iterator<char>()));

  const auto& entry = entries_.at(path);
  for (int32_t line_no : entry.LineNos()) {
    auto iter_start = text_view->get_buffer()->get_iter_at_line(line_no - 1);
    auto iter_end = text_view->get_buffer()->get_iter_at_line(line_no);
    text_view->get_buffer()->apply_tag(tag, iter_start, iter_end);
  }
}

bool MainWindow::UpdateUI() {
  static constexpr size_t MAX_NUM_RESULTS = 1000;

  std::vector<ag::AgEntry> entries;
  if (worker_.FetchNewResults(entries)) {
    for (const auto& entry : entries) {
      if (list_box->get_children().size() > MAX_NUM_RESULTS) {
        CancelSearch();
        break;
      }

      entries_[entry.Path().string()] = entry;
      Gtk::Label* row_label = Gtk::manage(new Gtk::Label(entry.Path().string()));
      Gtk::Box* row_box = Gtk::manage(new Gtk::Box());
      row_label->set_alignment(0.0);
      row_box->pack_start(*row_label);
      Gtk::ListBoxRow *row = Gtk::manage(new Gtk::ListBoxRow());
      row->add(*row_box);
      list_box->append(*row);
    }
  }

  show_all();
  return true;
}

}  // namespace app::gtk

