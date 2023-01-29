#include <filesystem>
#include <thread>
#include <mutex>

#include "ag/ag_entry.h"

namespace app::gtk {

class AgWorker {
 public:
  ~AgWorker() noexcept;

  void Start(const std::filesystem::path& path, const std::string& query);

  bool FetchNewResults(std::vector<ag::AgEntry>& out);

  void Cancel() noexcept;

 private:
  void MainThread(std::filesystem::path path, std::string query) noexcept;

  std::atomic<bool> finished_{false};
  std::mutex lock_;
  std::thread thread_;
  std::vector<ag::AgEntry> entries_;
};

}  // namespace app::gtk

