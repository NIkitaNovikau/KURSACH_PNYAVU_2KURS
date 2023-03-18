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
		Node<T>* tmp1 = new Node<T>;            //�������� ������ ��� �������
		tmp1->node = tmp;
		tmp1->next = nullptr;
		tmp1->pred = nullptr;
		if (!head || !tail) // ������� �� �������
		{
			tail = tmp1; //��������� �� ����� �������
			head = tmp1; //��������� �� ������ �������
		}
		else
		{
			tmp1->next = head;//��������� �� ����� �������
			head->pred = tmp1;//������ ���� ����� �������
			head = tmp1;//�������� ��������� ������ �� ����� �������
		}
	}
	catch (bad_alloc e)
	{
		cout << "\n ���������� bad_alloc: ���������� ���������� ������ � ������" << e.what() << endl;
		return;
	}

}

//������� ������ ������� ���� index == 0 �� � ������ ��� � ������ == 1
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
			cout << "������� ����� " << endl;
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
			cout << "������� ����� " << endl;
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
			cout << "\n������ �������������: "
				"�������� ���� 0(�����) , ���� 1(������)";
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
			cout << "������� ������";
			return;
		}
		if (index == 0)//���� �����
		{
			Node<T>* n = tail;
			tail = tail->next;
			tail->pred = NULL;
			delete n;
			size--;
		}
		else if (index == 1)//���� ������
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
			cout << "\n������ �������������: "
				"�������� ���� 0(�����) , ���� 1(������)";
			return;
		}

	}
}

template<typename T>
void Deque<T>::pop_any(T value)
{
	Node<T>* n = tail;//������ �� ����� �������

	if (!head || !tail)
	{
		cout << "������� ������";
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
	}//���� �� ������ ��� �� �������

	if ((n->node == value))//������ �������
	{
		if (n == tail)//���� �����
		{
			tail = tail->next;
			tail->pred = nullptr;
		}
		else if (n == head)//���� ������
		{
			head = head->pred;
			head->next = nullptr;
		}
		else//���� ���-�� ������
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
	//cout << "������: " << size << endl;
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
