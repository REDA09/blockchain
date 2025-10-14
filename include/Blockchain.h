#pragma once
#include "Block.h"
#include "Transaction.h"
#include <vector>
#include <string>

class Blockchain {
public:
    std::vector<Block> chain;
    int difficulty;
    Blockchain(int diff=2);
    Block createGenesisBlock();
    void addBlock(const std::vector<Transaction>& txs);
    bool isChainValid() const;
    void addBlockPoS(const std::vector<Transaction>& txs, const std::string& validator);
};
