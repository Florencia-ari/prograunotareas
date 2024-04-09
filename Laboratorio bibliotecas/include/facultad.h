//encabezados
#ifndef FACULTAD_H
#define FACULTAD_H
//biblioteca para las cadenas con caracteres
#include <string>

//definimos valores constantes que se utilizaran
#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

//clase facultad
class Facultad
{
	//metodos privados y publicos

	public:
		 void ejecutarCiclo();
	protected:

	private:
		int buscarAleatorio(int minimo, int maximo);
		void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);
		void imprimirLineaMatriz();
		float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], std::string nombreFacultad);
};

#endif // FACULTAD_H
