#include <iostream>

#include "Dinarrays.h"

int main()
{
    try
    {
        // Test 1: Default constructor
        std::cout << "Test 1: Default constructor\n";
        Dynarray<int> emptyArray;
        std::cout << "Default Dynarray created successfully.\n\n";

        // Test 2: Constructor with size only
        std::cout << "Test 2: Constructor with size only\n";
        Dynarray<int> intArray(5); // Creates an array of 5 integers
        std::cout << "Dynarray with 5 default-initialized elements created successfully.\n\n";

        // Test 3: Constructor with size and default value
        std::cout << "Test 3: Constructor with size and default value\n";
        Dynarray<int> intArrayWithValue(5, 42); // Creates an array of 5 integers initialized to 42
        std::cout << "Dynarray with 5 elements set to 42 created successfully.\n\n";

        // Test 4: Initializer list constructor
        std::cout << "Test 4: Initializer list constructor\n";
        Dynarray<int> intArrayFromList = {1, 2, 3, 4, 5};
        // Creates an array with 5 elements initialized to {1, 2, 3, 4, 5}
        std::cout << "Dynarray initialized with {1, 2, 3, 4, 5} created successfully.\n\n";

        // Test 5: Constructor with non-default constructible type
        std::cout << "Test 5: Constructor with non-default constructible type\n";
        Dynarray<std::string> stringArray(3, "Hello"); // Creates an array of 3 strings initialized to "Hello"
        std::cout << "Dynarray with 3 elements set to \"Hello\" created successfully.\n\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
    }

    return 0;
}
