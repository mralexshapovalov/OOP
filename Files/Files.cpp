// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;



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
//
//std::ifstream input("201 RAW.txt"); //Открываешь первый файл для чтения
//std::string string; //Строка-буфер
//std::ofstream output("201 ready.txt"); //Открываешь второй файл для записи
//while (std::getline(input, string))  //Считываешь из файла строку (пока не EOF)
//output << string << std::endl;  //И записываешь эту строку в выходной файл
//system("pause");
//return 0;
//
// 
//std::ifstream ready;
//
//ready.open("201 ready.txt");
//
//
//if (ready.is_open())
//{
//
//    const int SIZE0 = 1500;
//    char sz_buffer0[SIZE0]{};
//
//    while (!ready.eof())
//    {
//
//        //fin >> sz_buffer;
//        ready.getline(sz_buffer0, SIZE0);
//        std::cout << sz_buffer0 << std::endl;
//    }
//    ready.close();
//
//   
//}
//
//else
//{
//    std::cerr << "Error:File not found" << std::endl;
//}
//
//
//
//
//
//}

std::ifstream fin;
fin.open("201 RAW.txt");
if (fin.is_open())
{
	const int size = _MAX_FNAME;
	char sz_bufer[size]{};//Áóôåð ôàéëà 
	char st_bufer[size]{};//Áóôåð èçìåíåííîãî ôàéëà	
	int size_st{};
	while (!fin.eof())
	{
		fin.getline(sz_bufer, size);
        std::cout << sz_bufer << std::endl;

		size_st = strlen(sz_bufer);//îïðåäåëÿåì ðàçìåð ñòðîêè äëÿ ïðîõîäà ïî íåé
		for (int i = 0, coll = 0; i < size_st; i++)
		{
			if (sz_bufer[i] == ' ' && coll == 0)
			{
				strcpy_s(st_bufer, size, sz_bufer + i + 8);
				coll++;
			}
			if (sz_bufer[i] == ' ')
			{
				strcat_s(st_bufer, size, " ");
			}
			if (sz_bufer[i] == ' ' && sz_bufer[i + 1] != ' ')
			{
				strncat(st_bufer, sz_bufer, i);
			}
		}

		char fillename[_MAX_FNAME] = { "201 ready.txt" };
        std::ofstream  fout;					//1)Ñîçäàåì ïîòîê
		fout.open(fillename, std::ios_base::app);//2) Îòêðûâàåì ïîòîê
		fout << st_bufer << std::endl;	//3)ïèøåì â ïîòîê
		system("notepad 201 ready.txt");
		fout.close();				//4)çàêðûâàåì ïîòîê çàïèñè		
	}
	fin.close();//çàêðûâàåì ïîòîê ÷òåíèÿ
}
else
{
	std::cerr << "Error: File not found" << std::endl;
	//cout -console out
	//cerr - console error
}


}

