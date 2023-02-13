
#include "String.h"
//-------------------------------------------------------------------------------------------//

////////////////////////////// Class Defenition END/////////////////////////////////////////////



#define BASE_CHECK
//#define CALLING_CONSTUCTORS
int main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	String str(5);
	str.print();
	
	String str1 = "Hello ";
	//std::cout << str1 << std::endl;

	String str2 = "World";
	//std::cout << str2 << std::endl;

	String str3;
	str3 = str1 + str2;//Конкатенация (слияние) строк //move constuctor
	std::cout << str3 << std::endl;


	
	//str1 = str1;
	//std::cout << str1 << std::endl;

	////String str1 += str2;/
	//std::cout << str1 << std::endl;

	/*String str4 = str3;
	str4.print();*/

#endif // BASE_CHECK

#ifdef  CALLING_CONSTUCTORS
	String str1;//Default constructor
	str1.print();
	String str2 = "Hello";//Single argument constuctor
	str2.print();
	String str3 = str2;//CopyConstructor
	str3.print();
	String str4(); //Не вывзывается коструктор,тк здесь не создается объект
				   //Обяъвляется str4 функция,которая не принимает никаких параметров
				   //и возвращает значение типа String.

	//str4.print();//str4 -это не объект,а функция.А для функции вызывается объект.

	//Если сы хотим явно вызвать конструктор по умолчания ,то это можно сделать так:
	String str5{};
	str5.print();
	String str6{ 22 };
	str6.print();
	String str7{ "World" };
	str7.print();
	String str8{ str7 };
#endif //  CALLING_CONSTUCTORS
}







