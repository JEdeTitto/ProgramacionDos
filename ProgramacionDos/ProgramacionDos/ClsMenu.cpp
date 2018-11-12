#include "ClsMenu.h"

void ClsMenu::Agregar_Items(ClsMenuItem pItem)
{
	vecItems[ContadorOpcion] = pItem;
	ContadorOpcion++;
}

int ClsMenu::MostrarMenu()
{
	int retorno;
	system("cls");
	cout << "MENU: " << Nombre << endl;
	cout << "Opciones:" << endl;
	for (int i = 0; i < ContadorOpcion; i++)
	{
		cout << i + 1 << "). ";
		cout << vecItems[i].Titulo << " - ";
		cout << vecItems[i].Descripcion << endl;
	}
	cout << "Elija su opcion: ";
	cin >> retorno;
	return retorno;
}
