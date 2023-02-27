// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;


//#define WRITE_TO_FILE
//#define READ_TO_FILE
//#define FILE

int main(void)
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
	strcat_s(sz_connand, _MAX_FNAME, fileName);
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



	

	

#ifdef FILE
	
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

#endif // FILE



	std::ifstream file;
	file.open("201 RAW.txt");

	if (file.is_open())
	{

		const int SIZE = _MAX_FNAME;
		char sz_buffer[SIZE]{}; //zero-terminated string(sz)
		char st_bufer[SIZE]{};
		int size_st{};

		while (!file.eof())
		{

			/*fin >> sz_buffer;*/
			file.getline(sz_buffer, SIZE);
			std::cout << sz_buffer << std::endl;
			size_st = strlen(sz_buffer);

			for (int i = 0, coll = 0; i < size_st; i++)
			{
				if (sz_buffer[i] == ' ' && coll == 0)
				{
					strcpy_s(st_bufer, SIZE, sz_buffer + i + 8);
					coll++;
				}
				if (sz_buffer[i] == ' ')
				{
					strcat_s(st_bufer, SIZE, " ");
				}
				if (sz_buffer[i] == ' ' && sz_buffer[i + 1] != ' ')
				{
					strncat(st_bufer, sz_buffer, i);
				}
			}

			char fillename[SIZE] = { "201 ready.txt" };
			std::ofstream  fout;					//1)Ñîçäàåì ïîòîê
			fout.open(fillename, std::ios_base::app);//2) Îòêðûâàåì ïîòîê
			fout << st_bufer << std::endl;	//3)ïèøåì â ïîòîê
			
			fout.close();
		}


		file.close();




    }

	else
	{
		std::cerr << "Error:File not found" << std::endl;
	}

	system("notepad 201 ready.txt");
}









