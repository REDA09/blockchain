#include "../include/Blockchain.h"
#include "../include/PoS.h"
#include <iostream>
#include <chrono>
#include <vector>

int main() {
    const int num_blocks = 10;
    const int difficulty = 0;

    std::vector<Transaction> txs = {
        {"1","Alice","Bob",10},
        {"2","Bob","Charlie",5}
    };

    // --- Test SHA256 ---
    Blockchain chainSHA(difficulty, HashMode::SHA256);
    long long totalTimeSHA = 0;
    long long totalIterSHA = 0;

    for (int i=0;i<num_blocks;++i){
        auto start = std::chrono::high_resolution_clock::now();
        chainSHA.addBlock(txs);
        auto end = std::chrono::high_resolution_clock::now();
        totalTimeSHA += std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        totalIterSHA += chainSHA.chain.back().nonce;
    }

    // --- Test AC_HASH ---
    Blockchain chainAC(difficulty, HashMode::AC_HASH, 30, 64); // Rule 30, 64 steps
    long long totalTimeAC = 0;
    long long totalIterAC = 0;

    for (int i=0;i<num_blocks;++i){
        auto start = std::chrono::high_resolution_clock::now();
        chainAC.addBlock(txs);
        auto end = std::chrono::high_resolution_clock::now();
        totalTimeAC += std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        totalIterAC += chainAC.chain.back().nonce;
    }

    // --- Résultats ---
    std::cout << "=== Comparaison SHA256 vs AC_HASH ===\n";
    std::cout << "Méthode\t\tTemps moyen (ms)\tItérations moyennes\n";
    std::cout << "SHA256\t\t" << totalTimeSHA/num_blocks 
              << "\t\t" << totalIterSHA/num_blocks << "\n";
    std::cout << "AC_HASH\t\t" << totalTimeAC/num_blocks 
              << "\t\t" << totalIterAC/num_blocks << "\n";

    return 0;
}
