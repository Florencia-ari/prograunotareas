#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;
//definiendo variables constantes
#define MAX_GOL 10
#define MIN_GOL 1
#define NUMERO_EQUIPO 6

//definiendo prototipo
void llamarCiclo();

int GeneraGoles(int Matriz[15][2],string equipo1, string equipo2);
int Aleatorio(int minimo,int maximo);

int main()
{
    //llamando funcion
    llamarCiclo();
    return 0;
}
//funcion
void llamarCiclo()
{
    int x=0;
    int y=0;
    int equipoA;
    int equipoB;
    int Matriz[15][2];
    int n;
    int nmarcador[6][5];
    string MatrizNom[15][2];
    string nombresEquipos[NUMERO_EQUIPO];
    string equipo2;
    string equipo1;
    int MatrizGoles[15][2]; //cambiar por Matriz a MatrizGoles
    char opcion;
    bool repetir=true;
    do
    {

        system("cls");
        for (int f=0;f<=5;f++)
        {
            for(int c=0;c<=4;c++)
            {
                nmarcador[f][c]=0;

            }
        }

        for (int i=0; i<NUMERO_EQUIPO;i++)
        {
            cout<<"Ingrese el nombre del equipo "<< i+1<<": ";
            cin >> nombresEquipos[i];
        }
        int pos=0;
        int posB=1;
        int par_jugA[6]={0,0,0,0,0,0};
        int par_jugB[6]={0,0,0,0,0,0};
        int Par_ganA[6]={0,0,0,0,0,0};
        int Par_ganB[6]={0,0,0,0,0,0};
        int Par_perA[6]={0,0,0,0,0,0};
        int Par_perB[6]={0,0,0,0,0,0};
        int Par_empA[6]={0,0,0,0,0,0};
        int Par_empB[6]={0,0,0,0,0,0};
        //CICLO GENERA GOLES PARTIDOS DE IDA
        for (n=1;n<=5;n++)
        {
            equipo1=nombresEquipos[n-1]; //E1  E2
            int n1=n; //N1=1  N1=2
            int sentiB=posB; //toma el valor de la posB VALE 1 2DA VUELTA  VALE 2
            for (int i=n+1;i<=6;i++)
            {
                equipo2=nombresEquipos[n1]; //E2  E3
                equipoA=Aleatorio(MIN_GOL,MAX_GOL);
                equipoB=Aleatorio(MIN_GOL,MAX_GOL);
                Matriz[x][y]=equipoA; //X=0 Y=0
                Matriz[x][y+1]=equipoB;//X=0 Y=1
                MatrizNom[x][y]=equipo1;
                MatrizNom[x][y+1]=equipo2;
                cout<<MatrizNom[x][y]; //VERIFICAR X DONDE SE DEBE SUMAR
                cout<<'-';
                cout<<MatrizNom[x][y+1];
                cout<<"     ";
                cout<<Matriz[x][y];
                cout<<'-';
                cout<<Matriz[x][y+1]<<endl;
                n1++; //2  AHORA VALE 3
                par_jugA[pos]++; //POS 0 CORRESPONDE AL E1   AHORA CORRESPONDE AL E2
                par_jugB[sentiB]++; //POSB VALE 1 CORRESPONDE AL E3
                if (equipoA>equipoB)
                {
                    Par_ganA[pos]++;
                    Par_perB[sentiB]++;
                }else if (equipoA<equipoB)
                {
                    Par_perA[pos]++;
                    Par_ganB[sentiB]++;
                }else
                {
                    Par_empA[pos]++;
                    Par_empB[sentiB]++;
                }
                sentiB++; //SENTI VALE 2 QUE EN SIG CICLO CORRESPONDE AL EQUIPO E3 AHORA SENTI B AHORA VALE 3

                /*for (int g=0;g<=5;g++)
                {
                    cout<<par_jugA[g];
                    cout<<"    ";
                    cout<<par_jugB[g];
                    cout<<"    ";
                    cout<<Par_ganA[g];
                    cout<<"    ";
                    cout<<Par_ganB[g]<<endl;
                }*/
            } //finaliza primer ciclo
            //pos++; //POS VALE 1
            //posB++; //AHORA VALE 2// creo que tendria que ir despues del ciclo donde integra en la matriz marcador


            for (int i=pos; i<=n;i++) //POS VALE 0  N VALE 1
            {
                int tot=0;
                for (int y=0;y<=3;y++)
                {
                    if (i==pos) //SI I ES IGUAL 0
                    {
                        switch(y) //donde opción es la variable a comparar
                        {
                            case 0: nmarcador[i][y]+=par_jugA[pos];//revisar que variable es n o pos o que otra
                            break;
                            case 1: nmarcador[i][y]+=Par_ganA[pos];
                            break;
                            case 2: nmarcador[i][y]+=Par_perA[pos];
                            break;
                            case 3: nmarcador[i][y]+=Par_empA[pos];
                            break;
                        }
                    }else if (i==n) //SI I ES IGUAL A N QUE ES 1
                    {
                        switch(y) //donde opción es la variable a comparar
                        {
                            case 0: nmarcador[i][y]+=par_jugB[n];//revisar que variable es n o pos o que otra
                            break;
                            case 1: nmarcador[i][y]+=Par_ganB[n];
                            break;
                            case 2: nmarcador[i][y]+=Par_perB[n];
                            break;
                            case 3: nmarcador[i][y]+=Par_empB[n];
                            break;
                        }
                    }
                }
            }
            pos++; //POS VALE 1
            posB++; //AHORA VALE 2// creo que tendria que ir despues del ciclo donde integra en la matriz marcador
        }



        // DE VUELTA

        for (int h=0;h<6;h++)
        {
            par_jugA[h]=0;
            par_jugB[h]=0;
            Par_ganA[h]=0;
            Par_ganB[h]=0;
            Par_perA[h]=0;
            Par_perB[h]=0;
            Par_empA[h]=0;
            Par_empB[h]=0;
        }

        pos=0;
        posB=1;
        for (n=1;n<=5;n++)
        {
            //int nmarcador[6][4]; //si se agrega funcion nmarcador - eliminar esta definicion
            //int par_jugA[6]={0,0,0,0,0,0};
            //int par_jugB[6]={0,0,0,0,0,0};
            equipo1=nombresEquipos[n-1];
            int n1=n;
            int sentiB=posB; //toma el valor de la posB
            for (int i=n+1;i<=6;i++)
            {
                equipo2=nombresEquipos[n1];
                equipoA=Aleatorio(MIN_GOL,MAX_GOL);
                equipoB=Aleatorio(MIN_GOL,MAX_GOL);
                Matriz[x][y]=equipoA;
                Matriz[x][y+1]=equipoB;
                MatrizNom[x][y]=equipo1;
                MatrizNom[x][y+1]=equipo2;
                cout<<MatrizNom[x][y];
                cout<<'-';
                cout<<MatrizNom[x][y+1];
                cout<<"     ";
                cout<<Matriz[x][y];
                cout<<'-';
                cout<<Matriz[x][y+1]<<endl;
                n1++;
                par_jugA[pos]++;
                par_jugB[sentiB]++; //verificar
                if (equipoA>equipoB)
                {
                    Par_ganA[pos]++;
                    Par_perB[sentiB]++;
                }else if (equipoA<equipoB)
                {
                    Par_perA[pos]++;
                    Par_ganB[sentiB]++;
                }else
                {
                    Par_empA[pos]++;
                    Par_empB[sentiB]++;
                }
                sentiB++;
                //cout<<sentiB<<endl; //verifica que sentiB si este cambiando de valor
                /*for (int g=0;g<=5;g++)
                {
                    cout<<par_jugA[g];
                    cout<<"    ";
                    cout<<par_jugB[g];
                    cout<<"    ";
                    cout<<Par_ganA[g];
                    cout<<"    ";
                    cout<<Par_ganB[g]<<endl;
                }*/
            } //finaliza primer ciclo
        // creo que tendria que ir despues del ciclo donde integra en la matriz marcador
            //x++;


            //JUEGOS DE VUELTA

            for (int i=pos; i<=n;i++) //POS VALE 0  N VALE 1
            {
                int tot=0;
                for (int y=0;y<=3;y++)
                {
                    if (i==pos) //SI I ES IGUAL 0
                    {
                        switch(y) //donde opción es la variable a comparar
                        {
                            case 0: nmarcador[i][y]+=par_jugA[pos];//revisar que variable es n o pos o que otra
                            break;
                            case 1: nmarcador[i][y]+=Par_ganA[pos];
                            break;
                            case 2: nmarcador[i][y]+=Par_perA[pos];
                            break;
                            case 3: nmarcador[i][y]+=Par_empA[pos];
                            break;
                        }
                    }else if (i==n) //SI I ES IGUAL A N QUE ES 1
                    {
                        switch(y) //donde opción es la variable a comparar
                        {
                            case 0: nmarcador[i][y]+=par_jugB[n];//revisar que variable es n o pos o que otra
                            break;
                            case 1: nmarcador[i][y]+=Par_ganB[n];
                            break;
                            case 2: nmarcador[i][y]+=Par_perB[n];
                            break;
                            case 3: nmarcador[i][y]+=Par_empB[n];
                            break;
                        }
                    }
                }
            }
            pos++;
            posB++;
        }

        //CICLO RECORRE LA MATRIZ, SUMANDO LOS PARTIDOS GANADOS*3 Y EMPATADOS
        for (int f=0;f<=5;f++)
        {
            for(int c=0;c<=3;c++)
            {
                if (c==1 )
                {
                    nmarcador[f][4]+=nmarcador[f][c]*3;
                }else if (c==3)
                {
                    nmarcador[f][4]+=nmarcador[f][c];
                }
            }
        }
        int Gan=nmarcador[0][4];
        int Per=nmarcador[0][4];
        int gana=0, pier=0;
        for (int q=0;q<5;q++)
        {
            int Var=nmarcador[q+1][4];
            if (Var > Gan)
            {
                Gan=Var; gana=q+1;
            }
            if (Var < Per)
            {
                Per=Var; pier=q+1;
            }
        }
        cout << "\n\nEl equipo "<<nombresEquipos[gana]<<" es CAMPEON! con "<<Gan<<" puntos."<<endl;
        cout << "El equipo "<<nombresEquipos[pier]<<" BAJA de categoria con "<<Per<<" puntos."<<endl;
        cout<<"\n                                     *MARCADOR*"<<endl;

        cout<<endl;
        cout<<" ---------------------------------------------------------------------------------------"<<endl;
        cout<<"|   EQUIPOS  |   P.JUGADOS  |   P.GANADOS  |  P.PERDIDOS  | P.EMPATADOS  |     TOTAL    |"<<endl;
        cout<<" ---------------------------------------------------------------------------------------"<<endl;
        for (int f=0;f<=5;f++)
        {
            cout<<"|"<<setw(8)<<nombresEquipos[f]<<"    |";
            for(int c=0;c<=4;c++)
            {
                cout<<setw(8)<<nmarcador[f][c]<<"      |";
            }
        cout<<"\n --------------------------------------------------------------------------------------- "<<endl;
        }
        cout<<"Desea otro calculo? s/n ";
        cin>>opcion;
        if (opcion=='n')
        {
            repetir=false;
        }

    }while (repetir);

}
//fin funcion
int Aleatorio(int minimo,int maximo)
{
    return minimo + rand()/(RAND_MAX/(maximo-minimo+1)+1);
}
