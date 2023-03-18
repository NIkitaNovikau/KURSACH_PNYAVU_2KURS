#pragma once
#include<iostream>
#include "String.h"
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

class Devices
{
protected:
    String yearOfIssue;
    String brand;
    int cost;
public:

    Devices()
    {
        this->cost = 0;
    }
    Devices(char* _yearOfIssue, char* _brand, int cost)
    {
        this->yearOfIssue = _yearOfIssue;
        this->brand = _brand;
        this->cost = cost;
    }

    friend ostream& operator<<(ostream& on, Devices& ss);
    friend istream& operator>>(istream& in, Devices& ss);

    friend void operator <<= (ostream& stream, Devices& tmp);
    friend void operator >>= (istream& is, Devices& tmp);

    friend void operator <= (ostream& os, Devices& tmp);
    friend void operator >= (istream& is, Devices& tmp);

    inline String getName() { return yearOfIssue; }                
    inline void setName(const String os) { this->yearOfIssue = os; }
    inline String getBrand() { return brand; }
    inline void setBrand(const String os) { this->brand = os; }
    inline int getCost() { return cost; }
    inline void setCost(const int os) { this->cost = os; }

    Devices& operator=(const Devices& other);
    bool operator==(Devices& other);
    bool operator==(char* other);
    bool operator > (const Devices& tmp);

    ~Devices()
    { }
};



