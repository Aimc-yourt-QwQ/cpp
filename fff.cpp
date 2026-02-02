#include <iostream>
class Hello {
    Hello() {
        std::cout << "Hello" << std::endl;
    }
};
int main() {
    Hello myobj;
    return 0;
}