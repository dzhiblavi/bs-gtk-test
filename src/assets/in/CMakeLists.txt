configure_file(project.h.in project.h)

cc_library(
  NAME project-config
  ALIAS project::config
  TYPE INTERFACE
  HDR_DIRS ${CMAKE_CURRENT_BINARY_DIR}
)
