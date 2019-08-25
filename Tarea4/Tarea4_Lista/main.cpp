#include <iostream>

#include "ListaActividades.h"
#include <iostream>

void menuDias();
void ingresarActividad(ListaActividades* l);
void opcionesMenu();
void limpiarBuffer();

using namespace std;

int main() {
    
    ListaActividades* l = new ListaActividades();
    bool menu = true;
    int opc = 0;
    
    while(menu){
        cout << endl << endl;
        opcionesMenu();
        cin >> opc;
        
        if(opc == 1){
            ingresarActividad(l);
            limpiarBuffer();
            opc = 0;
        }else if(opc == 2){
            cout << endl << endl;
            limpiarBuffer();
            l->imprimirSemana();
            system("pause");
            opc = 0;
        }else if(opc == 3){
            cout << endl << endl;
            
            //INGRESO DEL DIA
            menuDias();
            limpiarBuffer();
            int dia;
            cin >> dia;
            
            l->imprimirDia(dia);
            system("pause");
            opc = 0;
        }else if(opc == 4){
            menu = false;
            break;
        }
    }
    
    
    
    /*
    ListaActividades* l = new ListaActividades();
    l->add("A",1,7);
    l->add("A",2,7);
    l->add("A",6,7);
    l->add("B",1,11);
    l->add("B",6,11);
    l->add("B",1,20);
    
    //l->imprimirSemana();
    //l->imprimirDia(1);
    */
    
    return 0;
}

void ingresarActividad(ListaActividades *l)
{
    
    cout << endl
         << endl
         << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "|            INGRESAR ACTIVIDAD         |" << endl;
    cout << "+---------------------------------------+" << endl;
    
    //INGRESO DEL DIA
    menuDias();
    limpiarBuffer();
    int dia;
    cin >> dia;
    
    //INGRESO DE LA HORA
    limpiarBuffer();
    int hora;
    cout << endl << endl << "Hora: [ 1 - 24 ] " << endl;
    cout << "Ingresa la hora: ";
    cin >> hora;
    
    
    //INGRESO DE LA ACTIVIDAD
    limpiarBuffer();
    char actividad[150];
    cout << "Ingresa la actividad: ";
    cin.get(actividad, 150);
    
    l->add(actividad, dia, hora);
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
    cout << "LISTA DE ACTIVIDADES - TAREA NO.# 4" << endl;
    cout << "-----------------------------------" << endl
         << endl;
    cout << "1. Ingresar Actividad" << endl;
    cout << "2. Ver Lista Completa de Actividades" << endl;
    cout << "3. Ver Lista de Actividades por Día" << endl;
    cout << "4. Salir " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Ingresa una opcion: ";
}

void limpiarBuffer(){
    while ((getchar()) != '\n');
}


