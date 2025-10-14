#include "../include/Block.h"
#include "../include/MerkleTree.h"
#include <sstream>
#include <iomanip>
#include <chrono>

static inline std::string nowIso() {
    using namespace std::chrono;
    auto t = system_clock::now();
    std::time_t tt = system_clock::to_time_t(t);
    std::tm tm = *std::gmtime(&tt);
    std::ostringstream ss;
    ss<<std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
    return ss.str();
}

Block::Block(int idx, const std::vector<Transaction>& txs, const std::string& prev) {
    index = idx;
    transactions = txs;
    prevHash = prev;
    timestamp = nowIso();
    merkleRoot = ::merkleRoot(transactions);
    nonce = 0;
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::ostringstream ss;
    ss<<index<<timestamp<<prevHash<<merkleRoot<<nonce;
    return sha256_str(ss.str());
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    while (true) {
        hash = calculateHash();
        if (hash.substr(0, difficulty) == target) break;
        ++nonce;
    }
}
