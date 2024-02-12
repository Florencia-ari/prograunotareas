#include <iostream>

using namespace std;

int main()
{
    int num1, num2;

	cout << "Ingrese numero 1: ";
	cin >> num1;
	cout << "Ingrese numero 2: ";
	cin >> num2;

	if (num1 % num2 == 0) {
    cout << num1 << " es multiplo de " << num2 <<endl;
	} else {
    cout << num1 << " no es multiplo de " << num2 << endl;
	}
    return 0;
}
