function(cc_proto_library)
  cmake_parse_arguments(
    ARG
    ""
    "NAME;ALIAS;TYPE"
    "PROTO_SRCS"
    ${ARGN}
  )	

  protobuf_generate_cpp(PROTO_SRC PROTO_HEADER ${ARG_PROTO_SRCS})

  cc_library(
    NAME ${ARG_NAME}
    ALIAS ${ARG_ALIAS}
    TYPE ${ARG_TYPE}
    HDRS ${PROTO_HEADER}
    SRCS ${PROTO_SRC}
    SYSTEM protobuf::libprotobuf
    COPTS
      -Wno-unused-parameter
      -Wno-implicit-int-float-conversion
      -Wno-sign-conversion
  )

  target_include_directories(
    ${ARG_NAME} PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
  )
endfunction()
