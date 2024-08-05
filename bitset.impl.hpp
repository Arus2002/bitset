#include "bitset.hpp"

#include <bitset>
#include <cmath>
#include <algorithm>

template <std::size_t N>
bitset<N>::bitset() 
    : m_count_flag{0}
    , m_size{(N + BITS_PER_UNIT - 1) / (BITS_PER_UNIT)}
    , m_bits_array(m_size, 0) 
{}

template <std::size_t N>
bitset<N>::bitset(unsigned long value)
    : m_count_flag{0}
    , m_size{(N + BITS_PER_UNIT - 1) / (BITS_PER_UNIT)}
    , m_bits_array(m_size, 0) 
{
    for (int i = 0; i < BITS_PER_UNIT; ++i) {
        if ((value & (1U << i))) {
            set(i, true);
        }
        else {
            set(i, false);
        }
    }
}

template <std::size_t N>
bitset<N>::bitset(const std::string& bits)
    : m_count_flag{0}
    , m_size{(N + BITS_PER_UNIT - 1) / (BITS_PER_UNIT)}
    , m_bits_array(m_size, 0)
{
    checkForCorrectString(bits);
    int settingBit = 0;
    for (int i = bits.size() - 1; i >= 0; --i) {
        if (bits[i] == '1') {
            set(settingBit, true);
        }
        else {
            set(settingBit, false);
        }
        ++settingBit;
    }   
}

template <std::size_t N>
void bitset<N>::set(std::size_t index, bool bit) {
    if (index < 0  index >= N) {
        throw std::range_error("Index can't be negative or greater than size of bits!");
    }
    if (bit) {
        ++m_count_flag;
        std::size_t bits_array_index = index / BITS_PER_UNIT;
        std::size_t bit_index = index % BITS_PER_UNIT;
        m_bits_array[bits_array_index] |= (1U << bit_index);
    }
    else {
        std::size_t bits_array_index = index / BITS_PER_UNIT;
        std::size_t bit_index = index % BITS_PER_UNIT;
        m_bits_array[bits_array_index] &= ~(1U << bit_index);
    }
}

template <std::size_t N>
void bitset<N>::reset(std::size_t index) {
    if (index < 0  index >= N) {
        throw std::range_error("Index can't be negative or greater than size of bits!");
    }
    std::size_t bits_array_index = index / BITS_PER_UNIT;
    std::size_t bit_index = index % BITS_PER_UNIT;
    if ((m_bits_array[bits_array_index] & (1U << bit_index))) {
        --m_count_flag;
        m_bits_array[bits_array_index] &= ~(1U << bit_index);
    }
}

template <std::size_t N>
void bitset<N>::flip() {
    for (int i = 0; i < m_size; ++i) {
        m_bits_array[i] = ~m_bits_array[i];
    }
}

template <std::size_t N>
void bitset<N>::flip(std::size_t index) {
    if (index < 0  index >= N) {
        throw std::range_error("Index can't be negative or greater than size of bits!");
    }
    bool bit = (m_bits_array[bits_array_index] & (1U << bit_index));
    set(index, !bit);
}

template <std::size_t N>
std::string bitset<N>::to_string() const {
    std::string result;
    for (int i = 0; i < N; ++i) {
        std::size_t bits_array_index = i / BITS_PER_UNIT;
        std::size_t bit_index = i % BITS_PER_UNIT;
        bool bit = (m_bits_array[bits_array_index] & (1U << bit_index));
        if (bit) {
            result += '1';
        }
        else {
            result += '0';
        }      
    }
    std::reverse(result.begin(), result.end());
    return result;
}

template <std::size_t N>
unsigned long bitset<N>::to_ulong() const {
    if (N >= BITS_PER_UNIT) {
        throw std::range_error("You can't convert this number to unsigned long!");
    }
    unsigned long result = 0;
    for (int i = N - 1; i >= 0; --i) {
        std::size_t bits_array_index = i / BITS_PER_UNIT;
        std::size_t bit_index = i % BITS_PER_UNIT;
        int bit = (m_bits_array[bits_array_index] & (1U << bit_index));
        //std::cout << bits_array_index << " " << bit_index << " " << i << " "<< bit << std::endl;
        result += bit * std::pow(2, i);   
    }
    return result;
}

template <std::size_t N>
unsigned long long bitset<N>::to_ullong() const {
    unsigned long long result = 0;
    for (int i = N - 1; i >= 0; --i) {
        std::size_t bits_array_index = i / BITS_PER_UNIT;
        std::size_t bit_index = i % BITS_PER_UNIT;
        bool bit = (m_bits_array[bits_array_index] & (1U << bit_index));
        //std::cout << bits_array_index << " " << bit_index << " " << i << " "<< bit << std::endl;
        result += bit * std::pow(2, i);   
    }
    return result;
}

template <std::size_t N>
bool bitset<N>::operator[](std::size_t index) const {
    std::size_t bits_array_index = index / BITS_PER_UNIT;
    std::size_t bit_index = index % BITS_PER_UNIT;
    return (m_bits_array[bits_array_index] & (1U << bit_index)) != 0;
}

template <std::size_t N>
bool bitset<N>::test(std::size_t index) const {
    if (index < 0  index >= N) {
        throw std::out_of_range("Index out of range");
    }
    std::size_t bits_array_index = index / BITS_PER_UNIT;
    std::size_t bit_index = index % BITS_PER_UNIT;
    return (m_bits_array[bits_array_index] & (1U << bit_index)) != 0;
}

template <std::size_t N>
bool bitset<N>::all() const {
    return m_count_flag == N;
}

template <std::size_t N>
bool bitset<N>::any() const {
    return m_count_flag != 0;
}

template <std::size_t N>
bool bitset<N>::none() const {
    return m_count_flag == 0;
}

template <std::size_t N>
std::size_t bitset<N>::count() const {
    return m_count_flag;
}

template <std::size_t N>
std::size_t bitset<N>::size() const {
    return N;
}

template <std::size_t N>
void bitset<N>::checkForCorrectString(const std::string& bits) const {
    if (bits.size() > N) {
        throw std::range_error("Bits you have provided have greater size than the size of bitset.");
    }
    for (int i = 0; i < bits.size(); ++i) {
        if (bits[i] != '1' && bits[i] != '0') {
            throw std::invalid_argument("Your string must only consists of digits: 0 and 1");
        }
    }
}