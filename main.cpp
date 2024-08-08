#include "bitset.hpp"
#include <bitset>

int main() {
    //Ex. 2
    // std::bitset<18> b1("110011");
    // std::bitset<18> b2("000001");
    // b2 &= b1;
    // std::cout << b2 << std::endl; 

    // bitset<18> a1("110011");
    // bitset<18> a2("000001");
    // a2 &= a1;
    // std::cout << a2 << std::endl;

    //Ex. 3
    // std::bitset<sizeof(unsigned long) * 8 * 2> b(std::numeric_limits<unsigned long>::max() + 2);
    // std::cout << b.to_ullong() << " " << b.to_string() << std::endl;
    // bitset<sizeof(unsigned long) * 8 * 2> s(std::numeric_limits<unsigned long>::max() + 2);
    // std::cout << s.to_ullong() << " " << s.to_string() << std::endl;

    //Ex. 4
    // std::bitset<64> b("1111110");
    // std::cout << sizeof(unsigned long long) * 8 << std::endl;
    // b.reset(5);
    // b = b << 5;
    // b.set(0);
    // std::cout << b.to_ullong() << " " << b.to_string() << " " << b[5] << std::endl;
    // bitset<64> s("1111110");
    // s.reset(5);
    // s = s << 5;
    // s.set(0);
    // std::cout << s.to_ullong() << " " << s.to_string() << " " << s[5] << std::endl;

    //Ex. 5
    // std::bitset<64> b;
    // std::cin >> b;
    // std::cout << b.to_ullong() << std::endl;
    // b.set(0);
    // std::cout << b.to_ullong() << std::endl;

    // bitset<64> s;
    // std::cin >> s;
    // std::cout << s.to_ullong() << std::endl;
    // s.set(0);
    // std::cout << s.to_ullong() << std::endl;

    //Ex. 6
    // std::bitset<sizeof(unsigned long) * 8> b(std::numeric_limits<unsigned long>::max() + 1);
    // std::cout << b.to_ullong() << " " << b.to_string() << std::endl;
    // bitset<sizeof(unsigned long) * 8> s(std::numeric_limits<unsigned long>::max() + 1);
    // std::cout << s.to_ullong() << " " << s.to_string() << std::endl;

    //Ex. 7
    // std::bitset<sizeof(unsigned long) * 8> b(std::numeric_limits<unsigned long>::max());
    // std::cout << b.to_ullong() << " " << b.to_string() << std::endl;
    // bitset<sizeof(unsigned long) * 8> s(std::numeric_limits<unsigned long>::max());
    // std::cout << s.to_ullong() << " " << s.to_string() << std::endl;
}