// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"

using namespace std;

//����� - ��� ��� ������ 
//��������� - ��� ��� ������

#ifdef STRICT_POINT //Working 16.01.2023
class Point //�������� ��������� ��� �����, �� ������� ����� ��� ������.
    //������ � ��������� ��� �������� ����������������� (����������) ������ ������

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

    Point A;//����������� ���������� � ���� Point 
              //���������� ������� � ��������� Point 
             // �������� ���������� � ��������� Point
            //������ ����� �������  ������������ ������ ��� ���������


    A.x = 2;
    A.y = 3;
    cout << A.x << "\t" << A.y << endl;

    Point* pA = &A;

    cout << pA->x << "\t" << pA->y << endl;
    };
#endif // DEBUG

//������������

}




