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
class clsAlumno_AS : clsBase_AS
{
protected:
	string getCadena();
public:
	int codAlumno;
	int dniAlumno;
	string nombreApellidoAlumno;

	clsAlumno_AS();
	clsAlumno_AS(int, int, string);
	void mostrarRegistro();
	void grabar();
};

clsAlumno_AS::clsAlumno_AS(int cod, int dni, string nombre)
{
	this->codAlumno = cod;
	this->dniAlumno = dni;
	this->nombreApellidoAlumno = nombre;
	this->nombreArchivo = "lista_alumnos.txt";
}

clsAlumno_AS::clsAlumno_AS()
{
	this->nombreArchivo = "lista_alumnos.txt";
}

void clsAlumno_AS::mostrarRegistro()
{
	cout << this->codAlumno << "/t" << dniAlumno << "/t" << nombreApellidoAlumno << endl;
}

string clsAlumno_AS::getCadena()
{
	string retorno("");
	retorno += to_string(this->codAlumno);
	retorno += ";";
	retorno += to_string(this->dniAlumno);
	retorno += ";";
	retorno += this->nombreApellidoAlumno;
	retorno += "\n";

	return retorno;
}

void clsAlumno_AS::grabar()
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