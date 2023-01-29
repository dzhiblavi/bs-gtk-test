add_library(app.ui_LIBRARY STATIC app_main.cpp MainWindow.cpp)
add_library(app::ui ALIAS app.ui_LIBRARY)

target_link_libraries(
  app.ui_LIBRARY PUBLIC
  app::ag
  core::logging
  core::compiler
  Gtk::Gtk
)
