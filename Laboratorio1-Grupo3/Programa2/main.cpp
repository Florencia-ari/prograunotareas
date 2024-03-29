//Sistema de votaci�n

//Librerias Utilizadas
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//Constantes Simbolicas

#define NUMERO_CANDIDATOS 5
#define NUMERO_AFILIADOS 50
#define NUMERO_RONDAS 5

// Funciones

void generarVotosAleatorios(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS]);
void imprimirResultados(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS], string candidatos[]);
void calcularGanador(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS], string candidatos[]);

//Funcion Main

int main() {

	//Encabezado
	cout<<endl<<  "********************** Laboratorio1 - Modulo 1 - Grupo 3 ***********************" << endl << endl;

	//Numeros Aleatorios

    srand(time(nullptr));


    string candidatos[NUMERO_CANDIDATOS];
    int votos[NUMERO_CANDIDATOS][NUMERO_RONDAS];

	//Candidatos
    cout << "Ingrese el Nombre de los Candidatos:" << endl  << endl;
    for (int i = 0; i < NUMERO_CANDIDATOS; ++i) {
        cout << "Candidato " << i + 1 << ": ";
        getline(cin, candidatos[i]);
    }

    char opcion;
    //Generar botos
    do {
        generarVotosAleatorios(votos);
        imprimirResultados(votos, candidatos);
        calcularGanador(votos, candidatos);

		//Repetir proceso
        cout << "�Desea realizarlo de nuevo? (si/no): ";
        cin >> opcion;
        cin.ignore(); // Limpiar
    } while (opcion == 'si' || opcion == 'SI'|| opcion == 's'|| opcion == 'S');

    return 0;
}

void generarVotosAleatorios(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS]) {
    for (int i = 0; i < NUMERO_CANDIDATOS; ++i) {
        for (int j = 0; j < NUMERO_RONDAS; ++j) {
            matriz[i][j] = rand() % (NUMERO_AFILIADOS + 1); // Generar votos aleatorios entre 0 y NUMERO_AFILIADOS
        }
    }
}

void imprimirResultados(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS], string candidatos[]) {
    cout << "\n-------------------------RESULTADOS----------------------------:\n"<< endl;

    cout << setw(15) << "Candidato";
    for (int i = 0; i < NUMERO_RONDAS; ++i) {

        cout << setw(10) << "Ronda " << i + 1;
    }
    cout << endl;

    for (int i = 0; i < NUMERO_CANDIDATOS; ++i) {
        cout << setw(15) << candidatos[i];


        for (int j = 0; j < NUMERO_RONDAS; ++j) {
            cout << setw(10) << matriz[i][j];
        }
        cout << endl;
    }
}

void calcularGanador(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS], string candidatos[]) {
    int totalVotos[NUMERO_CANDIDATOS] = {0};

    // Calcular el total de votos
    for (int i = 0; i < NUMERO_CANDIDATOS; ++i) {
        for (int j = 0; j < NUMERO_RONDAS; ++j) {
            totalVotos[i] += matriz[i][j];
        }
    }

    // Encontrar el candidato ganador y el candidato con menos votos
    int maxVotos = totalVotos[0];
    int minVotos = totalVotos[0];
    int indiceMax = 0;
    int indiceMin = 0;

    for (int i = 1; i < NUMERO_CANDIDATOS; ++i) {
        if (totalVotos[i] > maxVotos) {
            maxVotos = totalVotos[i];
            indiceMax = i;
        }
        if (totalVotos[i] < minVotos) {
            minVotos = totalVotos[i];
            indiceMin = i;
        }
    }

    cout << "\nCandidato ganador: " << candidatos[indiceMax] << " = " << maxVotos << " votos.\n"<< endl;
    cout << "Candidato con menos votos: " << candidatos[indiceMin] << " = " << minVotos << " votos.\n"<< endl<< endl;
}
