function(cc_binary)
  cmake_parse_arguments(
    ARG
    ""
    "NAME"
    "SRCS;DEPS;SYSTEM;COPTS"
    ${ARGN}
  )	

  add_executable(${ARG_NAME} ${ARG_SRCS}) 

  target_compile_options(
    ${ARG_NAME} PRIVATE
    -W -Wall -Werror -Wextra
    -Wconversion -Wsign-conversion
    -pedantic -pedantic-errors
    ${ARG_COPTS}
  )

  foreach(lib ${ARG_DEPS})
    target_link_libraries(${ARG_NAME} PUBLIC ${lib})
  endforeach()

  foreach(lib ${ARG_SYSTEM})
    get_target_property(lib_include_dirs ${lib} INTERFACE_INCLUDE_DIRECTORIES)
    target_link_libraries(${ARG_NAME} PUBLIC ${lib})
    target_include_directories(${ARG_NAME} SYSTEM PRIVATE ${lib_include_dirs})
  endforeach()
endfunction()
