#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "donut.h"

TEST(donutTests, defaultConstructorTest)
{
    donut d;
    EXPECT_EQ(d.getIcing(), NOICE);
    EXPECT_EQ(d.getTopping(), NOTOP);
    EXPECT_EQ(d.getDrizzle(), NODRIZZLE);
}
TEST(donutTests, paramConstructorTest)
{
    donut d("vanilla", "bacon", "raspberry");
    EXPECT_EQ(d.getIcing(), VANILLA);
    EXPECT_EQ(d.getTopping(), BACON);
    EXPECT_EQ(d.getDrizzle(), RASPBERRY);
}
TEST(donutTests, toStringTest)
{
    donut d("vanilla", "bacon", "raspberry");
    std::string donutStr = d.toString();
    EXPECT_STRCASEEQ(donutStr.c_str(), "Icing: Vanilla Topping: Bacon Drizzle: Raspberry");
}

extern "C" int startTest(int x, char **y)
{
    testing::InitGoogleTest(&x, y);
    int code = RUN_ALL_TESTS();
    return code;
}

extern "C" int __wrap_main(int x, char **y)
{
    return startTest(x, y);
}