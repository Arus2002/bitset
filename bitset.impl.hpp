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
            set(i);
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
            set(settingBit);
        }
        else {
            set(settingBit, false);
        }
        ++settingBit;
    }   
}

template <std::size_t N>
unsigned long bitset<N>::to_ulong() const {
    unsigned long result = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (test(i) && i >= sizeof(unsigned long) * 8) {
            throw std::range_error("This number can't be represented in unsigned long!");
        }
        std::size_t bits_array_index = i / BITS_PER_UNIT;
        std::size_t bit_index = i % BITS_PER_UNIT;
        bool bit = (m_bits_array[bits_array_index] & (1U << bit_index));
        if(test(i)) {
            result |= 1UL << i;
        } 
    }
    return result;
}

template <std::size_t N>
unsigned long long bitset<N>::to_ullong() const {
    unsigned long long result = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (test(i) && i >= sizeof(unsigned long long) * 8) {
            throw std::range_error("This number can't be represented in unsigned long long!");
        }
        std::size_t bits_array_index = i / BITS_PER_UNIT;
        std::size_t bit_index = i % BITS_PER_UNIT;
        if(test(i)) {
            result |= 1ULL << i;
        }
    }
    return result;
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
void bitset<N>::set(std::size_t index, bool bit) {
    if (index < 0) {
        throw std::range_error("Index can't be negative or greater than size of bits!");
    }
    if (bit) {
        ++m_count_flag;
        std::size_t bits_array_index = index / BITS_PER_UNIT;
        std::size_t bit_index = index % BITS_PER_UNIT;
        m_bits_array[bits_array_index] |= (1U << bit_index);
    }
    else {
        reset(index);
    }
}

