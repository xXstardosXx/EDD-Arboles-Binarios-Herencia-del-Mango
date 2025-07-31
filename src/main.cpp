#include <iostream>
#include "../includes/arbol.h"
using namespace std;

int main(){
    Arbol *arbol = new Arbol();
    arbol->cargarMagos("./data/magos.csv");
    arbol->mostrar(0, arbol->head);
    system("pause");
    return 0;
}