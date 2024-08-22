#include <gtest/gtest.h>
#include "bitset.hpp"
#include <bitset>

class BitsetTest2: public ::testing::Test {
protected:
    BitsetTest2()
        : bs1("110011")
	, bs2("000001")
        , my_bs1("110011")
	, my_bs2("000001") {}

protected:
    std::bitset<18> bs1;
    std::bitset<18> bs2;

    bitset<18> my_bs1;
    bitset<18> my_bs2;
};

TEST_F(BitsetTest2, test_binary_operations) {
    bs2 &= bs1;
    std::cout << "Standart opertaor&= : " << bs2 << std::endl;
    bs2 |= bs1;
    std::cout << "Standart opertaor|= : " << bs2 << std::endl; 
    bs2 = bs1 ^ bs2;
    std::cout << "Standart opertaor^ : " << bs2 << std::endl;
    bs2 = ~bs2;
    std::cout << "Standart opertaor~ : " << bs2 << std::endl;

    my_bs2 &= my_bs1;
    std::cout << "My bitset opertaor&= : " << my_bs2 << std::endl;
    my_bs2 |= my_bs1;
    std::cout << "My bitset opertaor|= : " << my_bs2 << std::endl;
    my_bs2 = my_bs1 ^ my_bs2;
    std::cout << "My bitset opertaor^ : " << my_bs2 << std::endl;
    my_bs2 = ~my_bs2;
    std::cout << "My bitset opertaor~ : " << my_bs2 << std::endl;

    EXPECT_EQ(bs2.to_ulong(), my_bs2.to_ulong());
    EXPECT_EQ(bs2.to_string(), my_bs2.to_string());
}

