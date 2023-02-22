// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>



//char fileName[_MAX_FNAME] = {};
//std::cout << "Введите имя файла:";
//std::cin.getline(fileName, _MAX_FNAME);
//if (strcmp(fileName + strlen(fileName) - 4, ".txt"))
//strcat_s(fileName, _MAX_FNAME, ".txt");
//
//std::ofstream fout;//1)Создаем поток:
//fout.open(fileName, std::ios_base::app); //2)Открываем поток
//
//fout << "Hello files"; //3)Пишем поток
//
//fout.close();                       //4)Закрываем поток
//char sz_connand[_MAX_FNAME] = "notepad ";
//strcat_s(sz_connand, _MAX_FNAME, fileName);
//system(sz_connand);
//
//#endif // DEBUG
//
//
//
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

int main()
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

    std::ifstream fin("Fill.txt"); //Поток открывается прямо при создании

    if (fin.is_open()) 
    {
        //Будем читать файл
        const int SIZE = 256;//Буфер
        char buffer[SIZE] = {};
     
        while (!fin.eof()) 
        {

            fin.getline(buffer, SIZE);

            /*fin >> buffer;*/
            std::cout << buffer <<std::endl;

        }
        fin.close();
    }

    else
    {
        std::cerr << "Error:file not found" <<std:: endl;
    }

   

}
