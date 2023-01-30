pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_library(libgtk-imported INTERFACE)
add_library(Gtk::Gtk ALIAS libgtk-imported)

target_link_directories(
  libgtk-imported INTERFACE
  ${GTK_LIBRARY_DIRS}
  ${GTKMM_LIBRARY_DIRS}
)

target_include_directories(
  libgtk-imported INTERFACE
  ${GTK_INCLUDE_DIRS}
  ${GTKMM_INCLUDE_DIRS}
)

target_link_libraries(
  libgtk-imported INTERFACE
  ${GTK_LIBRARIES}
  ${GTKMM_LIBRARIES}
)
