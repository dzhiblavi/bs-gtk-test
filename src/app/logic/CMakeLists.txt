add_library(app.logic_LIBRARY STATIC AgWorker.cpp)
add_library(app::logic ALIAS app.logic_LIBRARY)

target_link_libraries(
  app.logic_LIBRARY PUBLIC
  app::ag
)
