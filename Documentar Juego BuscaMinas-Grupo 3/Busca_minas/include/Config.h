#ifndef CONFIG_H
#define CONFIG_H

//Archivo de encabezado para las configuraciones de nuestro juego
class Config
{
    public:
        //Parametros que recibe del main
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        //Metodos get y set que acceden a los atributos privados
        int getfilasTablero();
        int setfilasTablero(int filasTablero);
        int getcolumnasTablero();
        int setcolumnasTablero(int columnasTablero);
        int getminasTablero();
        int setminasTablero(int minasTablero);
        bool getmodoDesarrolladorTablero();
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
        int getvidasTablero();
        int setvidasTablero(int vidasTablero);
        void menuConfiguracion();
    protected:

    private:
        //Atributos privados que son encapsulados para que nadie acceda a ellos directamente
        int filasTablero;
        int columnasTablero;
        int minasTablero;
        bool modoDesarrolladorTablero;
        int vidasTablero;
};

#endif // CONFIG_H
