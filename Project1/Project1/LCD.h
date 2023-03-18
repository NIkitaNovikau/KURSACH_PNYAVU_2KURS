#pragma once
#include<iostream>
#include"Monitor.h"

class LCD : public Monitor
{
protected:
   String matrix;
   int turnOnSpeed;

public:
    LCD() : Monitor()
    {
        this->turnOnSpeed = 0;
    }
    LCD(char* _matrix, int _turnOnSpeed , char* _screenResolution,int _numberOfInches, char* _yearOfIssue, char* _brand,int cost)
        : Monitor(_screenResolution, _numberOfInches,_yearOfIssue, _brand, cost )
    {
        this->matrix = _matrix;
        this->turnOnSpeed = _turnOnSpeed;
    }

    String getMatrix() { return matrix; }
    void setMatrix(const String os) { this->matrix = os; }
    int getTurnOnSpeed() { return turnOnSpeed; }
    void setTurnOnSpeed(const int os) { this->turnOnSpeed = os; }

    friend ostream& operator<<(ostream& on, LCD& ss);
    friend istream& operator>>(istream& in, LCD& ss);

    friend void operator <<= (ostream& stream, LCD& tmp);
    friend void operator >>= (istream& is, LCD& tmp);

    friend void operator <= (ostream& os, LCD& tmp);
    friend void operator >= (istream& is, LCD& tmp);

    LCD& operator=(const LCD& other);
    bool operator==(LCD& other);
    bool operator==( char* other);
    bool operator > (const LCD& tmp);

    ~LCD()
    { }
};