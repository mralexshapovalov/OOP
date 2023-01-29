// Franction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//В классе Fraction реализовать :
//1. Конструкторы и вывод на экран;
//5;		//double a = 5;
//1 / 2;
//2(3 / 4);
//
//2. Написать методы :
//Fraction & to_proper();	//целую часть интегрирует в числитель
//Fraction& to_improper();//выделяет целую часть из числителя
//3. Перегрузить арифметические операторы : +, -, *, / ;
//4. Перегрузить операторы++ / --;
//5. Перегрузить составные присваивания : +=, -=, *=, /=;
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
//7. Перегрузить оператор ввода с клавиатуры;


class Fraction {


    int integer;        //целая часть
    int numerator;      //Числитель
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

    Fraction(int integer) 
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 0;

        cout << integer << endl;

    }

    Fraction(int integer,int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        this->denominator = denominator;

        cout << integer << numerator<< denominator << endl;

    }
    Fraction(int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        this->denominator = denominator;

        cout << numerator << denominator << endl;

    }
    ~Fraction()
    {
        cout << integer<< numerator << denominator << endl;
    }

    Fraction& to_proper() 
    {



    }
    Fraction& to_improper()
    {



    }


};

Fraction operator+(const Fraction& left, const Fraction& right)
{

    Fraction res;


    return res;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{

    Fraction res;


    return res;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{

    Fraction res;


    return res;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{

    Fraction res;


    return res;
}




int main()
{
    Fraction A = 5;
    Fraction B(2, 3);
    Fraction C(1,2, 3);
 
}


