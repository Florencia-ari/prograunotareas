#ifndef CELDA_H
#define CELDA_H
//Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
//Fecha: 17 marzo 2023

class Celda
{
    public:
        Celda();
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);
        //get y set para llamar al atributo privado
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();
        //get y set para llamar al atributo privado
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();
         //get y set para llamar al atributo privado
        bool setMina(bool estadoMina);
        bool getMina();
         //get y set para llamar al atributo privado
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();

        void imprimirCelda();
    protected:

    private:
        int coordenadaX, coordenadaY;
        bool mina, minaDescubierta;
};

#endif // CELDA_H
