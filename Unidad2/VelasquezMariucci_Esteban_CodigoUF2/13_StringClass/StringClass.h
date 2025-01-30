//
// Created by esvel on 27/10/2024.
//

#ifndef STRINGCLASS_H
#define STRINGCLASS_H

/**
 * @class StringClass
 * @brief A basic class to hold strings.
 *
 * This class manages the memory of string usage.
 */
class StringClass
{
private:
    char* string;

    /**
     * @brief Copies one string to another location.
     *
     * This function copies each character from the original string to the new location
     * until it hits the null character.
     *
     * @param location Where to copy the string to.
     * @param origin The string we want to copy.
     */
    void copy(char* location, const char* origin)
    {
        int i = 0;

        while (origin[i] != '\0')
        {
            location[i] = origin[i];
            i++;
        }

        location[i] = '\0';
    }

    /**
     * @brief Finds the length of a string.
     *
     * This function counts each character in the string until it gets null.
     *
     * @param str The string whose length we're using.
     * @return Length of the string.
     */
    int length(const char* str)
    {
        int len = 0;
        while (str[len] != '\0') // Count until the end of the string
        {
            len++;
        }
        return len; // Return how long the string is
    }

public:
    /**
     * @brief Sets up the string and saves a copy of it.
     *
     * This constructor takes a  string, figures out its length,
     * and makes a new copy.
     *
     * @param cStr  string to copy.
     */
    StringClass(const char* cStr)
    {
        const int len = length(cStr);
        string = new char[len + 1];

        copy(string, cStr);
    }

    ~StringClass()
    {
        delete[] string; // Free up memory used by the string
    }
};


#endif //STRINGCLASS_H
