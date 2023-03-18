#include"touchMouse.h"

void operator <<= (ostream& stream, touchMouse& tmp)
{
	stream <<= dynamic_cast <Mouse&>(tmp);
	stream << tmp.cursorFrequency << "|" << tmp.numberOfSensors << "|";
	stream << endl;
}

void operator >>= (istream& stream, touchMouse& tmp)
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
		getline(ss, s1, '|');
		tmp.setCursorFrequency(s1.c_str());
		getline(ss, s1, '|');
		tmp.setNumberOfSensors(atoi(s1.c_str()));
	}
}

void operator <= (ostream& os, touchMouse& tmp)
{
	os <= dynamic_cast <Mouse&>(tmp);
	int n = sizeof(tmp.cursorFrequency);
	char* t = new char[n];
	t = tmp.cursorFrequency.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	os.write(reinterpret_cast<char*>(&tmp.numberOfSensors), sizeof(int));

}

void operator >= (istream& is, touchMouse& tmp)
{
	is >= dynamic_cast <Mouse&>(tmp);
	int n;
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	char* t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setCursorFrequency(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	tmp.setNumberOfSensors(n);

}
istream& operator>>(istream& in, touchMouse& ss)
{
    in >> dynamic_cast<Mouse&>(ss);
    cout << "¬ведите уровень частоты курсора :";
    in >> ss.cursorFrequency;
    cout << "¬ведите кол-во датчиков :";
	int enter(istream & in);
	int ch = enter(in);
	ss.numberOfSensors = ch;
    return in;
}

ostream& operator<<(ostream& on, touchMouse& ss)
{
    on << dynamic_cast<Mouse&>(ss);
    on << setiosflags(ios::left)
        << setw(15) << ss.cursorFrequency
        << setw(15) << ss.numberOfSensors
        << endl;
    return on;
}

touchMouse& touchMouse::operator=(const touchMouse& other)
{
    this->yearOfIssue = other.yearOfIssue;
    this->brand = other.brand;
    this->cost = other.cost;

    this->mouseSensitivity = other.mouseSensitivity;
    this->material = other.material;

    this->cursorFrequency = other.cursorFrequency;
    this->numberOfSensors = other.numberOfSensors;

    return *this;
}
bool touchMouse::operator==(touchMouse& other)
{
    if (this->cursorFrequency == other.cursorFrequency)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool touchMouse::operator==(char* other)
{
	if ((this->cursorFrequency == other))
		return true;
	else
		return false;
}

bool touchMouse::operator > (const touchMouse& tmp)
{
	if (this->cursorFrequency > tmp.cursorFrequency)
		return true;
	if (this->numberOfSensors < tmp.numberOfSensors)
		return false;
}