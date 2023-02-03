add_subdirectory(logic)
add_subdirectory(ui)

cc_binary(
  NAME app
  SRCS main.cpp
  DEPS
    app::ui
    app::logic
    project::config
)
