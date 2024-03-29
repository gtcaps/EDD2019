//
// Created by aybso on 25/08/2019.
//

#ifndef TAREA4_LISTA_LISTAACTIVIDADES_H
#define TAREA4_LISTA_LISTAACTIVIDADES_H

#include <iostream>
#include <string>
#include "Nodo.h"
#include <fstream>


class ListaActividades {
    
    private:
        Nodo* dias;
        Nodo* horas;
    
        bool esDia(int dia){
            if(dia > 0 && dia < 8){
                return true;
            }
            return false;
        }
        
        bool existeDia(int dia){
            if(dias != NULL && esDia(dia)){
                Nodo* aux = dias;
                while(aux != NULL){
                    if(aux->x == dia){
                        return true;
                    }
                    aux = aux->siguiente;
                }
            }
            return false;
        }
        
        void setDia(int dia){
            string dia_s = dia + "";
            
            if(esDia(dia) && !existeDia(dia)){
                if(dias == NULL){
                    dias = new Nodo(dia_s, dia, 0);
                }else{
                    Nodo* nuevoDia = new Nodo(dia_s, dia, 0);
                    
                    if(nuevoDia->x < dias->x){
                        nuevoDia->siguiente = dias;
                        dias = nuevoDia;
                    }else{
                        Nodo* aux = dias->siguiente;
                        Nodo* ant = dias;
                        
                        while(aux != NULL){
                            if(nuevoDia->x < aux->x){
                                ant->siguiente = nuevoDia;
                                nuevoDia->siguiente = aux;
                                break;
                            }
                            ant = aux;
                            aux = aux->siguiente;
                        }
                        
                        if(aux == NULL){
                            ant->siguiente = nuevoDia;
                        }
                    }
                }
            }
        }
        
        bool esHora(int hora){
            if(hora > 0 && hora < 25){
                return true;
            }
            return false;
        }
        
        bool existeHora(int hora){
            if(horas != NULL && esHora(hora)){
                Nodo* aux = horas;
                while(aux != NULL){
                    if(aux->y == hora){
                        return true;
                    }
                    aux = aux->abajo;
                }
            }
            return false;
        }
        
        void setHora(int hora){
            string hora_s = hora + "";
    
            if(esHora(hora) && !existeHora(hora)){
                if(horas == NULL){
                    horas = new Nodo(hora_s, 0, hora);
                }else{
                    Nodo* nuevaHora = new Nodo(hora_s, 0, hora);
            
                    if(nuevaHora->y < horas->y){
                        nuevaHora->abajo = horas;
                        horas = nuevaHora;
                    }else{
                        Nodo* aux = horas->abajo;
                        Nodo* ant = horas;
                
                        while(aux != NULL){
                            if(nuevaHora->y < aux->y){
                                ant->abajo = nuevaHora;
                                nuevaHora->abajo = aux;
                                break;
                            }
                            ant = aux;
                            aux = aux->abajo;
                        }
                
                        if(aux == NULL){
                            ant->abajo = nuevaHora;
                        }
                    }
                }
            }
        }
        
        Nodo* getDia(int dia){
            if(esDia(dia) && existeDia(dia)){
                Nodo* aux = dias;
                while(aux != NULL){
                    if(aux->x == dia){
                        return aux;
                    }
                    aux = aux->siguiente;
                }
            }
            return NULL;
        }
        
        Nodo* getHora(int hora){
            if(esHora(hora) && existeHora(hora)){
                Nodo* aux = horas;
                while(aux != NULL){
                    if(aux->y == hora){
                        return aux;
                    }
                    aux = aux->abajo;
                }
            }
            return NULL;
        }
        
        string nombreDia(int dia){
            if(dia == 1){
                return "Lunes";
            }else if(dia == 2){
                return "Martes";
            }else if(dia == 3){
                return "Miercoles";
            }else if(dia == 4){
                return "Jueves";
            }else if(dia == 5){
                return "Viernes";
            }else if(dia == 6){
                return "Sabado";
            }else{
                return "Domingo";
            }
        }
        
