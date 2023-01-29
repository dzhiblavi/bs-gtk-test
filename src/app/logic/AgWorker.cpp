#include "app/logic/AgWorker.h"
#include "ag/ag_search.h"

namespace app::gtk {

void AgWorker::Start(const std::filesystem::path& path, const std::string& query) {
  Cancel();
  std::lock_guard<std::mutex> lg(lock_);
  thread_ = std::thread(std::bind(&AgWorker::MainThread, this, path, query));
}

bool AgWorker::FetchNewResults(std::vector<ag::AgEntry>& out) {
  std::lock_guard<std::mutex> lg(lock_);
  if (finished_ && entries_.empty()) {
    return false;
  }
  out = std::move(entries_);
  entries_.clear();
  return !out.empty();  
}

void AgWorker::Cancel() noexcept {
  finished_ = true;
  if (thread_.joinable()) {
    thread_.join();
  }
  finished_ = false;
  entries_.clear();
}

void AgWorker::MainThread(std::filesystem::path path, std::string query) noexcept {
  app::ag::AgSearchIterator iterator = app::ag::AgSearchIterator::Search(path, query);
  app::ag::AgEntry entry;

  while (!finished_ && iterator.Next(entry)) {
    std::lock_guard<std::mutex> lg(lock_);
    entries_.push_back(entry);
  }

  iterator.Cancel();
  finished_ = true;
}

}  // namespace app::gtk

