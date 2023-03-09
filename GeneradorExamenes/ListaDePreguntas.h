#pragma once
#include <iostream>
using namespace std;
#include "Preguntas.h"

const int MAX_COD = 80;

class ListaDePreguntas
{
protected:


public:
	Preguntas cadena[MAX_COD];
	int cantidad;
	ListaDePreguntas();
	ListaDePreguntas(const ListaDePreguntas & unaLista);

	~ListaDePreguntas();

	ListaDePreguntas & operator=(const ListaDePreguntas & unaLista);

	int catidadDePreguntas() const;

	bool operator ==(const ListaDePreguntas & unaLista) const;
	bool operator !=(const ListaDePreguntas & unaLista) const;

	bool insertar(int indice, const Preguntas & unaCadena);
	bool insertar(int indice, const char * cadena);
	bool insertar(int indice, const ListaDePreguntas & unaLista);

	bool insertarAlComienzo(const Preguntas & unaCadena);
	bool insertarAlComienzo(const char * cadena);
	bool insertarAlComienzo(const ListaDePreguntas & unaLista);

	bool insertarAlFinal(const Preguntas & unaCadena);
	bool insertarAlFinal(const char * cadena);
	bool insertarAlFinal(const ListaDePreguntas & unaLista);

	ListaDePreguntas & operator+(const Preguntas & unaCadena);
	ListaDePreguntas & operator+(const char * cadena);
	ListaDePreguntas & operator+(const ListaDePreguntas & unaLista);

	friend ListaDePreguntas & operator+(const char * cadena, ListaDePreguntas & unaLista);
	friend ListaDePreguntas & operator+(const Preguntas & unaCadena, ListaDePreguntas & unaLista);

	bool estaLlena() const;
	bool estaVacia() const;

	bool incluye(const Preguntas & unaCadena) const;
	bool incluye(const char * cadena) const;

	int indiceDe(const Preguntas & unaCadena) const;
	int indiceDe(const char * cadena) const;
	int indiceDeLaUltima(const Preguntas & unaCadena) const;
	int indiceDeLaUltima(const char * cadena) const;

	bool remover(int indice);
	bool removerElPrimer();
	bool removerElUltimo();
	bool remover(int indice, Preguntas & unaCadena);
	bool removerElPrimer(Preguntas & unaCadena);
	bool removerElUltimo(Preguntas & unaCadena);

	ListaDePreguntas & operator-(const Preguntas & unaCadena);
	ListaDePreguntas & operator-(const char * cadena);
	ListaDePreguntas & operator-(int indice);
	friend ListaDePreguntas & operator-(const char * cadena, ListaDePreguntas & unaLista);
	friend ListaDePreguntas & operator-(const Preguntas & unaCadena, ListaDePreguntas & unaLista);

	void vaciar();

	void ordenarAscendente();
	void ordenarDescendente();

	bool reemplazar(int indice, const Preguntas & unaCadena);
	bool reemplazar(int indice, const char * cadena);

	const Preguntas & operator[](int indice) const;
	Preguntas & operator[](int indice);

	int frecuencia(const Preguntas & unaCadena) const;
	int frecuencia(const char * cadena) const;

	static int MaxPreguntas();

	friend ostream & operator<<(ostream & out, const ListaDePreguntas & unaLista);
};