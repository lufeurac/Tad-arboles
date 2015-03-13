#include<iostream>
#include "ArbolBinario.h"
using namespace std;

void pereza()
{
    cout<<endl<<endl;
}

int main()
{
    ArbolBinario<int> arbol(1);
    if(arbol.insertar(1,2))
        cout << "Se inserto el nodo correctamente" << endl;
    else
        cout << "No se inserto el nodo" << endl;

    if(arbol.insertar(2,3))
        cout << "Se inserto el nodo correctamente" << endl;
    else
        cout << "No se inserto el nodo" << endl;

    if(arbol.insertar(3,4))
        cout << "Se inserto el nodo correctamente" << endl;
    else
        cout << "No se inserto el nodo" << endl;

    if(arbol.insertar(2,5))
        cout << "Se inserto el nodo correctamente" << endl;
    else
        cout << "No se inserto el nodo" << endl;

    if(arbol.insertar(1,6))
        cout << "Se inserto el nodo correctamente" << endl;
    else
        cout << "No se inserto el nodo" << endl;

    if(arbol.insertar(3,7))
        cout << "Se inserto el nodo correctamente" << endl;
    else
        cout << "No se inserto el nodo" << endl;

    pereza();
    cout << "Raiz del arbol: " << arbol.obtenerDatoRaiz() << endl;
    cout << "La altura del arbol es: " << arbol.altura() << endl;
    cout << "El tamanio del arbol es: " << arbol.tamano(arbol.obtenerRaiz()) << endl;
    cout << "El arbol ordenado por pre-orden es el siguiente: ";
    arbol.preOrden(arbol.obtenerRaiz());
    cout << endl;
    cout << "El arbol ordenado por in-orden es el siguiente: ";
    arbol.inOrden(arbol.obtenerRaiz());
    cout << endl;
    cout << "El arbol ordenado por pos-orden es el siguiente: ";
    arbol.posOrden(arbol.obtenerRaiz());
    cout << endl;
    cout << "El arbol ordenado por nivel-orden es el siguiente: ";
    arbol.nivelOrden(arbol.obtenerRaiz());
    cout << endl;

    if(arbol.eliminar(6))
        cout << "Se elimino correctamente" << endl;

    if(arbol.eliminar(7))
        cout << "Se elimino correctamente" << endl;

    if(arbol.eliminar(3))
        cout << "Se elimino correctamente" << endl;

    if(arbol.eliminar(4))
        cout << "Se elimino correctamente" << endl;

    if(arbol.eliminar(2))
        cout << "Se elimino correctamente" << endl;

    if(arbol.eliminar(5))
        cout << "Se elimino correctamente" << endl;

    cout << "El arbol ordenado por nivel-orden es el siguiente: ";
    arbol.nivelOrden(arbol.obtenerRaiz());
    cout << endl;
    return 0;
}

