// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;



int main(void)
{

    setlocale(LC_ALL, "RUS");


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




