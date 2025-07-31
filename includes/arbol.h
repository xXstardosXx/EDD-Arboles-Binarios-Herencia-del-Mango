#ifndef ARBOL_H
#define ARBOL_H
#include <string>
#include "mago.h"
using namespace std;

class Nodo{
    Mago mago;
    Nodo *hijos[2];
    Nodo *padre;

    public:
        Nodo(Mago _mago, Nodo *_padre): 
            mago(_mago){
            padre = _padre;
            hijos[0] = hijos[1] = nullptr;
        }
    
    friend class Arbol;

};

class Arbol{
    public:
        Nodo *head;
        Arbol(){
            head = nullptr;
        }
        void cargarMagos(string);
        void insertar(Mago, Nodo *&, Nodo *);
        void buscarNodo(Nodo *, Mago);
        void mostrar(int, Nodo *);
};

#endif