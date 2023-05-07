#include <iostream>
#include <cmath>

class Real
{

protected:
    float _value;

public:
    virtual Real operator+(Real &other) { return Real(_value + other._value); }
    virtual Real operator-(Real &other) { return Real(_value - other._value); }
    virtual Real operator*(Real &other) { return Real(_value * other._value); }
    virtual Real operator/(Real &other) { return Real(_value / other._value); }
    friend std::ostream &operator<<(std::ostream &output, Real const &that)
    {
        return output << that._value;
    }
    Real(float value = 0) : _value(value)
    {
        std::cout << "Real constructor called" << std::endl;
    }

    ~Real(void)
    {
        std::cout << "Real destructor called" << std::endl;
    }
};

class Integer : public Real
{
protected:
    int _value;

public:
    Integer(int value = 0) : Real(int(round(value)))
    {
        std::cout << "Integer constructor called" << std::endl;
    }

    ~Integer(void)
    {
        std::cout << "Integer destructor called" << std::endl;
    }
};

int main(int argc, char **argv)
{
    Real r1(1.23), r2(4.56);
    Integer i1(1), i2(2);

    std::cout << i1 + i2 << " " << std::endl;
    std::cout << r1 + r2 << " " << std::endl;
    std::cout << r1 + i2 << " " << std::endl;
    std::cout << i1 + r2 << " " << std::endl;

    return 0;
}