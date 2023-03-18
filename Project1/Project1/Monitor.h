#pragma once
#include"Monitor.h"
#include<iostream>
#include "Devices.h"
#include "String.h"

using namespace std;

class Monitor : public Devices
{
protected:
	String screenResolution;
	int numberOfInches;

public:
	Monitor() : Devices()
	{
		numberOfInches = 0;
	}
	Monitor(char* _screenResolution,int _numberOfInches  , char* _yearOfIssue, char* _brand , int cost) : Devices(_yearOfIssue, _brand, cost)
	{
		this->screenResolution = _screenResolution;
		this->numberOfInches = _numberOfInches;
	}

    String getScreenResolution() { return screenResolution; }			
	void  setScreenResolution(const String os) { this->screenResolution = os; }
	int getNumberOfInches() { return numberOfInches; }
	void  setNumberOfInches(const int os) { this->numberOfInches = os; }

	friend ostream& operator<<(ostream& on, Monitor& ss);
	friend istream& operator>>(istream& in, Monitor& ss);

	friend void operator <<= (ostream& stream, Monitor& tmp);
	friend void operator >>= (istream& is, Monitor& tmp);

	friend void operator <= (ostream& os, Monitor& tmp);
	friend void operator >= (istream& is, Monitor& tmp);

	Monitor& operator=(const Monitor& other);
	bool operator==(Monitor& other);
	bool operator==( char* other);
	bool operator > (const Monitor& tmp);

	~Monitor()
	{ }
};
