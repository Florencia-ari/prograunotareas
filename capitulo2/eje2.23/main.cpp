#include <iostream>

using namespace std;

int main()
{
     int num1, num2, num3, num4, num5;
     int mayor, menor;

     cout << "Ingrese numero 1: ";
	 cin >> num1;
     cout << "Ingrese numero 2: ";
     cin >> num2;
     cout << "Ingrese numero 3: ";
     cin >> num3;
     cout << "Ingrese numero 4: ";
     cin >> num4;
     cout << "Ingrese numero 5: ";
     cin >> num5;

	mayor = menor = num1;

	if (num2 > mayor) {
		mayor = num2;
	}
	if (num3 > mayor) {
		mayor = num3;
	}
	if (num4 > mayor) {
		mayor = num4;
	}
	if (num5 > mayor) {
		mayor = num5;
	}

	if (num2 < menor) {
		menor = num2;
	}
	if (num3 < menor) {
		menor = num3;
	}
	if (num4 < menor) {
		menor = num4;
	}
	if (num5 < menor) {
		menor = num5;
	}

	cout << "El mayor es " << mayor << endl;
	cout << "El menor es " << menor << endl;
    return 0;
}
