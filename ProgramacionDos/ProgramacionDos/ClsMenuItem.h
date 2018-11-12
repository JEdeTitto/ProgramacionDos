#pragma once

#include <conio.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class ClsMenuItem {
	public:
		string Titulo;
		string Descripcion;
		ClsMenuItem() {};
		ClsMenuItem(string _titulo, string _descripcion) {
			Titulo = _titulo;
			Descripcion = _descripcion;
		};
};