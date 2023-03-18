#pragma once
#include<iostream>

using namespace std;

class Exp_vvod
{
private:
	int nm;
	char ch[80];
public:
	Exp_vvod(const Exp_vvod& num)
	{
		nm = num.nm;
		strcpy_s(ch, strlen(num.ch) + 1, num.ch);
	}
	Exp_vvod(int number, const char* str)
	{
		strcpy_s(ch, strlen(str) + 1, str);
		nm = number;
	}
	void show()
	{
		for (int i = 0; ch[i]; i++)
		{
			cout << ch[i];
		}
		cout << endl;
	}
	~Exp_vvod()
	{ }
};