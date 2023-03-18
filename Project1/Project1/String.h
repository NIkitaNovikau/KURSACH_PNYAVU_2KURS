#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include"Exp_vvod.h"

using namespace std;

class String
{
private:
    char* str;
    long int length;
public:

    String(const char* p)
    {
        if (p == NULL)
        {
            this->length = 0;
            this->str = new char[this->length + 1];
            strcpy(this->str, "");
        }
        else
        {
            length = strlen(p);
            this->str = new char[this->length + 1];
            strcpy(this->str, p);
        }
    }
    String(int _length = 100)
    {
        this->length = _length;
        this->str = new char[this->length + 1];
        strcpy(this->str, "");
    }
    //конструктор
    String(char str[]) 
    {
        this->length = strlen(str);
        this->str = new char[this->length + 1];
        strcpy(this->str, str);
    }
    //конструктор копирования
    String(const String& str)
    {
        this->length = str.length;
        this->str = new char[this->length + 1];
        strcpy(this->str, str.str);
    }
    friend ostream& operator<<(ostream& on, String& ss);
    friend istream& operator>>(istream& in, String& ss);

    String& operator=(const String& other);
    String& operator+= (String const& other);
    String operator()(int index1, int length);
    String operator+(const String& other);

    bool operator==(const String& tmp);
    bool operator == (const char* tmp);
    bool operator!=(const String& other);
    bool operator<(const String& other);
    bool operator>(const String& other);

    char& operator[](int index);

    void operator = (char* str);
    void operator = (const char str[]);
    char* c_str()
    {
        return this->str;
    }

    int slength()
    {
        return this->length;
    }
    ~String()
    {
        delete[] this->str;
    }

};
