#include "Examen.h"



Examen::Examen(bool exist)
{
	this->exist = exist;
}

Examen::Examen(const Examen & unExamen)
{
	this->header = unExamen.header;
	this->body = unExamen.body;
}


Examen::~Examen()
{
	
}

Examen & Examen::operator=(const Examen & unExamen)
{
	this->header = unExamen.header;
	this->body = unExamen.body;
	return(*this);
}

void Examen::setLang(int lang)
{
	this->lang = lang;
}

void Examen::setHeader()
{
	this->header.setFechaUsuario();
	this->header.setHoraUsuario();
}

void Examen::setBody()
{
	this->body.setNum();
	this->body.setPregunta();
}

void Examen::setExist(bool exist)
{
	this->exist = exist;
}

bool Examen::getExist() const
{
	return this->exist;
}



void Examen::printExam()
{
	if (lang == 1)
	{
		cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		this->header.MostrarEncabezado();
		cout << "\nPreguntas:";
		this->body.printCuerpo();
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	}
	else
	{
		cout << "\n\n";
		this->header.setNombre("Name: ________________________\t\t");
		this->header.setFecha("Date: ");
		this->header.setID("ID:_______________\n");
		this->header.setHora("Time: ");
		this->header.MostrarEncabezado();
		cout << "\nQuestions:";
		this->body.printCuerpo();
	}
}

void Examen::MenuExam()
{
	MyMenu e;
	int decision;

	e.cambiarTitulo("Menu de Modificaciones");
	e.cambiarPregunta("Elija una opcion: ");
	e + "Editar Encabezado(Fecha y Hora)" + "Editar Preguntas" + "Remover Pregunta" + "Insertar Pregunta" + "Salida";
	do
	{
		cout << e;
		cin >> decision;
		switch (decision)
		{
		case 1:
			setHeader();
			printExam();
			break;
		case 2:
			int x;
			cout << "Existen " << body.getQnum() << " Preguntas." << endl << endl;
			body.printCuerpo();
			cout << "Que pregunta desea editar? ";
			cin >> x;
			while (x < 0 || x > body.getQnum())
			{
				cout << "\nPregunta equivocada, vuelva a ingresarla: ";
				cin >> x;
			}
			this->body.cambiarPregunta(x);
			break;
		case 3:
			int y;
			cout << "Existen " << body.getQnum() << " Preguntas." << endl << endl;
			body.printCuerpo();
			cout << "Que pregunta desea remover? ";
			cin >> y;
			while (y < 0 || y > body.getQnum())
			{
				cout << "\nPregunta equivocada, vuelva a ingresarla: ";
				cin >> y;
			}
			this->body.removerPregunta(y);
			break;
		case 4:
			
			this->body.insertarPregunta();
			break;
		case 5:
			cout << "La modificacion a sido exitosa." << endl;
			break;
		default:
			cout << "Error: Elija una de las opciones." << endl;
		}
	} while (decision != e.cantidadDeOpciones());

}


