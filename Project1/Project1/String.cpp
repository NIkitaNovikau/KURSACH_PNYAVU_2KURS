#include"String.h"

istream& operator>>(istream& in, String& ss)
{
	rewind(stdin);
	extern char* exp(istream & in);
	const char* ch = exp(in);
	strcpy_s(ss.str, strlen(ch) + 1, ch);
	return in;
}

ostream& operator<<(ostream& on, String& ss)
{
	return on << ss.str;
}
String& String::operator=(const String& other)
{
	length = strlen(other.str);
	this->str = new char[length + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);
	return *this;
}
void String::operator=(char* str)
{
	delete[] this->str;
	this->length = strlen(str);
	this->str = new char[this->length + 1];
	strcpy_s(this->str, this->length + 1, str);
}

//перегруженный оператор присваивания String - char str[]
void String::operator = (const char str[])
{
	delete[] this->str;
	this->length = strlen(str);
	this->str = new char[this->length + 1];
	strcpy_s(this->str, this->length + 1, str);
}

String& String::operator+= (String const& other)
{
	return (this->operator=(this->operator+(other)));
}

String String::operator+(const String& other)
{
	String newStr;

	int thisLength = strlen(this->str);
	int otherLength = strlen(other.str);

	newStr.length = thisLength + otherLength;

	newStr.str = new char[thisLength + otherLength + 1];

	int i = 0;
	for (; i < thisLength; i++)
	{
		newStr.str[i] = this->str[i];
	}

	for (int j = 0; j < otherLength; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}

	newStr.str[thisLength + otherLength] = '\0';

	return newStr;

}

char& String::operator[](int index)
{
	return this->str[index];
}

bool String::operator>(const String& obj)
{
	if ((strcmp(this->str, obj.str)) > 0)
		return true;
}

bool String::operator<(const String& obj)
{
	if ((strcmp(this->str, obj.str)) < 0)
		return false;
}

String String::operator()(int index1, int length1)
{
	String obrstr;
	obrstr.str = new char[length + 1];

	for (int i = 0; i < length + 1; i++)
	{
		obrstr.str[i] = this->str[i];
	}
	for (int count = index1; count < length1 + 1; ++count)
	{
		cout << obrstr.str[count];
	}
	return obrstr;
}

bool String::operator!=(const String& other)
{
	return !(this->operator==(other));
}

bool String::operator==(const String& tmp)
{
	if (!strcmp(this->str, tmp.str))
		return true;
	else
		return false;
}
bool String::operator == (const char* tmp)
{
	if (strcmp(this->str, tmp) == 0)
		return true;
	else
		return false;
}
