#include "Base.h"
#include "conio.h"
#include <iostream>

using namespace std;

int main() {
	Base __base = Base("ProgII");
	cout << __base.getFirma() << endl;
	_getch();
	return 0;
}