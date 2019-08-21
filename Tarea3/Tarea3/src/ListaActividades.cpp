#include "ListaActividades.h"

#include <iostream>
using namespace std;

bool ListaActividades::estaVacia(NodoDoble* nodo) {
	if (nodo == NULL) {
		return true;
	}

	return false;
}

ListaActividades::ListaActividades() {
	cabeza = NULL;
	cola = NULL;
}

void ListaActividades::agregarActividad(string actividad) {
	if (estaVacia(cabeza)) {
		cabeza = cola = new NodoDoble(actividad);
	} else {
		NodoDoble* nuevaActividad = new NodoDoble(actividad);
		cola->setSiguiente(nuevaActividad);
		nuevaActividad->setAnterior(cola);
		cola = nuevaActividad;
	}
}

void ListaActividades::imprimir() {

	if (estaVacia(cabeza)) {
		cout << "Lista Vacia" << endl;
	} else {
		NodoDoble* aux = cabeza;
		while (aux != NULL) {
			cout << aux->getActividad() << endl;
			aux = aux->getSiguiente();
		}
	}

}

