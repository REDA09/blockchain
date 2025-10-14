#pragma once
#include "Transaction.h"
#include <vector>
#include <string>
#include <chrono>

class Block {
public:
    int index;
    std::string timestamp;
    std::string prevHash;
    std::string merkleRoot;
    long long nonce;
    std::string hash;
    std::vector<Transaction> transactions;
    Block() = default;
    Block(int idx, const std::vector<Transaction>& txs, const std::string& prev);
    void mineBlock(int difficulty);
    std::string calculateHash() const;
};
