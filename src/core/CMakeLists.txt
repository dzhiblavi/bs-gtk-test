cc_library(
  NAME core-compiler
  ALIAS core::compiler
  TYPE INTERFACE
  HDRS
    compiler.h
)

cc_library(
  NAME core-logging
  ALIAS core::logging
  TYPE STATIC
  HDRS
    logging.h
  SRCS
    logging.cpp
  SYSTEM
    glog::glog
)
