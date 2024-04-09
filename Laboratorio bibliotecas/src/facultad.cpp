#include "facultad.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

//implementacion del metodo ejecutar ciclo de la clase Facultad
void Facultad::ejecutarCiclo() {
	//declaramos e inicializamos las variables
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;
    bool repetir = true;

    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;

    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Carlos", "Luis", "Maria", "Pedro", "Juan"};
   //iniciamos un ciclo do - while que ejecutara el ciclo de funcionamiento de la facultad mientras repetir sea verdadero
    do {
        system("cls");
        promedio_facultad_1 = 0;
        promedio_facultad_2 = 0;
        promedio_facultad_3 = 0;
        cout << "*** Comparativo de Facultades ***" << endl << endl;
        //llamamos a los metodos de llemar matriz e imprimir matriz
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");

       //calculamos el promedio y se realiza la comparación
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3) {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
        } else if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3) {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
        } else if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1) {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
        } else {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea realizar otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n') {
            repetir = false;
        }
    } while (repetir);
}

//Implementaciones de los metodos buscar aleatorio, llenar matriz e imprimir matriz
int Facultad::buscarAleatorio(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void Facultad::llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]) {
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++) {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++) {
            if (x == 0 || x == 3)  //primer parcial
            {
                calificacion = buscarAleatorio(MIN_CALIFICACION, 20);
            } else if (x == 1)  //segundo parcial
            {
                calificacion = buscarAleatorio(MIN_CALIFICACION, 25);
            } else if (x == 2)  //examen final
            {
                calificacion = buscarAleatorio(MIN_CALIFICACION, 35);
            }
            suma += (float) calificacion;
            matriz[y][x] = calificacion;
            calificacion = 0;
        }
        // Agregar promedio

        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void Facultad::imprimirLineaMatriz() {
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++) {
        cout << "+---------";
    }
    cout << "+\n";
}

float Facultad::imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad) {
    //Función que imprime la matriz en pantalla y realizando los cálculos necesarios del promedio
    int y, x;

    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirLineaMatriz();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++) {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirLineaMatriz();
    for (y = 0; y < NUMERO_ALUMNOS; y++) {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++) {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor) {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor) {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirLineaMatriz();
    }
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "Nota mayor: " << setw(10) << alumnoPromedioMayor << setw(10) << promedioMayor << endl;
    cout << "Nota menor: " << setw(10) << alumnoPromedioMenor << setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) << promedioGeneral << endl << endl;
    return promedioGeneral;
}
