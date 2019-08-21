#ifndef LISTACABECERAS_H
#define LISTACABECERAS_H


#include "./include/NodoSimple.h"
#include <iostream>
#include <string>

using namespace std;

class ListaCabeceras {


	private:
	NodoSimple* cabeza;
	NodoSimple* cola;
	NodoSimple* buscarNodo(int dia);

	bool estaVacia(NodoSimple* nodo);
	bool esMenor(int elementoMenor, int elementoMayor);
	bool esMayor(int elementoMayor, int elementoMenor);
	bool existeDia(int dia);
	string nombreDia(int dia);

	void insertarInicio(int dia, string actividad);
	void insertarFinal(int dia, string actividad);
	void insertarOrdenado(int dia, string actividad);



	public:
	ListaCabeceras();
	virtual void add(int dia, string actividad);
	virtual void imprimir();
	virtual void imprimir(int dia);

};

#endif // LISTACABECERAS_H
