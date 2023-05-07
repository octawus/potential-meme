#include <iostream>

int main()
{
    // Declare a pointer to a character
    char *a = new char('A');
    (void)a;

    // Declare a constant pointer to a character
    char * const b = new char('B');
    (void)b;

    // Declare a pointer to a constant char
    const char *c = "C";
    (void)c;

    // Declare a constant pointer to a constant char
    char const * const d = "D";
    (void)d;

    // Declare a reference to a char
    char &ref_e = *a;
    (void)ref_e;

    // Declare a reference to a constan char
    const char &ref_f = *c;  
    (void)ref_f;

    return 0;
}