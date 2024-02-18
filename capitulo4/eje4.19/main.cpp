#include <iostream>

using namespace std;

int main() {

  int numero, mayor,mayor2, contador;
  contador = 0;

  while (contador < 10) {
    cout << "Ingrese un numero: ";
    cin >> numero;

    if (numero> mayor) {
      mayor2= mayor;
      mayor=numero;
    }else if (numero > mayor2){
    	mayor2=numero;
    	}

    contador++;
  }

  cout <<endl<< "El numero mayor es: " << mayor << endl;
  cout<<"El segundo numero mayor es:"<<mayor2;

  return 0;
}

