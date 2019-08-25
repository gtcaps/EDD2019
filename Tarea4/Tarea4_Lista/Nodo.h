//
// Created by aybso on 25/08/2019.
//

#ifndef TAREA4_LISTA_NODO_H
#define TAREA4_LISTA_NODO_H

#include <string>
#include <iostream>

using namespace std;

class Nodo{
    
    public:
        string valor;
        int x;
        int y;
        Nodo* siguiente;
        Nodo* abajo;
        
        Nodo(){
            valor = "";
            x = 0;
            y = 0;
            siguiente = NULL;
            abajo = NULL;
        }
        
        Nodo(string val, int x_, int y_){
            valor = val;
            x = x_;
            y = y_;
            siguiente = NULL;
            abajo = NULL;
        }
        
};



#endif //TAREA4_LISTA_NODO_H
