#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "common.h"
}

TEST(test1, suite1)
{
    EXPECT_EQ(1, 1);
    /*ASSERT_THAT(0, Eq(0)); */
}
