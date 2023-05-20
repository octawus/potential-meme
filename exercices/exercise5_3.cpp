#include <iostream>
#include <stdexcept>

class DivisionError  : public std::runtime_error {
    public:
        DivisionError( void ) : std::runtime_error("DivideByZero"){  }
};

double divide (double a, double b)
{
    if ( b == 0)
    {
        throw DivisionError();
    }
    return a/b;
}

int main (int argc, char **argv )
{
    divide(10,5);
    divide(1,0);
    return 0;
}