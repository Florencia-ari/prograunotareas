#include <iostream>
#include <iomanip>
//Maria Florencia Ariaga Chiroy

using namespace std;

int main()
{

  float ventas;
  float pago;

  while (true) {
    cout << "Introduzca las ventas en dolares (-1 para salir): ";
    cin >> ventas;

    if (ventas == -1) {
      break;
    }

    pago = 200 + (ventas * 0.09);

    cout << "El salario es: $" << pago<< endl;
  }

  return 0;
}
