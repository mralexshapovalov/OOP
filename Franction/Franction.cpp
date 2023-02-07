// Franction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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
//5. Перегрузить составные присваивания : +=, -=, *=, /=;            DONE
//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
//7. Перегрузить оператор ввода с клавиатуры;                        DONE
//Обьявление класса

class Fraction;

Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction 
{
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

    void set_integer(int integer) 
    {
        this->integer = integer;
    }

    void set_numerator(int numerator) 
    {
        this->numerator = numerator;
    }

    void set_denominator(int denominator) 
    {
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
        reduce();
    }

    Fraction(double decimal) 
    {
        decimal += 1e-17;
        this->integer = decimal; //Сохраняем целую часть
        decimal -= integer;      //убираем целую часть из девятияной дроби
        this->denominator = 1e+18;
        this->numerator = decimal * denominator;
        reduce();
        cout << "ConstuctorDecimal" << this << endl;
    }


   explicit Fraction(int integer)
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
    Fraction& operator()(int integer, int numerator, int denominator) 
    {

        set_integer(integer);
        set_numerator(numerator);
        set_denominator(denominator);
        return *this; 

    }

    Fraction& operator=(const Fraction& other) 
    {

        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator=other.denominator;

        cout << "Operator=" << this << endl;
        return *this;
    }

    Fraction& to_proper() 
    {
        integer += numerator / denominator;  //Fraction & to_proper();	//выделяет целую часть из числителя
        numerator %= denominator;
        return* this;
    }

    Fraction& to_improper()                 //Fraction& to_improper();//целую часть интегрирует в числитель 
    {
        numerator += integer * denominator;
        integer = 0;
        return *this;
    }

    Fraction& reduce()                 //Fraction& to_improper();//целую часть интегрирует в числитель 
    {
         int more, less, rest = 0;

        if (numerator > denominator)more = numerator, less = denominator;
        else less = numerator = numerator, more = denominator;

        do 
        {
            rest = more % less;
            more = less;
            less = rest;

        } while (rest);

       long long int GCD = more; //GCD= Наибольший общий делитель
        
        numerator /= GCD;
        denominator /= GCD;

        return *this;
    }


    std::ostream& print(std::ostream& os)const 
    {
        if (integer)os << integer <<" "; //Ожидает целое число

        if (numerator)  ////Ожидает числитель
        {
            if (integer)os << "(";
            os << numerator << "/" << denominator;
            if (integer)os << ")";
        }

        else if (integer == 0)os << 0;
       

        return os;
    }
    
    //4. Перегрузить операторы++ / --;

    Fraction& operator++() //Префексный 
    {
        integer++;
        return *this;
    }

    Fraction operator++(int) //Посфиксный
    {
        Fraction old = *this;
        integer++;
        return old;
    }

    Fraction& operator--()//Префексный 
    {
        integer--;
        return *this;
    }

    Fraction operator--(int) //Посфиксный
    {
        Fraction old = *this;
        integer--;
        return old;
    }


//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;
//7. Перегрузить оператор ввода с клавиатуры;

   

    Fraction inverted()const 
    {
        Fraction inverted = *this;
        inverted.to_improper();

        swap(inverted.numerator, inverted.denominator);
        return inverted;
    }

    Fraction & operator *=(const Fraction& other)
    {
        return *this = *this * other;
    }

    Fraction& operator/=(const Fraction& other)
    {
       return *this = *this / other;
    }

    Fraction& operator+=(const Fraction& other)
    {
        return *this = *this + other;
    }

    Fraction& operator-=(const Fraction& other)
    {
        return *this = *this - other;
    }

    explicit operator int()const
    {
        
        return Fraction(*this).to_proper().integer;

    }
    explicit operator double()const
    {

        return integer + (double)numerator / denominator;

    }
    
};

Fraction operator+( Fraction left,  Fraction right)
{
    left.to_improper();
    right.to_improper();

    return  Fraction  //Default Constuctor
    (
        left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator()
    );
}

Fraction operator-( Fraction left,  Fraction right)
{
    left.to_improper();
    right.to_improper();

    return  Fraction  //Default Constuctor
    (
        left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator()

    ).to_proper();
}

Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();

    //Явно вызываем конструктор и создаем временный безымянный объект,который сразу же возращается на место вызова
    return  Fraction  //Default Constuctor
    (
        left.get_numerator() * right.get_numerator(),
        left.get_denominator() * right.get_denominator()

    ).to_proper().reduce();

    //result.set_numerator(left.get_numerator() * right.get_numerator());
    //result.set_denominator(left.get_denominator() * right.get_denominator());
}


Fraction operator/( Fraction left,  Fraction right)
{

    return left * right.inverted();
}

//6. Перегрузить операторы сравнения : == , != , > , < , >= , <= ;

bool operator==(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();

    return left.get_numerator() * right.get_denominator() ==
           right.get_numerator() * left.get_denominator();
}

bool operator !=(const Fraction& left, const Fraction& right)
{
    return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();

    return left.get_numerator() * right.get_denominator() >
          right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
   left.to_improper();
   right.to_improper();

   return left.get_numerator() * right.get_denominator() <
         right.get_numerator() * left.get_denominator();

}

bool operator <=( Fraction left,  Fraction right)
{
    return left < right || left == right;
}

bool operator >=( Fraction left,  Fraction right)
{
    return !(left <=right);
}

//7. Перегрузить оператор ввода с клавиатуры;
std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
    return obj.print(os);
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
    
  /*  int integer, numerator, denominator;
    is >> integer >> numerator >> denominator;
    obj(integer, numerator, denominator);
    return is;*/

    const int SIZE = 32;
    char buffer[SIZE] = {};
    is >> buffer;

    int number[3] = {};

    char delimmiters[] = "/()";
    
    is >> buffer;
    is.getline(buffer, SIZE);
    int n = 0;//счетчик чисел введеныой строке 
    for (char* pch = strtok(buffer, delimmiters); pch; pch=strtok(NULL,delimmiters))
        number[n++]=atoi(pch); //Функция atoi() Ascii string integer перобразует строку в число 

    switch (n)
    {
    case1:obj.set_integer(number[0]); break;
    case2:
        obj.set_numerator(number[0]);
        obj.set_denominator(number[1]);
        break;
    case3:obj(number[0],number[1],number[2]); break;

    }
    return is;

}


//#define CONTUCTOR_CHEK

//#define CONVERSION_OTHER_TO_CLASS
int main()
{
    setlocale(LC_ALL, "RUS");
//
//#ifdef CONTUCTOR_CHEK
//    Fraction A;
//    A.print();
//    Fraction B = 5;
//    B.print();
//
//    Fraction C(2, 3);
//    C.print();
//
//    Fraction D(2, 3, 4);
//    D.print();
//
//    Fraction E = D;
//    E.print();
//#endif CONTUCTOR_CHEK
//
//
//#ifdef CONVERSION_OTHER_TO_CLASS
//
//
//
//
//
//    Fraction A = (Fraction)5;
//
//    A.print();
//
//
//    Fraction B;
//    B = Fraction(8);
//    B.print();
//#endif // CONVERSION_OTHER_TO_CLASS
//
//
//    //Fraction A(2, 3, 4);
//    //A.print();

    //int a = (int)A;
    //cout << a << endl;


//#ifdef HOMEWORk1

    //Fraction B(2, 3, 4);
    //double b = (double)B;
    //cout << B << endl;

//#endif

//#ifdef HOMEWORk2

 /*   Fraction B = (2, 3,4);
    double b = (double)B;
    cout << B << endl;*/

//#endif


    //Fraction B = 2.75;
    //B.print();
  /*  double b = (double)B;
    cout << B << endl;*/

    Fraction A;
    cout << "Введите простую дробь: "; cin >> A;
    cout << A << endl;

}
