#include"Iter.h"

template<typename T>
Iter<T>& Iter<T>::operator++()
{
	if (ptr->next == NULL)
	{
		ptr = NULL;
		return *this;
	}
	ptr = ptr->next;
	return *this;
}

template<typename T>
Iter<T>& Iter<T>::operator--()
{
	if (ptr->pred == NULL)
	{
		ptr = NULL;
		return *this;
	}
	ptr = ptr->pred;
	return *this;
}

template<typename T>
T& Iter<T>::operator*()
{
	return ptr->node;
}

template<typename T>
Node<T>* Iter<T>::operator&()
{
	return ptr;
}

template<typename T>
bool Iter<T>::operator==(const Node<T>* tmp)
{
	if (this->ptr == tmp)
	{
		return true;
	}
	return false;
}

template<typename T>
bool Iter<T>::operator != (const Node<T>* tmp)
{
	if (this->ptr != tmp)
	{
		return true;
	}
	return false;
}

template<typename T>
Iter<T>& Iter<T>::operator=(const Node <T>& tmp)
{
	if (this->ptr != tmp)
	{
		ptr = tmp;
	}
	return *this;
}

