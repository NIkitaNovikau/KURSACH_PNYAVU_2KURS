#pragma once
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

template<class T>
class textFile
{
public:
	textFile() {};
	textFile(string _title);
	~textFile() {};
	void toFile(T& obj, string _filename);
	void fromFile(T& obj, string _filename, int i);
	int checkCount(string _filename);
	void clear(string _filename);

};
