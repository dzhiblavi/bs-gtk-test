#include "ag/ag_entry.h"

namespace app::ag {

AgEntry::AgEntry(const std::filesystem::path& path, int32_t line_no)
  : path_(path), line_no_(line_no) {}

const std::filesystem::path& AgEntry::Path() const noexcept { return path_; }

int32_t AgEntry::LineNo() const noexcept { return line_no_; }

}  // namespace app::ag

