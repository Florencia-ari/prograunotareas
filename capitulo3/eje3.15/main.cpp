#include <iostream>

using namespace std;

class Fecha {
public:
    Fecha(int mes, int dia, int año);
    void establecerMes(int mes);
    int obtenerMes() const;
    void establecerDia(int dia);
    int obtenerDia() const;
    void establecerAnio(int año);
    int obtenerAnio() const;
    void mostrarFecha() const;

private:
    int mes;
    int dia;
    int año;
};

Fecha::Fecha(int mes, int dia, int año)
: mes(mes), dia(dia), año(año)
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

void Fecha::establecerAnio(int año)
{
    this->año = año;
}

int Fecha::obtenerAnio() const
{
    return año;
}

void Fecha::mostrarFecha() const
{
    cout << mes << "/" << dia << "/" << año << endl;
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

