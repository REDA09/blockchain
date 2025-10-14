#include "../include/Blockchain.h"

Blockchain::Blockchain(int diff): difficulty(diff) {
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() {
    std::vector<Transaction> t;
    t.push_back(Transaction{"0","genesis","network",0.0});
    return Block(0,t,"0");
}

void Blockchain::addBlock(const std::vector<Transaction>& txs) {
    int idx = chain.size();
    Block newBlock(idx, txs, chain.back().hash);
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

void Blockchain::addBlockPoS(const std::vector<Transaction>& txs, const std::string& validator) {
    int idx = chain.size();
    Block newBlock(idx, txs, chain.back().hash);
    newBlock.hash = newBlock.calculateHash();
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    for (size_t i=1;i<chain.size();++i) {
        const Block& current = chain[i];
        const Block& previous = chain[i-1];
        if (current.hash != current.calculateHash()) return false;
        if (current.prevHash != previous.hash) return false;
    }
    return true;
}
