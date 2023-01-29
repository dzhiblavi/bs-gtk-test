#include <gtest/gtest.h>

#include "msg.pb.h"

TEST(proto, generate) {
  msg::Message msg;
  msg.add_id(239);
  ASSERT_EQ(1, msg.id_size());
}

