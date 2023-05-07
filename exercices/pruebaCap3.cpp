#include <iostream>

class Foo
{
    private: 
        int cost;
        const char *color;
        float capacity;

    public: 
        //Foo ( void )
        //{ std::cout << "Constructing Foo without parameters" << std::endl; }

        Foo(int cost=0, const char *color="none", float capacity=0.0) : cost(cost), color(color), capacity(capacity) { };

        void printer( void ) {
            std::cout << "Cost: " << cost << "\nColor: " << *color << "\nCapacity: " << capacity << std::endl;
        };
};

int main (int argc, char **argv){
    Foo foo;
    Foo foo2(20);

    foo.printer();
    foo2.printer();

    return 0;
}