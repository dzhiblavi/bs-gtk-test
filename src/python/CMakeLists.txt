cc_library(
  NAME greet
  TYPE STATIC
  SRCS greet.cpp
  HDR_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
)

cc_python_module(
  MODULE_NAME py_greet
  SRCS py_greet.cpp
  DEPS greet
)
