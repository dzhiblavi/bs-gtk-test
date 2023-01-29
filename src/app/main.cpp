#include "app/ui/app_main.h"
#include "core/logging.h"

int main(int argc, char* argv[]) {
  core::logging::InitLogging(argc, argv);
  return app::gtk::AppMain(argc, argv);
}

