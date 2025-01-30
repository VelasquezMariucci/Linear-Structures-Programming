#include <cstdlib>
#include <new>
#include <iostream>
#include <string>
#include <stdexcept>

/**
 * @class MemorySpace
 * @brief Class to manage memory with alignment.
 *
 * @tparam T template object.
 */
template <typename T>
class MemorySpace
{
private:
    T* pMemory; // Pointer to the memory we got
    size_t numBlocks; // How many blocks we got
    size_t alignment; // How we want to align them

public:
    /**
     * @brief Constructor for MemorySpace.
     *
     * The function checks if the alignment or number of blocks is zero. If so, throws a bad_alloc exception. It then
     * allocates memory with the specified alignment using _aligned_malloc. If memory allocation fails, throws a
     * bad_alloc exception.
     *
     * @param numBlocks How many blocks to make.
     * @param alignment How we want to align them.
     * @exception std::bad_alloc
     */
    MemorySpace(size_t numBlocks, size_t alignment)
        : numBlocks(numBlocks), alignment(alignment), pMemory(nullptr) // Start with nothing
    {
        // Check if blocks or alignment is zero
        if (alignment == 0 || numBlocks == 0)
        {
            throw std::bad_alloc();
        }

        // Get memory with alignment
        pMemory = static_cast<T*>(_aligned_malloc(sizeof(T) * numBlocks, alignment));
        if (pMemory == nullptr)
        {
            throw std::bad_alloc();
        }
    }

    ~MemorySpace()
    {
        _aligned_free(pMemory);
    }

    /**
     * @brief Get element at a specific index.
     *
     * Checks if the index is within bounds (0 to numBlocks-1). If the index is out of range, throws an out_of_range
     * exception. Returns the element at the specified index.
     *
     * @param index Where to look.
     * @return The element at that index.
     */
    T& getElement(size_t index)
    {
        if (index >= numBlocks)
        {
            throw std::out_of_range("Index out of range.");
        }

        return pMemory[index]; // Return the element
    }
};
