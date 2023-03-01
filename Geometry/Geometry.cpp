// Geometry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <glut.h>
#include <Windows.h>


/*Реализовать иерархию геометрических фигур : квадрат, треугольник, прямоугольник, круг и т.д.
Для каждой фигуры необходимо вывести ее первичные свойства, такие как радиус, длина стороны, и т.д.
и вторичные свойства такие как площадь, периметр, так же каждую фигуру нужно нарисоват*/



enum Color
{

    ConsoleBlue = 0x99,
    ConsoleGreen = 0xAA,
    ConsoleRED=0xCC,
    ConsoleDefault=0x07

};

class Shape 
{

protected:

    Color color;

public:

    Shape(Color color) :color(color){};
    virtual ~Shape(){}

    virtual double get_area()const = 0;
    virtual double get_perimetr()const = 0;
    virtual void draw()const = 0;

    virtual void information()const
    {
        std::cout << "The area of the figure: " << get_area() << std::endl;
        std::cout << "The perimetr of the figure: " << get_perimetr() << std::endl;
    }
};

class Square :public Shape //Квадрат
{

private:

    double side;//Сторона


public:
    const double getSide() const
    {
        return side;
    }

    void setSide(double side)
    {
        this->side = side;
    }


    Square(double side, Color color):Shape(color)
    {

        setSide(side);
    }

    ~Square() 
    {

        /*std::cout << "SquareDestructor" << this << std::endl;*/

    }

    double get_area() const override
    {
        return side * side;// взоврщает плошадь квадрата S=a*b
    }

    double get_perimetr() const override
    {

        return (side + side) * 2;//Возвращает периметр квдадрата P=2(a+b)

    }

    void draw() const override
    {
        std::cout << "Square" << std::endl;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, ConsoleRED);

        for (int i = 0; i < side; i++) 
        {
            for (int j = 0; j < side; j++) 
            {
                std::cout  << "* ";
            }

            std::cout << std::endl;
        }

        SetConsoleTextAttribute(hConsole, ConsoleDefault);
    }

    void information()const
    {
  
        std::cout << "The length of the side of the square: " << side << std::endl; //Длина стороны квадрата
        Shape::information();

    }

};

class Rect :public Shape //Прямоугольник
{
private:

    double length;//Длина
    double width; //Ширина


public:

    const double getLength() const
    {
        return length;
    }
    const double getWidth() const
    {
        return width;
    }

    void setLength(double length)
    {
        this->length = length;
    }

    void setWidth(double width)
    {
        this->width = width;
    }


    Rect(double length, double width, Color color) :Shape( color)
    {

        setLength(length);
        setWidth(width);
    }

    ~Rect()
    {

        /*std::cout << "SquareDestructor" << this << std::endl;*/

    }

    double get_area() const override
    {
        return length * width;// взоврщает плошадь квадрата S=a*b
    }

    double get_perimetr() const override
    {

        return (length + width)*2;//Возвращает периметр квдадрата P=2(a+b)

    }

    void draw() const override
    {
        std::cout << "\nRectangle" << std::endl;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, ConsoleGreen);
    
        for (int i = 0; i < length; i++)
        { 
            for (int j = 0; j < width; j++)
            {
                std::cout << "* "; 
                
            }
            
            std::cout << std::endl;
        }
       
        SetConsoleTextAttribute(hConsole, ConsoleDefault);
    }

    void information()const
    {

        std::cout << "The length of the side of the rectangle: " << length << std::endl; //Длина пямоугольника
        std::cout << "The Width of the side of the rectangle: " << width << std::endl; //Ширина прямоуголника
        Shape::information();

    }

};

//class Circle :public Shape //Круг
//{
//public:
//
//
//};
//
//class Rhomb :public Shape //Круг
//{
//public:
//
//
//};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Square square(5, Color::ConsoleRED);
    square.draw();
    square.information();

    Rect rect(5, 10, Color::ConsoleGreen);
    rect.draw();
    rect.information();


   /* rectangle.draw();
    rectangle.information();*/
}

