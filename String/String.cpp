#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class String;

String operator+(const String& left, const String& right);

class String
{
	int size; //Размер строки
	char* str; //Адресс строки в динамической памяти

public:

	int get_size()const
	{
		return size;
	}
	char* get_str()
	{
		return str;
	}

	const char* get_str()const
	{
		return str;
	}

	void set_str(char* str)
	{
		this->str = str;
	}
	//Constuctor

	explicit String(int size = 80) :size(size),str(new char[size]{})
	{
		std::cout << "DefConstructor\t" << this << std::endl;
	}

	String(const char* str) :String(strlen(str)+1)
	{
		//this->size = size;
		//this->str = new char[size] {};
		//strcpy(this->str, str); //копирует данные из строки

		//std::cout << "1ArgConstuctor " << this << std::endl;

		
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		std::cout << "1ArgConstuctor " << this << std::endl;

	}

	~String()
	{
		delete this->str;
		std::cout << "Destructor\t" << this << std::endl;
	}


	String(const String& other) :String(other.str)
	{

		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];


		std::cout << "CopyConstuctor:\t " << this << std::endl;
	}
	String( String&& other) noexcept : size(other.size), str(other.str)
	{

		//ShalovCopy-поверхносное копирование
		
		other.str = nullptr;
		std::cout << "MoveConstuctor:\t " << this << std::endl;
	}

	String& operator=(const String& other) 
	{

		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)

			this->str[i] = other.str[i];

		std::cout << "CopyAsigment:\t " << this << std::endl;
		return *this;
	}

	String& operator=(String&& other) 
	{

		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		std::cout << "MoveAssignment:\t" << this << std::endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}


	char operator[](int i)const
	{

		return str[i];
	}

	char& operator[](int i)
	{

		return str[i];
	}

	
	void print()const
	{
		std::cout << "Size:\t" << size << std::endl;
		std::cout << "Str:\t" << str << std::endl;
	}


};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		/*cat.get_str()[i] = left.get_str()[i];*/
	    cat[i] = left[i];

	for (int i = 0; i < right.get_size(); i++)
		/*cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	    cat[i+left.get_size()-1] = right[i];

	return cat;
}

 
std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

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

	String str4 = str3;
	str4.print();

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







