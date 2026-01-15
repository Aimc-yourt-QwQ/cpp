#include <iostream>
#include <string>

class MyClass {  // 使用合法的类名
public:
    // 构造函数（与类名相同）
    MyClass() {
        for (int i = 0; i <= 10; i++) {
            std::cout << i << std::endl;
        }
    }
    
    void display() {
        // 如果你想要显示某个成员变量，需要先定义它
        // 例如：
        // std::cout << someMemberVariable << std::endl;
        
        // 或者重新循环：
        for (int i = 0; i <= 10; i++) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyClass myObj;  // 创建对象时会自动调用构造函数
    myObj.display();  // 调用成员函数
    return 0;
}
