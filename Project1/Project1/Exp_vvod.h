#pragma once
#include"Exception.h"

inline char* exp(istream& in)
{
    int fe;
    char* str = new char[80];
    do
    {
        rewind(stdin);
        try
        {
            fe = 0;
            in.getline(str, 80);
            for (int i = 0; str[i]; i++)
            {
                if (str[i] == ' ')
                    i++;
                if (!(str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))
                    i++;
                if ((str[i] >= 'А' && str[i] <= 'Я') || (str[i] >= 'а' && str[i] <= 'я'))
                    throw Exp_vvod(1, "Error: Написано не на английском языке");
            }
        }
        catch (Exp_vvod ob)
        {
            fe = 1;
            ob.show();
            rewind(stdin);
        }
    } while (fe);
    return str;
}

inline int enter()
{
    int x;
    bool flag;
    do
    {
        rewind(stdin);
        try
        {
            rewind(stdin);
            flag = false;
            cin >> x;
            if (!cin.good() || cin.peek() != '\n' ||  x < 0)
                throw overflow_error("Введено не целое число или отрицательное");
        }
        catch (overflow_error ob)
        {
            cin.clear();
            rewind(stdin);
            flag = true;
            cout << "Error: " << ob.what() << endl;
        }
    } while (flag);
    return x;
}

inline int enter(istream& in)
{
    int x;
    bool flag;
    do
    {
        rewind(stdin);
        try
        {
            rewind(stdin);
            flag = false;
            in >> x;
            if (!in.good() || in.peek() != '\n' || x < 0)
                throw overflow_error("Введено не целое число или отрицательное");
        }
        catch (overflow_error ob)
        {
            in.clear();
            rewind(stdin);
            flag = true;
            cout << "Error: " << ob.what() << endl;
        }
    } while (flag);
    return x;
}