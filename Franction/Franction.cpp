// Franction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Franction {


    int integer;        //целая часть
    int numerator;     //знаменатель
    int denominator;   //знаменатель


public :

    int get_integer()const 
    {

        return integer;

    }
    int get_numerator()const
    {

        return numerator;

    }
    int get_denominator()const
    {

        return denominator;

    }
    void set_integer(int integer) {

        this->integer = integer;
    }
    void set_numerator(int numerator) {

        this->numerator = numerator;
    }
    void set_denominator(int denominator) {

        if (denominator == 0)denominator = 1;
        this->denominator = denominator;

    }
};



int main()
{
    
}


