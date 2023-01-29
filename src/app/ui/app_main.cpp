#include "app/ui/app_main.h"
#include "app/ui/MainWindow.h"

namespace app::gtk {

int AppMain(int argc, char** argv) {
  auto app = Gtk::Application::create(argc, argv, "gtk.example");
  auto builder = Gtk::Builder::create();
  builder->add_from_file("/Users/dzhiblavi/cpp-gtk/src/assets/glade/ag.glade");

  std::unique_ptr<MainWindow> window_ptr;
  {
    MainWindow* window = nullptr;
    builder->get_widget_derived("/MainWindow", window);
    window_ptr.reset(window);
  }

  return app->run(*window_ptr);
}

}  // namespace app::gtk

