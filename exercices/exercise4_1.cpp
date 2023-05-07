#include <iostream>

class Foo {

public:
    Foo ( void ) {
        std::cout << "Default foo constructor being invoked" << std::endl;
    }

    ~Foo () {
        std::cout << "Foo destroyed" << std::endl;
    }
};


class Bar : public Foo  {

public:
    Bar ( void ) {
        std::cout << "Default bar constructor being invoked" << std::endl;
    }

    ~Bar () {
        std::cout << "Bar destroyed" << std::endl;
    }
};


int main() {

    Bar bar;

    return 0;
}