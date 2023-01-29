#pragma once

#include <filesystem>

namespace app::ag {

class AgEntry {
 public:
  AgEntry() noexcept = default;
  AgEntry(const std::filesystem::path& path, int32_t line_no);

  const std::filesystem::path& Path() const noexcept;

  int32_t LineNo() const noexcept;

 private:
  std::filesystem::path path_;
  int32_t line_no_;
};

}  // namespace app::ag

