#include "../include/AC_Hash.h"
#include <iostream>

int main() {
    std::string s1 = "Hello World!";
    std::string s2 = "Hello world!";

    std::string h1 = ac_hash(s1, 30, 128);
    std::string h2 = ac_hash(s2, 30, 128);

    std::cout << "Hash 1: " << h1 << "\n";
    std::cout << "Hash 2: " << h2 << "\n";

    if (h1 != h2) std::cout << "Test OK: les hashes sont différents.\n";
    else std::cout << "Test FAIL: hashes identiques.\n";

    return 0;
}
