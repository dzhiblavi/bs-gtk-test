#include "ag/ag_search.h"

#include <glog/logging.h>

#include <cstdio>
#include <iostream>

namespace app::ag {

bool AgSearchIterator::Next(AgEntry& entry) {
  static constexpr size_t MAX_PATH_LENGTH = 1024;

  std::string line;
  if (!ReadLine(line)) {
    return false;
  }

  char path[MAX_PATH_LENGTH];
  int32_t line_no;

  if (2 == std::sscanf(line.c_str(), "%[^:]:%d:%*s", path, &line_no)) {
    entry = AgEntry(std::string(path), line_no);
    return true;
  } else {
    LOG(ERROR) << "Invalid (unrecognized) ag output line: " << line;
    return false;
  }
}

bool AgSearchIterator::ReadLine(std::string& line) {
  return child_.running() && std::getline(stream_, line) && !line.empty();
}

AgSearchIterator::~AgSearchIterator() noexcept { child_.wait(); }

void AgSearchIterator::Cancel() { child_.terminate(); }

AgSearchIterator AgSearchIterator::Search(
    const std::filesystem::path& root, const std::string& query)
{
  AgSearchIterator iterator;
  iterator.child_ = boost::process::child(
      boost::process::search_path("ag"),
      query, root.string(), boost::process::std_out > iterator.stream_);
  return iterator;
}

}  // namespace app::ag
