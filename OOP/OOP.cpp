// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"

using namespace std;

//Класс - это тип данных 
//Структура - это тип данных

#ifdef STRICT_POINT //Working 16.01.2023
class Point //Создавая стурктуру или класс, мы создаем новый тип данных.
    //Классы и структуры еще называют пользовательскими (составными) типами данных

{

public:

    double x;
    double y;

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
    //    //RAII -Resource Aqulisation(выделенине ресурсов -значит инцилизация)
    //    cout << "Constructro\t" << this<<endl;
    //}
    //Point(double x) 
    //{

    //    this->x = x;
    //    this->y = 0;
    //    cout << "!ArgConstructor" << this << endl;

    //}

    Point(double x=0, double y=0) 
    {

        this->x = x;
        this->y = y;
        cout << "Constructro\t" << this << endl;
    }

    ~Point()
    {
        cout << "Deconstructro\t"<<  this << endl;

    }
    void Print()const
    {
        cout << "X=" << x << "\tY=" << y << endl;
    }

};


int main()
{
    setlocale(LC_ALL, "RUS");

    
#ifdef STRUCT_POINT//Working 16.01.2023

    Point A;//Обяъвеление переменной А типа Point 
              //Объявление объекта А структуры Point 
             // Создание экземпляра А структуры Point
            //Объкты часто назвает  экземплярами класса или структуры

    

    A.x = 2;
    A.y = 3;
    cout << A.x << "\t" << A.y << endl;

    Point* pA = &A;

    cout << pA->x << "\t" << pA->y << endl;
    };
#endif // DEBUG

Point A;
A.Print();

Point B(2, 4); 
B.Print();

Point C = 4;
C.Print();

}




