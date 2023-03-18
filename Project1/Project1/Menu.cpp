#pragma once
#include "Menu.h"

void shapka(int nm)
{
	if (nm == 1)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << setiosflags(ios::left)
			<< setw(13) << "Год_выпуска"
			<< setw(11) << "Бренд"
			<< setw(10) << "Цена"
			<< setw(14) << "Чувст. мыши"
			<< setw(12) << "Город"
			<< setw(17) << "Частота курсора"
			<< setw(15) << "Кол-во датчиков"
			<< endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
	}
	if (nm == 2)
	{
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << setiosflags(ios::left)
			<< setw(13) << "Год_выпуска"
			<< setw(10) << "Бренд"
			<< setw(10) << "Цена"
			<< setw(14) << "Чувст. мыши"
			<< setw(12) << "Материал"
			<< setw(15) << "Улица"
			<< setw(17) << " Длина провода"
			<< setw(13) << "Время отклика"
			<< endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
	}
	if (nm == 3)
	{
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << setiosflags(ios::left)
			<< setw(13) << "Год_выпуска"
			<< setw(12) << "Бренд"
			<< setw(10) << "Цена"
			<< setw(15) << "Разреш. экрана"
			<< setw(15) << "Кол-во дюймов"
			<< setw(14) << "Mатрица"
			<< setw(11) << "Время вкл."
			<< endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
	}
	if (nm == 4)
	{
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << setiosflags(ios::left)
			<< setw(13) << "Год_выпуска"
			<< setw(10) << "Бренд"
			<< setw(10) << "Цена"
			<< setw(16) << "Разреш. экрана"
			<< setw(16) << "Кол-во дюймов"
			<< setw(12) << "Плазма"
			<< setw(10) << "Яркость"
			<< endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
	}
}

template<typename T>
void USER(Deque<T> _c, T _a, int _k)
{
	Deque<T>* data1 = new Deque<T>;
	Algorithm<T> alg;
	string k;
	T* tmp1;
	int z = 10;
	tmp1 = new T[z];
	T ss;
	int w;
	while (1)
	{
		cout << endl << "Выбери операцию" << endl;
		cout <<"1-Сортировка по контейнеру" << endl <<"2-поиск по контейнеру" << endl << "3-поиск по контейнеру с итератором" << endl 
			<< "4-Прочесть файл" << endl << "5-Выход" << endl;
		w = enter();
		switch (w)
		{
		case 1:
		{
			system("cls");
			shapka(_k);
			data1->show(1);
			alg.sort(*data1);
			cout << endl << "После сортировки" << endl;
			shapka(_k);
			data1->show(1);
			break;
		}
		case 2:
		{
			system("cls");
			shapka(_k);
			data1->show(1);
			cin >> ss;
			alg.search(data1->Begin(), ss);
			break;
		}
		case 3:
		{
			system("cls");
			shapka(_k);
			data1->show(1);
			cin >> ss;
			alg.search2(data1->Begin(), data1->End(), ss);
			break;
		}
		case 4:
		{
			system("cls");
			textFile<T> b;
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			int count;
			count = b.checkCount(q);
			for (int i = 0; i < count; i++)
			{
				z++;
				b.fromFile(tmp1[i], q, i);
				data1->Push(tmp1[i]);

			}
			cout << "Данные успешно считаны из файла." << endl;
			shapka(_k);
			data1->show(1);
			break;

		}
		case 5:
		{
			return;
		}
		}
	}
}

