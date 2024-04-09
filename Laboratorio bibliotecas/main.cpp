// Tarea de Maria Florencia Ariaga Chiroy

//archivo de encabezado
#include "facultad.h"

//Biblioteca para generar numeros aleatorios
#include <cstdlib>

//biblioteca que proporciona funciones y tipos para trabajar con el tiempo y la fecha del sistema
#include <ctime>

using namespace std;

//funcion principal
int main()
{
	//generar numeros aleatorios
    srand(time(nullptr));
    Facultad facultad;
    //se llama el metodo ejecutarciclo del objeto facultad
    facultad.ejecutarCiclo();
    return 0;
}
