#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

int main() {
    try {
        std::vector<int> myVector(5);
        int value = myVector.at(10);  // Accessing out-of-bounds position
        
        // This line will not be reached if the exception is thrown
        std::cout << "Value at position 10: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught std::out_of_range exception: " << e.what() << std::endl;
    }

    try {

        size_t largeSize = 1000000000000000000;  // Example: 1 exabyte
        int* largeArray = new int[largeSize];

         // This line will not be reached if the allocation fails
        std::cout << "Memory allocation successful!" << std::endl;
        
        // Clean up the allocated memory
        delete[] largeArray;

    } catch (const std::bad_alloc& e) {
        std::cerr << "Caught std::bad_alloc exception: " << e.what() << std::endl;
    }

    try {
        int maxValue = std::numeric_limits<int>::max();
        int value = maxValue;
        if (value + 1 > maxValue) {
            throw std::overflow_error("Overflow occurred");
        }
        
        std::cout << "Result: " << value << std::endl;
    } catch (const std::overflow_error& e) {
        std::cerr << "Overflow error occurred: " << e.what() << std::endl;
    }
    return 0;

}