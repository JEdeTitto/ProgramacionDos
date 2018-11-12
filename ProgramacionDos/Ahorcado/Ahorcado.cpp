#include "Ahorcado.h"
#include <iostream>

using namespace std;

void Ahorcado::Run()
{
	ClsMenuItem op1 = ClsMenuItem("Alfa", "Descripcion Alfa");
	ClsMenuItem op2 = ClsMenuItem("Beta", "Descripcion Beta");
	ClsMenuItem op3 = ClsMenuItem("Gama", "Descripcion Gama");
	ClsMenu oM(3);

	oM.Agregar_Items(op1);
	oM.Agregar_Items(op2);
	oM.Agregar_Items(op3);

	int valor_devuelto;
	valor_devuelto = oM.MostrarMenu();
	cout << "Devolvio: " << valor_devuelto;

	_getch();
	cout << "Ahorcado" << endl;
}
