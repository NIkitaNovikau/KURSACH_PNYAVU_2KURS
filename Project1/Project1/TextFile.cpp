#include"TextFile.h"

template<class T>
void textFile<T>::toFile(T& obj, string _filename)
{
	ofstream ofs(_filename, ofstream::app);
	if (!ofs)
	{
		cout << "Не удалось открыть файл: " << _filename;
		system("pause");
		return;
	}
	ofs <<= obj;
	ofs.close();
}

template<class T>
void textFile<T>::fromFile(T& obj, string _filename, int i)
{
	ifstream ifs(_filename, ifstream::in);
	if (!ifs)
	{
		cout << "Не удалось открыть файл: " << _filename;
		system("pause");
		return;
	}
	string s;
	while (i > 0)
	{
		getline(ifs, s);
		i--;
	}
	ifs >>= obj;
	ifs.close();
}

template<class T>
int textFile<T>::checkCount(string _filename)
{
	ifstream ifs(_filename, ifstream::in);
	if (!ifs)
	{
		cout << "Не удалось открыть файл: " << _filename;
		system("pause");
		return -1;
	}
	int count = 0;
	string s;
	while (getline(ifs, s))
	{
		count++;
	}
	ifs.close();
	return count;
}

template<class T>
void textFile<T>::clear(string _filename)
{
	ofstream ofs(_filename, ofstream::out);
	ofs.close();
}
