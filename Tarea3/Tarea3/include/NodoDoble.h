#ifndef NODODOBLE_H
#define NODODOBLE_H

#include <string>

using namespace std;

class NodoDoble
{
	private:
	string actividad;
	NodoDoble* siguiente;
	NodoDoble* anterior;



	public:
	NodoDoble();
	NodoDoble(string actividad_);

	void setActividad(string actividad_);
	void setSiguiente(NodoDoble* siguiente_);
	void setAnterior(NodoDoble* anterior_);

	string getActividad();
	NodoDoble* getSiguiente();
	NodoDoble* getAnterior();
};

#endif // NODODOBLE_H
