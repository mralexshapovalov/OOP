// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
using namespace std;

//Êëàññ - ýòî òèï äàííûõ 
//Ñòðóêòóðà - ýòî òèï äàííûõ

#ifdef STRICT_POINT //Working 16.01.2023
class Point //Ñîçäàâàÿ ñòóðêòóðó èëè êëàññ, ìû ñîçäàåì íîâûé òèï äàííûõ.
    //Êëàññû è ñòðóêòóðû åùå íàçûâàþò ïîëüçîâàòåëüñêèìè (ñîñòàâíûìè) òèïàìè äàííûõ

{

public:

    double x;
    double y;

};
#endif // DEBUG

#ifdef CONSTRUCTOR_CHEK
class Point
{
private:
    double x;
    double y;

public:

    //Point()
    //{
    //    x = y = 0;
    //    //RAII -Resource Aqulisation(âûäåëåíèíå ðåñóðñîâ -çíà÷èò èíöèëèçàöèÿ)
    //    cout << "Constructro\t" << this<<endl;
    //}
    //Point(double x) 
    //{

    //    this->x = x;
    //    this->y = 0;
    //    cout << "!ArgConstructor" << this << endl;

    //}

    Point(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;

        cout << "Конструктор копирования" << this << endl;

    }

    Point(double x = 0, double y = 0)
    {

        this->x = x;
        this->y = y;
        cout << "Constructror\t" << this << endl;
    }

    ~Point()
    {
        cout << "Deconstructro\t" << this << endl;

    }
    void Print()const
    {
        cout << "X=" << x << "\tY=" << y << endl;
    }

};

#endif // DEBUG

class Point
{
private:
    double x;
    double y;

public:

    //Point()
    //{
    //    x = y = 0;
    //    //RAII -Resource Aqulisation(âûäåëåíèíå ðåñóðñîâ -çíà÷èò èíöèëèçàöèÿ)
    //    cout << "Constructro\t" << this<<endl;
    //}
    //Point(double x) 
    //{

    //    this->x = x;
    //    this->y = 0;
    //    cout << "!ArgConstructor" << this << endl;

    //}

    Point(const Point& other) 
    { 
      this->x = other.x; 
      this->y = other.y; 

    cout << "Конструктор копирования" << this << endl; 
    
    }

    Point(double x = 0, double y = 0)
    {

        this->x = x;
        this->y = y;
        cout << "Constructror\t" << this << endl;
    }

    ~Point()
    {
        cout << "Deconstructro\t" << this << endl;

    }
    // Operators
    void operator=(const Point& other) {


        this->x = other.x;
        this->y = other.y;

        cout << "CopyAssingment:\t" << this << endl;
    }


    void Print()const
    {
        cout << "X=" << x << "\tY=" << y << endl;
    }

};


int main()
{
    setlocale(LC_ALL, "RUS");


//#ifdef STRUCT_POINT//Working 16.01.2023
//#endif // DEBUG

//#ifdef CONSTRUCTOR_CHEK
//Point A;
//A.Print();
//
//Point B(2, 4);
//B.Print();
//
//Point C = 4;
//C.Print();
//
//Point D = C;
//D.Print();

  /*  Point A(2, 3);
    A.Print();
    Point B = A;
    B.Print();
    Point C;
    C = B;
    C.Print();*/

    Point A, B, C;
    A = B = C = Point(2, 2);


//#endif // CONSTRUCTOR_CHEK{}





}
