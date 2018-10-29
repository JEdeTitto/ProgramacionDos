#pragma once

#include <Windows.h>
#include <conio.h>
#include <string.h>

using namespace std;

/*
	Tipos de botones a utilizar por el control uaiMessageBoxConsole
*/
enum uaiMessageBoxConsoleType {
	Aceptar,
	Aceptar_Cancelar
};

/*
	Control muestra por pantalla el mensaje seleccionado con opciones de 
	solo aceptar o aceptar-cancelar. Retorna con TRUE(aceptacion) o FALSE(cancelacion)
*/
class uaiMessageBoxConsole
{
private:
	SMALL_RECT __rectMsg = { 15, 5, 65, 15 };
	string __button_aceptar =  " ACEPTAR ";
	string __button_cancelar = " CANCELAR ";
	bool __seleccion = true;
	uaiMessageBoxConsoleType __type;

	HANDLE __orig_handle_output, __msgb_handle_output;

	int _word_wrap(std::string strResult[], char* string, int line_width);
	bool _create_handle_console();
	void _draw_messagebox();
	void _draw_title(string tit);
	void _draw_message(string msg);

	void _draw_buttons_aceptar();
	void _draw_buttons_aceptar_cancelar();

	void _draw_buttons();
	bool _get_button_selection();
public:
	uaiMessageBoxConsole();
	~uaiMessageBoxConsole();

	bool ShowMessage(string titulo, string msg, uaiMessageBoxConsoleType tipo);
};

/////////////////////////////////////////////////////////////////////////////
/// PRIVADO

// dado un texto determinado y la ongituda maxima de ancho
// genera una lista con el texto correspondiente a cada linea
// haciendo un salto si la palabra no entra en la linea.
// devuelve la cantidad de lineas generadas
inline int uaiMessageBoxConsole::_word_wrap(std::string strResult[], char* string, int line_width)
{
	int i = 0;
	int k, counter;
	int lines = 0;
	while (i < strlen(string))
	{
		for (counter = 1; counter <= line_width; counter++)
		{
			if (i == strlen(string))
			{
				strResult[lines] += (char)0;
				return ++lines;
			}

			if (string[i] == '\n')
			{
				strResult[lines] += (char)0;
				lines++;
				counter = 1;
			}
			else {
				strResult[lines] += string[i];
			}
			i++;
		}

		if (isspace(string[i]))
		{
			strResult[lines] += (char)0;
			i++;
			lines++;
		}
		else
		{
			for (k = i; k > 0; k--)
			{
				if (isspace(string[k]))
				{
					strResult[lines] += (char)0;
					i = k + 1;
					lines++;
					break;
				}
			}
		}
	}
	strResult[lines] += (char)0;
	return ++lines;
}

// recupera el handle de consola y recupera el contenido actual de pantalla
// y copia el contenido al nuevo buffer temporal
inline bool uaiMessageBoxConsole::_create_handle_console()
{
	SMALL_RECT sRect;
	COORD coordBufSize;
	COORD coordBufCoord;
	CHAR_INFO chiBuffer[2000]; //[25][80];
	bool fSuccess;

	__orig_handle_output = GetStdHandle(STD_OUTPUT_HANDLE);
	__msgb_handle_output = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
					FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	if (__orig_handle_output == INVALID_HANDLE_VALUE || __msgb_handle_output == INVALID_HANDLE_VALUE) {
		return false;
	}
	if (!SetConsoleActiveScreenBuffer(__msgb_handle_output)) {
		return false;
	}

	sRect = { 0, 0, 80, 25 };
	coordBufSize = { 80, 25 };
	coordBufCoord = { 0, 0 };

	//lee el contenido de la pantalla
	if (!ReadConsoleOutput(__orig_handle_output, chiBuffer, coordBufSize, coordBufCoord, &sRect)) {
		return false;
	}

	//graba el contenido al nuevo buffer para imprimir la ventan de mensaje
	if (!WriteConsoleOutput(__msgb_handle_output, chiBuffer, coordBufSize, coordBufCoord, &sRect)) {
		return false;
	}

	return true;
}

// dibuja el borde del cuadro de messagebox
inline void uaiMessageBoxConsole::_draw_messagebox()
{
	COORD cursor;
	char ch_VERT_DBL = 186; 
	char ch_HORIZ_DBL = 205;
	char ch_HORIZ_SNG = 196;

	char ch_SUPIZQ = 201;
	char ch_SUPDER = 187;
	char ch_INFIZQ = 200;
	char ch_INFDER = 188;

	short spcs = __rectMsg.Right - __rectMsg.Left - 1;

	//verticales
	for (SHORT i = __rectMsg.Top + 1; i < __rectMsg.Bottom; i++) {
		cursor = { __rectMsg.Left, i }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
		std::cout << ch_VERT_DBL + string(spcs, ' ') + ch_VERT_DBL;
	}

	//horizontales
	for (SHORT i = __rectMsg.Left + 1; i < __rectMsg.Right; i++) {
		cursor = {i, __rectMsg.Top }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
		std::cout << ch_HORIZ_DBL;

		cursor = { i, __rectMsg.Top + 2 }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
		std::cout << ch_HORIZ_SNG;

		cursor = { i, __rectMsg.Bottom - 2 }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
		std::cout << ch_HORIZ_SNG;

		cursor = { i, __rectMsg.Bottom }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
		std::cout << ch_HORIZ_DBL;
	}

	cursor = { __rectMsg.Left, __rectMsg.Top };	SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << ch_SUPIZQ;

	cursor = { __rectMsg.Right, __rectMsg.Top }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << ch_SUPDER;

	cursor = { __rectMsg.Left, __rectMsg.Bottom }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << ch_INFIZQ;

	cursor = { __rectMsg.Right, __rectMsg.Bottom };	SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << ch_INFDER;
}

