#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <thread>
#include <unordered_map>
#include <gtkmm.h>

#include "core/logging.h"
#include "app/logic/AgWorker.h"

namespace app::gtk {

class MainWindow : public Gtk::ApplicationWindow {
 public:
  MainWindow(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder);

 private:
  void StartSearch();
  void CancelSearch();
  void FillTextView(Gtk::ListBoxRow* row_selected);
  bool UpdateUI();

  Glib::RefPtr<Gtk::Builder> builder;
  Gtk::Button* start_button = nullptr;
  Gtk::Button* cancel_button = nullptr;
  Gtk::SearchEntry* search_entry = nullptr;
  Gtk::FileChooserButton* dir_selector = nullptr;
  Gtk::ListBox* list_box = nullptr;
  Gtk::TextView* text_view = nullptr;

  std::unordered_map<std::string, ag::AgEntry> entries_;
  AgWorker worker_;
  sigc::slot<bool> update_ui_slot_;
};

}  // namespace app::gtk

