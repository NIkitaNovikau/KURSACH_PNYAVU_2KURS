#pragma once
#include<iostream>
#include"Mouse.h"
#include "String.h"

using namespace std;

class wiredMouse : public Mouse
{
protected:
    int responseTime;       //время отклика
    int wireLength;  //длина провода
    String scrollingWay;  //сп-б прокрутки
public:
    wiredMouse() : Mouse()
    {
        this->responseTime = 0;
        this->wireLength = 0;
    }
    wiredMouse(char* _scrollingWay, int _wireLength, int _responseTime, char* _mouseSensitivity, char* _material, char* _yearOfIssue, char* _brand, int cost)
        : Mouse(_mouseSensitivity, _material, _yearOfIssue, _brand, cost)
    {
        this->scrollingWay = _scrollingWay;
        this->wireLength = _wireLength;
        this->responseTime = _responseTime;
    }
    String getScrollingWay() { return this->scrollingWay; }
    void setScrollingWay(const String os) { this->scrollingWay = os; }
    int getResponseTime() { return this->responseTime; }
    void setResponseTime(const int os) { this->responseTime = os; }
    int getWireLength() { return this->wireLength; }
    void setWireLength(const int os) { this->wireLength = os; }

    friend ostream& operator<<(ostream& on, wiredMouse& ss);
    friend istream& operator>>(istream& in, wiredMouse& ss);

    friend void operator <<= (ostream& stream, wiredMouse& tmp);
    friend void operator >>= (istream& is, wiredMouse& tmp);

    friend void operator <= (ostream& os, wiredMouse& tmp);
    friend void operator >= (istream& is, wiredMouse& tmp);

    wiredMouse& operator=(const wiredMouse& other);
    bool operator==(wiredMouse& other);
    bool operator==( char* other);
    bool operator > (const wiredMouse& tmp);

    ~wiredMouse()
    { }
};