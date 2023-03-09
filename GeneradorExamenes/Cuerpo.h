#pragma once
#include "ListaDePreguntas.h"
#include "Preguntas.h"


class Cuerpo : public ListaDePreguntas
{
protected:
	ListaDePreguntas lista;

public:
	Cuerpo();
	Cuerpo(const Cuerpo & unCuerpo);
	~Cuerpo();
	Cuerpo & operator = (const Cuerpo & unCuerpo);
	void setNum();
	void setPregunta();

	void cambiarPregunta(int indice);
	void removerPregunta(int indice);
	void insertarPregunta();
	int getQnum() const;

	void printCuerpo() const;
};

