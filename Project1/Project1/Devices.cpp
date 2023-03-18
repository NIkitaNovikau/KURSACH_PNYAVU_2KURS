#include"Devices.h"

void operator <<= (std::ostream& stream, Devices& tmp)
{
	stream << tmp.yearOfIssue << "|" << tmp.brand << "|" << tmp.cost << "|" ;
}

void operator >>= (std::istream& stream, Devices& tmp)
{
	string s, s1;
	if (getline(stream, s))
	{
		stringstream ss;
		ss << s;
		getline(ss, s1, '|');
		tmp.setName(s1.c_str());
		getline(ss, s1, '|');
		tmp.setBrand(s1.c_str());
		getline(ss, s1, '|');
		tmp.setCost(atoi(s1.c_str()));
	}
}


void operator <= (std::ostream& os, Devices& tmp)
{
	int n = sizeof(tmp.yearOfIssue);
	char* t = new char[n];
	t = tmp.yearOfIssue.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	n = sizeof(tmp.brand);
	t = new char[n];
	t = tmp.brand.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	os.write(reinterpret_cast<char*>(&tmp.cost), sizeof(int));
}

void operator >= (std::istream& is, Devices& tmp)
{
	int n;
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	char* t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setName(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setBrand(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	tmp.setCost(n);
}

ostream& operator<<(ostream& on, Devices& ss)
{
	rewind(stdin);
	return on << setiosflags(ios::left)
		<< setw(13) << ss.yearOfIssue
		<< setw(13) << ss.brand
		<< setw(10) << ss.cost;

}

istream& operator>>(istream& in, Devices& ss)
{
	cout << "¬ведите год выпуска :";
	in >> ss.yearOfIssue;
	cout << "¬ведите бренд :";
	in >> ss.brand;
	cout << "¬ведите цену :";
	int enter(istream & in);
	int ch = enter(in);
	ss.cost = ch;
	return in;
}

Devices& Devices::operator=(const Devices& other)
{
	this->yearOfIssue = other.yearOfIssue;
	this->brand = other.brand;
	this->cost = other.cost;

	return *this;
}

bool Devices::operator==(Devices& other)
{
	if ((this->yearOfIssue == other.yearOfIssue) )
		return true;
	else
		return false;
}
bool Devices::operator==(char* other)
{
	if ((this->yearOfIssue == other) )
		return true;
	else
		return false;
}

bool Devices::operator > (const Devices& tmp)
{
	if (this->yearOfIssue > tmp.yearOfIssue)
		return true;
	if (this->brand < tmp.brand)
		return false;
	if (this->cost == tmp.cost)
		return false;
}