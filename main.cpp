#include "bitset.hpp"
#include <bitset>

int main() {
    //Ex. 1
    std::bitset<64> bs(2345);
    bs.set(2);
    bs.reset(33);
    std::cout << "Standart to_ulong after set and reset: " << bs.to_ulong() << std::endl;
    std::cout << "Standart to_string after set and reset: " << bs.to_string() << std::endl;
    bs <<= 56;
    std::cout << "Standart to_ullong after left shift: " << bs.to_ullong() << std::endl;
    bs >>= 4;
    std::cout << "Standart to_string after right shift: " << bs.to_string() << std::endl;

    // bitset<64> bset(2345);
    // bset.set(2);
    // bset.reset(33);
    // std::cout << "My bitset to_ulong after set and reset: " << bset.to_ulong() << std::endl;
    // std::cout << "My bitset to_string after set and reset: " << bset.to_string() << std::endl;
    // bset <<= 56;
    // std::cout << "My bitset to_ullong after left shift: " << bset.to_ullong() << std::endl;
    // bset >>= 4;
    // std::cout << "My bitset to_string after right shift: " << bset.to_string() << std::endl;

    //Ex. 2
    // std::bitset<18> b1("110011");
    // std::bitset<18> b2("000001");
    // b2 &= b1;
    // std::cout << "Standart opertaor&= : " << b2 << std::endl;
    // b2 |= b1;
    // std::cout << "Standart opertaor|= : " << b2 << std::endl; 
    // b2 = b1 ^ b2;
    // std::cout << "Standart opertaor^ : " << b2 << std::endl;
    // b2 = ~b2;
    // std::cout << "Standart opertaor~ : " << b2 << std::endl;

    // bitset<18> a1("110011");
    // bitset<18> a2("000001");
    // a2 &= a1;
    // std::cout << "My bitset opertaor&= : " << a2 << std::endl;
    // a2 |= a1;
    // std::cout << "My bitset opertaor|= : " << a2 << std::endl;
    // a2 = a1 ^ a2;
    // std::cout << "My bitset opertaor^ : " << a2 << std::endl;
    // a2 = ~a2;
    // std::cout << "My bitset opertaor~ : " << a2 << std::endl;

    //Ex. 3
    // std::bitset<sizeof(unsigned long) * 8 * 2> b(std::numeric_limits<unsigned long>::max() + 2);
    // std::cout << "Standart to_ullong: " << b.to_ullong() << std::endl;
    // std::cout << "Standart to_string: " << b.to_string() << std::endl;
    // bitset<sizeof(unsigned long) * 8 * 2> s(std::numeric_limits<unsigned long>::max() + 2);
    // std::cout << "My bitset to_ullong: " << s.to_ullong() << std::endl;
    // std::cout << "My bitset to_string: " << s.to_string() << std::endl;

    //Ex. 4
    // std::bitset<64> b("1111110");
    // b.reset(5);
    // b = b << 5;
    // b.set(0);
    // b[0] = true;
    // std::cout << "Standart to_ullong: " << b.to_ullong() << std::endl;
    // std::cout << "Standart to_string: " << b.to_string() << std::endl;
    // std::cout << "Standart operator[]: " << b[5] << std::endl; 
    // bitset<64> s("1111110");
    // s.reset(5);
    // s = s << 5;
    // s.set(0);
    // s[0] = true;
    // std::cout << "My bitset to_ullong: " << s.to_ullong() << std::endl;
    // std::cout << "My bitset to_string: " << s.to_string() << std::endl;
    // std::cout << "Standart operator[]: " << s[5] << std::endl; 

    //Ex. 5
    // std::bitset<64> b;
    // std::cin >> b;
    // std::cout << "Standart ostream operator: " << b << std::endl;
    // b.set(0);
    // std::cout << "Standart ostream operator: " << b << std::endl;

    // bitset<64> s;
    // std::cin >> s;
    // std::cout << "My bitset ostream operator: " << s << std::endl;
    // s.set(0);
    // std::cout << "My bitset ostream operator: " << s << std::endl;

    //Ex. 6
    // std::bitset<sizeof(unsigned long) * 8> b(std::numeric_limits<unsigned long>::max());
    // std::cout << "My bitset to_ulong: " << b.to_ulong() << std::endl;
    // std::cout << "My bitset to_string: " << b.to_string() << std::endl;
    // bitset<sizeof(unsigned long) * 8> s(std::numeric_limits<unsigned long>::max());
    // std::cout << "My bitset to_ulong: " << s.to_ulong() << std::endl;
    // std::cout << "My bitset to_string: " << s.to_string() << std::endl;

    //Ex. 7
    // std::bitset<16> b(6000);
    // std::cout << "Standart none(): " << b.none() << std::endl;
    // std::cout << "Standart any(): " << b.any() << std::endl;
    // std::cout << "Standart count(): " << b.count() << std::endl;
    // std::cout << "Standart all(): " << b.all() << std::endl;

    // bitset<16> s(6000);
    // std::cout << "My bitset none(): " << s.none() << std::endl;
    // std::cout << "My bitse any(): " << s.any() << std::endl;
    // std::cout << "My bitse count(): " << s.count() << std::endl;
    // std::cout << "My bitse all(): " << s.all() << std::endl;
}