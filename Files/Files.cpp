// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>

#define WRITE_TO_FILE
//#define READ_TO_FILE

int main()
{
    setlocale(LC_ALL, "RUS");

#ifdef WRITE_TO_FILE

    char fileName[_MAX_FNAME] = {};
    std::cout << "Введите имя файла:";
    std::cin.getline(fileName, _MAX_FNAME);
    if (strcmp(fileName + strlen(fileName) - 4, ".txt"))
        strcat_s(fileName, _MAX_FNAME, ".txt");

    std::ofstream fout;//1)Создаем поток:
    fout.open(fileName, std::ios_base::app); //2)Открываем поток

    fout << "Hello files"; //3)Пишем поток

    fout.close();                       //4)Закрываем поток
    char sz_connand[_MAX_FNAME] = "notepad ";
    strcat_s(sz_connand,_MAX_FNAME, fileName);
    system(sz_connand);

#endif // DEBUG



#ifdef READ_TO_FILE

    std::ifstream fin;

    fin.open("File.txt");

    if (fin.is_open())
    {

        const int SIZE = 1500;
        char sz_buffer[SIZE]{};

        while (!fin.eof())
        {

            /*fin >> sz_buffer;*/
            fin.getline(sz_buffer, SIZE);
            std::cout << sz_buffer << std::endl;
        }
        fin.close();


}
    else
    {
        std::cerr << "Error:File not found" << std::endl;
    }

#endif // DEBUG


  
   

}
