#include "../include/MerkleTree.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <algorithm>

std::string sha256_str(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
    std::ostringstream ss;
    for (int i=0;i<SHA256_DIGEST_LENGTH;i++) ss<<std::hex<<std::setw(2)<<std::setfill('0')<<(int)hash[i];
    return ss.str();
}

std::string merkleRoot(const std::vector<Transaction>& txs) {
    if (txs.empty()) return sha256_str("");
    std::vector<std::string> layer;
    for (const auto& t: txs) layer.push_back(sha256_str(t.toString()));
    while (layer.size() > 1) {
        if (layer.size() % 2 != 0) layer.push_back(layer.back());
        std::vector<std::string> next;
        for (size_t i=0;i<layer.size(); i+=2)
            next.push_back(sha256_str(layer[i] + layer[i+1]));
        layer.swap(next);
    }
    return layer.front();
}
