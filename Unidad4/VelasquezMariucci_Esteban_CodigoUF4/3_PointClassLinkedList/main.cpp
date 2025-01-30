#include <iostream>

/*Declara una clase “punto” que represente un punto dentro de un plano
(coordenadas x e y), y genera una clase Nodo cuyo campo de valor sea “punto”.*/

/**
 * @brief Represents a point.
 */
class Point
{
public:
    float x;
    float y;

    /**
     * @brief Default constructor.
     */
    Point() : x(0), y(0)
    {
    }

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the point with specified x and y coordinates.
     *
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     */
    Point(float x, float y) : x(x), y(y)
    {
    };

    /**
     * @brief Retrieves the x-coordinate of the point.
     *
     * @return The x-coordinate as a float.
     */
    const float getX()
    {
        return x;
    }

    /**
     * @brief Retrieves the y-coordinate of the point.
     *
     * @return The y-coordinate as a float.
     */
    const float getY()
    {
        return y;
    }
};

/**
 * @brief struct to represent a node of a linked list.
 *
 * The node holds data and points to the next node making it easy to add new
 * items to the structure.
 *
 * @tparam T type of data to be stored.
 */
template <typename T>
class Node
{
public:
    T data;
    Node* next;

    /**
     * @brief Constructor with parameters for Node.
     *
     * @param data The data to store in the node.
     *  @param next Pointer to the next node.
     */
    Node(T& data, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

int main()
{
    // Create points
    Point p1(1, 2);
    Point p2(3, 4);

    // Create nodes
    Node<Point>* n1 = new Node<Point>(p1);
    Node<Point>* n2 = new Node<Point>(p2);

    // Connect nodes
    n1->next = n2;

    // Print
    Node<Point>* current = n1;
    while (current != nullptr)
    {
        std::cout << "Point: (" << current->data.getX() << ", " << current->data.getY() << ")" << std::endl;
        current = current->next;
    }

    return 0;
}
