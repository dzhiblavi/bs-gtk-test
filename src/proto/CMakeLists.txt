protobuf_generate_cpp(PROTO_SRC PROTO_HEADER msg.proto)
add_library(libproto-msg ${PROTO_SRC} ${PROTO_HEADER})
add_library(proto::msg ALIAS libproto-msg)

target_compile_options(
    libproto-msg PRIVATE
    -Wno-unused-parameter  # generated code produces warnings
)
target_include_directories(
    libproto-msg PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(
    libproto-msg PUBLIC
    protobuf::libprotobuf
)

add_subdirectory(test)
