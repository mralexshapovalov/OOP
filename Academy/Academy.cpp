// Academy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


#define HUMAN_TAKE_PARAMETERS const std:: string& last_name,const std::string& first_name,int year,int month,int day
#define HUMAN_GIVE_PARAMETERS last_name,first_name,year,month,day

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

    Human (HUMAN_TAKE_PARAMETERS)
    {
        set_last_name(last_name);
        set_firs_name(first_name);

        set_birthday_data(year, month, day);

        std::cout << "HConstructor:\t" << this << std::endl;
    
    }
   virtual ~Human() 
   {
        std::cout << "HDetructor:\t" << this << std::endl;
   }
    //Methods

    virtual void info()const
    {
        std::cout << last_name << " " << first_name << " " << get_age() << " " << std::endl;
    }
};

#define STUDENT_TAKE_PARAMETERS  const std::string& specialty, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS specialty,group,rating,attendance

class Student:public Human 
{
private:

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

    double get_rating()const 
    {
        return rating;
    }

    double get_attendance()const 
    {
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

    Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)//вызов конструктора базового классаа
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendance(attendance);

        std::cout << "SConstructor:\t" << this << std::endl;
    }

    Student(const Human& human, STUDENT_TAKE_PARAMETERS):Human(human)
    {
        set_speciality(specialty);
        set_group(group);
        set_rating(rating);
        set_attendance(attendance);
        std::cout << "SConstructor:\t" << this <<std::endl;
    }

    ~Student() 
    {
        std::cout << "SDetructor:\t" << this << std::endl;
    }

    void info()const
    {
        Human::info();
        std::cout << speciality << " " << group << " " << rating << " " <<attendance<< std::endl;
    }

};

#define TEACHER_TAKE_PARAMETERS	const std::string& specialty, unsigned int experience
class Teacher :public Human
{
private:

    std::string specialty;
    unsigned int experience;

public:

    const std::string& get_specialty()const
    {
        return specialty;
    }

    unsigned int get_experience()const
    {
        return experience;
    }

    void set_specialty(const std::string& specialty)
    {
        this->specialty = specialty;
    }

    void set_experience(unsigned int experience)
    {
        this->experience = experience;
    }

    //				Constructor:
    Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
    {
        set_specialty(specialty);
        set_experience(experience);
        std::cout << "TConstructor:\t" << this << std::endl;
    }
    ~Teacher()
    {
        std::cout << "TDestructor:\t" << this << std::endl;
    }

    void info()const
    {
        Human::info();
        std::cout << specialty << " " << experience << " \n";
    }
};

class Graduate :public Student
{
private:

    std::string subject;

public:

    const std::string& get_subject()const
    {
        return subject;
    }
    void set_subject(const std::string& subject)
    {
        this->subject = subject;
    }
    Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject):Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
    {
        set_subject(subject);
        std::cout << "GConstructor:\t" << this << std::endl;
    }
    ~Graduate()
    {
        std::cout << "GDestructor:\t" << this << std::endl;
    }
    void info()const
    {
        Student::info();
        std::cout << subject << std::endl;
    }
};

#define TIME
#define NHERITANCE_CHECK
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


#ifdef INHERITANCE_CHECK
    Human human("Òóïåíêî", "Âàñèëèé", 1990, 04, 01);
    human.info();

    //Student student("Òóïåíêî", "Âàñèëèé", 1990, 04, 01, "IT", "start", 60, 30);
    Student student(human, "IT", "start", 60, 30);
    student.info();

    Teacher teacher("Einstein", "Albert", 1879, 03, 14, "Atronomy", 120);
    teacher.info();

    Graduate graduate("Abignale", "Frank", 1920, 01, 02, "Artist", "Criminal", 98, 11, "Foregry documents");
    graduate.info();

#endif // INHERITANCE_CHECK

    //Polymorphism
    /*
    ----------------
    Ad-Hoc polymorphism
    ----------------
    1. Pointer to base class
        (Generalisation - Îáîáùåíèå)
        Upcast - ïðåîáðàçîâàíèå äî÷åðíåãî îáúåêòà â áàçîâûé òèï.
    2. Virtual methods;
    */

    Human* group[] =
    {
        new Student("Pinkman", "Jessie", 1990, 03,04, "Chemistry", "WW_220", 90, 95),
        new Teacher("White", "Walter", 1960, 9, 20, "Chemistry", 25),
        new Graduate("Schrader", "Hank", 1970, 06,07, "Criminalistic", "WW_220", 75, 80, "How to catch Heizenberg"),
        new Student("Vercetty", "Tomas", 1970, 05, 25, "Criminalistic", "Vice", 90, 95),
        new Teacher("Diaz", "Ricardo", 1960, 03,03, "Weapons distribution", 20)
    };

    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
        group[i]->info();
        std::cout << "\n--------------------------------------------\n";
    }

    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
        delete group[i];
    }

}

