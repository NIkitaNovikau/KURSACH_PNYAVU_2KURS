#pragma once

//классы для работы с данными
#include<iostream>
#include"Shablon.cpp"
#include"locale.h"
#include"windows.h"
#include "Mouse.h"
#include"touchMouse.h"
#include "Devices.h"
#include"wiredMouse.h"
#include"Monitor.h"
#include"LCD.h"
#include"PDP.h"
#include<iomanip>
#include"TextFile.cpp"
#include"Iter.cpp"
#include"Algoritm.cpp"
#include<vector>

using namespace std;

inline void shapka(int nm);

template<typename T>
void ADM(Deque<T> _c, T _a , int _k);
template<typename T>
void USER(Deque<T> _c, T _a, int _k);

inline int MenuADM();
inline int MenuUSER();
