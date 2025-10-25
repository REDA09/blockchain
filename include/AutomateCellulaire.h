#pragma once
#include <vector>
#include <cstdint>
#include <string>

class AutomateCellulaire {
public:
    std::vector<uint8_t> state;  // état binaire de l'automate (0 ou 1)
    uint32_t rule;                // numéro de règle (30, 90, 110)

    AutomateCellulaire(uint32_t r = 30);  // constructeur, règle par défaut Rule 30

    // 1.1 Initialiser l'état à partir d'un vecteur de bits
    void init_state(const std::vector<uint8_t>& init);

    // 1.2 Évolution d'un pas selon la règle
    void evolve();

    // 1.3 Afficher l'état (utile pour vérifier la règle)
    std::string to_string() const;
};
