#include <iostream>

using namespace std;

int main()
{
    float km_dia, gasolina, estacionamiento, peaje;

	cout << "kilometros por dia: ";
	cin >> km_dia;
	cout << "costo de gasolina por litro: ";
	cin >> gasolina;
	cout << "cuotas de estacionamiento por dia: ";
	cin >> estacionamiento;
	cout << "peaje por dia: ";
	cin >> peaje;

	float consumo_gasolina = km_dia / 10;
	float costo_gasolina = consumo_gasolina * gasolina;
	float costo_total = costo_gasolina + estacionamiento + peaje;
	cout << "El costo total por dia es: " << costo_total << endl;

	float costo_compartido = costo_total / 2;
	cout << "Si comparte el viaje el costo es: " << costo_compartido << endl;

    return 0;
}
