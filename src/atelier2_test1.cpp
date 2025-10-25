#include "../include/AutomateCellulaire.h"
#include <iostream>
#include <vector>

int main() {
    AutomateCellulaire ac(30); // Rule 30
    std::vector<uint8_t> init = {0,0,0,1,0,0,0}; // état initial
    ac.init_state(init);

    std::cout << "État initial : " << ac.to_string() << "\n";

    for (int i = 0; i < 5; ++i) {
        ac.evolve();
        std::cout << "Pas " << i+1 << " : " << ac.to_string() << "\n";
    }

    return 0;
}
