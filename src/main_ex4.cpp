#include "../include/Blockchain.h"
#include "../include/PoS.h"
#include <iostream>
#include <chrono>

int main() {
    Blockchain powChain(4);
    Blockchain posChain(0);
    PoS pos;
    pos.setStake("Alice", 50);
    pos.setStake("Bob", 30);
    pos.setStake("Carol", 20);
    std::vector<Transaction> txs = {
        {"1","Alice","Bob",10},
        {"2","Bob","Charlie",5}
    };
    auto s1 = std::chrono::high_resolution_clock::now();
    powChain.addBlock(txs);
    auto e1 = std::chrono::high_resolution_clock::now();
    auto t_pow = std::chrono::duration_cast<std::chrono::milliseconds>(e1-s1).count();
    auto s2 = std::chrono::high_resolution_clock::now();
    std::string validator = pos.selectValidator();
    posChain.addBlockPoS(txs, validator);
    auto e2 = std::chrono::high_resolution_clock::now();
    auto t_pos = std::chrono::duration_cast<std::chrono::milliseconds>(e2-s2).count();
    std::cout<<"PoW time: "<<t_pow<<" ms\n";
    std::cout<<"PoS time: "<<t_pos<<" ms (validator: "<<validator<<")\n";
    std::cout<<"PoW valid: "<<(powChain.isChainValid()?"yes":"no")<<"\n";
    std::cout<<"PoS valid: "<<(posChain.isChainValid()?"yes":"no")<<"\n";
    return 0;
}
