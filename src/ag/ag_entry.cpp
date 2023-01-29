#include "ag/ag_entry.h"

namespace app::ag {

AgEntry::AgEntry(const std::filesystem::path& path) : path_(path) {}

const std::filesystem::path& AgEntry::Path() const noexcept { return path_; }

const std::vector<int32_t>& AgEntry::LineNos() const noexcept { return line_nos_; }

void AgEntry::AddLineNo(int32_t line_no) { line_nos_.push_back(line_no); }

}  // namespace app::ag

