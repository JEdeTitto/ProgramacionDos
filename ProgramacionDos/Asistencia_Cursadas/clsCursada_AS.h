#pragma once
//#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "clsBase_AS.h"
#include "clsAlumno_AS.h"
#include "clsMateria_AS.h"

using namespace std;
class clsCursada_AS : clsBase_AS
{
private:
	void cargarVectorAlumnos();
protected:
	string getCadena();
public:
	int codCursada;
	string nombreProfesor;
	time_t fechaInicio;
	string turnoCursada;
	clsMateria_AS materiaCursada;
	clsAlumno_AS *alumnosCursada;

	clsCursada_AS();
	clsCursada_AS(int, string, time_t, string, clsMateria_AS);
	void mostrarRegistro();
	//string getCadena();
	void grabar();
};

clsCursada_AS::clsCursada_AS(int cod, string nombre, time_t fecha, string turno, clsMateria_AS mate)
{
	this->codCursada = cod;
	this->nombreProfesor = nombre;
	this->fechaInicio = fecha;
	this->turnoCursada = turno;
	this->materiaCursada = mate;
	cargarVectorAlumnos();
	this->nombreArchivo = "lista_cursadas.txt";
}

clsCursada_AS::clsCursada_AS()
{
	cargarVectorAlumnos();
	this->nombreArchivo = "lista_cursadas.txt";
}

void clsCursada_AS::cargarVectorAlumnos()
{
	try
	{
		int i = 0, desde = 0, hasta = 0;
		string linea;
		ifstream Archivo;
		Archivo.open(nombreArchivo);
		if (Archivo.is_open())
		{
			while (getline(Archivo, linea))
			{
				i++;
			}

			//creo el vector de alumnos
			alumnosCursada = new clsAlumno_AS[i];
			for (int y = 0; y < i; y++)
			{
				Archivo >> linea;
				//cod_alumno
				hasta = linea.find(";"); // 2
				alumnosCursada[y].codAlumno = stoi(linea.substr(desde,hasta)); //(0,2)
			}
			Archivo.close();
		}
		else
			throw exception("Error al cargar alumnos en vector ");
	}
	catch (const std::exception& EX)
	{
		cout << "Error en el Archivo" << EX.what();
		throw EX;
	}
}

void clsCursada_AS::mostrarRegistro()
{
	cout << this->codCursada << "/t" << nombreProfesor << "/t" << fechaInicio << "/t" << turnoCursada << endl;
}

//string clsMateria_AS::getCadena()
//{
//	string retorno("");
//	retorno += to_string(this->codCursada);
//	retorno += ";";
//	retorno += this->nombreProfesor;
//	retorno += ";";
//	retorno += to_string(this->fechaInicio);
//	retorno += ";";
//	retorno += to_string(this->turnoCursada);
//	retorno += "\n";
//
//	return retorno;
//}

void clsCursada_AS::grabar()
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
