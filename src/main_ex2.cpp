#include "../include/Blockchain.h"
#include <iostream>
#include <chrono>

int main() {
    Blockchain chain(4);
    std::vector<Transaction> txs = {
        {"1","Alice","Bob",10},
        {"2","Bob","Charlie",5}
    };
    auto start = std::chrono::high_resolution_clock::now();
    chain.addBlock(txs);
    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout<<"Block mined with PoW in "<<ms<<" ms\n";
    std::cout<<"Blockchain valid: "<<(chain.isChainValid() ? "yes":"no")<<"\n";
    return 0;
}
