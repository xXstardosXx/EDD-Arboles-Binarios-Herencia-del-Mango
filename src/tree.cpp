#include "../includes/arbol.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void Arbol::cargarMagos(string nombre_archivo){
    ifstream inFile(nombre_archivo, ifstream::in);
    string line, word;
    int id, edad, id_padre;
    string nombre, apellido, genero, tipo_magia;
    bool estado, es_dueño;
    int count = 0;
    while(getline(inFile, line)){
        stringstream str(line);
        while(getline(str, word, ',')){
            switch(count){
                case 0: id = stoi(word); break;
                case 1: nombre = word; break;
                case 2: apellido = word; break;
                case 3: genero = (word == "H")? "Hombre" : "Mujer"; break;
                case 4: edad = stoi(word); break;
                case 5: id_padre = stoi(word); break;
                case 6: estado = (stoi(word) == 0)? false : true; break;
                case 7: tipo_magia = word; break;
                case 8: es_dueño = (stoi(word) == 0)? false : true; break;
            }
            count++;
        }
        count = 0;
        insertar(Mago(id, nombre, apellido, genero, edad, id_padre, estado, tipo_magia, es_dueño), head, nullptr);
    }
    inFile.close();
}

void Arbol::insertar(Mago mago, Nodo *&posicion, Nodo *padre){
    if(posicion == nullptr){
        Nodo *nuevo_nodo = new Nodo(mago, padre);
        posicion = nuevo_nodo;
    }else{
        if(mago.id_padre == posicion->mago.id){
            (posicion->hijos[0] == nullptr)? insertar(mago, posicion->hijos[0], posicion) : insertar(mago, posicion->hijos[1], posicion);
        }else{
            buscarNodo(posicion, mago);
        }
    }
}

void Arbol::buscarNodo(Nodo *posicion, Mago mago){
    if(posicion == nullptr){
        return;
    }else if(posicion->mago.id != mago.id_padre){
        buscarNodo(posicion->hijos[0], mago);
        buscarNodo(posicion->hijos[1], mago);
    }else{
        insertar(mago, posicion, posicion->padre);
    }
}

void Arbol::mostrar(int count, Nodo *posicion){
    if(posicion == nullptr){
        return;
    }else{
        mostrar(count+1, posicion->hijos[1]);
        for(int i=0; i<count; i++){
            cout<<"  ";
        }
        cout<<posicion->mago.nombre<<endl;
        mostrar(count+1, posicion->hijos[0]);
        
    }
}