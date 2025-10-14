#pragma once
#include <string>
#include <sstream>

struct Transaction {
    std::string id;
    std::string sender;
    std::string receiver;
    double amount;
    std::string toString() const {
        std::ostringstream ss;
        ss<<id<<'|'<<sender<<'|'<<receiver<<'|'<<amount;
        return ss.str();
    }
};
