// Franction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"


#define CONTUCTOR_CHEK

#define CONVERSION_OTHER_TO_CLASS

int main()
{
    setlocale(LC_ALL, "RUS");


    //Fraction A;
    //A.print();
    //Fraction C(2, 3);
    //C.print();

    /*Fraction B = 5;
    B.print();

    ;

    Fraction D(2, 3, 4);
    D.print();

    Fraction E = D;
    E.print();*/

//
//
//    Fraction F = (Fraction)5;
//
//    F.print();
//
//
//    Fraction G;
//    G = Fraction(8);
//    G.print();
//#endif // CONVERSION_OTHER_TO_CLASS
//
//
//    //Fraction A(2, 3, 4);
//    //A.print();
//
//    int a = (int)F;
//    cout << a << endl;
//
//
//
//    Fraction K(2, 3, 4);
//    double k = (double)K;
//    cout << K << endl;
//
//
//
//
//
//    Fraction B = (2, 3,4);
//    double b = (double)B;
//    cout << B << endl;
//
//
//
//
    Fraction B = 2.75;
    B.print();

    double b = (double)B;
    cout << B << endl;

    Fraction A;
    cout << "Введите простую дробь: "; cin >> A;
    cout << A << endl;

}
