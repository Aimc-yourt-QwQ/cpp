#include <iostream>
#include <iomanip>

int main() {
    
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (j <= i) {
                std::cout << j << "×" << i << "=" 
                         << std::setw(2) << i * j << "  ";
            } else {
                std::cout << "          ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}
