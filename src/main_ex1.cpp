#include "../include/MerkleTree.h"
#include "../include/Transaction.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Transaction> txs = {
        {"1","Alice","Bob",10},
        {"2","Bob","Charlie",5},
        {"3","Charlie","David",8},
        {"4","David","Alice",2}
    };
    std::string root = merkleRoot(txs);
    std::cout<<"Merkle Root: "<<root<<"\n";
    return 0;
}
