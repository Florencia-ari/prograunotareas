#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setw(10) << "Entero"
			<<setw(10) << "Cuadrado"
             << setw(10) << "Cubo" <<endl;

    for (int i = 0; i <= 10; ++i) {
        int cuadrado = i * i;
        int cubo = i * i * i;

        cout << setw(10) << i
                  << setw(10) << cuadrado
                  << setw(10) << cubo <<endl;
    }
    return 0;
}
