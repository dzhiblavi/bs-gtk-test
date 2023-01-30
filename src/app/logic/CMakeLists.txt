add_library(libapp-logic STATIC AgWorker.cpp)
add_library(app::logic ALIAS libapp-logic)

target_link_libraries(
  libapp-logic PUBLIC
  app::ag
)
