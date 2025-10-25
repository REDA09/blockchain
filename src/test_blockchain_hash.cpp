#include "../include/Blockchain.h"
#include "../include/PoS.h"
#include <iostream>
#include <chrono>

int main() {
    std::vector<Transaction> txs1 = {
        {"1","Alice","Bob",10},
        {"2","Bob","Charlie",5}
    };

    std::vector<Transaction> txs2 = {
        {"3","Carol","Dave",15},
        {"4","Eve","Frank",7}
    };

    // --- Test PoW avec SHA256 ---
    std::cout << "--- Minage avec SHA256 ---\n";
    Blockchain chainSHA(0, HashMode::SHA256);  // difficulté = 2
    auto start1 = std::chrono::high_resolution_clock::now();
    chainSHA.addBlock(txs1);
    std::cout << "Premier bloc SHA256 ajouté.\n";
    chainSHA.addBlock(txs2);
    std::cout << "Deuxième bloc SHA256 ajouté.\n";
    auto end1 = std::chrono::high_resolution_clock::now();
    auto t_sha = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();

    std::cout << "Temps total SHA256: " << t_sha << " ms\n";
    std::cout << "Blockchain SHA256 valide: " 
              << (chainSHA.isChainValid() ? "oui" : "non") << "\n\n";

    // --- Test PoW avec AC_HASH ---
    std::cout << "--- Minage avec AC_HASH ---\n";
    Blockchain chainAC(0, HashMode::AC_HASH, 30, 16);
    auto start2 = std::chrono::high_resolution_clock::now();
    chainAC.addBlock(txs1);
    std::cout << "Premier bloc AC_HASH ajouté.\n";
    chainAC.addBlock(txs2);
    std::cout << "Deuxième bloc AC_HASH ajouté.\n";
    auto end2 = std::chrono::high_resolution_clock::now();
    auto t_ac = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

    std::cout << "Temps total AC_HASH: " << t_ac << " ms\n";
    std::cout << "Blockchain AC_HASH valide: " 
              << (chainAC.isChainValid() ? "oui" : "non") << "\n";

    return 0;
}
