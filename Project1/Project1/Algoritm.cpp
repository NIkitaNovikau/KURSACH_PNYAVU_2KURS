#include"Algoritm.h"

template <class T>
Algorithm<T>::Algorithm()
{
}

template <class T>
Algorithm<T>::~Algorithm()
{
}

template<class T> 
Deque<T>& Algorithm<T>::search(Node<T>* beg, T _obj)
{
	Node<T>* rab = beg;
	Deque<T> temp;

	while (rab != NULL)
	{
		if (rab->node == _obj)
		{
			cout << rab->node;
			temp.Push(rab->node);
		}
		rab = rab->next;
	}
	return temp;
}

template<class T> 
Deque<T>& Algorithm<T>::search2(Node<T>* beg, Node<T>* end, T _obj)
{
	Node<T>* rab = beg;
	Deque<T> temp;
	Iter<T> it;
	for (it = beg; it != end->next; ++it)
	{
		if (*it == _obj)
		{
			cout << *it;
			temp.Push(*it);
		}
	}
	return temp;
}

template<class T> 
void Algorithm<T>::sort(Deque<T>& a)
{
	Node<T>* tmp = new Node<T>;
	Iter<T> it_beg = a.Begin();
	Iter<T> it_next = a.Begin()->next;
	while (it_beg != NULL)
	{
		it_next = it_beg;
		++it_next;
		while (it_next != NULL)
		{
			if ((*it_beg) > (*it_next))
			{
				tmp->node = *it_beg;
				*it_beg = *it_next;
				*it_next = tmp->node;
			}
			++it_next;
		}
		++it_beg;
	}
}