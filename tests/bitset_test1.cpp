#include <gtest/gtest.h>
#include "bitset.hpp"
#include <bitset>

class BitsetTest1: public ::testing::Test {
protected:
    BitsetTest1()
        : bs(2345)
	, my_bs(2345) {}

protected:
    std::bitset<64> bs;
    bitset<64> my_bs;
};

TEST_F(BitsetTest1, test_set_reset) {
    bs.set(2);
    bs.reset(33);
    std::cout << "Standart to_ulong after set and reset: " << bs.to_ulong() << std::endl;
    std::cout << "Standart to_string after set and reset: " << bs.to_string() << std::endl;

    my_bs.set(2);
    my_bs.reset(33);
    std::cout << "My bitset to_ulong after set and reset: " << my_bs.to_ulong() << std::endl;
    std::cout << "My bitset to_string after set and reset: " << my_bs.to_string() << std::endl;

    EXPECT_EQ(bs.to_ulong(), my_bs.to_ulong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}

TEST_F(BitsetTest1, test_flip) {
    bs.flip(5);
    bs.flip();
    std::cout << "Standart to_ulong after set and reset: " << bs.to_ulong() << std::endl;
    std::cout << "Standart to_string after set and reset: " << bs.to_string() << std::endl;

    my_bs.flip(5);
    my_bs.flip();
    std::cout << "My bitset to_ulong after set and reset: " << my_bs.to_ulong() << std::endl;
    std::cout << "My bitset to_string after set and reset: " << my_bs.to_string() << std::endl;

    EXPECT_EQ(bs.to_ulong(), my_bs.to_ulong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}

TEST_F(BitsetTest1, test_right_left_shift) {
    bs <<= 56;
    std::cout << "Standart to_ullong after left shift: " << bs.to_ullong() << std::endl;
    bs >>= 4;
    std::cout << "Standart to_string after right shift: " << bs.to_string() << std::endl;

    my_bs <<= 56;
    std::cout << "My bitset to_ullong after left shift: " << my_bs.to_ullong() << std::endl;
    my_bs >>= 4;
    std::cout << "My bitset to_string after right shift: " << my_bs.to_string() << std::endl;

    EXPECT_EQ(bs.to_ulong(), my_bs.to_ulong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}
