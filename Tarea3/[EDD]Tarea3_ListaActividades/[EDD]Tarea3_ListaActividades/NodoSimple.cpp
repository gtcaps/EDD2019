#include "NodoSimple.h"
#include <cstddef>

NodoSimple::NodoSimple() {

	this->dia = 0;
	this->siguiente = NULL;
	lista = new ListaActividades();
	tamanio = 0;

}

NodoSimple::NodoSimple(int dia) {
	this->dia = dia;
	this->siguiente = NULL;
	lista = new ListaActividades();
	tamanio = 0;
}

NodoSimple::NodoSimple(int dia, string actividad) {
	this->dia = dia;
	this->siguiente = NULL;
	lista = new ListaActividades();
	lista->agregarActividad(actividad);
	tamanio = 0;
}

void NodoSimple::setDia(int dia) {
	this->dia = dia;
}

void NodoSimple::setActividad(string actividad) {
	lista->agregarActividad(actividad);
}

void NodoSimple::setSiguiente(NodoSimple* siguiente) {
	this->siguiente = siguiente;
}

void NodoSimple::imprimirLista() {
	lista->imprimir();
}

int NodoSimple::getDia() {
	return dia;
}

int NodoSimple::getTamanio() {
	return tamanio;
}

NodoSimple* NodoSimple::getSiguiente() {
	return this->siguiente;
}
