// Geometry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <glut.h>

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
    Color color;


public:

    Shape(Color color) :color(color) 
    
    {

    
    };

    virtual ~Shape(){}

    virtual double ger_area()const = 0;
    virtual double get_perimetr()const = 0;
    virtual void draw()const = 0;



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


    Square() 
    {


    }

    ~Square() 
    {

        std::cout << "SquareDestructor" << this << std::endl;

    }

    double get_area() 
    {
        return side * side;// взоврщает плошадь квадрата S=a*b
    }

    double get_perimetr() 
    {

        return 2*(side + side);//Возвращает периметр квдадрата P=2(a+b)

    }

    void draw() 
    {

        for (int i = 0; i < side; i++) 
        {
            for (int j = 0; j < side; i++) 
            {

                std::cout << "* ";

            }
            std::cout << std::endl;

        }

    }


};

class Rectangle :public Shape //Прямоугольник
{
public:

};

class Circle :public Shape //Круг
{
public:


};

class Rhomb :public Shape //Круг
{
public:


};


int main()
{

}

