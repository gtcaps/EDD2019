#include <iostream>
#include <iostream>
#include <string>

using namespace std;

class NodoDoble
{
private:
    string actividad;
    NodoDoble *siguiente;
    NodoDoble *anterior;

public:
    NodoDoble();
    NodoDoble(string actividad_);

    void setActividad(string actividad_);
    void setSiguiente(NodoDoble *siguiente_);
    void setAnterior(NodoDoble *anterior_);

    string getActividad();
    NodoDoble *getSiguiente();
    NodoDoble *getAnterior();
};

NodoDoble::NodoDoble()
{
    actividad = "";
    siguiente = NULL;
    anterior = NULL;
}

NodoDoble::NodoDoble(string actividad_)
{
    actividad = actividad_;
    siguiente = NULL;
    anterior = NULL;
}

void NodoDoble::setActividad(string actividad_)
{
    actividad = actividad_;
}

void NodoDoble::setSiguiente(NodoDoble *siguiente_)
{
    siguiente = siguiente_;
}

void NodoDoble::setAnterior(NodoDoble *anterior_)
{
    anterior = anterior_;
}

string NodoDoble::getActividad()
{
    return string(actividad);
}

NodoDoble *NodoDoble::getSiguiente()
{
    return siguiente;
}

NodoDoble *NodoDoble::getAnterior()
{
    return anterior;
}

class ListaActividades
{
private:
    NodoDoble *cabeza;
    NodoDoble *cola;

    bool estaVacia(NodoDoble *nodo);

public:
    ListaActividades();
    void agregarActividad(string actividad);
    void imprimir();
};

bool ListaActividades::estaVacia(NodoDoble *nodo)
{
    if (nodo == NULL)
    {
        return true;
    }

    return false;
}

ListaActividades::ListaActividades()
{
    cabeza = NULL;
    cola = NULL;
}

void ListaActividades::agregarActividad(string actividad)
{
    if (estaVacia(cabeza))
    {
        cabeza = cola = new NodoDoble(actividad);
    }
    else
    {
        NodoDoble *nuevaActividad = new NodoDoble(actividad);
        cola->setSiguiente(nuevaActividad);
        nuevaActividad->setAnterior(cola);
        cola = nuevaActividad;
    }
}

void ListaActividades::imprimir()
{

    if (estaVacia(cabeza))
    {
        cout << "Lista Vacia" << endl;
    }
    else
    {
        NodoDoble *aux = cabeza;
        while (aux != NULL)
        {
            cout << aux->getActividad() << endl;
            aux = aux->getSiguiente();
        }
    }
}

class NodoSimple
{

private:
    int dia;
    NodoSimple *siguiente;
    ListaActividades *lista;
    int tamanio;

public:
    NodoSimple();
    NodoSimple(int dia);
    NodoSimple(int dia, string actividad);

    void setDia(int dia);
    void setActividad(string actividad);
    void setSiguiente(NodoSimple *siguiente);
    void imprimirLista();

    int getDia();
    int getTamanio();

    NodoSimple *getSiguiente();
};

NodoSimple::NodoSimple()
{

    this->dia = 0;
    this->siguiente = NULL;
    lista = new ListaActividades();
    tamanio = 0;
}

NodoSimple::NodoSimple(int dia)
{
    this->dia = dia;
    this->siguiente = NULL;
    lista = new ListaActividades();
    tamanio = 0;
}

NodoSimple::NodoSimple(int dia, string actividad)
{
    this->dia = dia;
    this->siguiente = NULL;
    lista = new ListaActividades();
    lista->agregarActividad(actividad);
    tamanio = 0;
}

void NodoSimple::setDia(int dia)
{
    this->dia = dia;
}

void NodoSimple::setActividad(string actividad)
{
    lista->agregarActividad(actividad);
}

void NodoSimple::setSiguiente(NodoSimple *siguiente)
{
    this->siguiente = siguiente;
}

void NodoSimple::imprimirLista()
{
    lista->imprimir();
}

int NodoSimple::getDia()
{
    return dia;
}

int NodoSimple::getTamanio()
{
    return tamanio;
}

NodoSimple *NodoSimple::getSiguiente()
{
    return this->siguiente;
}

class ListaCabeceras
{

private:
    NodoSimple *cabeza;
    NodoSimple *cola;
    NodoSimple *buscarNodo(int dia);

