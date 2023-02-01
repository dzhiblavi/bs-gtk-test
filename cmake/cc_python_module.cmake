function(cc_python_module)
  cmake_parse_arguments(
    ARG
    ""
    "MODULE_NAME;"
    "SRCS;DEPS;SYSTEM;COPTS"
    ${ARGN}
  )

  cc_library(
    NAME ${ARG_MODULE_NAME}
    TYPE MODULE
    SRCS ${ARG_SRCS}
    DEPS ${ARG_DEPS}
    COPTS ${ARG_COPTS}
    SYSTEM
      ${ARG_SYSTEM}
      Boost::python
      Python3::Python
  )

  set_target_properties(${ARG_MODULE_NAME} PROPERTIES PREFIX "")
endfunction()
