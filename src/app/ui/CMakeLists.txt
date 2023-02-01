cc_library(
  NAME app-ui
  ALIAS app::ui
  TYPE STATIC
  SRCS
    app_main.cpp
    MainWindow.cpp
  DEPS
    core::logging
    core::compiler
  SYSTEM
    Gtk::Gtk
)
