#include <iostream>
using namespace std;

int main()
{
	//a) Inicializar la variable unsigned int contadorEstudiantes con 0.
	unsigned int contadorEstudiantes{0};

	//b) Inicializar la variable double saldoInicial con 1000.0
	double saldoInicial{1000.0};

	//c)Inicializar un objeto de la clase cuenta que proporcione un constructor
	//que reciba un unsigned int, dos string y un double para inicializar los
	//miembros de datos numeroCuenta, primerNombre, apellido y saldo.

    class Cuenta {
public:
  unsigned int numeroCuenta;
  string primerNombre;
  string apellido;
  double saldo;

  Cuenta(unsigned int numeroCuenta, string primerNombre, string apellido, double saldo) {
    this->numeroCuenta = numeroCuenta;
    this->primerNombre = primerNombre;
    this->apellido = apellido;
    this->saldo = saldo;
  }
};
    return 0;
}
