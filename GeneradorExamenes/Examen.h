#pragma once
#include "Encabezado.h"
#include "Cuerpo.h"
#include "Menu2.h"

class Examen : public Cuerpo
{
protected:
	Encabezado header;
	Cuerpo body;
	bool exist;

public:
	int lang;
	Examen(bool exist = false);
	Examen(const Examen & unExamen);
	~Examen();
	Examen & operator =(const Examen & unExamen);
	
	void setLang(int lang);
	void setHeader();
	void setBody();
	void setExist(bool exist);

	bool getExist() const;

	void printExam();
	void MenuExam();
};

