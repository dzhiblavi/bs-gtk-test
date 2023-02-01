cc_test(
  NAME test_proto
  SRCS
    test.cpp
  DEPS
    proto::msg
  SYSTEM
    glog::glog
)
