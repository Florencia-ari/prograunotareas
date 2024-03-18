#include <iostream>

using namespace std;

class Fecha {
public:
    Fecha(int mes, int dia, int a�o);
    void establecerMes(int mes);
    int obtenerMes() const;
    void establecerDia(int dia);
    int obtenerDia() const;
    void establecerAnio(int a�o);
    int obtenerAnio() const;
    void mostrarFecha() const;

private:
    int mes;
    int dia;
    int a�o;
};

Fecha::Fecha(int mes, int dia, int a�o)
: mes(mes), dia(dia), a�o(a�o)
{
    if (mes < 1 || mes > 12) {
        this->mes = 1;
    }
}

void Fecha::establecerMes(int mes)
{
    if (mes < 1 || mes > 12) {
        this->mes = 1;
    } else {
        this->mes = mes;
    }
}

int Fecha::obtenerMes() const
{
    return mes;
}

void Fecha::establecerDia(int dia)
{
    this->dia = dia;
}

int Fecha::obtenerDia() const
{
    return dia;
}

void Fecha::establecerAnio(int a�o)
{
    this->a�o = a�o;
}

int Fecha::obtenerAnio() const
{
    return a�o;
}

void Fecha::mostrarFecha() const
{
    cout << mes << "/" << dia << "/" << a�o << endl;
}

int main()
{
    Fecha fecha(13, 25, 2023);

    fecha.mostrarFecha();

    fecha.establecerMes(2);
    fecha.establecerDia(14);
    fecha.establecerAnio(2024);

    fecha.mostrarFecha();

    return 0;
}