template<typename T>
void ADM(Deque<T> _c, T _a , int _k)
{
	system("cls");
	Deque<T>* data1 = new Deque<T>;
	string k;
	T* tmp1;
	textFile<T> b;
	Algorithm<T> alg;
	vector<T> vect;
	T s;
	T ss;
	int w;
	int z;
	int count;
	cout << "Выделить память " << endl;
	cin >> z;
	int cc;
	tmp1 = new T[z];
	for (int i = 0; i < z; i++)
	{
		cin >> s;
		tmp1[i] = s;
		data1->Push(s);
	}
	while (1)
	{
		rewind(stdin);
		cout << endl << "Выбери операцию" << endl;
		cout << "1-Добавить в конец deque" << endl << "2-Показать deque" << endl << "3-Удалить элемент" << endl << "4-Удалить любой элемент" << endl
			<< "5-Очистить deque" << endl << "6-Узнать размер deque" << endl << "7-Сортировка" << endl << "8-Поиск по очереди" << endl << "9-Поиск по очереди(Iter)" << endl
			<< "10-Прочесть файл" << endl << "11-Записать в файл" << endl << "12-Очистка файла" << endl << "13-Отмена действия " << endl 
			<< "14-Выход" << endl;
		w = enter();
		switch (w)
		{
	
		case 1:
		{
			system("cls");
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			vect.clear();
			b.clear(q);
			vect = data1->get();
			for (int i = 0; i < data1->show_size(); i++)
				b.toFile(vect[i], q);
			system("cls");
			cin >> s;
			*tmp1 = s;
			data1->Push(s);
			system("cls");
			cout << "Объект успешно добавлен" << endl;
			system("cls");

			break;
		}

		case 2:
		{
			system("cls");
			shapka(_k);
			data1->show(1);
			break;
		}
		case 3:
		{
			system("cls");
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			b.clear(q);
			vect.clear();
			vect = data1->get();
			for (int i = 0; i < data1->show_size(); i++)
				b.toFile(vect[i], q);
			system("cls");
			data1->pop(1);
			cout << "deque после удаления " << endl;
			shapka(_k);
			data1->show(1);
			break;
		}
		case 4:
		{
			system("cls");
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			b.clear(q);
			vect.clear();
			vect = data1->get();
			for (int i = 0; i < data1->show_size(); i++)
				b.toFile(vect[i], q);
			system("cls");
			int i = 0;
			cout << "Какой элемент удалить " << endl;
			cin >> i;
			data1->pop_any(tmp1[i]);
			cout << "deque после удаления " << endl;
			shapka(_k);
			data1->show(1);
			break;
		}
		case 5:
		{
			system("cls");
			data1->delet();
			break;
		}
		case 6:
		{
			system("cls");
			cout << data1->show_size() << endl;
			break;
		}
		case 7:
		{
			system("cls");
			shapka(_k);
			data1->show(1);
			alg.sort(*data1);
			cout << endl << "После сортировки" << endl;
			shapka(_k);
			data1->show(1);
			break;
		}
		case 8:
		{
			system("cls");
			shapka(_k);
			data1->show(1);
			cin >> ss;
			alg.search(data1->Begin(), ss);
			break;
		}
		case 9:
		{
			system("cls");
			shapka(_k);
			data1->show(1);
			cin >> ss;
			alg.search2(data1->Begin(), data1->End(), ss);
			break;
		}
		case 10:
		{
			system("cls");
			Deque<T> c;
			T* tmp2;
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			int count;
			count = b.checkCount(q);
			tmp2 = new T[count];
			for (int i = 0; i < count; i++)
			{
				b.fromFile(tmp2[i], q, i);
				c.Push(tmp2[i]);
			}
			cout << "Данные успешно считаны из файла." << endl;
			shapka(_k);
			data1->show(0);
			break;
		}
		case 11:
		{
			system("cls");
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			vector<T> ww;
			ww = data1->get();
			textFile<T> b;
			for (int i = 0; i < data1->show_size(); i++)
				b.toFile(ww[i], q);
			cout << "Данные успешно записаны в файл." << endl;
			break;
		}
		case 12:
		{
			system("cls");
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			b.clear(q);
			cout << "Файл очищен." << endl;
			break;
		}
		case 13:
		{
			system("cls");
			data1->delet();
			string q;
			cout << "Введите имя файла" << endl;
			cin >> k;
			q = k + ".txt";
			int count;
			count = b.checkCount(q);
			tmp1 = new T[count];
			for (int i = 0; i < count; i++)
			{
				b.fromFile(tmp1[i], q, i);
				data1->Push(tmp1[i]);
			}
			cout << "Данные успешно считаны из файла." << endl;
			shapka(_k);
			data1->show(0);
			break;
			cout << "Отмена действия прошла успешно." << endl;
			break;
		}
		case 14:
		{
			return;
		}
		}
	}
}

int MenuADM()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	while (1)
	{
		system("cls");
		cout << " МЕНЮ АДМИНА" << endl;
		cout << " 1 - Редактировать информацию(touchMouse)" << endl;
		cout << " 2 - Редактировать информацию(wiredMouse)" << endl;
		cout << " 3 - Редактировать информацию(LCD)" << endl;
		cout << " 4 - Редактировать информацию(PDP)" << endl;
		cout << " 0 - Выйти" << endl;
		cout << "Выберите команду:";
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			Deque<touchMouse> c;
			touchMouse a;
			int k = 1;
			ADM(c, a , k);
			break;
		}
		case 2:
		{
			Deque<wiredMouse> c;
			wiredMouse a;
			int k = 2;
			ADM(c, a, k);
			break;
		}
		
		case 3:
		{
			Deque<LCD> c;
			LCD a;
			int k = 3;
			ADM(c, a, k);
			break;
		}
		case 4:
		{
			Deque<PDP> c;
			PDP a;
			int k = 4;
			ADM(c, a, k);
			break;
		}
		case 0:
		{
			return 0;
		}
		}
		cout << endl;
		system("pause");
	}
	system("pause");
	return 0;
}
int MenuUSER()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	while (1)
	{
		system("cls");
		cout << " МЕНЮ ПОЛЬЗОВАТЕЛЯ" << endl;
		cout << " 1 - Показать информацию(touchMouse)" << endl;
		cout << " 2 - Показать  информацию(wiredMouse)" << endl;
		cout << " 3 - Показать  информацию(LCD)" << endl;
		cout << " 4 - Показать  информацию(PDP)" << endl;
		cout << " 0 - Выйти" << endl;
		cout << "Выберите команду:";
		int k;
		int z;
		k = enter();
		switch (k)
		{
		case 1:
		{
			Deque<touchMouse> c;
			touchMouse a;
			int k = 1;
			USER(c, a, k);
			break;
		}
		case 2:
		{
			Deque<wiredMouse> c;
			wiredMouse a;
			int k = 2;
			USER(c, a, k);
			break;
		}

		case 3:
		{
			Deque<LCD> c;
			LCD a;
			int k = 3;
			USER(c, a, k);
			break;
		}
		case 4:
		{
			Deque<PDP> c;
			PDP a;
			int k = 4;
			USER(c, a, k);
			break;
		}
		case 0:
		{
			return 0;
		}
		}
		cout << endl;
		system("pause");
	}
	system("pause");
	return 0;
}