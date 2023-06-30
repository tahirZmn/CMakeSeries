#include <gtest/gtest.h>

// Example function to be tested
int add(int a, int b) {
    return a + b;
}

// Example test case
TEST(ExampleTest, Addition) {
    EXPECT_EQ(add(2, 2), 4);
}

// Run all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}