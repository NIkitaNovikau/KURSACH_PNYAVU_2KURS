#pragma once
#include<iostream>
#include"Shablon.h"

using namespace std;

template<typename T>
class Iter
{
private:
	Node<T>* ptr;
public:
	Iter()
	{
		ptr = NULL;
	}
	Iter(Node<T>* tmp)
	{
		ptr = tmp;
	}

	Iter(const Iter& tmp) : ptr(tmp.ptr) {}
	~Iter() { }

	Iter& operator++();

	Iter& operator--();

	T& operator*();

	Node<T>* operator & ();

	bool operator == (const Node<T>* tmp);

	bool operator != (const Node<T>* tmp);

	Iter& operator=(const Node<T>& tmp);
};