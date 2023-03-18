#pragma once
#include<iostream>
#include"Mouse.h"


using namespace std;

class touchMouse : public Mouse
{
protected:
    int numberOfSensors;
    String cursorFrequency;
public:
    touchMouse() : Mouse() 
    {
        this->numberOfSensors = 0;
    }
    touchMouse(char* _cursorFrequency, int _numberOfSensors , char* _mouseSensitivity, char* _material, char* _yearOfIssue, char* _brand, int cost)
        : Mouse(_mouseSensitivity, _material, _yearOfIssue, _brand, cost)
    {
        this->cursorFrequency = _cursorFrequency;
        this->numberOfSensors = _numberOfSensors;
    }
    String getCursorFrequency() { return this->cursorFrequency; }
    void setCursorFrequency(const String os) { this->cursorFrequency = os; }
    int getNumberOfSensors() { return this->numberOfSensors; }
    void setNumberOfSensors(const int os) { this->numberOfSensors = os; }

    friend ostream& operator<<(ostream& on, touchMouse& ss);
    friend istream& operator>>(istream& in, touchMouse& ss);

    friend void operator <<= (ostream& stream, touchMouse& tmp);
    friend void operator >>= (istream& is, touchMouse& tmp);

    friend void operator <= (ostream& os, touchMouse& tmp);
    friend void operator >= (istream& is, touchMouse& tmp);

    touchMouse& operator=(const touchMouse& other);
    bool operator==(touchMouse& other);
    bool operator==(char* other);
    bool operator > (const touchMouse& tmp);

    ~touchMouse()
    { }
};