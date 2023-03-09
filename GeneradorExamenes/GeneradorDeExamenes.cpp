#include "GeneradorDeExamenes.h"



GeneradorDeExamenes::GeneradorDeExamenes(int indice)
{
	this->indice = indice;
}

GeneradorDeExamenes::GeneradorDeExamenes(const GeneradorDeExamenes & aGen)
{
	this->indice = indice;
}


GeneradorDeExamenes::~GeneradorDeExamenes()
{
	delete[] a;
}

GeneradorDeExamenes & GeneradorDeExamenes::operator=(const GeneradorDeExamenes & aGen)
{
	return(*this);
}

void GeneradorDeExamenes::setExam()
{
	this->a[indice].setHeader();
	this->a[indice].setBody();
}


void GeneradorDeExamenes::MenuGen()
{
	MyMenu m;
	int decision;

	m.cambiarTitulo("\nMenu de Generador de Examenes");
	m.cambiarPregunta("Elija una opcion: ");
	m + "Crear un Examen" + "Modificar un Examen" + "Imprimir Examen" + "Salir";
	do
	{
		cout << m;

		if (!(cin >> decision))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
			cout << "\n****\n" << "Error - Por favor elija una de las opciones. (1, 2, 3, 4)" << "\n****";
		}
		switch (decision)
		{
			case 1: 
				int l;
				cout << "\nDesea el modelo del examen en espa~ol o en ingles? (Ingrese 1 para espa~ol y 2 para ingles)\n";
				cin >> l;
				while (l < 1 || l > 2)
				{
					cout << "\nError - Ingrese una opcion valida: ";
					cin >> l;
				}
				this->a[indice].setLang(l);
				this->a[indice].setExist(true);
				setExam();
				this->a[indice].printExam();
				indice++;
				break;
			case 2:
				if (a[0].getExist())
				{
					int x;
					cout << "\nExisten " << indice << " Examenes." << endl << endl;
					cout << "Que examen desea editar? ";
					cin >> x;
					while (x < 0 || x > indice)
					{
						cout << "\nError - Examen equivocado, vualva a ingresarlo: ";
						cin >> x;
					}
					a[x - 1].MenuExam();
				}
				else
					cout << "\n****\n" << "No se a creado un examen aun." << "\n****\n";
				break;
			case 3:
				if (a[0].getExist())
				{
					int y;
					cout << "\nExisten " << indice << " Examenes." << endl << endl;
					cout << "Que examen desea imprimir? ";
					cin >> y;
					while (y < 0 || y > indice)
					{
						cout << "\nError - Examen equivocado, vualva a ingresarlo: ";
						cin >> y;
					}
					a[y - 1].printExam();
				}
				else
					cout << "\n****\n" << "No existe examen para imprimir." << "\n****\n";
				break;		
			case 4:
				cout << "\n****\n" << "Fin del programa." << "\n****\n" << endl;
				break;
			default:
				cout << endl;
		}
	} 
	while (decision != m.cantidadDeOpciones());

}


