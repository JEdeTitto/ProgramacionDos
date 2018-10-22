#include <time.h>
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	time_t today;
	time(&today);

	char Buffer[100];
	ctime_s(Buffer, sizeof(Buffer), &today);
	cout << Buffer;
	_getch();
	return 0;
}