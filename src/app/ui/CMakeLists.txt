add_library(libapp-ui STATIC app_main.cpp MainWindow.cpp)
add_library(app::ui ALIAS libapp-ui)

target_link_libraries(
  libapp-ui PUBLIC
  app::ag
  core::logging
  core::compiler
  Gtk::Gtk
)
