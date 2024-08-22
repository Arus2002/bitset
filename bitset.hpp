#ifndef BITSET_HPP
#define BITSET_HPP

#include <iostream>
#include <vector>

template <std::size_t N>
class bitset {
public:
    bitset();
    explicit bitset(unsigned long value);
    explicit bitset(const std::string& bits);
    
    unsigned long to_ulong() const;
    unsigned long long to_ullong() const;
    std::string to_string() const;

    void set(std::size_t index, bool bit = true);
    void reset(std::size_t index);
    void flip();
    void flip(std::size_t index);

    bool all() const;
    bool any() const;
    bool none() const;
    std::size_t count() const;
    std::size_t size() const;

private:
    class Proxy {
    public:
        Proxy(bitset<N>& bits, std::size_t pos);
        Proxy& operator=(bool value);
        operator bool() const;

    private:
        bitset<N>& bits;
        std::size_t pos;
    };

public:
    Proxy operator[](std::size_t index);
    bool operator[](std::size_t index) const;
    bool test(std::size_t index) const;

    bitset& operator&=(const bitset& other);
    bitset& operator|=(const bitset& other);
    bitset& operator^=(const bitset& other);
    bitset operator~() const;
    bitset operator<<(std::size_t pos) const;
    bitset& operator<<=(std::size_t pos);
    bitset operator>>(std::size_t pos) const;
    bitset& operator>>=(std::size_t pos);
    bool operator==(const bitset& other) const;
    bool operator!=(const bitset& other) const;

    template<std::size_t M>
    friend bitset<M> operator&(const bitset<M>& lhs, const bitset<M>& rhs);
    template<std::size_t M>
    friend bitset<M> operator|(const bitset<M>& lhs, const bitset<M>& rhs);
    template<std::size_t M>
    friend bitset<M> operator^(const bitset<M>& lhs, const bitset<M>& rhs);

    template <std::size_t M>
    friend std::ostream& operator<<(std::ostream& os, const bitset<M>& bs);
    template <std::size_t M>
    friend std::istream& operator>>(std::istream& is, bitset<M>& bs);

private:
    void checkForCorrectString(const std::string& bits) const;

private:
    int m_count_flag;
    std::size_t m_size;
    static const std::size_t BITS_PER_UNIT = sizeof(unsigned int) * 8;
    std::vector<unsigned int> m_bits_array;
};

#include "bitset.impl.hpp"

#endif
