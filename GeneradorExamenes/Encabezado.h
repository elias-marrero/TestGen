#include "MyString2.h"
#include "MyDate2.h"
#include "MyTime2.h"

#pragma once
class Encabezado
{
private:
	MyString Nombre, ID, Fecha, Hora;
	MyDate FechaUsuario;
	MyTime HoraUsuario;

public:
	Encabezado(MyString Nombre = "Nombre: ________________________\t\t", MyString ID = "ID:_______________\n",
		MyString Fecha = "Fecha: ", MyString Hora = "Hora: ", MyDate FechaUsuario = 1, MyTime HoraUsuario = 1);
	Encabezado(const Encabezado & unEncabezado);
	Encabezado & operator = (const Encabezado & unEncabezado);
	~Encabezado();

	void setNombre(MyString unNombre);
	void setID(const MyString & unID);
	void setFecha(const MyString & unaFecha);
	void setHora(const MyString & unaHora);
	void setFechaUsuario();
	void setHoraUsuario();

	const MyString & getNombre() const;
	const MyString & getID() const;
	const MyString & getFecha() const;
	const MyString & getHora() const;
	const MyDate & getFechaUsuario() const;
	const MyTime & getHoraUsuario() const;

	void PedirFecha();
	void PedirHora();
	void MostrarFecha() const;
	void MostrarHora() const;
	void MostrarEncabezado();

};
