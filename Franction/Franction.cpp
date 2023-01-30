// Franction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
//4. Перегрузить операторы++ / --;                                   DONE
//5. Перегрузить составные присваивания : +=, -=, *=, /=;
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
//7. Перегрузить оператор ввода с клавиатуры;                        DONE


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
    Fraction()
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;

        cout << integer << endl;
    }

    Fraction(int integer) 
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;

        cout << integer << endl;

    }

    Fraction(int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        this->denominator = denominator;

        cout << numerator << denominator << endl;

    }

    Fraction(int integer,int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        this->denominator = denominator;

        cout << integer << numerator<< denominator << endl;

    }

  /*  ~Fraction()
    {
        cout << integer<< numerator << denominator << endl;
    }*/

    Fraction& to_proper() 
    {



    }
    Fraction& to_improper()
    {



    }
 //3. Перегрузить арифметические операторы : +, -, *, / ;
    
  
 //4. Перегрузить операторы++ / --;

    Fraction& operator++() 
    {
        integer++;
        numerator++;
        denominator++;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction old = *this;
        integer++;
        numerator++;
        denominator++;
        return old;
    }

    Fraction& operator--()
    {
        integer--;
        numerator--;
        denominator--;
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction old = *this;
        integer--;
        numerator--;
        denominator--;
        return old;
    }



 //5. Перегрузить составные присваивания : +=, -=, *=, /=;
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
//7. Перегрузить оператор ввода с клавиатуры;


    Fraction& operator ()(int integer, int numerator,int denominator)  /*E0980	вызов объекта типа класса без соответствующей функции operator() или функций преобразования указателя в функцию	Frantion*/
    {
        set_integer(integer);
        set_numerator(numerator);
        set_denominator(denominator);

        return *this;
    }



    void print()const
    {
        /*cout << "X = " << x << "\tY = " << y << endl;*/
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


//7. Перегрузить оператор ввода с клавиатуры;

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{

    return os << obj.get_integer() << ' ( ' << obj.get_numerator() << '/' << obj.get_denominator() << ' )' << endl;

}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
    int integer, numerator, denominator;
    is >> integer >> numerator >> denominator;
    obj(integer, numerator, denominator);
    return is;
}


int main()
{
    Fraction A = 5;
    Fraction B(2, 3);
    Fraction C(1,2, 3);
 
}


