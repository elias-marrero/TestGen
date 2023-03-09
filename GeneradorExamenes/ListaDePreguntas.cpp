#include "ListaDePreguntas.h"

ListaDePreguntas::ListaDePreguntas()
{
	this->cantidad = 0;
}

ListaDePreguntas::ListaDePreguntas(const ListaDePreguntas & unaLista)
{
	(*this) = unaLista;
}

ListaDePreguntas::~ListaDePreguntas()
{
}

ListaDePreguntas & ListaDePreguntas::operator=(const ListaDePreguntas & unaLista)
{
	this->cantidad - unaLista.cantidad;

	for (int i = 0; i < unaLista.cantidad; i++)
		(*this)[i] = unaLista[i];

	return (*this);
}

int ListaDePreguntas::catidadDePreguntas() const
{
	return(this->cantidad);
}

ListaDePreguntas & ListaDePreguntas::operator+(const Preguntas & unaCadena)
{
	this->insertarAlFinal(unaCadena);
	return(*this);
}

ListaDePreguntas & ListaDePreguntas::operator+(const char * cadena)
{
	this->insertarAlFinal(cadena);
	return(*this);
}

ListaDePreguntas & ListaDePreguntas::operator+(const ListaDePreguntas & unaLista)
{
	this->insertarAlFinal(unaLista);
	return(*this);
}

bool ListaDePreguntas::remover(int indice)
{
	Preguntas temporero;

	return(this->remover(indice, temporero));
}

bool ListaDePreguntas::removerElPrimer()
{
	Preguntas temporero;

	return(this->removerElPrimer(temporero));
}

bool ListaDePreguntas::removerElUltimo()
{
	Preguntas temporero;

	return(this->removerElUltimo(temporero));
}

bool ListaDePreguntas::remover(int indice, Preguntas & unaCadena)
{
	bool removed = false;

	if (indice >= 0 && indice < this->cantidad)
	{
		unaCadena = (*this)[indice];
		for (int i = indice; i < (this->cantidad - 1); i++)
			(*this)[i] = (*this)[i + 1];

		--(this->cantidad);
		removed = true;
	}
	return(removed);
}

bool ListaDePreguntas::removerElPrimer(Preguntas & unaCadena)
{
	return(this->remover(0, unaCadena));
}

bool ListaDePreguntas::removerElUltimo(Preguntas & unaCadena)
{
	return(this->remover(this->cantidad - 1, unaCadena));
}

ListaDePreguntas & ListaDePreguntas::operator-(const Preguntas & unaCadena)
{
	this->remover(this->indiceDeLaUltima(unaCadena));
	return(*this);
}

ListaDePreguntas & ListaDePreguntas::operator-(const char * cadena)
{
	this->remover(this->indiceDeLaUltima(cadena));
	return (*this);
}

ListaDePreguntas & ListaDePreguntas::operator-(int indice)
{
	this->remover(indice);
	return(*this);
}

void ListaDePreguntas::vaciar()
{
	this->cantidad = 0;
}

void ListaDePreguntas::ordenarAscendente()
{
	int n = this->cantidad;
	Preguntas temp;
	bool switched = true;

	for (int pass = 0; pass < (n - 1) && switched; pass++)
	{
		switched = false;
		for (int j = 0; j < (n - 1 - pass); j++)
			if ((*this)[j] > (*this)[j + 1])
			{
				temp = (*this)[j];
				(*this)[j] = (*this)[j + 1];
				(*this)[j + 1] = temp;
				switched = true;
			}
	}
}

void ListaDePreguntas::ordenarDescendente()
{
	int n = this->cantidad;

	Preguntas temp;
	bool switched = true;

	for (int pass = 0; pass < (n - 1) && switched; pass++)
	{
		switched = false;
		for (int j = 0; j < (n - 1 - pass); j++)
			if ((*this)[j] < (*this)[j + 1])
			{
				temp = (*this)[j];
				(*this)[j] = (*this)[j + 1];
				(*this)[j + 1] = temp;
				switched = true;
			}
	}
}

bool ListaDePreguntas::reemplazar(int indice, const Preguntas & unaCadena)
{
	bool replaced = false;

	if (indice >= 0 && indice < this->cantidad)
	{
		(*this)[indice] = unaCadena;
		replaced = true;
	}
	return(replaced);
}

bool ListaDePreguntas::reemplazar(int indice, const char * cadena)
{
	return(this->reemplazar(indice, Preguntas(cadena)));
}

const Preguntas & ListaDePreguntas::operator[](int indice) const
{
	return((this->cadena)[indice]);
}

Preguntas & ListaDePreguntas::operator[](int indice)
{
	return((this->cadena)[indice]);
}

int ListaDePreguntas::frecuencia(const Preguntas & unaCadena) const
{
	int f = 0;
	for (int i = 0; i < this->cantidad; i++)
		if ((*this)[i] == unaCadena)
			++f;
	return(f);
}

int ListaDePreguntas::frecuencia(const char * cadena) const
{
	return(this->frecuencia(Preguntas(cadena)));
}

