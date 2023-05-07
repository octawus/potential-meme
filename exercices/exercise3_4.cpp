#include <iostream>
#include <cmath>

class Point
{
private:
    //Private constructor to be called only from inside specific constructors
    Point( const float x, const float y ) : _x(x), _y(y)  { };
    float _x;
    float _y;
    
public:
    Point( void ) : _x(0.0), _y(0.0) {};

    static Point cartesian(const float x, const float y) {
        return Point(x, y);
    }

    static Point polar(const float r, const float theta) {
        return Point(theta * std::cos(r), theta * std::sin(r));
    }    

    friend std::istream & operator >> (std::istream & input, Point & that)
    { return input >> that._x >> that._y; }

    friend std::ostream & operator << (std::ostream & output, Point & that)
    { return output << "(" << that._x << ", " << that._y << ")"; }

    void printer (){
        std::cout << "X: " << _x << "Y:" << _y << "\n" << std::endl;
    }
};

int main ( int argc, char **argv )
{
    Point p;
    std::cout << "Enter a new point x y: ";
    std::cin >> p;
    std::cout << "p  = " << p << std::endl;
    
    return 0;
}