#include "../include/Block.h"
#include "../include/MerkleTree.h"
#include "../include/AC_Hash.h"
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

Block::Block(int idx, const std::vector<Transaction>& txs, const std::string& prev,
             HashMode mode, uint32_t rule, size_t steps) {
    index = idx;
    transactions = txs;
    prevHash = prev;
    timestamp = nowIso();
    merkleRoot = ::merkleRoot(transactions);
    nonce = 0;
    hashMode = mode;
    acRule = rule;
    acSteps = steps;
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::ostringstream ss;
    ss<<index<<timestamp<<prevHash<<merkleRoot<<nonce;
    std::string data = ss.str();
    if (hashMode == HashMode::SHA256) {
        return sha256_str(data);
    } else {
        return ac_hash(data, acRule, acSteps);
    }
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    while (true) {
        hash = calculateHash();
        if (hash.substr(0, difficulty) == target) break;
        ++nonce;
    }
}
