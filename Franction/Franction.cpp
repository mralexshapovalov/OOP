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
    //Constructors
    Fraction()//По умолчанию 
    {
        this->integer = 0;
        this->numerator = 0;
        this->denominator= 1;

        cout << "DefaultConstuctor " << this << endl;
    }
    Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;

        cout << "1ArgConstuctor " << this << endl;
    }

    Fraction(int numerator,int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        this->set_denominator(denominator);

        cout << "Constuctor " << this << endl;
    }

    Fraction(int integer ,int numerator , int denominator )
    {
        this->integer = integer;
        this->numerator = numerator;
        this->set_denominator(denominator);

        cout << "Constructor " << this << endl;
    }
    Fraction(const Fraction& other)
    {

        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator=other.denominator;

        cout << "CopyConstructor " << this << endl;

    }

    ~Fraction()
    {
        cout << "Destrucror " << this << endl;

    }

    Fraction& to_proper() 
    {

        integer += numerator / denominator;
        numerator %= denominator;
        return* this;

    }

    Fraction& to_improper()
    {

        numerator += integer * denominator;
        integer = 0;
        return *this;

    }

    void print()const 
    {

        if (integer)cout << integer <<" "; //Ожидает целое число

        if (numerator)  ////Ожидает числитель
        {
            if (integer)cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)cout << ")";
        }

        else if (integer == 0)cout << 0;
        cout << endl;
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

    Fraction inverted()const 
    {


        Fraction inverted = *this;
        inverted.to_improper();

        swap(inverted.numerator, inverted.denominator);
        return inverted;
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

Fraction operator*( Fraction left,  Fraction right)
{

  
    left.to_improper();
    right.to_improper();


   //Явно вызываем конструктор и создаем временный безымянный объект,который сразу же возращается на место вызова
    return  Fraction  //Default Constuctor
    (
        left.get_numerator() * right.get_numerator(),
        left.get_denominator() * right.get_denominator()

    ).to_proper();

    //result.set_numerator(left.get_numerator() * right.get_numerator());
    //result.set_denominator(left.get_denominator() * right.get_denominator());

}

Fraction operator/( const Fraction& left, const Fraction& right)
{
   /* left.to_improper();
    right.to_improper();

    Fraction res;


    return Fraction(

        left.get_numerator() * right.get_denominator(),
        right.get_numerator() * left.get_denominator()

    ).to_proper();*/


    return left * right.inverted();

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

//#define CONTUCTOR_CHEK
int main()
{
 
#ifdef CONTUCTOR_CHEK
    Fraction A;
    A.print();
    Fraction B = 5;
    B.print();

    Fraction C(2, 3);
    C.print();

    Fraction D (2, 3, 4);
    D.print();

    Fraction E=D;
    E.print();
#endif CONTUCTOR_CHEK


    double a = 2;
    double b = 3;
    double c = a * b;

    Fraction A(2, 3, 4);
    A.print();

    Fraction B(3, 4, 5);
    B.print();

    Fraction C=A*B;
    C.print();

    Fraction D = A / B;
    D.print();

  /*  A *= B;
    A.print();*/
 
}