        string nombreHora(int hora){
            if(hora == 1){
                return "1:00 am";
            }else if(hora == 2){
                return "2:00 am";
            }else if(hora == 3){
                return "3:00 am";
            }else if(hora == 4){
                return "4:00 am";
            }else if(hora == 5){
                return "5:00 am";
            }else if(hora == 6){
                return "6:00 am";
            }else if(hora == 7){
                return "7:00 am";
            }else if(hora == 8){
                return "8:00 am";
            }else if(hora == 9){
                return "9:00 am";
            }else if(hora == 10){
                return "10:00 am";
            }else if(hora == 11){
                return "11:00 am";
            }else if(hora == 12){
                return "12:00 pm";
            }else if(hora == 13){
                return "1:00 pm";
            }else if(hora == 14){
                return "2:00 pm";
            }else if(hora == 15){
                return "3:00 pm";
            }else if(hora == 16){
                return "4:00 pm";
            }else if(hora == 17){
                return "5:00 pm";
            }else if(hora == 18){
                return "6:00 pm";
            }else if(hora == 19){
                return "7:00 pm";
            }else if(hora == 20){
                return "8:00 pm";
            }else if(hora == 21){
                return "9:00 pm";
            }else if(hora == 22){
                return "10:00 pm";
            }else if(hora == 23){
                return "11:00 pm";
            }else{
                return "00:00 am";
            }
            
        }
        
    public:
        ListaActividades(){
            dias = NULL;
            horas = NULL;
        }
        
        void add(string actividad, int dia, int hora){
            if(esDia(dia) && esHora(hora)){
                
                //INSERTAR CABECERAS
                setDia(dia);
                setHora(hora);
                
                //OBTENER NODOS
                Nodo* posDia = getDia(dia);
                Nodo* posHora = getHora(hora);
                
                //CREO LA ACTIVIDAD
                Nodo* nuevoDia = new Nodo(actividad, dia, hora);
                
                //INSERTAR LA ACTIVIDAD EN EL DIA
                
                if( posDia->abajo == NULL ){
                    posDia->abajo = nuevoDia;
                }else{
                    Nodo* actual = posDia->abajo;
                    Nodo* ant = posDia;
                    
                    while(actual != NULL){
                        if(nuevoDia->y < actual->y){
                            ant->abajo = nuevoDia;
                            nuevoDia->abajo = actual;
                            break;
                        }
                        ant = actual;
                        actual = actual->abajo;
                    }
                    
                    if(actual == NULL){
                        ant->abajo = nuevoDia;
                    }
                }
    
                //INSERTAR LA ACTIVIDAD EN LA HORA
    
                if( posHora->siguiente == NULL ){
                    posHora->siguiente = nuevoDia;
                }else{
                    Nodo* actual = posHora->siguiente;
                    Nodo* ant = posHora;
        
                    while(actual != NULL){
                        if(nuevoDia->x < actual->x){
                            ant->siguiente = nuevoDia;
                            nuevoDia->siguiente = actual;
                            break;
                        }
                        ant = actual;
                        actual = actual->siguiente;
                    }
        
                    if(actual == NULL){
                        ant->siguiente = nuevoDia;
                    }
                }
                
                
            }else{
                cout << "No se puede ingresar el dia y la hora" << endl;
                cout << endl << endl;
            }
            
        }
        
        void imprimirDia(int dia){
            Nodo* d = getDia(dia);
            
            if(d != NULL){
                cout << "------------> " << nombreDia(d->x) << " <------------" << endl;
    
                Nodo* fils = d->abajo;
                while(fils != NULL){
                    cout << "[ " << nombreDia(fils->x) << " , " << nombreHora(fils->y) << " , " << fils->valor << " ] " << endl;
                    fils = fils->abajo;
                }
    
                cout << endl << endl;
            }else{
                cout << " No existe ese dia " << endl << endl;
            }
        }
        
        void imprimirSemana(){
            
            if(dias == NULL){
                cout << "La lista esta vacia, agrege una actividad " << endl;
            }else{
                Nodo* aux = dias;
                while(aux != NULL){
                    cout << "------------> " << nombreDia(aux->x) << " <------------" << endl;
        
                    Nodo* fils = aux->abajo;
                    while(fils != NULL){
                        cout << "[ " << nombreDia(fils->x) << " , " << nombreHora(fils->y) << " , " << fils->valor << " ] " << endl;
                        fils = fils->abajo;
                    }
        
                    cout << endl << endl;
                    aux = aux->siguiente;
                }
            }
        }
        
