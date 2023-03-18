#include"PDP.h"

void operator <<= (ostream& stream, PDP& tmp)
{
	stream <<= dynamic_cast <Monitor&>(tmp);
	stream << tmp.plasma << "|" << tmp.brightnessLevel << "|";
	stream << endl;
}

void operator >>= (istream& stream, PDP& tmp)
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
		tmp.setScreenResolution(s1.c_str());
		getline(ss, s1, '|');
		tmp.setNumberOfInches(atoi(s1.c_str()));
		getline(ss, s1, '|');
		tmp.setPlasma(s1.c_str());
		getline(ss, s1, '|');
		tmp.setBrightnessLevel(s1.c_str());
	}
}


void operator <= (ostream& os, PDP& tmp)
{
	os <= dynamic_cast <Monitor&>(tmp);
	int n = sizeof(tmp.plasma);
	char* t = new char[n];
	t = tmp.plasma.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	n = sizeof(tmp.brightnessLevel);
	t = new char[n];
	t = tmp.brightnessLevel.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));

}

void operator >= (istream& is, PDP& tmp)
{
	is >= dynamic_cast <Monitor&>(tmp);
	int n;
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	char* t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setPlasma(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setBrightnessLevel(t);

}

istream& operator>>(istream& in, PDP& ss)
{
    in >> dynamic_cast<Monitor&>(ss);
    cout << "¬ведите кака€ плазма установлена :";
    in >> ss.plasma;
    cout << "¬ведите уровень €ркости :";
    in >> ss.brightnessLevel;
    return in;
}

ostream& operator<<(ostream& on, PDP& ss)
{
    on << dynamic_cast<Monitor&>(ss);
    on << setiosflags(ios::left)
        << setw(15) << ss.plasma
        << setw(15) << ss.brightnessLevel
		<< endl;
    return on;
}

PDP& PDP::operator=(const PDP& other)
{
    this->yearOfIssue = other.yearOfIssue;
    this->brand = other.brand;
    this->cost = other.cost;

    this->screenResolution = other.screenResolution;
    this->numberOfInches = other.numberOfInches;

    this->plasma = other.plasma;
    this->brightnessLevel = other.brightnessLevel;
    return *this;
}

bool PDP::operator==(PDP& other)
{
    if ((this->plasma == other.plasma))
        return true;
    else
        return false;
}

bool PDP::operator==( char* other)
{
    if ((this->plasma == other))
        return true;
    else
        return false;
}

bool PDP::operator > (const PDP& tmp)
{
	if (this->plasma > tmp.plasma)
		return true;
	if (this->brightnessLevel < tmp.brightnessLevel)
		return false;
}