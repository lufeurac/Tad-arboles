//Arbol Binario.h

#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

#include "NodoExpresion.h"

template <class T>
class ArbolBinario
{
protected:
    NodoExpresion<T>* raiz;
public:
    ArbolBinario();
    ArbolBinario(T val);
    ~ArbolBinario();
    bool buscar(T& n);
    bool eliminar(T n);
    bool esVacio();
    bool insertar(T padre, T n);
    int altura();
    int alturaM(NodoExpresion<T>* inicio);
    int tamano(NodoExpresion<T>* inicio);
    NodoExpresion<T>* obtenerRaiz();
    void fijarRaiz(NodoExpresion<T>* nraiz);
    void inOrden(NodoExpresion<T>* inicio);
    void nivelOrden(NodoExpresion<T>* inicio);
    void preOrden(NodoExpresion<T>* inicio);
    void posOrden(NodoExpresion<T>* inicio);
    T obtenerDatoRaiz();
};

#include "ArbolBinario.hxx"

#endif // ARBOLBINARIO_H_INCLUDED

