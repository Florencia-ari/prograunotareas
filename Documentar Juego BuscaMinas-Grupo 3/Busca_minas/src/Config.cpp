//Incluimos las librerias que necesitaremos
#include <iostream>
#include <unistd.h> //Esta libreria nos servirá para usar funciones como system, que nos permite borrar pantalla con el "cls" y realizar una pausa con "pause"
#include "Config.h" //Incluimos el header de nuestra clase config, el archivo de encabezado que es: config.h
using namespace std;
//Agregamos los atributos al constructor
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero)
{
    //Construimos el objeto y colocamos this para identificar el objeto a utilizar
    this->filasTablero = filasTablero;
    this->columnasTablero = columnasTablero;
    this->minasTablero = minasTablero;
    this->modoDesarrolladorTablero = modoDesarrolladorTablero;
    this->vidasTablero = vidasTablero;
}
void Config::menuConfiguracion() //Llamamos a nuestra clase que usaremos en el main
{
    //Reutilizamos parte del codigo del main
    int opciones;
    int valorIngresado;
    bool repetir = true;
    do
    {
        system("cls"); //limpiamos pantalla
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl; //Mostramos los datos actuales, la 1ra vez muestra las constantes
        cout << "\t\t-------------------"<< endl;
        //Los get traen los objetos para poder modificarlos
        cout << "\t\t1. Filas del Tablero ----> " << this->getfilasTablero() << endl;
        cout << "\t\t2. Columnas del Tablero -> " << this->getcolumnasTablero() << endl;
        cout << "\t\t3. Minas del Tablero ----> " << this->getminasTablero() << endl;
        cout << "\t\t4. Modo del Juego -------> " << this->getmodoDesarrolladorTablero() << endl;
        cout << "\t\t5. Vidas del Jugador ----> " << this->getvidasTablero() << endl;
        cout << "\t\t6. Regresar al menu general" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        if (opciones!=6)//Verificamos la opcion que se escogió
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";
            cin >> valorIngresado;
        }
        switch (opciones) //Con el switch modificamos los valores predeterminados segun la opción
        {
        case 1: //Caso 1 modifica las filas del tablero
            {
                this->setfilasTablero(valorIngresado);
                cout << "Filas del Tablero actualizadas" << endl;
                break;
            }
        case 2: //Caso 2 modifica las columnas del tablero
            {
                this->setcolumnasTablero(valorIngresado);
                cout << "Columnas del Tablero actualizadas" << endl;
                break;
            }
        case 3: //Caso 3 modifica las minas que saldran en el tablero
            {
                this->setminasTablero(valorIngresado);
                cout << "Minas del Tablero actualizadas" << endl;
                break;
            }
        case 4: //Caso 4 modifica en que modo de juego estaremos
            {
                this->setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Juego actualizado" << endl;
                break;
            }
        case 5: //Caso 5 modifica las vidas del juego
            {
                this->setvidasTablero(valorIngresado);
                cout << "Vidas del Juego actualizadas" << endl;
                break;
            }
        case 6: repetir = false; //Caso 6 nos regresa al menú principal
                break;
        }
        system("pause"); //Muestra una pausa en donde tendremos que tocar cualquier tecla para continuar
    } while (repetir);
}
//Creamos los set y get de cada objeto utilizado, con el fin que se guarden las modificaciones que realicemos al juego
int Config::getfilasTablero()
{
    return this->filasTablero;
}
int Config::setfilasTablero(int filasTablero)
{
    this->filasTablero=filasTablero;
}
int Config::getcolumnasTablero()
{
    return this->columnasTablero;
}
int Config::setcolumnasTablero(int columnasTablero)
{
    this->columnasTablero=columnasTablero;
}
int Config::getminasTablero()
{
    return this->minasTablero;
}
int Config::setminasTablero(int minasTablero)
{
    this->minasTablero=minasTablero;
}
bool Config::getmodoDesarrolladorTablero()
{
    return this->modoDesarrolladorTablero;
}
bool Config::setmodoDesarrolladorTablero(bool modoDesarrolladorTablero)
{
    this->modoDesarrolladorTablero=modoDesarrolladorTablero;
}
int Config::getvidasTablero()
{
    return this->vidasTablero;
}
int Config::setvidasTablero(int vidasTablero)
{
    this->vidasTablero=vidasTablero;
}
