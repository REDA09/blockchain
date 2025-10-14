#pragma once
#include "Transaction.h"
#include <vector>
#include <string>

std::string sha256_str(const std::string& input);
std::string merkleRoot(const std::vector<Transaction>& txs);
