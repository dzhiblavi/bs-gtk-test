cc_proto_library(
  NAME proto-msg
  ALIAS proto::msg
  TYPE STATIC
  PROTO_SRCS msg.proto
)

add_subdirectory(test)
