#include <iostream>

using namespace std;
//Maria Florencia Ariaga Chiroy

int main()
{
	double kilometros;
	double litros;
	double total;
    while (true)
    {

		cout << "Escriba los kilometros usados (-1 para salir): ";
		cin>>kilometros;

		 if (kilometros == -1) {
            break;
        }
        cout << "Escriba los litros usados: ";
		cin>>litros;

		total=kilometros/litros;
		cout<<"Total KPL: "<<total<<endl<<endl;

    }

    return 0;
}
