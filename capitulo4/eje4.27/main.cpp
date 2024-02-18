#include <iostream>

using namespace std;

int main() {
	//Maria Florencia Ariaga Chiroy
  int binario, digito, decimal = 0, exponente = 1;

  cout << "Ingrese un numero binario: ";
  cin >> binario;

  while (binario > 0) {
    digito =binario % 10;
    decimal += digito * exponente;

    exponente *= 2;

    binario /= 10;
  }

  cout << "El valor en decimal es: " << decimal << endl;

  return 0;
}

