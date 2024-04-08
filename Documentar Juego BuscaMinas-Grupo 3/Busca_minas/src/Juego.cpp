#include "Juego.h"
#include <fstream>//libreria que permite el manejo, escritura y lectura de archivos externos del programa
#include <unistd.h> //libreria que proporciona acceso a la Api del sistema operativo POSIX


//primer metodo privado que genera numero aleatorio en el rango que se envía
int Juego::aleatorio_en_rango(int minimo, int maximo)
	{
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1); //retona numero aleatorio entre el minimo y maximo
	}
//segundo metodo privado genera numero aleatorio para ubicar la mina en fila aleatorio,
	int Juego::filaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1); //retorna un numero aleatorio como minimo 0 y como maximo la altura del tablero que es el total de filas(trae el dato de la clase tablero el metodo getAnchoTablero)
	}

//segundo metodo privado genera numero aleatorio para ubicar la mina en columna aleatorio,
	int Juego::columnaAleatoria()
	{
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);//retorna un numero aleatorio como minimo 0 y como maximo lel ancho del tablero que es el total de columnas(trae el dato de la clase tablero el metodo getAnchoTablero)
	}


//constructor que recibe e inicializa tablero, cantidad de minas y colocacion de minas aleatorias por medio de un metodo
	Juego::Juego(Tablero tablero, int cantidadMinas)
	{
		this->tablero = tablero; //objeto tablero
		this->cantidadMinas = cantidadMinas; //cantidad de minas atributo privado de juego.h
		this->colocarMinasAleatoriamente();
	}
//primer metodo publico, coloca las minas aleatiamente, no retorna nada solo ubica cursor
	void Juego::colocarMinasAleatoriamente()
	{
		int x, y, minasColocadas = 0; //inicia declarando entero x,y y minas colocadas con valor 0
		//inicia ciclo while mientras minasColocadas sea menor a la cantidad de minas que fue enviada al constructor, el cilo sigue iterando
		while (minasColocadas < this->cantidadMinas)
		{
			x = this->columnaAleatoria();//llama al metodo columnaAleatoria generando un numero aleatorio dentro del rango de columnas y lo asigna a x
			y = this->filaAleatoria();//llama al metodo filaAleatoria generando un numero aleatorio dentro del rango de filas y lo asigna a y
			if (this->tablero.colocarMina(x, y)) //manda x, y a tablero al metodo colocarMina que coloca la mina y devuelve un true
			{
				//al ser true minasColocadas se incrementa
				minasColocadas++;
			}
		}
	}
//segundo metodo publico, pregunta al usuario en que fila va a jugar
	int Juego::solicitarFilaUsuario()
	{
		int fila = 0; //declara entero a fila con un valor inicial de 0 para no ocupar espacio innecesario en memoria
		cout << "Ingresa la FILA en la que desea jugar: "; //pregunta al usuario
		cin >> fila; //almacena valor en variable fila
		return fila - 1; //retorna fila - 1 por los vectores que inician en 0
	}
//tercer metodo publico, pregunta al usuario en que columna va a jugar
	int Juego::solicitarColumnaUsuario()
	{
		int columna = 0;//declara entero a variable columna con un valor inicial de 0 para no ocupar espacio innecesario en memoria
		cout << "Ingresa la COLUMNA en la que desea jugar: ";//pregunta al usuario
		cin >> columna;//almacena valor en variable columna
		return columna - 1;//retorna fcolumna - 1 por los vectores que inician en 0
	}
//cuarto metodo publico, retorna un dato booleano 0 o 1, para saber si el jugador gana o pierde
	bool Juego::jugadorGana()
	{
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir(); //declara entero variable conteo que le asigna el numero de minas sin descubrir
		//decisor que verifica si conteo es igual a 0, retorna true, jugador gana si no el jugador descubrio una mina y pierde
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
//quinto metodo publico, inicia juego
	void Juego::iniciar()
	{
		int fila, columna;//declara entero variables fila y columna
		while (true) //ciclo que iterara hasta que encuentre un break
		{
			this->tablero.imprimir();//imprime el tablero, llamando desde la clase tablero al metodo imprimir
			fila = this->solicitarFilaUsuario(); //llama a metodo solicitarFilaUsuario y asigna el valor a fila
			columna = this->solicitarColumnaUsuario();//llama a metodo solicitarColumnaUsuario y asigna el valor a columna
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila); //declara boolean respuestaAUsuario y llama al metodo descubrirMina de la clase Tablero mandando los valores columna y fila retornando un true o false
			//decisor que verifica si respuestaAUsuario negado es false entonces manda un mensaje que usuario pierde el juego
			if (!respuestaAUsuario)
			{
				cout << "Perdiste el Juego\n"; //muestra mensaje
				this->tablero.setModoDesarrollador(true);//llama al metodo setModoDesarrollador de la clase Tablero con un valor true para mostrar el tablero en modo desarrollador
				this->tablero.imprimir();//imprime tablero
				break;//finaliza ciclo y termina juego
			}
			//decisor que verifica si en el metodo jugadorGana es true entonces jugador gana
			if (this->jugadorGana())
			{
				cout << "Ganaste el Juego\n";//muestra mensaje
				this->tablero.setModoDesarrollador(true);//llama al metodo setModoDesarrollador de la clase Tablero con un valor true para mostrar el tablero en modo desarrollador
				this->tablero.imprimir();//imprime tablero
				break;//finaliza ciclo y termina juego
			}
		}
	}
