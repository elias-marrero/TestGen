#pragma once
#include <iostream>
using namespace std;

class MyTime
{
private:
	int seconds;	//atributo
	int minutes;	//atributo
	int hour;		//atributo

public:
	MyTime(int hour = 0, int minutes = 0, int seconds = 0);
	MyTime(const MyTime & aTime);

	~MyTime();

	void setSeconds(int seconds);
	void setMinutes(int minutes);
	void setHour(int hour);

	int getSeconds() const;
	int getMinutes() const;
	int getHour()const;

	void showSeconds() const;
	void showMinutes() const;
	void showHour() const;
	void showTime() const;

	void setAM();
	void setPM();

	bool isAM() const;
	bool isPM() const;

	void askSeconds();
	void askMinutes();
	void askHour();
	void askTime();

	MyTime & operator= (const MyTime & aTime);

	bool operator == (const MyTime & aTime) const;
	bool operator != (const MyTime & aTime) const;
	bool operator > (const MyTime & aTime) const;
	bool operator < (const MyTime & aTime) const;

	friend ostream & operator << (ostream & out, const MyTime & aTime);
	friend istream & operator >> (istream & in, MyTime & aTime);

};