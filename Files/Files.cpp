// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include<fstream>

//#ifdef READ_TO_FILE
//
//std::ifstream fin;
//
//fin.open("File.txt");
//
//if (fin.is_open())
//{
//
//    const int SIZE = 1500;
//    char sz_buffer[SIZE]{};
//
//    while (!fin.eof())
//    {
//
//        /*fin >> sz_buffer;*/
//        fin.getline(sz_buffer, SIZE);
//        std::cout << sz_buffer << std::endl;
//    }
//    fin.close();
//
//
//}
//else
//{
//    std::cerr << "Error:File not found" << std::endl;
//}
//
//#endif // DEBUG

//#define SAVE_FILE

//#define WHRITE_TO_FILE
  #define READ_FROM_FILE

int main(void)
{
    
    setlocale(LC_ALL, "RUS");


#ifdef SAVE_FILE

    std::string path = "myFile.txt";

    std::ofstream fout;

    fout.open(path, std::ofstream::app);

    if (!fout.is_open())
    {

        std::cout << "Ошибка открытия файла" << std::endl;

    }
    else
    {
        std::cout << "Ввелите число";
        int a;
        std::cin >> a;
        fout << a;
        fout << "Открытие файла";
    }


    fout.close();
#endif // SAVE_FILE

#ifdef WHRITE_TO_FILE

    std::ofstream fout; //1)Создаем поток
    fout.open("Fill.txt", std::ios::app);//2)Открываем поток
    //std::ios::app-append,не переписывать
    //3)Пишем поток:


    fout << "HelloFile" << std::endl;
    fout.close();//Закрываем поток


    system("notpad Fill.txt");//Функция system()запускает любую программы к которой есть PATH в Windows (PATH-Путь)

#endif // DEBUG

    //FILE* fp = fopen("https://github.com/okovtun/PV_225/blob/master/Inheritance/Files/NetworkTask/201%20RAW.txt", "r");
    ////std::ifstream fin("Fill.txt"); //Поток открывается прямо при создании

    //if (fp.is_open())
    //{
    //    //Будем читать файл
    //    const int SIZE = 256;//Буфер
    //    char buffer[SIZE] = {};
    // 
    //    while (!*fp.eof())
    //    {
    //        
    //        fin.getline(buffer, SIZE);

    //        /*fin >> buffer;*/
    //        std::cout << buffer <<std::endl;

    //    }
    //    fin.close();
    //}

    //else
    //{
    //    std::cerr << "Error:file not found" <<std:: endl;
    //}

   




//std::ifstream fin;
//
//fin.open("201 RAW.txt");
//
//
//if (fin.is_open())
//{
//
//    const int SIZE = 1500;
//    char sz_buffer[SIZE]{};
//
//    while (!fin.eof())
//    {
//
//        //fin >> sz_buffer;
//        fin.getline(sz_buffer, SIZE);
//        std::cout << sz_buffer << std::endl;
//    }
//    fin.close();
//
//   
//}
//
// else
// {
//    std::cerr << "Error:File not found" << std::endl;
// }

std::ifstream input("201 RAW.txt"); //Открываешь первый файл для чтения
std::string string; //Строка-буфер
std::ofstream output("201 ready.txt"); //Открываешь второй файл для записи
while (std::getline(input, string))  //Считываешь из файла строку (пока не EOF)
output << string << std::endl;  //И записываешь эту строку в выходной файл
system("pause");
return 0;

 
std::ifstream ready;

ready.open("201 ready.txt");


if (ready.is_open())
{

    const int SIZE0 = 1500;
    char sz_buffer0[SIZE0]{};

    while (!ready.eof())
    {

        //fin >> sz_buffer;
        ready.getline(sz_buffer0, SIZE0);
        std::cout << sz_buffer0 << std::endl;
    }
    ready.close();

   
}

else
{
    std::cerr << "Error:File not found" << std::endl;
}





}

