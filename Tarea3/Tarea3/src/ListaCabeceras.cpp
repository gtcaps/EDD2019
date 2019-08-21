#include "ListaCabeceras.h"

using namespace std;
enum semana { lunes = 1, martes, miercoles, jueves, viernes, sabado, domingo };

NodoSimple* ListaCabeceras::buscarNodo(int dia) {

	NodoSimple* aux = cabeza;
	while (aux != NULL) {
		if (aux->getDia() == dia) {
			return aux;
		}
		aux = aux->getSiguiente();
	}

	return NULL;
}

bool ListaCabeceras::estaVacia(NodoSimple* nodo) {

	if (nodo == NULL) {
		return true;
	}

	return false;
}

bool ListaCabeceras::esMenor(int elementoMenor, int elementoMayor) {

	if (elementoMenor < elementoMayor) {
		return true;
	}

	return false;
}

bool ListaCabeceras::esMayor(int elementoMayor, int elementoMenor) {

	if (elementoMayor > elementoMenor) {
		return true;
	}

	return false;
}

bool ListaCabeceras::existeDia(int dia) {
	NodoSimple* aux = cabeza;
	while (aux != NULL) {

		if (aux->getDia() == dia) {
			return true;
		}

		aux = aux->getSiguiente();
	}

	return false;
}

string ListaCabeceras::nombreDia(int dia) {

	switch (dia) {
		case 1:
			return string("Lunes");
			break;
		case 2:
			return string("Martes");
			break;
		case 3:
			return string("Miercoles");
			break;
		case 4:
			return string("Jueves");
			break;
		case 5:
			return string("Viernes");
			break;
		case 6:
			return string("Sabado");
			break;
		case 7:
			return string("Domingo");
			break;
		default:
			break;
	}

	return string("");
}




void ListaCabeceras::insertarInicio(int dia, string _actividad) {

	if (estaVacia(cabeza)) {
		cabeza = cola = new NodoSimple(dia, _actividad);
	} else {
		NodoSimple* nuevoNodo = new NodoSimple(dia, _actividad);
		nuevoNodo->setSiguiente(cabeza);
		cabeza = nuevoNodo;
	}

}

void ListaCabeceras::insertarFinal(int dia, string _actividad) {
	if (estaVacia(cabeza)) {
		insertarInicio(dia, _actividad);
	} else {
		NodoSimple* nuevoNodo = new NodoSimple(dia, _actividad);
		cola->setSiguiente(nuevoNodo);
		cola = nuevoNodo;
	}
}

void ListaCabeceras::insertarOrdenado(int dia, string _actividad) {

	if (estaVacia(cabeza)) {
		insertarInicio(dia, _actividad);
	} else {
		if (esMenor(dia, cabeza->getDia())) {
			insertarInicio(dia, _actividad);
		} else if (esMayor(dia, cola->getDia())) {
			insertarFinal(dia, _actividad);
		} else {
			NodoSimple* diaActual = cabeza->getSiguiente();
			NodoSimple* diaAnterior = cabeza;

			while (diaActual != NULL) {
				if (dia < diaActual->getDia()) {
					NodoSimple* nuevoDia = new NodoSimple(dia, _actividad);
					diaAnterior->setSiguiente(nuevoDia);
					nuevoDia->setSiguiente(diaActual);
					break;
				}
				diaAnterior = diaActual;
				diaActual = diaActual->getSiguiente();
			}
		}
	}


}

ListaCabeceras::ListaCabeceras() {
	cabeza = NULL;
	cola = NULL;
}

void ListaCabeceras::add(int dia_, string actividad) {
	if (existeDia(dia_)) {
		//INGRESAR LA TAREA
		NodoSimple* dia = buscarNodo(dia_);
		dia->setActividad(actividad);
	} else {
		//SE CREA LA CABECERA
		if (dia_ >= lunes && dia_ <= domingo) {
			insertarOrdenado(dia_, actividad);
		} else {
			cout << "Ese dia de la semana no existe" << endl;
		}
	}




}

void ListaCabeceras::imprimir() {

	if (cabeza == NULL) {
		cout << "La lista esta vacia" << endl;
	} else {
		NodoSimple* aux = cabeza;

		while (aux != NULL) {
			cout << nombreDia(aux->getDia()) << endl;
			cout << "--------------------------------" << endl;
			aux->imprimirLista();
			cout << endl << endl;
			aux = aux->getSiguiente();
		}
	}

}

void ListaCabeceras::imprimir(int dia) {

	NodoSimple* aux = cabeza;

	if (aux == NULL) {
		cout << "No existe el dia" << endl;
	} else {
		while (aux != NULL) {
			if (aux->getDia() == dia) {
				cout << nombreDia(aux->getDia()) << endl;
				cout << "--------------------------------" << endl;
				aux->imprimirLista();
				cout << endl << endl;
			}
			aux = aux->getSiguiente();
		}
	}
}
