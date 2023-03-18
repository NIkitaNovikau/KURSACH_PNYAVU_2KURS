#include"Menu.cpp"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	while (1)
	{
		system("cls");
		cout << "               ГЛАВНОЕ МЕНЮ" << endl;
		cout << " 1 - Войти от имени администратора" << endl;
		cout << " 2 - Войти от имени пользователя" << endl;
		cout << " 0 - Выйти" << endl;
		cout << "Выберите команду:";
		switch (cin.get())
		{
		case '1':
		{
			MenuADM();
			break;
		}
		case '2':
		{
			MenuUSER();
			break;
		}
		case '0':
		{
			return 0;
		}

		}

	}
}
