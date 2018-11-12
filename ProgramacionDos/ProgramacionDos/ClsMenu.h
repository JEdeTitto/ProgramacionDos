#pragma once
#include <string>
#include "ClsMenuItem.h"

class ClsMenu {
	private:
		int ContadorOpcion = 0;
	public:
		string Nombre = "Menu ejercicio 8";
		ClsMenuItem *vecItems;  //le digo que vecItems ser� un vector, pero todav�a no s� cu�ntas posiciones 
		ClsMenu(int opciones) {
			vecItems = new ClsMenuItem[opciones];
		};
		void Agregar_Items(ClsMenuItem);
		int MostrarMenu();
};