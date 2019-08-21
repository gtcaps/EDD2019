#include "NodoDoble.h"

NodoDoble::NodoDoble() {
	actividad = "";
	siguiente = NULL;
	anterior = NULL;
}

NodoDoble::NodoDoble(string actividad_) {
	actividad = actividad_;
	siguiente = NULL;
	anterior = NULL;
}

void NodoDoble::setActividad(string actividad_) {
	actividad = actividad_;
}

void NodoDoble::setSiguiente(NodoDoble* siguiente_) {
	siguiente = siguiente_;
}

void NodoDoble::setAnterior(NodoDoble* anterior_) {
	anterior = anterior_;
}

string NodoDoble::getActividad() {
	return string(actividad);
}

NodoDoble* NodoDoble::getSiguiente() {
	return siguiente;
}

NodoDoble* NodoDoble::getAnterior() {
	return anterior;
}
