function(cc_library)
  cmake_parse_arguments(
    ARG
    ""
    "NAME;ALIAS;TYPE"
    "HDRS;SRCS;DEPS;SYSTEM;COPTS"
    ${ARGN}
  )	

  add_library(${ARG_NAME} ${ARG_TYPE}) 

  if(NOT "${ARG_ALIAS}" STREQUAL "")
    add_library(${ARG_ALIAS} ALIAS ${ARG_NAME})
  endif()

  foreach(src ${ARG_SRCS})
    target_sources(${ARG_NAME} PRIVATE ${src})
  endforeach()
  foreach(hdr ${ARG_HDRS})
    target_sources(${ARG_NAME} INTERFACE ${hdr})
  endforeach()

  if("${ARG_TYPE}" STREQUAL "INTERFACE")
    target_compile_options(
      ${ARG_NAME} INTERFACE
      -W -Wall -Werror -Wextra
      -Wconversion -Wsign-conversion
      -pedantic -pedantic-errors
      ${ARG_COPTS}
    )
  else()
    target_compile_options(
      ${ARG_NAME} PRIVATE
      -W -Wall -Werror -Wextra
      -Wconversion -Wsign-conversion
      -pedantic -pedantic-errors
      ${ARG_COPTS}
    )
  endif()

  foreach(lib ${ARG_DEPS})
    target_link_libraries(${ARG_NAME} PUBLIC ${lib})
  endforeach()

  foreach(lib ${ARG_SYSTEM})
    get_target_property(lib_include_dirs ${lib} INTERFACE_INCLUDE_DIRECTORIES)
    target_link_libraries(${ARG_NAME} PUBLIC ${lib})
    target_include_directories(${ARG_NAME} SYSTEM PRIVATE ${lib_include_dirs})
  endforeach()
endfunction()
