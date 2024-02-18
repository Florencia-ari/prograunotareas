#include <iostream>

using namespace std;

int main() {

  int numero, mayor, contador;
  contador = 0;

  while (contador < 10) {
    cout << "Ingrese un numero: ";
    cin >> numero;

    if (numero> mayor) {
      mayor= numero;
    }

    contador++;
  }

  cout <<endl<< "El numero mayor es: " << mayor << endl;

  return 0;
}

