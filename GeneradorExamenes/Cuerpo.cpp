#include "Cuerpo.h"



Cuerpo::Cuerpo()
{
}

Cuerpo::Cuerpo(const Cuerpo & unCuerpo)
{
	this->cantidad = unCuerpo.cantidad;
	this->lista = unCuerpo.lista;
	for (int x = 0; x < MAX_COD; x++)
	{
		this->cadena[x] = unCuerpo.cadena[x];
	}
}


Cuerpo::~Cuerpo()
{
}

Cuerpo & Cuerpo::operator=(const Cuerpo & unCuerpo)
{
	this->cantidad = unCuerpo.cantidad;
	this->lista = unCuerpo.lista;
	for (int x = 0; x < MAX_COD; x++)
	{
		this->cadena[x] = unCuerpo.cadena[x];
	}
	return(*this);
}

void Cuerpo::setNum()
{
	cout << "Entre la cantidad de preguntas que tendra el examen: ";
	cin >> this->cantidad;
	while (this->cantidad < 0 || this->cantidad > 80)
	{
		cout << "Error, el numer debe estar entre 1 y 80, re-entre: ";
		cin >> this->cantidad;
	}
}

void Cuerpo::setPregunta()
{
	for (int i = 0; i < this->cantidad; i++)
	{
		cout << endl << "Pregunta #" << i + 1 << ": ";
		cin >> lista.cadena[i];
		this->lista + lista.cadena[i];
	}
}

void Cuerpo::cambiarPregunta(int indice)
{
	cout << endl << "Pregunta #" << indice << ": ";
	cin >> lista.cadena[indice-1];
	lista.reemplazar(indice - 1, lista.cadena[indice - 1]);
	cout << endl << endl;
	cout << lista;
}

void Cuerpo::removerPregunta(int indice)
{
	cout << endl << "Pregunta #" << indice << ": ";

	lista.remover(indice - 1);
	cout << endl << endl;
	cout << lista;
}

void Cuerpo::insertarPregunta()
{
	cout << endl << "Pregunta: ";
	cin >> lista.cadena[cantidad];
	this->lista + lista.cadena[cantidad];	
	cout << endl << endl;
	cout << lista;
}

int Cuerpo::getQnum() const
{
	return this->cantidad;
}

void Cuerpo::printCuerpo() const
{
	cout << "\n\n"<<this->lista;
}
