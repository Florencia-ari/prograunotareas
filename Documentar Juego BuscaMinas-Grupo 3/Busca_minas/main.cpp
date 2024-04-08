//librerias utilizadas dentro del programa
#include <iostream> //libreria estandar que controla las entradas y salidas de informaci�n
#include <unistd.h> //libreria que controla el acceso a la API del sistema operativo

//Archivos de Implementaci�n
#include "Juego.h"//libreria que contiene la declaraci�n de la clase Juego
#include "Config.h"//libreria que contiene la declaraci�n de la clase Config

using namespace std;

int main()
{
    //constantes que contienen las dimensiones de la matriz
    const int FILASTABLERO = 5;
    const int COLUMNASTABLERO = 5;

    //minas que va a contener la matriz
    const int MINASENTABLERO = 3;

    //constante que permite la modificaci� del modo desarrollador"
    const bool MODODESARROLLADOR = true;

    //vidas disponibles para el jugador
    const int VIDASTABLERO = 3;

    //clase que maneja la configuraci�n del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);

    //inicializaci�n del juego
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    srand(getpid());
    int opciones;

    //inicializaci�n del ciclo que repite el proceso al menos una vez
    bool repetir = true;
    do
    {
        //limpia la pantalla
        system("cls");

        //despliegue del menu
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t-------------------"<< endl;
        cout << "\t\t1. Configuaracion del Juego" << endl;
        cout << "\t\t2. Iniciar el Juego" << endl;
        cout << "\t\t3. Salir del Juego" << endl;
        cout << "\n\t\tIngrese una opcion: ";

        //opciones disponibles que permiten la modificaci�n del juego
        cin >> opciones;

        //switch procesa los cambios almanecados en la funci�n opciones
        switch (opciones)
        {
        //despliega el men� de configuraci�nes para realizar cambios
        case 1:
            {
                configuracionJuego.menuConfiguracion();
                break;
            }
        //inicia un juego temporal con la configuaci�n actual
        case 2:
            {
              	Juego juegoTemporal(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
                juegoTemporal.iniciar();

                system("pause");
                break;
            }
        //cierra el ciclo
        case 3: repetir = false;
                break;
        }
    //ciclo que repite una vez m�s el proceso
    } while (repetir);

    //limpia la pantalla
    system("cls");
    return 0;
}
