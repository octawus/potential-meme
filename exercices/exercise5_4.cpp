#include <iostream>
#include <stdexcept>
#include <cmath>

struct DivideByZero : public std::runtime_error
{ DivideByZero( void ) : std::runtime_error("DivideByZero") { } };

struct OverflowError : public std::runtime_error
{ OverflowError( void ) : std::runtime_error("OverflowError") { } };

struct UnderflowError : public std::runtime_error
{ UnderflowError( void ) : std::runtime_error("UnderflowError") { } };


class Integer {
public:
    Integer( int value = 0 ) : _value(value) { };

    Integer operator+(Integer &other)
    {
        unsigned char result = _value+other._value;
        if( result < _value )
        { throw new OverflowError; }
        return Integer(result);
    }

    Integer operator-(Integer &other)
    {
        unsigned char result = _value-other._value;
        if( result > _value )
        { throw new UnderflowError; }
        return Integer(result);
    }

    Integer operator*(Integer &other)
    {
        unsigned char result = _value * other._value;
        if((_value > 1) and (other._value >1 ) and ( result < _value ))
        { throw new OverflowError; }
        return Integer(result);
    }

    Integer operator/(Integer &other)
    {
        if( other._value == 0 )
        { throw new DivideByZero; }

        return Integer(_value / other._value);
    }

    friend std::ostream& operator<< ( std::ostream& output, Integer const & that )
    { return output << that._value; }
protected:
    unsigned char _value;
};

int main( int argc, char **argv )
{
    Integer a(129), b(128), zero(0);

    try 
    {
        Integer c(a+b); // overflow
    } catch (OverflowError& e) {
        std::cerr << "Overflow error occurred: " << e.what() << std::endl;
    }

    try
    {
        Integer d(b-a); // underflow
    } catch (UnderflowError& e) {
        std::cerr << "Underflow error occurred: " << e.what() << std::endl;
    }
    
    try
    {
        Integer e(a/zero); // divide by zero
    }
    catch(DivideByZero& e)
    {
        std::cerr << "Divide by zero error occurred: " << e.what() << std::endl;
    }
    
   
    return 0;
}