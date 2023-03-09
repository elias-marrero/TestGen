#pragma once
#include <iostream>
using namespace std;

const int MAX_LAN = 80;

class Preguntas
{
private:
	char s[MAX_LAN + 1];

public:
	Preguntas(const char * s = "");
	Preguntas(char ch);
	Preguntas(const Preguntas & unaPregunta);
	~Preguntas();

	Preguntas & operator=(const char * s);
	Preguntas & operator=(char ch);
	Preguntas & operator=(const Preguntas & unaPregunta);

	void setS(const char * s);
	const char * getS() const;

	Preguntas operator+(const char * s) const;
	Preguntas operator+(char ch) const;
	Preguntas operator+(const Preguntas & unaPregunta) const;
	friend Preguntas operator+(const char * s, const Preguntas & unaPregunta);
	friend Preguntas operator+(char ch, const Preguntas & unaPregunta);

	bool operator==(const char * s) const;
	bool operator==(const Preguntas & unaPregunta) const;
	friend bool operator==(const char * s, const Preguntas & unaPregunta);

	bool operator!=(const char * s) const;
	bool operator!=(const Preguntas & unaPregunta) const;
	friend bool operator!=(const char * s, const Preguntas & unaPregunta);

	bool operator>(const char * s) const;
	bool operator>(const Preguntas & unaPregunta) const;
	friend bool operator>(const char * s, const Preguntas & unaPregunta);

	bool operator<(const char * s) const;
	bool operator<(const Preguntas & unaPregunta) const;
	friend bool operator<(const char * s, const Preguntas & unaPregunta);

	const char & operator[](int index) const;
	char & operator[](int index);

	friend istream & operator>>(istream & in, Preguntas & unaPregunta);
	friend ostream & operator<<(ostream & out, const Preguntas & unaPregunta);

	Preguntas trimLeadingSpaces() const;
	Preguntas trimEndingSpaces() const;
	Preguntas trimAllSpaces() const;

	Preguntas toUppercase() const;
	Preguntas toLowercase() const;

	Preguntas createSubstring(int from, int to) const;
	int len() const;
	bool isEmpty() const;

	Preguntas reverse() const;

	int indexOf(char ch) const;
	int indexOfLast(char ch) const;
	bool include(char ch) const;
	int frequency(char ch) const;

	bool representAnUnsignInteger() const;
	bool representAnInteger() const;
	bool representAReal() const;

	static int MaxLen();

	Preguntas & operator+=(const Preguntas & unaPregunta);
	Preguntas & operator+=(const char * s);
	Preguntas & operator+=(char ch);

	Preguntas & operator++();
	Preguntas operator++(int);

	Preguntas & operator--();
	Preguntas operator--(int);
};