    bool estaVacia(NodoSimple *nodo);
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

enum semana
{
    lunes = 1,
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo
};

NodoSimple *ListaCabeceras::buscarNodo(int dia)
{

    NodoSimple *aux = cabeza;
    while (aux != NULL)
    {
        if (aux->getDia() == dia)
        {
            return aux;
        }
        aux = aux->getSiguiente();
    }

    return NULL;
}

bool ListaCabeceras::estaVacia(NodoSimple *nodo)
{

    if (nodo == NULL)
    {
        return true;
    }

    return false;
}

bool ListaCabeceras::esMenor(int elementoMenor, int elementoMayor)
{

    if (elementoMenor < elementoMayor)
    {
        return true;
    }

    return false;
}

bool ListaCabeceras::esMayor(int elementoMayor, int elementoMenor)
{

    if (elementoMayor > elementoMenor)
    {
        return true;
    }

    return false;
}

bool ListaCabeceras::existeDia(int dia)
{
    NodoSimple *aux = cabeza;
    while (aux != NULL)
    {

        if (aux->getDia() == dia)
        {
            return true;
        }

        aux = aux->getSiguiente();
    }

    return false;
}

string ListaCabeceras::nombreDia(int dia)
{

    switch (dia)
    {
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

void ListaCabeceras::insertarInicio(int dia, string _actividad)
{

    if (estaVacia(cabeza))
    {
        cabeza = cola = new NodoSimple(dia, _actividad);
    }
    else
    {
        NodoSimple *nuevoNodo = new NodoSimple(dia, _actividad);
        nuevoNodo->setSiguiente(cabeza);
        cabeza = nuevoNodo;
    }
}

void ListaCabeceras::insertarFinal(int dia, string _actividad)
{
    if (estaVacia(cabeza))
    {
        insertarInicio(dia, _actividad);
    }
    else
    {
        NodoSimple *nuevoNodo = new NodoSimple(dia, _actividad);
        cola->setSiguiente(nuevoNodo);
        cola = nuevoNodo;
    }
}

void ListaCabeceras::insertarOrdenado(int dia, string _actividad)
{

    if (estaVacia(cabeza))
    {
        insertarInicio(dia, _actividad);
    }
    else
    {
        if (esMenor(dia, cabeza->getDia()))
        {
            insertarInicio(dia, _actividad);
        }
        else if (esMayor(dia, cola->getDia()))
        {
            insertarFinal(dia, _actividad);
        }
        else
        {
            NodoSimple *diaActual = cabeza->getSiguiente();
            NodoSimple *diaAnterior = cabeza;

            while (diaActual != NULL)
            {
                if (dia < diaActual->getDia())
                {
                    NodoSimple *nuevoDia = new NodoSimple(dia, _actividad);
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

ListaCabeceras::ListaCabeceras()
{
    cabeza = NULL;
    cola = NULL;
}

void ListaCabeceras::add(int dia_, string actividad)
{
    if (existeDia(dia_))
    {
        //INGRESAR LA TAREA
        NodoSimple *dia = buscarNodo(dia_);
        dia->setActividad(actividad);
    }
    else
    {
        //SE CREA LA CABECERA
        if (dia_ >= lunes && dia_ <= domingo)
        {
            insertarOrdenado(dia_, actividad);
        }
        else
        {
            cout << "Ese dia de la semana no existe" << endl;
        }
    }
}

void ListaCabeceras::imprimir()
{

    if (cabeza == NULL)
    {
        cout << "La lista esta vacia" << endl;
    }
    else
    {
        NodoSimple *aux = cabeza;

        while (aux != NULL)
        {
            cout << nombreDia(aux->getDia()) << endl;
            cout << "--------------------------------" << endl;
            aux->imprimirLista();
            cout << endl
                 << endl;
            aux = aux->getSiguiente();
        }
    }
}

void ListaCabeceras::imprimir(int dia)
{

    NodoSimple *aux = cabeza;

    if (aux == NULL)
    {
        cout << "No existe el dia" << endl;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->getDia() == dia)
            {
                cout << nombreDia(aux->getDia()) << endl;
                cout << "--------------------------------" << endl;
                aux->imprimirLista();
                cout << endl
                     << endl;
            }
            aux = aux->getSiguiente();
        }
    }
}

void opcionesMenu();
void menuDias();
void ingresarActividad(ListaCabeceras *l);
void limpiar_buffer();

int main()
{

    ListaCabeceras *l = new ListaCabeceras();

    bool ejecutar_menu = true;
    int opc = 0;

    while (ejecutar_menu)
    {

        opcionesMenu();
        int opc;
        cin >> opc;

        if (opc == 1)
        {
            ingresarActividad(l);
            opc = 0;
            system("pause");
            limpiar_buffer();
        }
        else if (opc == 2)
        {
            cout << endl
                 << endl;
            l->imprimir();
            cout << endl
                 << endl;
            opc = 0;
            system("pause");
            limpiar_buffer();
        }
        else if (opc == 3)
        {
            menuDias();
            limpiar_buffer();
            int dia;
            cin >> dia;
            while (dia < 1 || dia > 7)
            {
                cout << "Ingresa una dia: ";
                limpiar_buffer();
                cin >> dia;
            }

            cout << endl;
            l->imprimir(dia);
            cout << endl;
            system("pause");
            limpiar_buffer;
        }
        else if (opc == 4)
        {
            ejecutar_menu = false;
            break;
        }
    }

    return 0;
}

void limpiar_buffer()
{
    while ((getchar()) != '\n')
        ;
}

void ingresarActividad(ListaCabeceras *l)
{

    cout << endl
         << endl
         << endl;
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

void menuDias()
{
    cout << endl
         << endl;
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

void opcionesMenu()
{
    cout << endl
         << endl;
    cout << "LISTA DE ACTIVIDADES - TAREA NO.# 3" << endl;
    cout << "-----------------------------------" << endl
         << endl;
    cout << "1. Ingresar Actividad" << endl;
    cout << "2. Ver Lista Completa de Actividades" << endl;
    cout << "3. Ver Lista de Actividades por Día" << endl;
    cout << "4. Salir " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Ingresa una opción: ";
}