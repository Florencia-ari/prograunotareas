#include <iostream>

using namespace std;

int main() {
  int a, b, c;

  cout << "Ingrese el primer numero: ";
  cin >> a;

  cout << "Ingrese el segundo numero: ";
  cin >> b;

  cout << "Ingrese el tercer numero: ";
  cin >> c;

  if (a + b > c && a + c > b && b + c > a) {

    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
      cout << "Los numeros SI pueden ser los lados de un triangulo rectangulo" << endl;
    } else {
      cout << "Los numeros NO pueden ser los lados de un triangulo rectangulo." << endl;
    }
  } else {
    cout << "Los numeros NO pueden ser los lados de un triangulo rectangulo" << endl;
  }

  return 0;
}
