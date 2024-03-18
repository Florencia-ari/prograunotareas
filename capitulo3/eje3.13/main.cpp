#include <iostream>
#include <string>

using namespace std;

class Factura {
public:
	Factura(string numeroPieza, string descripcion, int cantidad, int precio);
	void mostrarFactura() const;
private:
	string numeroPieza;
	string descripcion;
	int cantidad;
	int precio;
};
Factura::Factura(string numeroPieza, string descripcion, int cantidad, int precio)
: numeroPieza(numeroPieza), descripcion(descripcion), cantidad(cantidad), precio(precio)
{
}
void Factura::mostrarFactura() const
{
	cout << "Numero de pieza: " << numeroPieza << endl;
	cout << "Descripcion: " << descripcion << endl;
	cout << "Cantidad: " << cantidad << endl;
	cout << "Precio por unidad: " << precio << endl;
	cout << "Total: " << precio * cantidad << endl;
}
int main()
{
	Factura factura("1", "clavos", 2, 10);
	factura.mostrarFactura();
	return 0;
}
