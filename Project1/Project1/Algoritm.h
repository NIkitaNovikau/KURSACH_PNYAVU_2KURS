#pragma once
#include "Shablon.h"
#include"Iter.h"

template <class T>
class Algorithm
{
public:
	Algorithm();
	~Algorithm();
	Deque<T>& search(Node<T>* beg, T _obj);
	Deque<T>& search2(Node<T>* beg, Node<T>* end, T _obj);
	void sort(Deque<T>& _a);
};
