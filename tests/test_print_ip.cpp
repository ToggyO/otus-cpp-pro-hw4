#include <gtest/gtest.h>
#include <iostream>

#include "print_ip.h"

TEST(TestHW4, TestInteger) {
    std::string ip;
    std::stringstream ss;

    print_ip(int8_t{-1}, ss);
    ss >> ip;
    EXPECT_EQ(ip, "255");

    print_ip(int16_t{0}, ss);
    ss >> ip;
    EXPECT_EQ(ip, "0.0");

    print_ip(int32_t{2130706433}, ss);
    ss >> ip;
    EXPECT_EQ(ip, "127.0.0.1");

    print_ip(int64_t{8875824491850138409}, ss);
    ss >> ip;
    EXPECT_EQ(ip, "123.45.67.89.101.112.131.41");
}

TEST(TestHW4, TestString) {
    std::string ip;
    std::stringstream ss;

    print_ip(std::string{"Hello, World!"}, ss);
    std::getline(ss, ip);
    EXPECT_EQ(ip, "Hello, World!");
}

TEST(TestHW4, TestContainers) {
    std::string ip;
    std::stringstream ss;

    print_ip(std::vector<int>{100, 200, 300, 400}, ss);
    ss >> ip;
    EXPECT_EQ(ip, "100.200.300.400");

    print_ip(std::list<short>{400, 300, 200, 100}, ss);
    ss >> ip;
    EXPECT_EQ(ip, "400.300.200.100");
}

TEST(TestHW4, TestTuple) {
    std::string ip;
    std::stringstream ss;

    print_ip(std::make_tuple(123, 456, 789, 0), ss);
    ss >> ip;
    EXPECT_EQ(ip, "123.456.789.0");
}
