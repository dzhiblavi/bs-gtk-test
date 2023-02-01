cc_library(
  NAME greet
  TYPE STATIC
  HDRS greet.h
  SRCS greet.cpp
)

cc_python_module(
  MODULE_NAME py_greet
  SRCS py_greet.cpp
  DEPS greet
)
