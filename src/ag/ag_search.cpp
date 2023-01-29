#include "ag/ag_search.h"

#include <glog/logging.h>

#include <cstdio>
#include <iostream>

namespace app::ag {

bool AgSearchIterator::Next(AgEntry& entry) {
  std::string path;
  int32_t line_no;

  if (!ReadLine(path, line_no)) {
    return false;
  }

  std::string s_path(path);
  entry = AgEntry(s_path);
  entry.AddLineNo(line_no);

  for (;;) {
    if (!ReadLine(path, line_no)) {
      break;
    }

    if (path != s_path) {
      last_line_ = std::make_pair(path, line_no);
      break;
    }

    entry.AddLineNo(line_no);
  }

  return true;
}

bool AgSearchIterator::ReadLine(std::string& line, int32_t& line_no) {
  if (last_line_.has_value()) {
    line = last_line_.value().first;
    line_no = last_line_.value().second;
    last_line_ = std::nullopt;
    return true;
  }

  if (!(child_.running() && std::getline(stream_, line) && !line.empty())) {
    return false;
  }

  static constexpr size_t MAX_PATH_LENGTH = 1024;
  char path[MAX_PATH_LENGTH];

  if (2 != std::sscanf(line.c_str(), "%[^:]:%d:%*s", path, &line_no)) {
    LOG(ERROR) << "Invalid (unrecognized) ag output line: " << line;
    return false;
  }

  line = std::string(path);
  return true;
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
