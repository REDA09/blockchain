#pragma once
#include "Transaction.h"
#include <vector>
#include <string>
#include <chrono>

enum class HashMode {
    SHA256,
    AC_HASH
};

class Block {
public:
    int index;
    std::string timestamp;
    std::string prevHash;
    std::string merkleRoot;
    long long nonce;
    std::string hash;
    std::vector<Transaction> transactions;
    HashMode hashMode = HashMode::SHA256;
    uint32_t acRule = 30;
    size_t acSteps = 128;

    Block() = default;
    Block(int idx, const std::vector<Transaction>& txs, const std::string& prev, 
          HashMode mode=HashMode::SHA256, uint32_t rule=30, size_t steps=128);
    void mineBlock(int difficulty);
    std::string calculateHash() const;
};
