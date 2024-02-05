Algoritmo calculadora_mejorada
	opcion <- -1;
	Mientras opcion<>0 Hacer
		Escribir '¿Qué desea realizar? :';
		Escribir '1. Sumar';
		Escribir '2. Restar';
		Escribir '3. Multiplicar';
		Escribir '4. Dividir';
		Escribir '0. Salir del programa';
		Leer opcion;
		Segun opcion  Hacer
			1:
				Escribir 'Ingrese un primer valor: ';
				Leer primero;
				Escribir 'Ingrese un segundo valor: ';
				Leer segundo;
				resultado <- primero+segundo;
				Escribir 'El resultado de la suma de: ',primero,' + ',segundo,' = ',resultado;
			2:
				Escribir 'Ingrese un primer valor: ';
				Leer primero;
				Escribir 'Ingrese un segundo valor: ';
				Leer segundo;
				resultado <- primero-segundo;
				Escribir 'El resultado de la resta de: ',primero,' - ',segundo,' = ',resultado;
			3:
				Escribir 'Ingrese un primer valor: ';
				Leer primero;
				Escribir 'Ingrese un segundo valor: ';
				Leer segundo;
				resultado <- primero*segundo;
				Escribir 'El resultado de la multiplicación de: ',primero,' * ',segundo,' = ',resultado;
			4:
				Escribir 'Ingrese un primer valor: ';
				Leer primero;
				Escribir 'Ingrese un segundo valor: ';
				Leer segundo;
				Si segundo<>0 Entonces
					resultado <- primero/segundo;
					Escribir 'El resultado de la división de: ',primero,' / ',segundo,' = ',resultado;
				SiNo
					Escribir 'Error: No se puede dividir por 0.';
				FinSi
			0:
				Escribir 'Saliendo de la calculadora.';
			De Otro Modo:
				Escribir 'Opción no válida.';
		FinSegun
	FinMientras
FinAlgoritmo
