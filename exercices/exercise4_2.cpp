#include <iostream>

void foo ( void )
{std::cout << "Standalone foo function called" << std::endl;}

class  Foo {

    public:
        void foo ( void )
        {
            std::cout << "Internal foo function called called" << std::endl;
        };

        Foo ( void ){
            ::foo();
            foo();
        }
};


int main() {
    Foo foo;

    return 0;
}