template <std::size_t N>
void bitset<N>::reset(std::size_t index) {
    if (index < 0) {
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
    if (index < 0) {
        throw std::range_error("Index can't be negative or greater than size of bits!");
    }
    std::size_t bits_array_index = index / BITS_PER_UNIT;
    std::size_t bit_index = index % BITS_PER_UNIT;
    bool bit = (m_bits_array[bits_array_index] & (1U << bit_index));
    set(index, !bit);
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
typename bitset<N>::Proxy bitset<N>::operator[](std::size_t index) {
    if (index >= N) {
        throw std::out_of_range("Bit position out of range");
    }
    return Proxy(*this, index);
}

template <std::size_t N>
bool bitset<N>::operator[](std::size_t index) const {
    std::size_t bits_array_index = index / BITS_PER_UNIT;
    std::size_t bit_index = index % BITS_PER_UNIT;
    return (m_bits_array[bits_array_index] & (1U << bit_index)) != 0;
}

template <std::size_t N>
bool bitset<N>::test(std::size_t index) const {
    if (index >= N) {
        throw std::out_of_range("Index out of range");
    }
    std::size_t bits_array_index = index / BITS_PER_UNIT;
    std::size_t bit_index = index % BITS_PER_UNIT;
    return (m_bits_array[bits_array_index] & (1U << bit_index)) != 0;
}

template <std::size_t N>
bitset<N>& bitset<N>::operator&=(const bitset<N>& other) {
    if (m_size != other.m_size) {
        throw std::range_error("Not equal bitsets");
    }
    for (int i = 0; i < m_size; ++i) {
        m_bits_array[i] &= other.m_bits_array[i];
    }
    return *this;
}

template <std::size_t N>
bitset<N>& bitset<N>::operator|=(const bitset<N>& other) {
    if (m_size != other.m_size) {
        throw std::range_error("Not equal bitsets");
    }
    for (int i = 0; i < m_size; ++i) {
        m_bits_array[i] |= other.m_bits_array[i];
    }
    return *this;
}

template <std::size_t N>
bitset<N>& bitset<N>::operator^=(const bitset<N>& other) {
    if (m_size != other.m_size) {
        throw std::range_error("Not equal bitsets");
    }
    for (int i = 0; i < m_size; ++i) {
        m_bits_array[i] ^= other.m_bits_array[i];
    }
    return *this;
}

template <std::size_t N>
bitset<N> bitset<N>::operator~() const {
    bitset<N> tmp = *this;
    for (int i = 0; i < m_size; ++i) {
        tmp.m_bits_array[i] =  ~m_bits_array[i];
    }
    return tmp;
}

template <std::size_t N>
bitset<N> bitset<N>::operator<<(std::size_t pos) const {
    if (pos < 0) {
        throw std::out_of_range("Index is negative");
    }
    bitset<N> result;
    if (pos >= N) {
        return result;
    }
    std::size_t unit_shift = pos / BITS_PER_UNIT;
    std::size_t bit_shift = pos % BITS_PER_UNIT;
    for (int i = 0; i < m_bits_array.size(); ++i) {
        std::size_t target_index = i + unit_shift;
        if (target_index >= m_bits_array.size()) {
            break;
        }
        result.m_bits_array[target_index] |= (m_bits_array[i] << bit_shift);
        if (bit_shift > 0 && target_index + 1 < m_bits_array.size()) {
            result.m_bits_array[target_index + 1] |= (m_bits_array[i] >> (BITS_PER_UNIT - bit_shift));
        }
    }
    return result;
}

template <std::size_t N>
bitset<N>& bitset<N>::operator<<=(std::size_t pos) {
    *this = *this << pos;
    return *this;
}

template <std::size_t N>
bitset<N> bitset<N>::operator>>(std::size_t pos) const {
    if (pos < 0) {
        throw std::out_of_range("Index is negative");
    }
    bitset<N> result;
    if (pos >= N) {
        return result;
    }
    std::size_t unit_shift = pos / BITS_PER_UNIT;
    std::size_t bit_shift = pos % BITS_PER_UNIT;  
    for (int i = 0; i < m_size; ++i) {
        int target_index = i + unit_shift;
        result.m_bits_array[i] = m_bits_array[target_index] >> bit_shift;
        if (i != m_size - unit_shift - 1) {
            result.m_bits_array[i] |= (m_bits_array[target_index + 1] << (BITS_PER_UNIT - bit_shift));
        } 
        if (i >= m_size - unit_shift) {
            result.m_bits_array[i] = 0;
        }
    }    
    return result;
}

template< std::size_t N>
bitset<N>& bitset<N>::operator>>=(std::size_t pos) {
    *this = *this >> pos;
    return *this;
}

template< std::size_t N>
bitset<N> operator&(const bitset<N>& lhs, const bitset<N>& rhs) {
    bitset<N> result;

    for (std::size_t i = 0; i < lhs.m_size; ++i) {
        result.m_bits_array[i] = lhs.m_bits_array[i] & rhs.m_bits_array[i];
    }

    return result;
}

template< std::size_t N>
bitset<N> operator|(const bitset<N>& lhs, const bitset<N>& rhs) {
    bitset<N> result;

    for (std::size_t i = 0; i < lhs.m_size; ++i) {
        result.m_bits_array[i] = lhs.m_bits_array[i] | rhs.m_bits_array[i];
    }

    return result;
}

template< std::size_t N>
bitset<N> operator^(const bitset<N>& lhs, const bitset<N>& rhs) {
    bitset<N> result;

    for (std::size_t i = 0; i < lhs.m_size; ++i) {
        result.m_bits_array[i] = lhs.m_bits_array[i] ^ rhs.m_bits_array[i];
    }

    return result;
}

template <std::size_t N>
std::ostream& operator<<(std::ostream& os, const bitset<N>& bs) {
    std::string bits = bs.to_string();
    os << bits;
    return os;
}

template <std::size_t N>
std::istream& operator>>(std::istream& is, bitset<N>& bs) {
    std::string bits;
    is >> bits;
    bs = bitset<N>(bits);
    return is;
}

template <std::size_t N>
bool bitset<N>::operator==(const bitset& other) const {
    return m_bits_array == other.m_bits_array &&
           m_count_flag == other.m_count_flag;
}

template <std::size_t N>
bool bitset<N>::operator!=(const bitset& other) const {
    return !(*this == other);
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

template <std::size_t N>
bitset<N>::Proxy::Proxy(bitset<N>& bits, std::size_t pos)
    : bits(bits), pos(pos) {}

template <std::size_t N>
typename bitset<N>::Proxy& bitset<N>::Proxy::operator=(bool value) {
    bits.set(pos, value);
    return *this;
}

template <std::size_t N>
bitset<N>::Proxy::operator bool() const {
    return bits.test(pos);
}
