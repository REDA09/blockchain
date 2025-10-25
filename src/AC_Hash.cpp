#include "../include/AC_Hash.h"
#include "AutomateCellulaire.h"
#include <bitset>
#include <sstream>
#include <algorithm>

static std::vector<uint8_t> string_to_bits(const std::string& s) {
    std::vector<uint8_t> bits;
    for (char c : s) {
        std::bitset<8> b(c);
        for (int i = 7; i >= 0; --i) bits.push_back(b[i]);
    }
    return bits;
}

std::string ac_hash(const std::string& input, uint32_t rule, size_t steps) {
    std::vector<uint8_t> bits = string_to_bits(input);

    if (bits.size() < 256) {
        size_t n = 256 - bits.size();
        for (size_t i = 0; i < n; ++i) bits.push_back(bits[i % bits.size()]);
    } else if (bits.size() > 256) {
        bits.resize(256);
    }

    AutomateCellulaire ac(rule);
    ac.init_state(bits);


    for (size_t i = 0; i < steps; ++i) ac.evolve();

    std::ostringstream ss;
    for (size_t i = 0; i < 256; i += 4) {
        uint8_t val = (ac.state[i] << 3) | (ac.state[i+1] << 2) | (ac.state[i+2] << 1) | ac.state[i+3];
        ss << std::hex << (int)val;
    }

    return ss.str();
}
