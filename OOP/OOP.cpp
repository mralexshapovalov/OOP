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

//Конструкторы

}




