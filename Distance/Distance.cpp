// Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include <cmath>


class Point 
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

    double Distance(Point A, Point B)
    {
        return sqrt(pow((A.x - B.x), 2) + (pow((A.y - B.y), 2)));
    }

};

int main()
{
  
    Point A;                    

    A.SetX(2);
    A.SetY(4);

    Point B;
    B.SetX(0);
    B.SetY(0);

    std::cout << "Point A: " << A.GetX() << "\t" << A.GetY() <<"\n";
    std::cout << "Point B: " << B.GetX() << "\t" << B.GetY() << "\n";
    std::cout << "Distance beetween two points : " << A.Distance(A, B);


}



