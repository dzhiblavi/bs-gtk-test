#pragma once

#include <filesystem>

namespace app::ag {

class AgEntry {
 public:
  AgEntry() noexcept = default;
  explicit AgEntry(const std::filesystem::path& path);

  const std::filesystem::path& Path() const noexcept;

  const std::vector<int32_t>& LineNos() const noexcept;

  void AddLineNo(int32_t line_no);

 private:
  std::filesystem::path path_;
  std::vector<int32_t> line_nos_;
};

}  // namespace app::ag

