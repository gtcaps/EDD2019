#include <iostream>
#include <string>
#include "ListaCabeceras.h"

using namespace std;

ListaCabeceras* l = new ListaCabeceras();
void opcionesMenu();
void menuDias();
void ingresarActividad(ListaCabeceras* l);
void limpiar_buffer();


int main() {


	/*
	l->add(5, "Levantarme");
	l->add(5, "Cepillarme");
	l->add(1,"Ir a la universidad");
	l->add(5, "Cambiarme");
	l->add(5, "Ir al colegio");

	l->imprimir();
	*/
	
	bool ejecutar_menu = true;
	int opc = 0;

	while (ejecutar_menu) {

		opcionesMenu();
		int opc;
		cin >> opc;


		if ( opc == 1 ) {
			ingresarActividad(l);
			opc = 0;
			system("pause");
			limpiar_buffer();
		} else if ( opc == 2 ) {
			cout << endl << endl;
			l->imprimir();
			cout << endl << endl;
			opc = 0;
			system("pause");
			limpiar_buffer();
		} else if ( opc == 3 ) {
			menuDias();
			limpiar_buffer();
			int dia;
			cin >> dia;
			while (dia < 1 || dia > 7 ) {
				cout << "Ingresa una dia: ";
				limpiar_buffer();
				cin >> dia;
			}

			cout << endl;
			l->imprimir(dia);
			cout << endl;
			system("pause");
			limpiar_buffer;
		} else if (opc == 4) {
			ejecutar_menu = false;
			break;
		} 


	}



	return 0;
}


void limpiar_buffer() {
	while ((getchar()) != '\n');
}

void ingresarActividad(ListaCabeceras* l) {

	cout << endl << endl << endl;
	cout << "+---------------------------------------+" << endl;
	cout << "|            INGRESAR ACTIVIDAD         |" << endl;
	cout << "+---------------------------------------+" << endl;

	menuDias();
	limpiar_buffer();
	int dia;
	cout << "Ingresa una dia: ";
	cin >> dia;

	limpiar_buffer();
	char actividad[150];
	cout << "Ingresa la actividad: ";
	cin.get(actividad, 150);


	l->add(dia, actividad);

}

void menuDias() {
	cout << endl << endl;
	cout << "SELECCIONE UN DIA DE LA SEMANA" << endl;
	cout << "-----------------------------------" << endl;
	cout << "1. Lunes" << endl;
	cout << "2. Martes" << endl;
	cout << "3. Miercoles" << endl;
	cout << "4. Jueves" << endl;
	cout << "5. Viernes" << endl;
	cout << "6. Sabado" << endl;
	cout << "7. Domingo" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Ingresa una dia: ";
}

void opcionesMenu() {
	cout << endl << endl;
	cout << "LISTA DE ACTIVIDADES - TAREA NO.# 3" << endl;
	cout << "-----------------------------------" << endl << endl;
	cout << "1. Ingresar Actividad" << endl;
	cout << "2. Ver Lista Completa de Actividades" << endl;
	cout << "3. Ver Lista de Actividades por Día" << endl;
	cout << "4. Salir " << endl;
	cout << "-----------------------------------" << endl;
	cout << "Ingresa una opción: ";
}