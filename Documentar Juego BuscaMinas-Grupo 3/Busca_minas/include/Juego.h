#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h" //incluye la definicion de la clase Tablero

//Se define clase
class Juego
{
private:
	Tablero tablero;//se crea objeto tablero de la clase Tablero
	//se encapsulan los atributos para acceder a ellos solo con metodos(que no puede acceder ni ver el usuario)
	int cantidadMinas;

	int aleatorio_en_rango(int minimo, int maximo);//crea los numeros aleatoriamente en un rango
	//decide donde se colocan las minas filas y columnas
	int filaAleatoria();
	int columnaAleatoria();
public:
    Juego(Tablero tablero, int cantidadMinas);//constructor que recibe tablero y cantidad de minas
	void colocarMinasAleatoriamente();//coloca las minas aleatoriamente
	 //conocer donde esta ubicado el usuario
	int solicitarFilaUsuario();
	int solicitarColumnaUsuario();
	//metodo para ver si la condiciones se cumplen y gana el jugador
	bool jugadorGana();
	//metodo para iniciar el juego
	void iniciar();

	void dibujarPortada(string nombreArchivo);
};

#endif // JUEGO_H
