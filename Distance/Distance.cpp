// Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include <cmath>

#define delimiter "\n_______________________________________________________________"
//Completed the work on 18.01.23
class Point
{

private:

    double x;
    double y;

public:

    double GetX()const
    {
        return x;
    }

    void SetX(double x)
    {

        this->x = x;
    }

    double GetY()const
    {
        return y;
    }

    void SetY(double y)
    {

        this->y = y;
    }

    /* double Distance(Point A, Point B)
     {
         return sqrt(pow((A.x - B.x), 2) + (pow((A.y - B.y), 2)));
     }*/

    double Distance(const Point& other)const
    {
        other.x = 125;
        double x_distance = this->x - other.x;
        double y_distance = this->y - other.y;
        double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
        return distance;
    }

    Point(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;

        std::cout << "Конструктор копирования" << this << std::endl;

    }

    Point(double x = 0, double y = 0)
    {

        this->x = x;
        this->y = y;
        std::cout << "Constructror\t" << this << std::endl;

    }

    ~Point()
    {
        std::cout << "Deconstructro\t" << this << std::endl;


    }
    void Print()const
    {
        std::cout << "X=" << x << "\tY=" << y << std::endl;

    }


};

double Distance(const Point& A, const Point &B)
{
    double x_distance = A.GetX() - B.GetX();
    double y_distance = A.GetY() - B.GetY();
    double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
    return distance;
}



int main()
{
//Completed the work on 18.01.23
    Point A;

    A.SetX(2);
    A.SetY(3);

    Point B;
    B.SetX(7);
    B.SetY(8);

    std::cout << "Point A: " << A.GetX() << "\t" << A.GetY() << "\n";
    std::cout << "Point B: " << B.GetX() << "\t" << B.GetY() << "\n";
    std::cout << delimiter << std::endl;
    std::cout << "Distance beetween two points : " << A.Distance(B) << std::endl;
    std::cout << delimiter << std::endl;
    std::cout << "Distance beetween two points : " << B.Distance(B) << std::endl;
    std::cout << delimiter << std::endl;
    std::cout << "Distance beetween two points : " << Distance(B, B) << std::endl;


  

}