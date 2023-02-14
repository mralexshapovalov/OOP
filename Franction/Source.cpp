#include "Header.h"

int Fraction::get_integer()const
{
    return integer;
}

int Fraction::get_numerator()const
{
    return numerator;
}

int Fraction::get_denominator()const
{
    return denominator;
}

void Fraction::set_integer(int integer)
{
    this->integer = integer;
}

void Fraction::set_numerator(int numerator)
{
    this->numerator = numerator;
}

void Fraction::set_denominator(int denominator)
{
    if (denominator == 0)denominator = 1;
    this->denominator = denominator;
}

Fraction::Fraction()//По умолчанию 
{
    this->integer = 0;
    this->numerator = 0;
    this->denominator = 1;

    cout << "DefaultConstuctor " << this << endl;
    reduce();
}

Fraction::Fraction(double decimal)
{
    decimal += 1e-17;
    this->integer = decimal; //Сохраняем целую часть
    decimal -= integer;      //убираем целую часть из девятияной дроби
    this->denominator = 1e+18;
    this->numerator = decimal * denominator;
    reduce();
    cout << "ConstuctorDecimal" << this << endl;
}

Fraction::Fraction(int integer)
{
    this->integer = integer;
    this->numerator = 0;
    this->denominator = 1;

    cout << "1ArgConstuctor " << this << endl;
}

Fraction::Fraction(int numerator, int denominator)
{
    this->integer = 0;
    this->numerator = numerator;
    this->set_denominator(denominator);

    cout << "Constuctor " << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator)
{
    this->integer = integer;
    this->numerator = numerator;
    this->set_denominator(denominator);

    cout << "Constructor " << this << endl;
}

Fraction::Fraction(const Fraction& other)
{
    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;

    cout << "CopyConstructor " << this << endl;
}

Fraction::~Fraction()
{
    cout << "Destrucror " << this << endl;
}

Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{

    set_integer(integer);
    set_numerator(numerator);
    set_denominator(denominator);
    return *this;

}

Fraction& Fraction::operator=(const Fraction& other)
{

    this->integer = other.integer;
    this->numerator = other.numerator;
    this->denominator = other.denominator;

    cout << "Operator=" << this << endl;
    return *this;
}

Fraction& Fraction::to_proper()
{
    integer += numerator / denominator;  //Fraction & to_proper();	//выделяет целую часть из числителя
    numerator %= denominator;
    return*this;
}

Fraction& Fraction::to_improper()                 //Fraction& to_improper();//целую часть интегрирует в числитель 
{
    numerator += integer * denominator;
    integer = 0;
    return *this;
}

Fraction& Fraction::reduce()                 //Fraction& to_improper();//целую часть интегрирует в числитель 
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

Fraction& Fraction::operator++() //Префексный 
{
    integer++;
    return *this;
}

Fraction& Fraction::operator--()//Префексный 
{
    integer--;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
    return *this = *this * other;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
    return *this = *this / other;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
    return *this = *this + other;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
    return *this = *this - other;
}

Fraction Fraction::operator++(int) //Посфиксный
{
    Fraction old = *this;
    integer++;
    return old;
}

Fraction Fraction::operator--(int) //Посфиксный
{
    Fraction old = *this;
    integer--;
    return old;
}

Fraction Fraction::inverted()const
{
    Fraction inverted = *this;
    inverted.to_improper();

    swap(inverted.numerator, inverted.denominator);
    return inverted;
}

Fraction::operator int()const
{
    return Fraction(*this).to_proper().integer;
}

Fraction::operator double()const
{
    return integer + (double)numerator / denominator;
}

Fraction operator+(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();

    return  Fraction  //Default Constuctor
    (
        left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator()
    );
}

Fraction operator-(Fraction left, Fraction right)
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

Fraction operator/(Fraction left, Fraction right)
{

    return left * right.inverted();
}

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

bool operator <=(Fraction left, Fraction right)
{
    return left < right || left == right;
}

bool operator >=(Fraction left, Fraction right)
{
    return !(left <= right);
}

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
    return obj.print(os);
}

std::istream& operator >> (std::istream& is, Fraction& obj)
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
    for (char* pch = strtok(buffer, delimmiters); pch; pch = strtok(NULL, delimmiters))
        number[n++] = atoi(pch); //Функция atoi() Ascii string integer перобразует строку в число 

    switch (n)
    {
    case1:obj.set_integer(number[0]); break;
    case2:
        obj.set_numerator(number[0]);
        obj.set_denominator(number[1]);
        break;
    case3:obj(number[0], number[1], number[2]); break;

    }
    return is;
}

std::ostream& Fraction::print(std::ostream& os)const
{
    if (integer)os << integer << " "; //Ожидает целое число

    if (numerator)  ////Ожидает числитель
    {
        if (integer)os << "(";
        os << numerator << "/" << denominator;
        if (integer)os << ")";
    }

    else if (integer == 0)os << 0;


    return os;
}
