#include"LCD.h"

void operator <<= (ostream& stream, LCD& tmp)
{
	stream <<= dynamic_cast <Monitor&>(tmp);
	stream << tmp.matrix << "|" << tmp.turnOnSpeed << "|";
	stream << endl;
}

void operator >>= (istream& stream, LCD& tmp)
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
		tmp.setMatrix(s1.c_str());
		getline(ss, s1, '|');
		tmp.setTurnOnSpeed(atoi(s1.c_str()));
	}
}

void operator <= (ostream& os, LCD& tmp)
{
	os <= dynamic_cast <Monitor&>(tmp);
	int n = sizeof(tmp.matrix);
	char* t = new char[n];
	t = tmp.matrix.c_str();
	os.write(reinterpret_cast<char*>(&n), sizeof(int));
	os.write(reinterpret_cast<char*>(&t), sizeof(t));
	os.write(reinterpret_cast<char*>(&tmp.turnOnSpeed), sizeof(int));
}

void operator >= (istream& is, LCD& tmp)
{
	is >= dynamic_cast <Monitor&>(tmp);
	int n;
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	char* t = new char[n];
	is.read(reinterpret_cast<char*>(&t), sizeof(t));
	tmp.setMatrix(t);
	is.read(reinterpret_cast<char*>(&n), sizeof(int));
	tmp.setTurnOnSpeed(n);

}

istream& operator>>(istream& in, LCD& ss)
{
    in >> dynamic_cast<Monitor&>(ss);
    cout << "Введите какая матрица установлена :";
    in >> ss.matrix;
    cout << "Введите время включения :";
	int enter(istream & in);
	int ch = enter(in);
	ss.turnOnSpeed = ch;
    return in;
}

ostream& operator<<(ostream& on, LCD& ss)
{
    on << dynamic_cast<Monitor&>(ss);
    on << setiosflags(ios::left)
        << setw(15) << ss.matrix
        << setw(15) << ss.turnOnSpeed
		<< endl;
    return on;
}

LCD& LCD::operator=(const LCD& other)
{
    this->yearOfIssue = other.yearOfIssue;
    this->brand = other.brand;
    this->cost = other.cost;

    this->screenResolution = other.screenResolution;
    this->numberOfInches = other.numberOfInches;

    this->matrix = other.matrix;
    this->turnOnSpeed = other.turnOnSpeed;
    return *this;
}

bool LCD::operator==(LCD& other)
{
    if ((this->matrix == other.matrix))
        return true;
    else
        return false;
}

bool LCD::operator==( char* other)
{
    if ((this->matrix == other))
        return true;
    else
        return false;
}

bool LCD::operator > (const LCD& tmp)
{
	if (this->matrix > tmp.matrix)
		return true;
	if (this->turnOnSpeed < tmp.turnOnSpeed)
		return false;
}