#include "MateriasAprobadas.h"
#include <iostream>

using namespace std;

void MateriasAprobadas::Run()
{
	ClsMenuItem op1 = ClsMenuItem("Opcion 1", "Materias Aprobadas");
	ClsMenuItem op2 = ClsMenuItem("Opcion 2", "Materias Aprobadas");
	ClsMenuItem op3 = ClsMenuItem("Opcion 3", "Materias Aprobadas");
	ClsMenu oM(3);

	oM.Agregar_Items(op1);
	oM.Agregar_Items(op2);
	oM.Agregar_Items(op3);

	int valor_devuelto;
	valor_devuelto = oM.MostrarMenu();
	cout << "Devolvio: " << valor_devuelto;
	_getch();
}
