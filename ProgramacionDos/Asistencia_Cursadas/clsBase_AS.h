#pragma once
//#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>

using namespace std;
class clsBase_AS
{
protected:
	string nombreArchivo;
	virtual string getCadena() =0;
public:
	virtual void mostrarRegistro() =0;
	virtual void grabar() =0;

	void recuperar() {};
	
	clsBase_AS();
};

