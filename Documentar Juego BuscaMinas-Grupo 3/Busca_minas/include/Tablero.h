#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <vector>
#include "Celda.h"

using namespace std;

//Definir la clase tablero y definir sus metodos publicos y protegidos
class Tablero
{
	//Metodos Publicos
    public:
    	//Constructor por defecto de la clase
        Tablero();
        //Constructor que inicializa un tablero con una altura, ancho y modo de desarrollo especificados
        Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);
        //Metodos get y set para obtener y establecer la altura, ancho y modo desarrollador del tablero
        int getAlturaTablero();
        int setAlturaTablero(int alturaTablero);
        int getAnchoTablero();
        int setAnchoTablero(int anchoTablero);
        bool getModoDesarrollador();
        bool setModoDesarrollador(bool modoDesarrollador);
        //Metodos para imprimir el tablero y sus separadores
        void imprimirSeparadorEncabezado();
        void imprimirSeparadorFilas();
        void imprimirEncabezado();
        void imprimir();
        //Metodos para colocar y descubrir minas en el tablero y tambien para contar el numero de celdas sin minas y sin descubrir
        bool colocarMina(int x, int y);
        bool descubrirMina(int x, int y);
        int contarCeldasSinMinasYSinDescubrir();


    //Metodos protegidos y privados
    protected:

    private:
    	//Almacenar la altura y el ancho del tablero
        int alturaTablero, anchoTablero;
        //indica si el juego esta en modo desarrollador
        bool modoDesarrollador;
        //matriz bidemensional de objetos, que representan el contenido del trablero del juego
        vector<vector<Celda> > contenidoTablero;

        string getRepresentacionMina(int x, int y);
        int minasCercanas(int fila, int columna);
};

#endif // TABLERO_H
