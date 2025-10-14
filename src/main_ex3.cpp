#include "../include/Blockchain.h"
#include "../include/PoS.h"
#include <iostream>
#include <chrono>

int main() {
    PoS pos;
    pos.setStake("Alice", 50.0);
    pos.setStake("Bob", 30.0);
    pos.setStake("Charlie", 20.0);
    std::string validator = pos.selectValidator();
    std::cout<<"Validator selected: "<<validator<<"\n";
    Blockchain chain(0);
    std::vector<Transaction> txs = {
        {"1","Alice","Bob",10},
        {"2","Bob","Charlie",5}
    };
    auto start = std::chrono::high_resolution_clock::now();
    chain.addBlockPoS(txs, validator);
    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout<<"Block validated by PoS in "<<ms<<" ms\n";
    std::cout<<"Blockchain valid: "<<(chain.isChainValid() ? "yes":"no")<<"\n";
    return 0;
}
