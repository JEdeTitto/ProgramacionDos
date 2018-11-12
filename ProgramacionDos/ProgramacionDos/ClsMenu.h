#pragma once
#include <string>
#include "ClsMenuItem.h"

class ClsMenu {
	private:
		int ContadorOpcion = 0;
	public:
		string Nombre = "Menu ejercicio 8";
		ClsMenuItem *vecItems;  //le digo que vecItems será un vector, pero todavía no sé cuántas posiciones 
		ClsMenu(int opciones) {
			vecItems = new ClsMenuItem[opciones];
		};
		void Agregar_Items(ClsMenuItem);
		int MostrarMenu();
};