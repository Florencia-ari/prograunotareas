#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;

#define NUMERO_CANDIDATOS 5
#define NUMERO_AFILIADOS 1000000
#define NUMERO_RONDAS 4

void generarVotosAleatorios(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS]);
void imprimirResultados(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS], string candidatos[]);
void calcularGanador(int matriz[NUMERO_CANDIDATOS][NUMERO_RONDAS], string candidatos[]);

int main()
{
    cout << "----------- Parcial 1 Maria Florencia Ariaga Chiroy -------------------" << endl;
    cout << "------------------ 9959-23-6741 -------------------" << endl<< endl;
	//numeros aleatorios
    srand(time(nullptr));

    string candidatos[NUMERO_CANDIDATOS];
    int votos[NUMERO_CANDIDATOS][NUMERO_RONDAS];

    cout << "Ingrese el Nombre de los Candidatos:" << endl  << endl;
    for (int i = 0; i < NUMERO_CANDIDATOS; ++i) {
        cout << "Candidato " << i + 1 << ": ";
        getline(cin, candidatos[i]);
    }

    char opcion;
    do {
        generarVotosAleatorios(votos);
        imprimirResultados(votos, candidatos);
        calcularGanador(votos, candidatos);

        cout << "¿Desea realizarlo de nuevo? (si/no): ";
        cin >> opcion;
        cin.ignore(); // Limpiar
    } while (opcion == 'si' || opcion == 'SI');


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
    cout << "\n---------------RESULTADOS------------------:\n"<< endl;
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

    cout << "\nCandidato ganador: " << candidatos[indiceMax] << " = " << maxVotos << " votos.\n";
    cout << "Candidato con menos votos: " << candidatos[indiceMin] << " = " << minVotos << " votos.\n";
}

