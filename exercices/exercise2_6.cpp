#include <iostream>

int main( int argc, char **argv )
{
    int i1 = 1;
    int i2 = 2;

    //The int is constant. This means that the value can not change but the place in memory where it is stored can.
    int const *p1 = &i1;

    std::cout << "p1 value: " << *p1 << std::endl; 

    //The memory where the data is stored is constant. That means that the value cannot "travel" through memory but the 
    //stored value can
    int *const p2 = &i1;

    //Everything is constant and nothing can change.
    int const * const p3 = &i1;

    p1 = &i2;    // OK
    // *p1 = 2;  // WRONG

    // p2 = &i2;  // WRONG
    *p2 = 2;      // OK

    // p3 = &i2;  // WRONG
    // *p3 = 2;   // WRONG

    // To have no warning at compilation for unused variables
    if( p3 == p2 ) { };

    return 0;
}