// titulo
inline void uaiMessageBoxConsole::_draw_title(string tit)
{
	short width = __rectMsg.Right - __rectMsg.Left - 2;
	if (tit.length() >= width) {
		tit = tit.substr(0, width - 5) + "...";
	}

	short sep = ((__rectMsg.Right - __rectMsg.Left) - tit.length()) / 2;
	COORD cursor = { __rectMsg.Left + sep, __rectMsg.Top + 1 };
	SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << tit;
}

// mensaje
inline void uaiMessageBoxConsole::_draw_message(string msg)
{
	short textwidth = __rectMsg.Right - __rectMsg.Left - 2;
	short textheight = __rectMsg.Bottom - __rectMsg.Top - 5;

	std::string msglines[25]; 

	char pmsg[80*25] = { 0 };
	msg.copy(pmsg, msg.length());

	int textlines = _word_wrap(msglines, pmsg, textwidth);
	if (textlines > textheight) textlines = textheight;

	//busca desde que linea para centrar
	int desdeLin = __rectMsg.Top + 3 + ((textheight - textlines)/2);

	for (int l = 0; l < textlines; l++)
	{
		COORD cursor = { __rectMsg.Left + 1, desdeLin + l };
		SetConsoleCursorPosition(__msgb_handle_output, cursor);
		std::cout << msglines[l];
	}
}

// solo boton aceptar
inline void uaiMessageBoxConsole::_draw_buttons_aceptar()
{
	SHORT sep;
	COORD cursor;
	sep = ((__rectMsg.Right - __rectMsg.Left) - __button_aceptar.length()) / 2;
	SetConsoleTextAttribute(__msgb_handle_output, 0xF0); 
	cursor = { __rectMsg.Left + sep, __rectMsg.Bottom - 1 }; 
	SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << __button_aceptar;
}

// botones aceptar y cancelar
inline void uaiMessageBoxConsole::_draw_buttons_aceptar_cancelar()
{
	SHORT sep;
	COORD cursor;

	sep = ((__rectMsg.Right - __rectMsg.Left) - __button_aceptar.length() - __button_cancelar.length()) / 3;

	if (__seleccion) { SetConsoleTextAttribute(__msgb_handle_output, 0xF0); }
	cursor = { __rectMsg.Left + sep, __rectMsg.Bottom - 1 }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << __button_aceptar;

	if (!__seleccion) { SetConsoleTextAttribute(__msgb_handle_output, 0xF0); }
	else { SetConsoleTextAttribute(__msgb_handle_output, 0x0F); }
	cursor = { __rectMsg.Left + sep + (SHORT)__button_aceptar.length() + sep, __rectMsg.Bottom - 1 }; SetConsoleCursorPosition(__msgb_handle_output, cursor);
	std::cout << __button_cancelar;
}


inline void uaiMessageBoxConsole::_draw_buttons()
{
	switch (__type)
	{
	case Aceptar:
		_draw_buttons_aceptar();
		break;
	case Aceptar_Cancelar:
		_draw_buttons_aceptar_cancelar();
		break;
	default:
		break;
	}
}


// seleccion de botones por flechas
// ENTER acepta la opcion seleccionada
// ESC lo toma como cancelacion
inline bool uaiMessageBoxConsole::_get_button_selection()
{
	while (true) {
		_draw_buttons();
		int ch = _getch();
		if (ch == 13)
		{
			return __seleccion;
		}
		else if (ch == 27)
		{
			__seleccion = false;
			return __seleccion;
		}
		else if (ch == 224) //flechas
		{
			ch = _getch();
			if ((ch == 77) || (ch == 75))
			{
				__seleccion = !__seleccion;
			}
		}
	}
	return false;
}



uaiMessageBoxConsole::uaiMessageBoxConsole()
{
}

uaiMessageBoxConsole::~uaiMessageBoxConsole()
{
}

/////////////////////////////////////////////////////////////////////////////
/// PUBLICO

inline bool uaiMessageBoxConsole::ShowMessage(string titulo, string msg, uaiMessageBoxConsoleType tipo)
{
	__type = tipo; //guarda internamente el tipo de mensaje a mostrar

	if (!_create_handle_console()) return false; //crea el buffer de pantalla

	_draw_messagebox(); //dibuja contenedor del messagebox

	_draw_title(titulo); // titulo

	_draw_message(msg); // mensaje

	bool bR = _get_button_selection(); // loop de seleccion de opcion

	SetConsoleActiveScreenBuffer(__orig_handle_output); // recupera buffer original

	return bR; //retorna con opcion seleccionada
}
