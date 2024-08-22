#include <gtest/gtest.h>
#include "bitset.hpp"
#include <bitset>

class BitsetTest6: public ::testing::Test {
protected:
    BitsetTest6()
        : bs(6000)
	, my_bs(6000) {}

protected:
    std::bitset<16> bs;
    bitset<16> my_bs;
};

TEST_F(BitsetTest6, test_none) {
    std::cout << "Standart none: " << bs.none() << std::endl;
   
    std::cout << "My bitset none: " << my_bs.none() << std::endl;
    
    EXPECT_EQ(bs.none(), my_bs.none());
}

TEST_F(BitsetTest6, test_any) {
    std::cout << "Standart any: " << bs.any() << std::endl;

    std::cout << "My bitset any: " << my_bs.any() << std::endl;

    EXPECT_EQ(bs.any(), my_bs.any());
}

TEST_F(BitsetTest6, test_count) {
    std::cout << "Standart count: " << bs.count() << std::endl;

    std::cout << "My bitset count: " << my_bs.count() << std::endl;

    EXPECT_EQ(bs.count(), my_bs.count());
}

TEST_F(BitsetTest6, test_all) {
    std::cout << "Standart all: " << bs.all() << std::endl;

    std::cout << "My bitset all: " << my_bs.all() << std::endl;

    EXPECT_EQ(bs.all(), my_bs.all());
}


