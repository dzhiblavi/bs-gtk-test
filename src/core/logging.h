#pragma once

#include <glog/logging.h>

#include "core/compiler.h"

namespace core::logging {

COLD_CODE
void InitLogging(int argc, char** argv);

}  // namespace core::logging

