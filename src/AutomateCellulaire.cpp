#include "../include/AutomateCellulaire.h"
#include <sstream>

// constructeur
AutomateCellulaire::AutomateCellulaire(uint32_t r) : rule(r) {}

// init_state() : copie l'état initial
void AutomateCellulaire::init_state(const std::vector<uint8_t>& init) {
    state = init;
}

// evolve() : applique la règle pour évoluer d'un pas
void AutomateCellulaire::evolve() {
    std::vector<uint8_t> next(state.size(), 0);

    for (size_t i = 0; i < state.size(); ++i) {
        // voisins gauche, centre, droite (bord = 0)
        uint8_t left  = (i == 0) ? 0 : state[i-1];
        uint8_t center = state[i];
        uint8_t right = (i == state.size()-1) ? 0 : state[i+1];

        // forme le motif binaire sur 3 bits
        uint8_t pattern = (left << 2) | (center << 1) | right;

        // applique la règle : bit pattern dans rule
        next[i] = (rule >> pattern) & 1;
    }

    state.swap(next);
}

// to_string() : convertit l'état en chaîne binaire pour affichage
std::string AutomateCellulaire::to_string() const {
    std::ostringstream ss;
    for (auto b : state) ss << (int)b;
    return ss.str();
}
