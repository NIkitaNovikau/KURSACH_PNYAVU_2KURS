#include"Monitor.h"

void operator <<= (ostream& stream, Monitor& tmp)
{
	stream <<= dynamic_cast <Devices&>(tmp);
	stream << tmp.screenResolution << "|" << tmp.numberOfInches << "|";
}

void operator >>= (istream& stream, Monitor& tmp)
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

	}
}

void operator <= (ostream& os, Monitor& tmp)
{
	os <= dynamic_cast <Devices&>(tmp);
	int n = sizeof(tmp.screenResolution);
	char* t = new char[n];
	t = tmp.screenResolution.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	os.write(reinterpret_cast<char*>(&tmp.cost), sizeof(int));
}

void operator >= (istream& is, Monitor& tmp)
{
	is >= dynamic_cast <Devices&>(tmp);
	int n;
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	char* t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setScreenResolution(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	tmp.setNumberOfInches(n);

}

istream& operator>>(istream& in, Monitor& ss)
{
    in >> dynamic_cast<Devices&>(ss);
    cout << "Введите разрешение экрана :";
    in >> ss.screenResolution;
    cout << "Введите кол-во дюймов :";
	int enter(istream & in);
	int ch = enter(in);
	ss.numberOfInches = ch;
    return in;
}

ostream& operator<<(ostream& on, Monitor& ss)
{
    on << dynamic_cast<Devices&>(ss);
    on << setiosflags(ios::left)
        << setw(15) << ss.screenResolution
        << setw(15) << ss.numberOfInches;
    return on;
}

Monitor& Monitor::operator=(const Monitor& other)
{
    this->yearOfIssue = other.yearOfIssue;
    this->brand = other.brand;
    this->cost = other.cost;

    this->screenResolution = other.screenResolution;
    this->numberOfInches = other.numberOfInches;
    return *this;
}

bool Monitor::operator==(Monitor& other)
{
    if ((this->screenResolution == other.screenResolution))
        return true;
    else
        return false;
}

bool Monitor::operator==( char* other)
{
    if ((this->screenResolution == other))
        return true;
    else
        return false;
}

bool Monitor::operator > (const Monitor& tmp)
{
	if (this->screenResolution > tmp.screenResolution)
		return true;
	if (this->numberOfInches < tmp.numberOfInches)
		return false;
}