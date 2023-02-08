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

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};

		std::cout << "DefConstructor\t" << this << std::endl;
	};

	String(const char* str)
	{
		//this->size = size;
		//this->str = new char[size] {};
		//strcpy(this->str, str); //копирует данные из строки

		//std::cout << "1ArgConstuctor " << this << std::endl;

		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];


		std::cout << "1ArgConstuctor " << this << std::endl;

	}

	~String()
	{
		delete this->str;
		std::cout << "Destructor\t" << this << std::endl;
	}

	String(const String& other) {


		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];


		std::cout << "CopyConstuctor:\t " << this << std::endl;
	}

	String& operator=(const String& other) {

		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)

			this->str[i] = other.str[i];

		std::cout << "CopyAsigment:\t " << this << std::endl;
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

int main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello ";
	//std::cout << str1 << std::endl;

	String str2 = "World";
	//std::cout << str2 << std::endl;

	String str3;
	str3 = str1 + str2;//Конкатенация (слияние) строк
	std::cout << str3 << std::endl;


	//str1 = str1;
	//std::cout << str1 << std::endl;

	str1 += str2;
	std::cout << str1 << std::endl;
}




