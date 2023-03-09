#include "MyDate2.h"

MyDate::MyDate(int month, int day, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

MyDate::MyDate(const MyDate & aDate)
{
	this->day = aDate.day;
	this->month = aDate.month;
	this->year = aDate.year;
}


MyDate::~MyDate()
{
}

void MyDate::setDay(int day)
{
	this->day = day;
}

void MyDate::setMonth(int month)
{
	this->month = month;
}

void MyDate::setYear(int year)
{
	this->year = year;
}

int MyDate::getDay() const
{
	return (this->day);
}

int MyDate::getMonth() const
{
	return (this->month);
}

int MyDate::getYear() const
{
	return (this->year);
}

void MyDate::showDay() const
{
	cout << this->day;
}

void MyDate::showMonth() const
{
	cout << this->month;
}

void MyDate::showYear() const
{
	cout << this->year;
}

void MyDate::showDate() const
{
	cout << this->month << '/' << this->day << '/'
		<< ((this->isAC()) ? this->year : -(this->year))
		<< ((this->isAC()) ? "	" : "BC");
}

void MyDate::setBC()
{
	if (this->year > 0)
		this->year *= -1;
}

void MyDate::setAC()
{
	if (this->year < 0)
		this->year *= -1;
}

bool MyDate::isBC() const
{
	return (this->year < 0);
}

bool MyDate::isAC() const
{
	return (this->year > 0);
}

bool MyDate::isLeapYear() const
{
	return((this->year % 400 == 0) ||
		(this->year % 100 != 0 &&
			this->year % 4 == 0));
}

void MyDate::askDay()
{
	bool validFeb, valid30, valid31;

	cout << "Enter a day: ";
	cin >> this->day;

	validFeb = ((this->month == 2) && ((this->isLeapYear() && this->day <= 29 ||
		(!this->isLeapYear()) && this->day <= 28)) && (this->day > 0));

	valid30 = ((this->month != 2) && ((this->month % 2 == 0 && this->month <= 6) ||
		(this->month % 2 != 0 && this->month >= 9)) &&
		(this->day > 0 && this->day <= 30));

	valid31 = ((this->month != 2) && ((this->month % 2 == 0 && this->month >= 8) ||
		(this->month % 2 != 0 && this->month <= 7)) &&
		(this->day > 0 && this->day <= 31));

	while (!validFeb && !valid30 && !valid31)
	{
		cout << "ERROR: Invalid value." << endl << endl;
		cout << "Enter an day: ";
		cin >> this->day;

		validFeb = ((this->month == 2) && ((this->isLeapYear() && this->day <= 29 ||
			(!this->isLeapYear()) && this->day <= 28)) && (this->day > 0));

		valid30 = ((this->month != 2) && ((this->month % 2 == 0 && this->month <= 6) ||
			(this->month % 2 != 0 && this->month >= 9)) &&
			(this->day > 0 && this->day <= 30));

		valid31 = ((this->month != 2) && ((this->month % 2 == 0 && this->month >= 8) ||
			(this->month % 2 != 0 && this->month <= 7)) &&
			(this->day > 0 && this->day <= 31));
	}

}

void MyDate::askDate()
{
	this->askYear();
	this->askMonth();
	this->askDay();
}

void MyDate::askMonth()
{
	cout << "Entre el mes: ";
	cin >> this->month;

	while (this->month < 1 || this->month > 12)
	{
		cout << "ERROR: Valor invalido." << endl << endl;
		cout << "Entre el mes: ";
		cin >> this->month;
	}
}

void MyDate::askYear()
{
	char d;
	cout << "Entre el a~o: ";
	cin >> this->year;

	while (this->year <= 0)
	{
		cout << "ERROR: Valor invalido." << endl << endl;
		cout << "Entre el a~o: ";
		cin >> this->year;
	}

	cout << endl << "Is AC (press 1; otherwise BC): ";
	cin >> d;
	if (d != '1')
		this->setBC();
}

ostream & operator << (ostream & out, const MyDate & aDate)
{
	aDate.showDate();
	return (out);
}

istream & operator >> (istream & in, MyDate & aDate)
{
	aDate.askDate();
	return (in);
}

MyDate & MyDate::operator = (const MyDate & aDate)
{
	this->day = aDate.day;
	this->month = aDate.month;
	this->year = aDate.year;

	return (*this);
}

bool MyDate::operator== (const MyDate & aDate) const
{
	return (this->day == aDate.day &&
		this->month == aDate.month &&
		this->year == aDate.year);
}

bool MyDate::operator != (const MyDate & aDate) const
{
	return(!((*this) == aDate));
}

bool MyDate::operator> (const MyDate & aDate) const
{
	return ((this->year > aDate.year) ||
		(this->year == aDate.year &&
			this->month > aDate.month) ||
			(this->year == aDate.year &&
				this->month == aDate.month &&
				this->day > aDate.day));
}

bool MyDate::operator < (const MyDate & aDate) const
{
	return (!((*this) > aDate || (*this) == aDate));
}