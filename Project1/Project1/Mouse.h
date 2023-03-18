#pragma once
#include<iostream>
#include "Devices.h"


using namespace std;

class Mouse : public Devices
{
protected:
    String material;
    String mouseSensitivity;

public:
    Mouse()
    {

    }
    Mouse(char* _mouseSensitivity, char* _material, char* _yearOfIssue, char* _brand, int cost) :Devices(_yearOfIssue, _brand, cost)
    {
        this->mouseSensitivity = _mouseSensitivity;
        this->material = _material;
    }

    inline String getMouseSensitivity() { return this->mouseSensitivity; }
    inline void setMouseSensitivity(const String os) { this->mouseSensitivity = os; }
    inline String getMaterial() { return this->material; }
    inline void setMaterial(const String os) { this->material = os; }

    friend ostream& operator<<(ostream& on, Mouse& ss);
    friend istream& operator>>(istream& in, Mouse& ss);

    friend void operator <<= (ostream& stream, Mouse& tmp);
    friend void operator >>= (istream& is, Mouse& tmp);

    friend void operator <= (ostream& os, Mouse& tmp);
    friend void operator >= (istream& is, Mouse& tmp);

    Mouse& operator=(const Mouse& other);
    bool operator==(Mouse& other);
    bool operator==(char* other);
    bool operator > (const Mouse& tmp);

    ~Mouse()
    { }
};