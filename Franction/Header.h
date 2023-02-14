#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;

Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

bool operator==(Fraction left, Fraction right);
bool operator !=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator <=(Fraction left, Fraction right);
bool operator >=(Fraction left, Fraction right);

std::ostream& operator << (std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);


class Fraction
{
    int integer;        //целая часть
    int numerator;      //Числитель
    int denominator;   //знаменатель

public:

    int get_integer()const;
    int get_numerator()const;
    int get_denominator()const;
    void set_integer(int integer);
    void set_numerator(int numerator);
    void set_denominator(int denominator);

    Fraction();
    Fraction(double decimal);
    explicit Fraction(int integer);
    Fraction(int numerator, int denominator);
    Fraction(int integer, int numerator, int denominator);
    Fraction(const Fraction& other);
    ~Fraction();

    Fraction& operator()(int integer, int numerator, int denominator);
    Fraction& operator=(const Fraction& other);
    Fraction& to_proper();
    Fraction& to_improper();                //Fraction& to_improper();//целую часть интегрирует в числитель 
    Fraction& reduce();                 //Fraction& to_improper();//целую часть интегрирует в числитель 
    Fraction inverted()const;


    Fraction operator++(int); //Посфиксный
    Fraction operator--(int); //Посфиксный
    Fraction& operator--();//Префексный 
    Fraction& operator++(); //Префексный 

    Fraction& operator *=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);


    explicit operator int()const;
    explicit operator double()const;


    std::ostream& print(std::ostream& os)const;
};

