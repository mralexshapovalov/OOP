// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"

using namespace std;

//����� - ��� ��� ������ 
//��������� - ��� ��� ������

class Point //�������� ��������� ��� �����, �� ������� ����� ��� ������.
    //������ � ��������� ��� �������� ����������������� (����������) ������ ������

{

private:

    double x;
    double y;

public:
    
    double GetX() 
    {
        return x;
    }
    void SetX(double valueX) 
    {

        x = valueX;
    }

    double GetY()
    {
        return y;
    }
    void SetY(double valueY)
    {

        y = valueY;
    }

    void Print() 
    {
        cout << "X=" << x << "\t Y=" << y << endl;

    }
   

};



int main()
{
    setlocale(LC_ALL, "RUS");

    Point A;//����������� ���������� � ���� Point 
           //���������� ������� � ��������� Point 
           // �������� ���������� � ��������� Point
    //������ ����� �������  ������������ ������ ��� ���������


    A.SetX(5);
    A.SetY(3);
    A.Print();

    Point* pA = &A;

    /*cout << pA->x << "\t" << pA -> y << endl;*/

}



//��������� � ����� ������ 
//��� ��������� � ����� ������� 
//����� ������������ �������� 
//.    -��� �������� �������� �������(����������� ��� �������� � ����� ������� �� ����� �������)
//->   -�������� ���������� ������� (Arrow operator) ������������ ��� ������� � ����� ������� �� ������� �������


//��������� ���
//
//1.������������� - ��� �������� ������������ ����� ������ �� �������� ����
//������������ ����������� �������������� �������  get; set ��������
//� ����� �++ ��������� 3 ������������ �������: 
//private:-��������� ����, �������� ������ ������, ���������� ������ ������ ������ ���� ����������, ��� �������� �� �� ��������� ����������.
//public: -��� ������� ����, �������� �� ������ ����� ���������.� ������ ������ ������ ��������� ������.
//protected:���������� ����, �������� ������ ������ ������ � ��� �������� �������(���� ������������ �������, ������������ ������ ��� ������������)
//    ������������ �������� ������ � ��������� �������� ��, ��� � ��������� ��� ���� �� ��������� ������� � � ������ ��� ���� �� ��������� �������
//    get;set - ������������ ������ �� ��� � �������� ���������� � ������
//    get(�����\�������)-��������� �������� (�����) ��������� ���������� (��������� ������ �� ������  � ���������� ������  ������)
//    set(���������,������.����������) -��������� ������ �������� ���������� � ������ )
//    ��� �� �������� � ������ � ���������� ������ ������ �� ������.����� ���� set  ������  ������������ ���������� ������ 
//2.������������
//3.�����������

