cc_library(
  NAME core-logging
  ALIAS core::logging
  TYPE STATIC
  HDR_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
  SRCS
    logging.cpp
  SYSTEM
    glog::glog
)
