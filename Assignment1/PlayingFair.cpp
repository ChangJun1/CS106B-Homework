#include <gtest/gtest.h>
#include <string>

std::string bSequenceOfOrder(int n);

std::string aSequenceOfOrder(int n) {
    if (n < 0) {
        throw std::invalid_argument("n can not be negative!");
    }
    if (n == 0) {
        return "A";
    }
    return aSequenceOfOrder(n - 1) + bSequenceOfOrder(n - 1);
}

std::string bSequenceOfOrder(int n) {
    if (n < 0) {
        throw std::invalid_argument("n can not be negative!");
    }
    if (n == 0) {
        return "B";
    }
    return bSequenceOfOrder(n - 1) + aSequenceOfOrder(n - 1);
}

TEST(TEST, MyTEST) {
    ASSERT_EQ(aSequenceOfOrder(3), "ABBABAAB");
    ASSERT_EQ(bSequenceOfOrder(3), "BAABABBA");
    ASSERT_EQ(aSequenceOfOrder(4), "ABBABAABBAABABBA");
    ASSERT_EQ(bSequenceOfOrder(4), "BAABABBAABBABAAB");
    EXPECT_ANY_THROW(aSequenceOfOrder(-137));
    EXPECT_ANY_THROW(bSequenceOfOrder(-137));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}