include(FindProtobuf)
find_package(Protobuf REQUIRED)

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER msg.proto)
add_library(proto.msg_LIBRARY ${PROTO_SRC} ${PROTO_HEADER})
add_library(proto::msg ALIAS proto.msg_LIBRARY)

target_compile_options(
    proto.msg_LIBRARY PRIVATE
    -Wno-unused-parameter  # generated code produces warnings
)
target_include_directories(
    proto.msg_LIBRARY PUBLIC
    ${PROTOBUF_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(
    proto.msg_LIBRARY PUBLIC
    ${PROTOBUF_LIBRARY}
)

add_subdirectory(test)
