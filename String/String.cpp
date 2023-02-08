#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class String
{
    int size; //Размер строки
    char* str; //Адресс строки в динамической памяти

public:

    int get_size()const
    {
        return size;
    }

    const char* get_str()const {

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
        this->size = size;
        this->str = new char[size] {};
        strcpy(this->str, str); //копирует данные из строки

        std::cout << "1ArgConstuctor " << this << std::endl;
    }

    ~String()
    {
        std::cout << "Destructor\t" << this << std::endl;
    };

    void print()const
    {

        std::cout << "Size:\t" << size << std::endl;
        std::cout << "Str:\t" << str << std::endl;
    }
};

    std::ostream& operator << (std::ostream& os, const String& obj)
    {
        return os << obj.get_str();
    }

    int main()
    {
        setlocale(LC_ALL, "");

        String str1 = "Hello";
        std::cout << str1 << std::endl;

        String str2 = "World";
        std::cout << str2 << std::endl;

        //String str3 = str1 + str2;	//Конкатенация (слияние) строк
        //std::cout << str3 << std::endl;

    }





