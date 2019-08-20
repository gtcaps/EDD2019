#pragma once
#include "ListaActividades.h"

class NodoSimple {

	private:
		int dia;
		NodoSimple* siguiente;
		ListaActividades* lista;
		int tamanio;

	public:
		NodoSimple();
		NodoSimple(int dia);
		NodoSimple(int dia, string actividad);

		void setDia(int dia);
		void setActividad(string actividad);
		void setSiguiente(NodoSimple* siguiente);
		void imprimirLista();

		int getDia();
		int getTamanio();

		NodoSimple* getSiguiente();


};

