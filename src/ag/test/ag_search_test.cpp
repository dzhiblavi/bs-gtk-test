#include <gtest/gtest.h>
#include <iostream>

#include "ag/ag_search.h"

namespace app::ag {

TEST(ag_search, project_dir) {
  AgSearchIterator iterator = AgSearchIterator::Search("/Users/dzhiblavi/cpp-gtk", "add");

  AgEntry entry;
  while (iterator.Next(entry)) {
    std::cout << "entry: " << entry.Path() << " line = " << entry.LineNos().size() << std::endl;
  }
}

}  // namespace app::ag
