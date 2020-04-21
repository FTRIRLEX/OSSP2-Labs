#include "stdafx.h"
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include "conio.h"
#include <bitset>

using std::string;

string line = "aabcdabcddaabcddacd";

string *symbl = new string[line.length()];
string *code = new string[line.length()];

bool checkLine(string st, int sz)
{
	bool flag = false;
	for (int i = 0; i < sz; i++)
	{
		//std::cout << st << " " << symbl[i] << std::endl;

		if (symbl[i] == st)
		{
			flag = true;
		}
	}
	return flag;
}

bool pvp(string st, int sz)
{
	bool flag = false;
	for (int i = 0; i < sz; i++)
	{
		//std::cout << st << " " << symbl[i] << std::endl;

		if (symbl[i] == st)
		{
			flag = true;
		}
	}
	return flag;
}

int main()
{
	int s = 0, sN = 0;
	string buf = "";

	for (int i = 0; i < line.length(); i++)
	{
		buf += line[i];
		if (!checkLine(buf, s))
		{
			symbl[s++] = buf;
			buf = "";
		}
	}

	string binary;

	for (int i = 1; i <= s; i++)
	{
		binary = std::bitset<4>(i).to_string();
		code[i-1] = binary;
	}

	for (int i = 0; i < s; i++)
	{
		std::cout << "SYMBL: " << symbl[i]<<" "<< code[i]<< std::endl;
	}

	string temp;
	buf = "";
	for (int i = 0; i < s - 1; i++) {
		for (int j = 0; j < s - i - 1; j++) {
			if (symbl[j].length() < symbl[j + 1].length()) {
				//std::cout << "SYMBL: " << symbl[j] << " " << code[j] << std::endl;

				temp = symbl[j];
				buf = code[j];
				symbl[j] = symbl[j + 1];
				code[j] = code[j + 1];
				symbl[j + 1] = temp;
				code[j + 1] = buf;
				//std::cout << "SYMBL: " << symbl[j] << " " << code[j] << std::endl;

			}
		}
	}
	for (int i = 0; i < s; i++)
	{
		//std::cout << "SYMBL: " << symbl[i]<<" "<< code[i]<< std::endl;
	}

	buf = "";
	for (int i = 0; i < line.length(); i++)
	{
		for (int j = 0; j < s; j++)
		{
			buf = line.substr(i, symbl[j].length());
			if (buf == symbl[j]) {
				i += symbl[j].length()-1;
				std::cout << " SYMBL: " << buf << "=" << code[j] << std::endl;
				break;
			}
		}
	}


	system("pause");
    return 0;
}