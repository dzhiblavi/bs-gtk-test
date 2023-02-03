include(GoogleTest)

function(cc_test)
  cmake_parse_arguments(
    ARG
    ""
    "NAME"
    "SRCS;DEPS;SYSTEM;COPTS"
    ${ARGN}
  )	

  enable_testing()

  cc_binary(
    NAME ${ARG_NAME}
    SRCS ${ARG_SRCS}
    DEPS ${ARG_DEPS}
    COPTS ${ARG_COPTS}
    SYSTEM
      ${ARG_SYSTEM}
      GTest::gtest_main
  )

  gtest_discover_tests(${ARG_NAME})
endfunction()
