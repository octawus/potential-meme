#include <iostream>

class Foo
{
    public: int value;
    public: Foo(int value=0) : value(value) { };
};

int main (int argc, char **argv){
    int i;
    Foo foo1;
    Foo foo2(200);

    std::cout << "Foo1: " << foo1.value << std::endl;
    std::cout << "Foo2: " << foo2.value << std::endl;

    std::cout << "Please enter an integer number: ";
    std::cin >> i;
    std::cout << "The value you entered is " << i << std::endl;
    return 0;
}