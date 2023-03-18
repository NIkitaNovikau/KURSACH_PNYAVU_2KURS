#pragma once
#include <iostream>
#include<vector>

using namespace std;
using std::bad_alloc;

template <typename T>
struct Node
{
	T node;//само значение
	Node* next;//указатель на след элемент
	Node* pred;//указатель на пред элемент
};

template <typename T>
class Deque
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
	template <typename T>
	friend class Iter;
public:

	Deque()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	~Deque()
	{
		delet();
	}
	Node<T>* Begin() { return head; }
	Node<T>* End() { return tail; }
	void Push(T tmp);
	int show_size();
	void show(int index);
	void pop(int index);
	void pop_any(T value);
	void delet();
	vector<T> get();
};
