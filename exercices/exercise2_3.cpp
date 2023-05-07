#include <iostream>

void swap_references(int & a, int & b){
    int c = a;
    a = b;
    b = c;
}

void swap_pointers(int *p1, int *p2)
{
    int p3 = *p1;
    *p1 = *p2;
    *p2 = p3;
}

void swap_reference_pointers(int * & p1, int * &p2)
{
    int * p3 = p1;
    p1 = p2;
    p2 = p3;
}

int main()
{   
    int x = 1;
    int y = 2;
    int * ptrx = &x;
    int * ptry = &y;

    std::cout << "x: " << x << ": " << y << std::endl;
    swap_references(x, y);
    std::cout << "x after swapping: " << x << " y after swapping: " << y << std::endl;

    std::cout << "x: " << *ptrx << " y: " << *ptry << std::endl;
    swap_pointers(ptrx, ptry);
    std::cout << "x after swapping: " << *ptrx << " y after swapping: " << *ptry << std::endl;

    std::cout << "x: " << *ptrx << " y: " << *ptry << std::endl;
    swap_reference_pointers(ptrx, ptry);
    std::cout << "x after swapping: " << *ptrx << " y after swapping: " << *ptry << std::endl;

    return 0;
}