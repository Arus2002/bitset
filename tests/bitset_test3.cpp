#include <gtest/gtest.h>
#include "bitset.hpp"
#include <bitset>

class BitsetTest3: public ::testing::Test {
protected:
    BitsetTest3()
        : bs(std::numeric_limits<unsigned long>::max() + 2)
	, my_bs(std::numeric_limits<unsigned long>::max() + 2) {} 

protected:
    std::bitset<sizeof(unsigned long) * 8 * 2> bs;
    bitset<sizeof(unsigned long) * 8 * 2> my_bs;
};

TEST_F(BitsetTest3, test_ullong) {
    std::cout << "Standart to_ullong: " << bs.to_ullong() << std::endl;
    std::cout << "Standart to_string: " << bs.to_string() << std::endl;

    std::cout << "My bitset to_ullong: " << my_bs.to_ullong() << std::endl;
    std::cout << "My bitset to_string: " << my_bs.to_string() << std::endl;
    EXPECT_EQ(bs.to_ullong(), my_bs.to_ullong());
    EXPECT_EQ(bs.to_string(), my_bs.to_string());
}

