//Arbol Binario.h

#ifndef ArbolExpresion_H_INCLUDED
#define ArbolExpresion_H_INCLUDED

#include "NodoExpresion.h"

template <class T>
class ArbolExpresion
{
protected:
    NodoExpresion<T>* raiz;
public:
    ArbolExpresion();
    ~ArbolExpresion();
    bool esVacio();
    bool insertarPre(T dato);
    bool insertarPos(T dato);
    int altura();
    int alturaM(NodoExpresion<T>* inicio);
    int tamano(NodoExpresion<T>* inicio);
    NodoExpresion<T>* obtenerRaiz();
    void fijarRaiz(NodoExpresion<T>* nraiz);
    void inOrden(NodoExpresion<T>* inicio);
    void nivelOrden(NodoExpresion<T>* inicio);
    void posOrden(NodoExpresion<T>* inicio);
    void preOrden(NodoExpresion<T>* inicio);
    void posOrdenEval(NodoExpresion<T>* inicio,string* s);
    void preOrdenEval(NodoExpresion<T>* inicio,string* s);
    T obtenerDatoRaiz();
};

#include "ArbolExpresion.hxx"

#endif // ArbolExpresion_H_INCLUDED

