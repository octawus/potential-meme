#include <iostream>
#include <string>
#include <cmath>

class Foo
{
private:
    int id;
    int cost;
    std::string color;
    float capacity;

public:
    //Foo(int id = 0, int cost = 0, std::string color = "none", float capacity = 0.0): id(id), cost(cost), color(color), capacity(capacity)
    //{
    //    std::cout << "Using default defined constructor" << std::endl;
    //}

    Foo(int id = 0, int cost = 0, std::string color = "none", float capacity = 0) : cost(cost), color(color), capacity(capacity)
    {
        std::cout << "Using manually defined constructor" << std::endl;
    }

    Foo(const Foo &oldFoo) : id(oldFoo.id), cost(oldFoo.cost), color(oldFoo.color), capacity(oldFoo.capacity)
    {
        std::cout << "Using copy constructor" << std::endl;
    }

    Foo &operator=(Foo &otherFoo)
    {
        // Gracefully handle self assignment
        if (this == &otherFoo)
            return *this;

        id = otherFoo.id;
        cost = otherFoo.cost;
        color = otherFoo.color;
        capacity = otherFoo.capacity;

        return *this;
    }

    bool operator==(Foo &otherFoo)
    {
        if (cost == otherFoo.cost && color == otherFoo.color && capacity == otherFoo.capacity)
        {
            return true;
        }
        return false;
    }

    bool operator!=(Foo &otherFoo)
    {
        if (cost != otherFoo.cost || color != otherFoo.color || capacity != otherFoo.capacity)
        {
            return true;
        }
        return false;
    }

    void printer(void)
    {
        std::cout << "Id: " << id << "\nCost: " << cost << "\nColor: " << color << "\nCapacity: " << capacity << std::endl;
    }

    ~Foo(void)
    {
        std::cout << "Foo destructor called" << std::endl;
    }
};

int main(int argc, char **argv)
{
    Foo foo;
    Foo foo2(1, 20, "red", 54.3);
    Foo foo3(foo2);

    std::cout << "Printing foo" << std::endl;
    foo.printer();
    std::cout << "Printing foo2" << std::endl;
    foo2.printer();
    std::cout << "Printing fo3" << std::endl;
    foo3.printer();

    if (foo2 == foo3)
    {
        std::cout << "Foos are equal" << std::endl;
    }

    if (foo != foo3)
    {
        std::cout << "Foos are NOT equal" << std::endl;
    }

    std::cout << "Equaling foos" << std::endl;
    foo = foo3;

    if (foo == foo3)
    {
        std::cout << "Foos are equal" << std::endl;
    }

    return 0;
}