#include "AsistenciaCursadas.h"
#include <iostream>

using namespace std;

void AsistenciaCursadas::Run()
{
	ClsMenuItem op1 = ClsMenuItem("Opcion 1", "Asistencia Cursadas");
	ClsMenuItem op2 = ClsMenuItem("Opcion 2", "Asistencia Cursadas");
	ClsMenuItem op3 = ClsMenuItem("Opcion 3", "Asistencia Cursadas");
	ClsMenu oM(3);

	oM.Agregar_Items(op1);
	oM.Agregar_Items(op2);
	oM.Agregar_Items(op3);

	int valor_devuelto;
	valor_devuelto = oM.MostrarMenu();
	cout << "Devolvio: " << valor_devuelto;
	_getch();
}
