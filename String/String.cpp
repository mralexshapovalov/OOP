#include"String.h"
int String::get_size()const
{
	return size;
}
char* String::get_str()
{
	return str;
}

const char* String::get_str()const
{
	return str;
}



String::String(int  size) :size(size), str(new char[size] {})
{
	std::cout << "DefConstructor\t" << this << std::endl;
}

String::String(const  char* str) :String(strlen(str) + 1)
{
	//this->size = size;
	//this->str = new char[size] {};
	//strcpy(this->str, str); //копирует данные из строки

	//std::cout << "1ArgConstuctor " << this << std::endl;


	for (int i = 0; i < size; i++)this->str[i] = str[i];
	std::cout << "1ArgConstuctor " << this << std::endl;

}


String::String(const String& other) :String(other.str)
{

	std::cout << "CopyConstructor:" << this << std::endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{

	other.str = nullptr;

	std::cout << "MoveConstructor:" << this << std::endl;
}

String::~String()
{
	delete[] str;
	std::cout << "Destructor\t" << this << std::endl;
}

String& String:: operator=(const String& other)
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

String& String:: operator=(String&& other)
{

	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	std::cout << "MoveAssignment:\t" << this << std::endl;
	return *this;
}

String& String:: operator+=(const String& other)
{
	return *this = *this + other;
}


char String :: operator[](int i)const
{

	return str[i];
}

char& String :: operator[](int i)
{

	return str[i];
}


void String::print()const
{
	std::cout << "Size:\t" << size << std::endl;
	std::cout << "Str:\t" << str << std::endl;
}



String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return cat;
}


std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}