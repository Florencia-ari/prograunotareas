Algoritmo eje9
	// Maria Florencia Ariaga Chiroy
	// 9959-23-6741
	Escribir 'Escribir un programa que indique si la suma de dos valores es positiva, negativa o cero';
	Definir valor1,valor2,suma Como Real;
	Escribir 'Ingrese el primer valor:';
	Leer valor1;
	Escribir 'Ingrese el segundo valor:';
	Leer valor2;
	suma <- valor1+valor2;
	Si suma>0 Entonces
		Escribir 'La suma es positiva = ',suma;
	SiNo
		Si suma<0 Entonces
			Escribir 'La suma es negativa = ',suma;
		SiNo
			Escribir 'La suma es cero = ',suma;
		FinSi
	FinSi
FinAlgoritmo
