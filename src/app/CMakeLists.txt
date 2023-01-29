add_subdirectory(logic)
add_subdirectory(ui)

add_executable(
  app
  main.cpp
)

target_link_libraries(
  app PRIVATE
  app::ui
  app::logic
)
