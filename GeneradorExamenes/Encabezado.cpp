#include "Encabezado.h"


Encabezado::Encabezado(MyString Nombre, MyString ID, MyString Fecha, MyString Hora, MyDate FechaUsuario, MyTime HoraUsuario)
{
	this->Nombre = Nombre;
	this->ID = ID;
	this->Fecha = Fecha;
	this->Hora = Hora;
	this->FechaUsuario = FechaUsuario;
	this->HoraUsuario = HoraUsuario;
}

Encabezado & Encabezado::operator= (const Encabezado & unEncabezado)
{
	this->Nombre = unEncabezado.Nombre;
	this->ID = unEncabezado.ID;
	this->Fecha = unEncabezado.Fecha;
	this->Hora = unEncabezado.Hora;
	this->FechaUsuario = unEncabezado.FechaUsuario;
	this->HoraUsuario = unEncabezado.HoraUsuario;

	return (*this);
}

Encabezado::Encabezado(const Encabezado & unEncabezado)
{
	this->Nombre = unEncabezado.Nombre;
	this->ID = unEncabezado.ID;
	this->Fecha = unEncabezado.Fecha;
	this->Hora = unEncabezado.Hora;
	this->FechaUsuario = unEncabezado.FechaUsuario;
	this->HoraUsuario = unEncabezado.HoraUsuario;
}

Encabezado::~Encabezado()
{
}

void Encabezado::setNombre(MyString unNombre)
{
	this->Nombre = unNombre;
}

void Encabezado::setID(const MyString & unID)
{
	this->ID = unID;
}

void Encabezado::setFecha(const MyString & unaFecha)
{
	this->Fecha = unaFecha;
}

void Encabezado::setHora(const MyString & unaHora)
{
	this->Hora = unaHora;
}

void Encabezado::setFechaUsuario()
{
	int dia, mes, ano;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << "Por favor ingrese la fecha del examen. (Utilizando solo espacios entre ellos en este orden: mes, dia, a~o)" << endl;
	cin >> mes >> dia >> ano;
	this->FechaUsuario.setDay(dia);
	this->FechaUsuario.setMonth(mes);
	this->FechaUsuario.setYear(ano);
}

void Encabezado::setHoraUsuario()
{
	this->HoraUsuario.askHour();
	this->HoraUsuario.askMinutes();
}

const MyString & Encabezado::getNombre()const
{
	return (this->Nombre);
}

const MyString & Encabezado::getID()const
{
	return (this->ID);
}

const MyString & Encabezado::getFecha()const
{
	return (this->Fecha);
}

const MyString & Encabezado::getHora()const
{
	return (this->Hora);
}

const MyDate & Encabezado::getFechaUsuario() const
{
	return (this->FechaUsuario);
}

const MyTime & Encabezado::getHoraUsuario() const
{
	return (this->HoraUsuario);
}

void Encabezado::PedirFecha()
{
	&MyDate::askDate;
}

void Encabezado::PedirHora()
{
	&MyTime::askHour;
}

void Encabezado::MostrarFecha()const
{
	FechaUsuario.showDate();
}

void Encabezado::MostrarHora()const
{
	HoraUsuario.showHour();
}

void Encabezado::MostrarEncabezado()
{
	cout << getNombre();
	cout << getID();
	cout << getFecha();
	MostrarFecha();
	cout << "\t\t\t";
	cout << getHora();
	cout << getHoraUsuario();

	cout << "\n\n";
}
