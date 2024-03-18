#include <iostream>
#include <string>

using namespace std;

class LibroCalificaciones {
public:
	explicit LibroCalificaciones(string nombreCurso, string nombreInstructor);
	void establecerNombreCurso(string nombre);
	string obtenerNombreCurso() const;
	void establecerNombreInstructor(string nombre);
	string obtenerNombreInstructor() const;
	void mostrarMensaje() const;
private:
	string nombreCurso;
	string nombreInstructor;
};

LibroCalificaciones::LibroCalificaciones(string nombreCurso, string nombreInstructor)
: nombreCurso(nombreCurso), nombreInstructor(nombreInstructor)
{
}
void LibroCalificaciones::establecerNombreCurso(string nombre)
{
	nombreCurso = nombre;
}
string LibroCalificaciones::obtenerNombreCurso()const
{
	return nombreCurso;
}
void LibroCalificaciones::establecerNombreInstructor(string nombre)
{
	nombreInstructor = nombre;
}
string LibroCalificaciones::obtenerNombreInstructor() const
{
	return nombreInstructor;
}
void LibroCalificaciones::mostrarMensaje() const
{
	cout << "Bienvenido al libro de calificaciones para: " << obtenerNombreCurso()
		<< "!" << endl;
	cout << "Este curso es presentado por: " << obtenerNombreInstructor() << endl;
}

int main()
{
	LibroCalificaciones libroCalificaciones("Programacion", "Eduardo");

	libroCalificaciones.mostrarMensaje();

	return 0;
}
