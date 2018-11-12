#include <iostream>
#include "conio.h"
#include "Base.h"

#include "../Ahorcado/Ahorcado.h";
#include "../Asistencia_Cursadas/AsistenciaCursadas.h";
#include "../Materias_Aprobadas/MateriasAprobadas.h";

using namespace std;

int main() {
	bool exitFlag = false;
	
	ClsMenuItem op1 = ClsMenuItem("Ahorcado", "Grupo 1");
	ClsMenuItem op2 = ClsMenuItem("Asistencia Cursadas", "Grupo 2");
	ClsMenuItem op3 = ClsMenuItem("Materias Aprobadas", "Grupo 3");
	ClsMenuItem op4 = ClsMenuItem("Salir", "");
	ClsMenu oM(4);

	oM.Agregar_Items(op1);
	oM.Agregar_Items(op2);
	oM.Agregar_Items(op3);
	oM.Agregar_Items(op4);

	int valor_devuelto;

	Base __base = Base("Grupo Integrador 2018");
	cout << __base.getFirma() << endl;

	while (!exitFlag) {
		int selectedOption = 0;
		selectedOption = oM.MostrarMenu();

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
		case 4:
			cout << "Saliendo..." << endl;
			exitFlag = true;
			break;
		}
	}
	return 0;
}