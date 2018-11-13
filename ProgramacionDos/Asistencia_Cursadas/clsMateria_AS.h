#pragma once
//#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "clsBase_AS.h"

using namespace std;
class clsMateria_AS : clsBase_AS
{
protected:
	string getCadena();
public:
	int codMateria;
	string nombreMateria;
	int cantClases;

	clsMateria_AS();
	clsMateria_AS(int, string,int);
	void mostrarRegistro();
	void grabar();
};

clsMateria_AS::clsMateria_AS(int cod, string nombre, int cant)
{
	this->codMateria = cod;
	this->cantClases = cant;
	this->nombreMateria = nombre;
	this->nombreArchivo = "lista_materias.txt";
}

clsMateria_AS::clsMateria_AS()
{
	this->nombreArchivo = "lista_materias.txt";
}

void clsMateria_AS::mostrarRegistro()
{
	cout << this->codMateria << "/t" << nombreMateria << "/t" << cantClases << endl;
}

string clsMateria_AS::getCadena()
{
	string retorno("");
	retorno += to_string(this->codMateria);
	retorno += ";";
	retorno += this->nombreMateria;
	retorno += ";";
	retorno += to_string(this->cantClases);
	retorno += "\n";

	return retorno;
}

void clsMateria_AS::grabar()
{
	try
	{
		int i;
		ofstream Archivo;
		Archivo.open(nombreArchivo);
		if (Archivo.is_open())
		{
			Archivo << this->getCadena();
			Archivo.close();
		}
		else
			throw exception("Error al intentar abrir el archivo ");
	}
	catch (const std::exception& EX)
	{
		cout << "Error en el Archivo" << EX.what();
		throw EX;
	}
}
