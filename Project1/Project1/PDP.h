#pragma once
#include<iostream>
#include"Monitor.h"

using namespace std;

class PDP : public Monitor
{
protected:
    String plasma;
    String brightnessLevel;

public:
    PDP() : Monitor()
    {

    }
    PDP(char* _plasma, char* _brightnessLevel, char* _screenResolution,int _numberOfInches, char* _yearOfIssue, char* _brand,int cost)
        : Monitor(_screenResolution, _numberOfInches, _yearOfIssue, _brand, cost)
    {
        this->plasma = plasma;
        this->brightnessLevel = _brightnessLevel;
    }

    String getPlasma() { return plasma; }
    void setPlasma(const String os) { this->plasma = os; }
    String getBrightnessLevel() { return brightnessLevel; }
    void setBrightnessLevel(const String os) { this->brightnessLevel = os; }

    friend ostream& operator<<(ostream& on, PDP& ss);
    friend istream& operator>>(istream& in, PDP& ss);

    friend void operator <<= (ostream& stream, PDP& tmp);
    friend void operator >>= (istream& is, PDP& tmp);

    friend void operator <= (ostream& os, PDP& tmp);
    friend void operator >= (istream& is, PDP& tmp);

    PDP& operator=(const PDP& other);
    bool operator==(PDP& other);
    bool operator==( char* other);
    bool operator > (const PDP& tmp);

    ~PDP()
    { }
};