#include <iostream>
#include <cassert>

double const_division(const double &, const double &);

int main(){

    double x = 17;
    double y = 2;

    double result = const_division(x, y);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

double const_division(const double & div1, const double & div2){
    assert(div2 != 0);
    return div1/div2;
}