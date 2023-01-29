#pragma once

#include <iterator>
#include <filesystem>
#include <boost/process.hpp>

#include "ag/ag_entry.h"

namespace app::ag {

class AgSearchIterator {
 public:
  AgSearchIterator(AgSearchIterator&&) noexcept = default;

  ~AgSearchIterator() noexcept;

  [[nodiscard]] bool Next(AgEntry& entry);

  void Cancel();

  static AgSearchIterator Search(const std::filesystem::path& root, const std::string& query);

 private:
  AgSearchIterator() noexcept = default;

  bool ReadLine(std::string& line);

  boost::process::ipstream stream_;
  boost::process::child child_;
};

}  // namespace app::ag
