#include <iostream>
#include <cmath>

//@Brief Abstract parent class that contains Area and Perimeter Functions
class FiguraGeometrica
{
public:
    FiguraGeometrica() = default;
    virtual ~FiguraGeometrica() = default;

private:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};


//Class that inherits functions from FiguraGeometrica Class to calculate Area and Perimeter
//of a Rectangle.
class Rectangle : public FiguraGeometrica
{
public:
    /*
     *@Brief contructor of a Rectangle Object.
     *
     *@param base Base of the rectangle.
     *@param height height of the rectangle.
     */
    Rectangle(float base, float height)
    {
        this->base = base;
        this->height = height;
    };
    ~Rectangle() override = default;

    //return the area of the rectangle multiplying base times height.
    float area() override
    {
        const float area = (this->base * this->height);
        return area;
    }

    //return the perimeter by multiplying the base twice and the height twice, then adding
    //those values.
    float perimeter() override
    {
        const float perimeter = ((this->base * 2) + (this->height * 2));
        return perimeter;
    };

private:
    float base;
    float height;
};

//Class that inherits functions from FiguraGeometrica Class to calculate Area and Perimeter
//of a right triangle.
class RightTriangle : public FiguraGeometrica
{
public:
    /*
     *@Brief contructor of a Right Triangle Object.
     *
     *@param base Base of the right triangle.
     *@param height height of the right triangle.
     */
    RightTriangle(float base, float height)
    {
        this->base = base;
        this->height = height;
    };
    ~RightTriangle() override = default;

    //Return the area of the right triangle by multiplying the base times the height and
    //dividing it by 2.
    float area() override
    {
        const float area = (this->base * this->height) / 2;
        return area;
    }

    //Return the perimeter of the right triangle by adding the base, the height and
    //hypotenuse it by 2.
    float perimeter() override
    {
        const float side1 = base;
        const float side2 = height;
        const float side3 = sqrt(pow(base, 2) + pow(height, 2));

        const float perimeter = side1 + side2 + side3;

        return perimeter;
    };

private:
    float base;
    float height;
};

//Class that inherits functions from FiguraGeometrica Class to calculate Area and Perimeter
//of a circle.
class Circle : FiguraGeometrica
{
public:
    /*
     *@Brief contructor of a Circle Object.
     *
     *@param radius Radius of the right triangle.
     */
    Circle(float radius)
    {
        this->radius = radius;
    };

    //Return the area of the circle by multiplying the pi with the radius to the power of 2.
    float area() override
    {
        const float area = M_PI * pow(radius, 2);
        return area;
    };

    //Return the perimeter of the circle by multiplying the radius by 2 and pi.
    float perimeter() override
    {
        const float perimeter = 2 * M_PI * radius;
        return perimeter;
    };

private:
    float radius;
};

int main()
{
    //creation of object instances
    Circle* circle = new Circle(10);
    Rectangle* rectangle = new Rectangle(10, 10);
    RightTriangle* triangle = new RightTriangle(10, 10);

    //printing the areas and perimeters of each object
    std::cout << "Circle perimeter: " << circle->perimeter() << std::endl;
    std::cout << "Circle area: " << circle->area() << std::endl;

    std::cout << "Rectangle perimeter: " << rectangle->perimeter() << std::endl;
    std::cout << "Rectangle area: " << rectangle->area() << std::endl;

    std::cout << "RightTriangle perimeter: " << triangle->perimeter() << std::endl;
    std::cout << "RightTriangle area: " << triangle->area() << std::endl;

    return 0;
}
