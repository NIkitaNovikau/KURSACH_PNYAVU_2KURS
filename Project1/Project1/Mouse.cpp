#include"Mouse.h"

void operator <<= (ostream& stream, Mouse& tmp)
{
	stream <<= dynamic_cast <Devices&>(tmp);
	stream << tmp.mouseSensitivity << "|" << tmp.material << "|";
}

void operator >>= (istream& stream, Mouse& tmp)
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
		getline(ss, s1, '|');
		tmp.setMouseSensitivity(s1.c_str());
		getline(ss, s1, '|');
		tmp.setMaterial(s1.c_str());

	}
}


void operator <= (ostream& os, Mouse& tmp)
{
	os <= dynamic_cast <Devices&>(tmp);
	int n = sizeof(tmp.mouseSensitivity);
	char* t = new char[n];
	t = tmp.mouseSensitivity.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	n = sizeof(tmp.material);
	t = new char[n];
	t = tmp.material.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));

}

void operator >= (istream& is, Mouse& tmp)
{
	is >= dynamic_cast <Devices&>(tmp);
	int n;
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	char* t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setMouseSensitivity(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setMaterial(t);

}
ostream& operator<<(ostream& on, Mouse& ss)
{
	on << dynamic_cast<Devices&>(ss);
	on << setiosflags(ios::left)
		<< setw(15) << ss.mouseSensitivity
		<< setw(15) << ss.material;
	return on;
}

istream& operator>>(istream& in, Mouse& ss)
{
	in >> dynamic_cast<Devices&>(ss);
	cout << "¬ведите уровень чувствительности мыши :";
	in >> ss.mouseSensitivity;
	cout << "¬ведите материал :";
	in >> ss.material;

	return in;
}

Mouse& Mouse::operator=(const Mouse& other)
{
	this->yearOfIssue = other.yearOfIssue;
	this->brand = other.brand;
	this->cost = other.cost;
	this->mouseSensitivity = other.mouseSensitivity;
	this->material = other.material;
	return *this;
}

bool Mouse::operator==(Mouse& other)
{
	if ((this->mouseSensitivity == other.mouseSensitivity))
		return true;
	else
		return false;
}

bool Mouse::operator==(char* other)
{
	if ((this->mouseSensitivity == other))
		return true;
	else
		return false;
}

bool Mouse::operator > (const Mouse& tmp)
{
	if (this->mouseSensitivity > tmp.mouseSensitivity)
		return true;
	if (this->material < tmp.material)
		return false;
}