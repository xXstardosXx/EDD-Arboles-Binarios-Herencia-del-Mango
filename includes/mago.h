#ifndef MAGO_H
#define MAGO_H
#include <string>
using namespace std;

class Mago{
    public:
        int id;
        string nombre;
        string apellido;
        string genero;
        int edad;
        int id_padre;
        bool esta_muerto;
        string tipo_magia;
        bool es_dueño;

        Mago(int _id, string _nombre, string _apellido, string _genero, int _edad, int _id_padre, bool _esta_muerto, string _tipo_magia, bool _es_dueño){
            id = _id;
            nombre = _nombre;
            apellido = _apellido;
            genero = _genero;
            edad = _edad;
            id_padre = _id_padre;
            esta_muerto = _esta_muerto;
            tipo_magia = _tipo_magia;
            es_dueño = _es_dueño;
        }
};

#endif