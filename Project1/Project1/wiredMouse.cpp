#include"wiredMouse.h"

void operator <<= (std::ostream& stream, wiredMouse& tmp)
{
	stream <<= dynamic_cast <Mouse&>(tmp);
	stream << tmp.scrollingWay << "|" << tmp.wireLength << "|" << tmp.responseTime << "|";
	stream << endl;
}

void operator >>= (std::istream& stream, wiredMouse& tmp)
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
		tmp.setMaterial(s1.c_str());
		getline(ss, s1, '|');
		tmp.setMouseSensitivity(s1.c_str());
		getline(ss, s1, '|');
		tmp.setScrollingWay(s1.c_str());
		getline(ss, s1, '|');
		tmp.setWireLength(atoi(s1.c_str()));
		tmp.setResponseTime(atoi(s1.c_str()));
	}
}

void operator <= (std::ostream& os, wiredMouse& tmp)
{
	os <= dynamic_cast <Mouse&>(tmp);
	int n = sizeof(tmp.scrollingWay);
	char* t = new char[n];
	t = tmp.scrollingWay.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	os.write(reinterpret_cast<char*>(&tmp.wireLength), sizeof(int));
	os.write(reinterpret_cast<char*>(&tmp.responseTime), sizeof(int));
}

void operator >= (std::istream& is, wiredMouse& tmp)
{
	is >= dynamic_cast <Mouse&>(tmp);
	int n;
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	char* t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setScrollingWay(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	tmp.setWireLength(n);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	tmp.setResponseTime(n);
}
istream& operator>>(istream& in, wiredMouse& ss)
{
    in >> dynamic_cast<Mouse&>(ss);
    cout << "¬ведите способ прокрутки :";
    in >> ss.scrollingWay;
    cout << "¬ведите длину провода :";
	int enter(istream & in);
	int ch = enter(in);
	ss.wireLength = ch;
    cout << "¬ведите врем€ отклика :";
	int enter(istream & in);
	int kk = enter(in);
	ss.responseTime = kk;
    return in;
}

ostream& operator<<(ostream& on, wiredMouse& ss)
{
    on << dynamic_cast<Mouse&>(ss);
    on << setiosflags(ios::left)
        << setw(15) << ss.scrollingWay
        << setw(15) << ss.wireLength
        << setw(15) << ss.responseTime
        << endl;
    return on;
}

wiredMouse& wiredMouse::operator=(const wiredMouse& other)
{
    this->yearOfIssue = other.yearOfIssue;
    this->brand = other.brand;
    this->cost = other.cost;

    this->mouseSensitivity = other.mouseSensitivity;
    this->material = other.material;

    this->scrollingWay = other.scrollingWay;
    this->wireLength = other.wireLength;
    this->responseTime = other.responseTime;

    return *this;
}

bool wiredMouse::operator==(wiredMouse& other)
{
    if (this->scrollingWay == other.scrollingWay)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool wiredMouse::operator==( char* other)
{
    if ((this->scrollingWay == other))
        return true;
    else
        return false;
}

bool wiredMouse::operator > (const wiredMouse& tmp)
{
	if (this->scrollingWay > tmp.scrollingWay)
		return true;
	if (this->wireLength < tmp.wireLength)
		return false;
	if (this->responseTime == tmp.responseTime)
		return false;
}