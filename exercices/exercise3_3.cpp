#include <cmath>
#include <iostream>

class Point
{
private:
    //Private constructor to be called only from 
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

    void printer (){
        std::cout << "X: " << _x << "Y:" << _y << "\n" << std::endl;
    }
};

int main(int argc, char **argv)
{
    Point p1 = Point::cartesian(5.7, 1.2);
    Point p2 = Point::polar(5.7, 1.2);
    p1.printer();
    p2.printer();   
    return 0;
}