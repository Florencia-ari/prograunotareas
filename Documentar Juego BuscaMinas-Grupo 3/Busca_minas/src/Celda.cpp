#include "Celda.h"
#include <iostream>
using namespace std;
//constructor vacio
Celda::Celda()
{
}
//constructor con atributos
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
    this->mina = estadoMina;
    this->minaDescubierta = false;
}
//llamamos al atributo con set y  inicializamos coordenadaX
int Celda::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX;
}
//llamamos al atributo con get y  retornara la coordenadaX
int Celda::getCoordenadaX()
{
    return this->coordenadaX;
}
//llamamos al atributo con set y  inicializamos coordenaday
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;
}
//llamamos al atributo con get y  retornara la coordenadaX
int Celda::getCoordenadaY()
{
    return this->coordenadaY;
}
//booleano que establece el estado de la mina
bool Celda::setMina(bool estadoMina)
{
    //si la celda llegara a tener una mina devovera un false
    if (this->getMina())
    {
        return false;
    }
    //de lo contrario mostrara un true
    else{
        this->mina = estadoMina;
        return true;
    }
}

bool Celda::getMina()
{
    return this->mina;
}
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta;
}
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta;
}
// no devuelve nada solo imprime la celda en la cordenada X y coordenada Y
void Celda::imprimirCelda()
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}
