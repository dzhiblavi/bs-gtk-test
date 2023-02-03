#include "app/ui/app_main.h"
#include "core/logging/logging.h"
#include "project.h"

int main(int argc, char* argv[]) {
  core::logging::InitLogging(argc, argv);
  LOG(INFO) << PROJECT_VERSION_MAJOR;
  return app::gtk::AppMain(argc, argv);
}

