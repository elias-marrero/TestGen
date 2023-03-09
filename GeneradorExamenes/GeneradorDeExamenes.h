#pragma once
#include "Menu2.h"
#include "Examen.h"
const int SIZE = 20;

class GeneradorDeExamenes 
{
private:
	Examen *a = new Examen[SIZE];
	int indice;

public:
	GeneradorDeExamenes(int indice = 0);
	GeneradorDeExamenes(const GeneradorDeExamenes & aGen);
	~GeneradorDeExamenes();
	GeneradorDeExamenes & operator =(const GeneradorDeExamenes & aGen);
	void setExam();
	void MenuGen();
};

