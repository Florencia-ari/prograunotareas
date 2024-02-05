Algoritmo eje5
	// Maria Florencia Ariaga Chiroy
	// 9959-23-6741
	Escribir 'Calcular el promedio de N numeros';
	Definir N Como Entero;
	Definir numero,suma,promedio Como Real;
	Escribir 'Ingrese la cantidad de números:';
	Leer N;
	suma <- 0;
	Para i<-1 Hasta N Hacer
		Escribir 'Ingrese el número ',i,':';
		Leer numero;
		suma <- suma+numero;
	FinPara
	promedio <- suma/N;
	Escribir 'El promedio de los ',N,' números es: ',promedio;
FinAlgoritmo
