#include <iostream>
#include "conio.h"
#include "Base.h"

#include "../Ahorcado/Ahorcado.h";
#include "../Asistencia_Cursadas/AsistenciaCursadas.h";
#include "../Materias_Aprobadas/MateriasAprobadas.h";

using namespace std;

void ShowMenuOptions();
int SelectMenuOption();

int main() {
	bool exitFlag = false;
	
	Base __base = Base("Grupo Integrador 2018");
	cout << __base.getFirma() << endl;
	ShowMenuOptions();

	while (!exitFlag) {
		int selectedOption = 0;

		selectedOption = SelectMenuOption();
		switch (selectedOption) {
		case 1:
			cout << "Seleccionado: 1" << endl;
			Ahorcado::Run();
			break;
		case 2:
			cout << "Seleccionado: 2" << endl;
			AsistenciaCursadas::Run();
			break;
		case 3:
			cout << "Seleccionado: 3" << endl;
			MateriasAprobadas::Run();
			break;
		case 9:
			cout << "Saliendo..." << endl;
			exitFlag = true;
			break;
		}
	}

	_getch();
	return 0;
}

void ShowMenuOptions() {
	cout << "======================" << endl;
	cout << "Ahorcado: 1" << endl;
	cout << "Asistencia Cursadas: 2" << endl;
	cout << "Materias Aprobadas: 3" << endl;
	cout << "======================" << endl;
	cout << "Salir: 9" << endl;
	cout << "======================" << endl << endl;
}

int SelectMenuOption() {
	int opt = 0;
	cout << "Ingrese el elemento deseado:";	cin >> opt;
	return opt;
}