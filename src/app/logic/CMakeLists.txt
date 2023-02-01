cc_library(
  NAME app-logic
  ALIAS app::logic
  TYPE STATIC
  SRCS
    AgWorker.cpp
  DEPS
    app::ag
)
