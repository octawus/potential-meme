#include <iostream>
#include <stdexcept>

class MyCustomException : public std::exception {
    public:
const char * what () {
        return "Custom C++ Exception";
    }
};

class Foo {
public:
    Foo( void )
    { throw MyCustomException(); }

    void do_something ( void ){
        std::cout << "Something done" << std::endl;
    }
};

int main( int argc, char **argv )
{   
    try
    {
        Foo *foo = new Foo;
        foo->do_something();
    }
    catch(MyCustomException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}