//
// Created by esvel on 27/10/2024.
//

#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <string>

class File
{
private:
    FILE* file;
    std::string fileName;

public:
    /**
     * @brief Constructor with file location.
     *
     * Opens the file at the specified location.
     *
     * @param location Path to the file to open.
     */
    File(std::string location)
    {
        file = fopen(location.c_str(), "w");
        if (file == nullptr)
        {
            std::cout << "File not found." << std::endl;
        }
        else
        {
            std::cout << "File found." << std::endl;

            fileName = location;
        }
    }

    /**
     * @brief Default constructor.
     *
     * Initializes file to nullptr and nombreArchivo to an empty string.
     */
    File() : file(nullptr), fileName("")
    {
    }

    /**
     * @brief Destructor to close the file.
     *
     * Closes the file if it is open.
     */
    ~File()
    {
        if (file != nullptr)
        {
            fclose(file);
            std::cout << "File: " << fileName << " closed." << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const File& file)
    {
        os << file.getName() << std::endl;

        return os;
    }

    //getters
    std::string getName() const
    {
        return this->fileName;
    }
};

#endif //FILES_H
