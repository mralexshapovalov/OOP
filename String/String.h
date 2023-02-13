//String.h
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class String;



String operator+(const String& left, const String& right);
std::ostream& operator << (std::ostream& os, const String& obj);

class String
{
	int size; //Размер строки
	char* str; //Адресс строки в динамической памяти

public:

	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//					Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);

	char operator[](int i)const;
	char& operator[](int i);

	//					Methods:
	void print()const;


};
////////////////////////////// Сlass declaration END///////////////////////////////////////////