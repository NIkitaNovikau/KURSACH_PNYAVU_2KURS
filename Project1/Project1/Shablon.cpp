#include"Shablon.h"

template<typename T>
vector<T> Deque<T>::get()
{
	vector<T> v;
	Iter<T> it;
	for (it = this->Begin(); it != this->End()->next; ++it)
	{
		v.push_back(*it);
	}
	return v;
}

template <typename T>
void Deque<T>::Push(T tmp)
{
	try
	{
		++size;
		Node<T>* tmp1 = new Node<T>;            //выделяем память под элемент
		tmp1->node = tmp;
		tmp1->next = nullptr;
		tmp1->pred = nullptr;
		if (!head || !tail) // очередь не создана
		{
			tail = tmp1; //указатель на хвост очереди
			head = tmp1; //указатель на начало очереди
		}
		else
		{
			tmp1->next = head;//указатель на хвост очереди
			head->pred = tmp1;//хвосту даем новый элемент
			head = tmp1;//передвиг указатель хвоста на новый элемент
		}
	}
	catch (bad_alloc e)
	{
		cout << "\n Исключение bad_alloc: невозможно разместить данные в памяти" << e.what() << endl;
		return;
	}

}

//функция вывода очереди если index == 0 то с хвоста или с головы == 1
template<typename T>
void Deque<T>::show(int index)
{
	try
	{
		Node<T>* n = tail;
		Node<T>* m = head;
		if (index != 0 && index != 1)
			throw 1;
		if (!tail)
		{
			cout << "Очередь пуста " << endl;
			return;
		}
		if (index == 0) {
			while (n)
			{
				cout << n->node;
				n = n->next;
			}
		}
		if (!head)
		{
			cout << "Очередь пуста " << endl;
			return;
		}
		if (index == 1) {
			while (n)
			{
				cout << n->node;
				n = n->pred;
			}
		}
		return;
	}
	catch (int i)
	{
		if (i == 1)
		{
			cout << "\nОшибка инициализации: "
				"выберете либо 0(хвост) , либо 1(голова)";
			return;
		}
	}
}

template<typename T>
void Deque<T>::pop(int index)
{
	try
	{
		if (index != 0 && index != 1)
			throw 1;
		if (!head || !tail)
		{
			cout << "Очередь пустая";
			return;
		}
		if (index == 0)//если хвост
		{
			Node<T>* n = tail;
			tail = tail->next;
			tail->pred = NULL;
			delete n;
			size--;
		}
		else if (index == 1)//если голова
		{
			Node<T>* n = head;
			head = head->pred;
			head->next = NULL;
			delete n;
			size--;
		}
	}
	catch (int i)
	{
		if (i == 1)
		{
			cout << "\nОшибка инициализации: "
				"выберете либо 0(хвост) , либо 1(голова)";
			return;
		}

	}
}

template<typename T>
void Deque<T>::pop_any(T value)
{
	Node<T>* n = tail;//указат на хвост очереди

	if (!head || !tail)
	{
		cout << "Очередь пустая";
		return;
	}
	if (n->next == NULL && (n->node == value))
	{
		delete n;
		size--;
		tail = head = nullptr;
		return;
	}
	while (n && !(n->node == value))
	{
		n = n->next;
	}//идем до хвоста или до элемент

	if ((n->node == value))//найден элемент
	{
		if (n == tail)//если хвост
		{
			tail = tail->next;
			tail->pred = nullptr;
		}
		else if (n == head)//если голова
		{
			head = head->pred;
			head->next = nullptr;
		}
		else//если что-то другое
		{
			n->pred->next = n->next;
			n->next->pred = n->pred;
		}
		delete n;
		size--;
	}
}
template<typename T>
int Deque<T>::show_size()
{
	//cout << "Размер: " << size << endl;
	return size;
}

template<typename T>
void Deque<T>::delet()
{
	while (head != nullptr)
	{
		Node<T>* n = head->next;
		delete head;
		head = n;
	}
	tail = nullptr;
	size = 0;
}