int ListaDePreguntas::MaxPreguntas()
{
	return (MAX_COD);
}

bool ListaDePreguntas::estaLlena() const
{
	return(this->cantidad == MAX_COD);
}

bool ListaDePreguntas::estaVacia() const
{
	return (this->cantidad == 0);
}

bool ListaDePreguntas::incluye(const Preguntas & unaCadena) const
{
	return(this->indiceDe(unaCadena) != -1);
}

bool ListaDePreguntas::incluye(const char * cadena) const
{
	return(this->indiceDe(Preguntas(cadena)) != -1);
}

int ListaDePreguntas::indiceDe(const Preguntas & unaCadena) const
{
	int indice = -1;

	for (int i = 0; i < this->cantidad && indice == -1; i++)
		if ((*this)[i] == unaCadena)
			indice = i;

	return(indice);
}

int ListaDePreguntas::indiceDe(const char * cadena) const
{
	return(this->indiceDe(Preguntas(cadena)));
}

int ListaDePreguntas::indiceDeLaUltima(const Preguntas & unaCadena) const
{
	int indice = -1;

	for (int i = this->cantidad - 1; i >= 0 && indice == -1; i--)
		if ((*this)[i] == unaCadena)
			indice = i;
	return(indice);
}

int ListaDePreguntas::indiceDeLaUltima(const char * cadena) const
{
	return(this->indiceDeLaUltima(Preguntas(cadena)));
}

bool ListaDePreguntas::operator==(const ListaDePreguntas & unaLista) const
{
	bool equal = (this->cantidad == unaLista.cantidad);

	if (equal)
		for (int j = 0; j < this->cantidad && equal; j++)
			if ((*this)[j] != unaLista[j])
				equal = false;
	return(equal);
}

bool ListaDePreguntas::operator!=(const ListaDePreguntas & unaLista) const
{
	return (!((*this) == unaLista));
}

bool ListaDePreguntas::insertar(int indice, const Preguntas & unaCadena)
{
	bool inserted = false;

	if (!(this->estaLlena()) && indice >= 0 && indice <= this->cantidad)
	{
		for (int i = this->cantidad - 1; i >= indice; i--)
			(*this)[i + i] = (*this)[i];
		(*this)[indice] = unaCadena;
		++(this->cantidad);
		inserted = true;
	}
	return(inserted);
}

bool ListaDePreguntas::insertar(int indice, const char * cadena)
{
	return(this->insertar(indice, Preguntas(cadena)));
}

bool ListaDePreguntas::insertar(int indice, const ListaDePreguntas & unaLista)
{
	bool inserted = false;

	if (((this->cantidad + unaLista.cantidad) <= MAX_COD) && (indice >= 0 && indice <= this->cantidad))
	{
		for (int i = 0; i < unaLista.cantidad; i++)
			this->insertar(indice + i, unaLista[i]);
		inserted = true;
	}
	return(inserted);
}

bool ListaDePreguntas::insertarAlComienzo(const Preguntas & unaCadena)
{
	return(this->insertar(0, unaCadena));
}

bool ListaDePreguntas::insertarAlComienzo(const char * cadena)
{
	return(this->insertar(0, Preguntas(cadena)));
}

bool ListaDePreguntas::insertarAlComienzo(const ListaDePreguntas & unaLista)
{
	return(this->insertar(0, unaLista));
}

bool ListaDePreguntas::insertarAlFinal(const Preguntas & unaCadena)
{
	return(this->insertar(this->cantidad, unaCadena));
}

bool ListaDePreguntas::insertarAlFinal(const char * cadena)
{
	return(this->insertar(this->cantidad, Preguntas(cadena)));
}

bool ListaDePreguntas::insertarAlFinal(const ListaDePreguntas & unaLista)
{
	return(this->insertar(this->cantidad, unaLista));
}

ListaDePreguntas & operator+(const char * cadena, ListaDePreguntas & unaLista)
{
	unaLista.insertarAlComienzo(cadena);
	return(unaLista);
}

ListaDePreguntas & operator+(const Preguntas & unaCadena, ListaDePreguntas & unaLista)
{
	unaLista.insertarAlComienzo(unaCadena);
	return(unaLista);
}

ListaDePreguntas & operator-(const char * cadena, ListaDePreguntas & unaLista)
{
	unaLista.remover(unaLista.indiceDe(cadena));

	return (unaLista);
}

ListaDePreguntas & operator-(const Preguntas & unaCadena, ListaDePreguntas & unaLista)
{
	unaLista.remover(unaLista.indiceDe(unaCadena));

	return (unaLista);
}

//-----------------------------------------------------------------------------------

ostream & operator<<(ostream & out, const ListaDePreguntas & unaLista)
{
	if (unaLista.estaVacia())
		out << "La lista esta vacia." << endl;
	else
		for (int i = 0; i < unaLista.cantidad; i++)
			out << (i + 1) << ". " << unaLista[i] << endl << endl << endl << endl << endl;
	return(out);
}