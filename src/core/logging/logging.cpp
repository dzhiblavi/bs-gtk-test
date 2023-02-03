#include "core/logging/logging.h"

namespace core::logging {

COLD_CODE
void InitLogging(int, char** argv) {
  google::InitGoogleLogging(argv[0]);
  google::InstallFailureSignalHandler();
}

}  // namespace core::logging

