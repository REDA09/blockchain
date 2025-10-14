#include "../include/PoS.h"
#include <vector>

void PoS::setStake(const std::string& node, double amount) {
    stakes[node] = amount;
}

std::string PoS::selectValidator() {
    std::vector<std::pair<std::string,double>> entries(stakes.begin(), stakes.end());
    double total = 0.0;
    for (auto &e: entries) total += e.second;
    if (entries.empty() || total <= 0.0) return "";
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<> dis(0.0, total);
    double r = dis(gen);
    double acc = 0.0;
    for (auto &e: entries) {
        acc += e.second;
        if (r <= acc) return e.first;
    }
    return entries.back().first;
}
