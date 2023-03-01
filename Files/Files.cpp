// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<direct.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	const int IP_MAX_SIZE = 16;
	const int MAC_MAX_SIZE = 18;

	char sz_ip_buffer[IP_MAX_SIZE] = {};
	char sz_mac_buffer[MAC_MAX_SIZE] = {};

	std::ifstream fin("201 RAW.txt");
	if (fin.is_open())
	{
		std::ofstream fout("201.txt");
		while (!fin.eof())
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
			fout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
		}
		fout.close();

		fout.open("result\\201.dhcpd");
		fin.clear();
		fin.seekg(0);
		for (int i = 1; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			for (int i = 0; sz_mac_buffer[i]; i++)
				if (sz_mac_buffer[i] == '-')sz_mac_buffer[i] = ':';
			if (strlen(sz_ip_buffer) == strlen(sz_mac_buffer))continue;
			cout << "host-" << i << "\n";
			cout << "{\n";
			cout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			cout << "\tfiexd-address\t\t" << sz_ip_buffer << ";\n";
			cout << "}\n";
			cout << endl;

			fout << "host-" << i << "\n";
			fout << "{\n";
			fout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			fout << "\tfiexd-address\t\t" << sz_ip_buffer << ";\n";
			fout << "}\n";
			fout << endl;
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

	system("notepad 201.txt");
	system("notepad 201.dhcpd");
}










