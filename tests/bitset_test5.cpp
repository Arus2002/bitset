#include <gtest/gtest.h>
#include "bitset.hpp"
#include <bitset>

class BitsetTest5: public ::testing::Test {
protected:
    std::bitset<64> bs;
    bitset<64> my_bs;
};

TEST_F(BitsetTest5, test_istream_ostream) {
    std::cout << "Please input binary for standart" << std::endl;
    std::cin >> bs;
    std::cout << "Standart ostream: " << bs << std::endl;

    std::cout << "Please enter the same binary for my bitset" << std::endl;
    std::cin >> my_bs;
    std::cout << "My bitset ostream: " << my_bs << std::endl;
    
    EXPECT_EQ(bs.to_ullong(), my_bs.to_ullong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}

