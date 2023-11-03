#include "arrayStack.h"
#include "linkedStack.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>

TEST(stackTest, arrayStackTest)
{
    arrayStack<int> as;
    EXPECT_THROW(as.pop(), std::underflow_error);
    EXPECT_THROW(as.top(), std::out_of_range);
    EXPECT_TRUE(as.isEmptyStack());
    for (int i = 0; i < 100; i++)
    {
        as.push(i);
    }
    EXPECT_TRUE(as.isFullStack());
    EXPECT_THROW(as.push(100), std::overflow_error);
    arrayStack<int> as2(20);
    arrayStack<int> as3(as);
}
// lecture activity test the linked list stack like we tested the array stack.

int main(int x, char **y)
{
    testing::InitGoogleTest(&x, y);
    int code = RUN_ALL_TESTS();
    return code;
}