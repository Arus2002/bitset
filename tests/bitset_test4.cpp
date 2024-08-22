#include <gtest/gtest.h>
#include "bitset.hpp"
#include <bitset>

class BitsetTest4: public ::testing::Test {
protected:
    BitsetTest4()
        : bs("1111110")
	, my_bs("1111110") {}

protected:
    std::bitset<64> bs;
    bitset<64> my_bs;
};

TEST_F(BitsetTest4, test_reset) {
    bs.reset(5);
    std::cout << "Standart to_ullong: " << bs.to_ullong() << std::endl;
    std::cout << "Standart to_string: " << bs.to_string() << std::endl;

    my_bs.reset(5);
    std::cout << "My bitset to_ullong: " << my_bs.to_ullong() << std::endl;
    std::cout << "My bitset to_string: " << my_bs.to_string() << std::endl;
    EXPECT_EQ(bs.to_ullong(), my_bs.to_ullong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}

TEST_F(BitsetTest4, test_left_shift) {
    bs = bs << 5;;
    std::cout << "Standart to_ullong: " << bs.to_ullong() << std::endl;
    std::cout << "Standart to_string: " << bs.to_string() << std::endl;

    my_bs = my_bs << 5;
    std::cout << "My bitset to_ullong: " << my_bs.to_ullong() << std::endl;
    std::cout << "My bitset to_string: " << my_bs.to_string() << std::endl;
    EXPECT_EQ(bs.to_ullong(), my_bs.to_ullong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}

TEST_F(BitsetTest4, test_set) {
    bs.set(0);
    std::cout << "Standart to_ullong: " << bs.to_ullong() << std::endl;
    std::cout << "Standart to_string: " << bs.to_string() << std::endl;

    my_bs.set(0);
    std::cout << "My bitset to_ullong: " << my_bs.to_ullong() << std::endl;
    std::cout << "My bitset to_string: " << my_bs.to_string() << std::endl;
    EXPECT_EQ(bs.to_ullong(), my_bs.to_ullong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}

TEST_F(BitsetTest4, test_bool_operator) {
    bs[0] = false;
    std::cout << "Standart to_ullong: " << bs.to_ullong() << std::endl;
    std::cout << "Standart to_string: " << bs.to_string() << std::endl;

    my_bs[0] = false;
    std::cout << "My bitset to_ullong: " << my_bs.to_ullong() << std::endl;
    std::cout << "My bitset to_string: " << my_bs.to_string() << std::endl;
    EXPECT_EQ(bs.to_ullong(), my_bs.to_ullong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}




