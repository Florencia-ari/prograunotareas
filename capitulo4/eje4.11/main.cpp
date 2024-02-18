#include <iostream>

using namespace std;

int main()
{
	//Maria Florencia Ariaga Chiroy
	//a

    if (edad >= 65) {
		cout << "Edad es mayor o igual que 65" << endl;
	} else {
		cout << "Edad es menor que 65" << endl;
	}

	//b

	if (edad >= 65) {
		cout << "Edad es mayor o igual que 65" << endl;
	} else {
		cout << "Edad es menor que 65" << endl;
	}

	//c

	unsigned int x = 1;
	unsigned int total=0;

	while (x <= 10) {
    total +=x;
    ++x;
	}

	//d

	while (x <= 100) {
		total += x;
		x++;
	}

	//e

	while (y > 0) {
		cout << y << endl;
		y--;
	}

    return 0;
}
