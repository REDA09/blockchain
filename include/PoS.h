#pragma once
#include <string>
#include <map>
#include <random>

class PoS {
public:
    std::map<std::string, double> stakes;
    PoS() = default;
    void setStake(const std::string& node, double amount);
    std::string selectValidator();
};
