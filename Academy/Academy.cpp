// Academy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class Human 
{
private:

    std::string last_name;
    std::string first_name;
    tm birth_date; //tm -timepoint Структура,содержащая календарную дату и время,разбитые на составляющие.

public:

    const std::string& get_last_name()const 
    {
        return last_name;
    }

    const std::string& get_first_name()const
    {
        return first_name;
    }

    tm get_birth_date()const 
    {
        return birth_date;
    }

    unsigned int get_age()const
    {
        time_t t_today = time(NULL);//Получаем текщию дату /время в формата Timestamp
        tm* tm_today = localtime(&t_today);

        unsigned int age = tm_today->tm_year - birth_date.tm_year;

        if (tm_today->tm_mon < birth_date.tm_mon)age--;
        if (tm_today->tm_mon == birth_date.tm_mon && tm_today->tm_mday < birth_date.tm_mday)age--;

        return age;
    }

    void set_last_name(const std::string& last_name) 
    {
        this->last_name = last_name;
    }

    void set_firs_name(const std::string& first_name) 
    {
        this->first_name = first_name;
    }

    void set_birthday_data(int year, int month, int day) 
    {
        birth_date.tm_year = year - 1900;
        birth_date.tm_mon = month - 1;
        birth_date.tm_mday = day;
    }

    Human (const std:: string& last_name,const std::string& first_name,int year,int month,int day)
    {
    
        set_last_name(last_name);
        set_firs_name(first_name);

        set_birthday_data(year, month, day);

        std::cout << "HConstructor:\t" << this << std::endl;
    
    }
    ~Human() {


        std::cout << "HDetructor:\t" << this << std::endl;

    }
    //Methods

    void info()const
    {
        std::cout << last_name << " " << first_name << " " << get_age() << " " << std::endl;
    }
};

class Student:public Human 
{
    std::string speciality;
    std::string group;
    double rating;
    double attendance;

public:

    const std::string& get_speciality()const
    {

        return speciality;

    }


    const std::string& get_group()const
    {

        return group;

    }
    double get_rating()const {


        return rating;

    }

    double get_attendance()const {


        return attendance;

    }

    void set_speciality(const std::string& speciality)
    {

        this->speciality = speciality;
    }

    void set_group(const std::string& group)
    {

        this->group = group;
    }

    void set_rating(double ratting)
    {

        this->rating = ratting;
    }

    void set_attendance(double attendance)
    {

        this->attendance = attendance;
    }


    Student
    (
        const std::string& last_name, const std::string& first_name, int year, int month, int day,
        const std::string& specialty, const std::string& group, double rating, double attendance
    ) :Human(last_name, first_name, year, month, day)//вызов конструктора базового классаа
 
    {

        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendance(attendance);

        std::cout << "SConstructor:\t" << this << std::endl;
    }

    ~Student() {


        std::cout << "SDetructor:\t" << this << std::endl;


    }
    void info()const
    {
        std::cout << speciality << " " << group << " " << rating << " " <<attendance<< std::endl;
    }

};

#define TIME

int main()
{

    setlocale(LC_ALL, "RUS");

#ifdef TIME
    //time_t t_today = time(NULL);//Получаем текщию дату /время в формата Timestamp
    //std::cout << t_today << std::endl;
    //
    //tm* tm_today = localtime(&t_today);
    //std::cout << tm_today->tm_year+1900 << std::endl;
    //std::cout << tm_today->tm_mon+1 << std::endl;
    //std::cout << tm_today->tm_mday << std::endl;
    //std::cout<<asctime(tm_today) << std::endl;

#endif // TIME


    Human human("Тупенко","Василий",1997,07,06);
    human.info();

    Student student("Тупенко", "Василий", 1997, 07, 06, "IT", "Start", 60, 30);
    student.info();

    int x = 10;
    int* p;
    p = &x;
    std::cout << "Address = " << p << std::endl;
    std::cout << "Value = " << *p << std::endl;
    return 0;

}

