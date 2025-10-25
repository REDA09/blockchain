#pragma once
#include "Block.h"
#include "Transaction.h"
#include <vector>
#include <string>

class Blockchain {
public:
    std::vector<Block> chain;
    int difficulty;
    HashMode hashMode = HashMode::SHA256;
    uint32_t acRule = 30;
    size_t acSteps = 128;

    Blockchain(int diff=2, HashMode mode=HashMode::SHA256, uint32_t rule=30, size_t steps=128);
    Block createGenesisBlock();
    void addBlock(const std::vector<Transaction>& txs);
    bool isChainValid() const;
    void addBlockPoS(const std::vector<Transaction>& txs, const std::string& validator);
};
