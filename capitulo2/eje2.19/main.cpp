#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3;
    cout << "Ingrese numero 1: ";
    cin >> num1;
    cout << "Ingrese numero 2: ";
    cin >> num2;
    cout << "Ingrese numero 3: ";
    cin >> num3;

	int suma = num1 + num2 + num3;
	float promedio = (float)suma / 3;
	int producto = num1 * num2 * num3;
	int minimo = num1;

	if (num2 < minimo) {
		minimo = num2;
	}
	if (num3 < minimo) {
		minimo = num3;
	}

	int maximo = num1;
	if (num2 > maximo) {
		maximo = num2;
	}
	if (num3 > maximo) {
		maximo = num3;
	}

	cout << "La suma es " << suma <<endl;
	cout << "El promedio es " << promedio << endl;
	cout << "El producto es " << producto << endl;
	cout << "El menor es " << minimo << endl;
	cout << "El mayor es " << maximo <<endl;

    return 0;
}
