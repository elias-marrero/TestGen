#include "Preguntas.h"

Preguntas::Preguntas(const char * s)
{
	(*this) = s;
}

Preguntas::Preguntas(char ch)
{
	(*this) = ch;
}

Preguntas::Preguntas(const Preguntas & unaPregunta)
{
	(*this) = unaPregunta;
}

Preguntas::~Preguntas()
{
}

Preguntas & Preguntas::operator=(const char * s)
{
	strcpy_s(this->s, MAX_LAN + 1, s);
	return (*this);
}

Preguntas & Preguntas::operator=(char ch)
{
	(*this) = "";
	(*this) = (*this) + ch;
	return (*this);
}

Preguntas & Preguntas::operator=(const Preguntas & unaPregunta)
{
	strcpy_s(this->s, MAX_LAN + 1, unaPregunta.s);
	return (*this);
}

void Preguntas::setS(const char * s)
{
	strcpy_s(this->s, MAX_LAN + 1, s);
}

const char * Preguntas::getS() const
{
	return (this->s);
}

int Preguntas::len() const
{
	return(strlen(this->s));
}

Preguntas Preguntas::operator+(const char * s) const
{
	Preguntas r(*this);

	strcat_s(r.s, MAX_LAN + 1, s);
	return(r);
}

Preguntas Preguntas::operator+(char ch) const
{
	Preguntas r(*this);

	if ((this->len() + 1) <= MAX_LAN)
	{
		(r.s)[this->len()] = ch;
		(r.s)[this->len() + 1] = '\0';
	}
	return(r);
}

Preguntas Preguntas::operator+(const Preguntas & unaPregunta) const
{
	return((*this) + unaPregunta.s);
}

Preguntas operator+(const char * s, const Preguntas & unaPregunta)
{
	return (Preguntas(s) + unaPregunta);
}

Preguntas operator+(char ch, const Preguntas & unaPregunta)
{
	return (Preguntas(ch) + unaPregunta);
}

bool Preguntas::operator==(const char * s) const
{
	return (strcmp(this->s, s) == 0);
}

bool Preguntas::operator==(const Preguntas & unaPregunta) const
{
	return (strcmp(this->s, unaPregunta.s) == 0);
}

bool operator==(const char * s, const Preguntas & unaPregunta)
{
	return (strcmp(s, unaPregunta.s) == 0);
}

bool Preguntas::operator!=(const char * s) const
{
	return (strcmp(this->s, s) != 0);
}

bool Preguntas::operator!=(const Preguntas & unaPregunta) const
{
	return (strcmp(this->s, unaPregunta.s) != 0);
}

bool operator!=(const char * s, const Preguntas & unaPregunta)
{
	return (strcmp(s, unaPregunta.s) != 0);
}

bool Preguntas::operator<(const char * s) const
{
	return (strcmp(this->s, s) < 0);
}

bool Preguntas::operator<(const Preguntas & unaPregunta) const
{
	return (strcmp(this->s, unaPregunta.s) < 0);
}

bool operator<(const char * s, const Preguntas & unaPregunta)
{
	return (strcmp(s, unaPregunta.s) < 0);
}

bool Preguntas::operator>(const char * s) const
{
	return (strcmp(this->s, s) > 0);
}

bool Preguntas::operator>(const Preguntas & unaPregunta) const
{
	return (strcmp(this->s, unaPregunta.s) > 0);
}

bool operator>(const char * s, const Preguntas & unaPregunta)
{
	return (strcmp(s, unaPregunta.s) > 0);
}

const char & Preguntas::operator[](int index) const
{
	return ((this->s)[index]);
}

char & Preguntas::operator[](int index)
{
	return((this->s)[index]);
}

istream & operator>>(istream & in, Preguntas & unaPregunta)
{
	char ch;

	unaPregunta = "";

	ch = in.get();
	while (ch == '\n')
		ch = in.get();

	while (ch != '\n')
	{
		unaPregunta = unaPregunta + ch;
		ch = in.get();
	}

	return (in);
}

ostream & operator<<(ostream & out, const Preguntas & unaPregunta)
{
	out << unaPregunta.s;

	return (out);
}

Preguntas Preguntas::trimLeadingSpaces() const
{
	Preguntas r;
	int i;
	for (i = 0; (this->s)[i] == '\t' || (this->s)[i] == ' '; i++);

	for (; i < this->len(); i++)
		r = r + (this->s)[i];
	return(r);
}

