// Geometry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
    Shape(Color color) :color(color) {};

    virtual ~Shape(){}

    virtual double ger_area()const = 0;
    virtual double get_perimetr()const = 0;
    virtual void draw()const = 0;



};



int main()
{

    std::cout << "Hello World!\n";


}