        void graficar() {
            ofstream archivo;
            archivo.open("grafica.txt");
            archivo << "digraph SparseMatrix{" << endl;
            archivo << "    node[shape=record,  width=1.4, height=0.8, fontsize=22, fontcolor=blue ];" << endl;
            archivo << "    graph[pencolor=transparent];" << endl;
            archivo << "    node[style=filled];" << endl;
            archivo << "    rankdir=LR;" << endl << endl;
            
            archivo << "    raiz[label=\"{Raiz}\" pos=\"0,0!\"];" << endl;
            
            if(dias != NULL && horas != NULL){
                //IMPRIMIENDO LAS CABECERAS DE X --------------------------------------
                Nodo* cabeceraX = dias;
    
                archivo << "    raiz -> x" << cabeceraX->x << "[dir=\"both\"]"<< endl;
                while(cabeceraX != NULL){
                    archivo << "    ";
                    archivo << "x"<< cabeceraX->x <<"[label=\"{  "<< nombreDia(cabeceraX->x) <<" }\"";
                    archivo << "pos=\""<< (cabeceraX->x * 2) <<",0!\"];" << endl;
        
        
                    if(cabeceraX->siguiente != NULL){
                        archivo << "    ";
                        archivo << "x" << cabeceraX->x << "->" << "x" << cabeceraX->siguiente->x << "[dir=\"both\"]"<<  endl;
                    }
        
                    cabeceraX = cabeceraX->siguiente;
                }
                //FIN DE LAS CABECERAS DE X -----------------------------------------------
    
                archivo << endl << endl;
    
    
                //IMPRIMIENDO LAS CABECERAS DE Y -----------------------------------------
                Nodo* cabeceraY = horas;
                archivo << "    raiz -> y" << cabeceraY->y << "[dir=\"both\"];"<< endl;
    
                while(cabeceraY != NULL){
                    archivo << "    ";
                    archivo << "y"<< cabeceraY->y <<"[label=\"{ " << nombreHora(cabeceraY->y) <<"}\"";
                    archivo << "pos=\" 0, "<< (cabeceraY->y * -2) <<"!\"];" << endl;
        
        
                    if(cabeceraY->abajo != NULL){
                        archivo << "    ";
                        archivo << "y" << cabeceraY->y << "->" << "y" << cabeceraY->abajo->y << "[dir=\"both\"]"<<  endl;
                    }
        
                    cabeceraY = cabeceraY->abajo;
                }
                //FIN DE LAS CABECERAS DE Y
    
                archivo << endl << endl;
    
                //IMPRIMIENDO LOS VALORES DE CADA COLUMNA X
                Nodo* x = dias;
                while(x != NULL){
        
                    Nodo* rows = x->abajo;
                    archivo << "    x" << x->x << "->nodo" << rows->x << "_" << rows->y << "[dir=both];" << endl;
                    while(rows != NULL){
            
                        archivo << "    ";
                        archivo << "nodo"<< rows->x << "_" << rows->y;
                        archivo << "[ label = \" { "<< rows->valor << " } \" ";
                        archivo << "pos =  \""<< (rows->x * 2) <<"," << (rows->y * -2) << "!\"]; " << endl;
            
                        if(rows->abajo != NULL){
                            archivo << "    ";
                            archivo << "nodo"<< rows->x << "_" << rows->y << "->";
                            archivo << "nodo" << rows->abajo->x << "_" << rows->abajo->y << "[dir=both];" << endl;
                        }
            
                        rows = rows->abajo;
                    }
                    archivo << endl;
                    x = x->siguiente;
                }
    
                //FIN DE LOS VALORES DE X
    
                archivo << endl << endl;
    
                //IMPRIMIENDO LOS VALORES DE CADA COLUMNA X
                Nodo* y = horas;
                while(y != NULL){
        
                    Nodo* cols = y->siguiente;
                    archivo << "    y" << y->y << "->nodo" << cols->x << "_" << cols->y << "[dir=both];" << endl;
                    while(cols != NULL){
            
                        if(cols->siguiente != NULL){
                            archivo << "    ";
                            archivo << "nodo"<< cols->x << "_" << cols->y << "->";
                            archivo << "nodo" << cols->siguiente->x << "_" << cols->siguiente->y << "[dir=both];" << endl;
                        }
            
                        cols = cols->siguiente;
                    }
                    archivo << endl;
                    y = y->abajo;
                }
    
                //FIN DE LOS VALORES DE X
            }else{
                archivo << "    vacio[label=\"{vacio}\" pos=\"0,0!\"];";
            }
            
           
            
           
            archivo << "}" << endl;
            archivo.close();
            cout << "archivo generado"<< endl;
            
            string generar_grafico = "neato -Tpng ";
            generar_grafico += "grafica.txt";
            generar_grafico += " -o ";
            generar_grafico += "grafica.png";
            system((generar_grafico).c_str());
            
            string abrir_imagen = "grafica.png";
            system((abrir_imagen).c_str());
            
            
            
        }
        
        
    
};


#endif //TAREA4_LISTA_LISTAACTIVIDADES_H