Preguntas Preguntas::trimEndingSpaces() const
{
	Preguntas r;
	int i;

	for (i = this->len() - 1; (this->s)[i] == '\t' || (this->s)[i] == ' '; i--);
	for (; i >= 0; i--)
		r = (this->s)[i] + r;
	return (r);
}

Preguntas Preguntas::trimAllSpaces() const
{
	Preguntas r;
	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] != '\t' && (this->s)[i] != ' ')
			r = r + (this->s)[i];
	return (r);
}

Preguntas Preguntas::toUppercase() const
{
	Preguntas r(*this);

	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] >= 'a' && (this->s)[i] <= 'z')
			(r.s)[i] = (this->s)[i] - 32;
	return (r);
}

Preguntas Preguntas::toLowercase() const
{
	Preguntas r(*this);

	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] >= 'A' && (this->s)[i] <= 'Z')
			(r.s)[i] = (this->s)[i] + 32;
	return (r);
}

Preguntas Preguntas::createSubstring(int from, int to) const
{
	Preguntas r;

	if (from >= 0 && to < this->len())
		for (int i = from; i <= to; i++)
			r = r + (this->s)[i];
	return (r);
}

Preguntas Preguntas::reverse() const
{
	Preguntas r(*this);
	char ch;

	for (int i = 0, j = this->len() - 1; i < j; i++, j--)
	{
		ch = (r.s)[i];
		(r.s)[i] = (r.s)[j];
		(r.s)[j] = ch;
	}

	return (r);
}

int Preguntas::indexOf(char ch) const
{
	int index = -1;

	for (int i = 0; (i < this->len()) && (index == -1); i++)
		if ((this->s)[i] == ch)
			index = i;
	return (index);
}

int Preguntas::indexOfLast(char ch) const
{
	int index = -1;

	for (int i = this->len() - 1; (i >= 0) && (index == -1); i--)
		if ((this->s)[i] == ch)
			index = i;
	return (index);
}

bool Preguntas::include(char ch) const
{
	bool found = false;

	for (int i = 0; i < this->len() && !found; i++)
		if ((this->s)[i] == ch)
			found = true;
	return (found);
}

bool Preguntas::isEmpty() const
{
	return (this->len() == 0);
}

int Preguntas::frequency(char ch) const
{
	int f = 0;

	for (int i = 0; i < this->len(); i++)
		if ((this->s)[i] == ch)
			++f;
	return(f);
}

bool Preguntas::representAnUnsignInteger() const
{
	bool represent = true;

	for (int i = 0; i < this->len() && represent; i++)
		if ((this->s)[i]< '0' || (this->s)[i] > '9')
			represent = false;
	return(represent && this->len() > 0);
}

bool Preguntas::representAnInteger() const
{
	Preguntas r(*this);
	if ((this->s)[0] == '+' || (this->s)[0] == '-')
		r = this->createSubstring(1, this->len() - 1);
	return(r.representAnUnsignInteger());
}

bool Preguntas::representAReal() const
{
	int point = this->indexOf('.');
	Preguntas prefix, sufix;
	bool valid;

	if (point != -1)
	{
		prefix = this->createSubstring(0, point - 1);
		sufix = this->createSubstring(point + 1, this->len() - 1);
		valid = prefix.representAnInteger() && sufix.representAnUnsignInteger();
	}
	else
		valid = this->representAnInteger();
	return(valid);
}

int Preguntas::MaxLen()
{
	return (MAX_LAN);
}

Preguntas & Preguntas::operator+=(const Preguntas & unaPregunta)
{
	return ((*this) = (*this) + unaPregunta);
}

Preguntas & Preguntas::operator+=(const char * s)
{
	return ((*this) = (*this) + s);
}

Preguntas & Preguntas::operator+=(char ch)
{
	return ((*this) = (*this) + ch);
}

Preguntas & Preguntas::operator++()
{
	return ((*this) = this->toUppercase());
}

Preguntas Preguntas::operator++(int)
{
	Preguntas r(*this);

	(*this) = this->toUppercase();
	return(r);
}

Preguntas & Preguntas::operator--()
{
	return ((*this) = this->toLowercase());
}

Preguntas Preguntas::operator--(int)
{
	Preguntas r(*this);

	(*this) = this->toLowercase();

	return(r);
}