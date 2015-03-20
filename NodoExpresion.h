//Nodo Binario.h

#ifndef NodoExpresion_H_INCLUDED
#define NodoExpresion_H_INCLUDED

using namespace std;

template< class T >
class NodoExpresion
{
protected:
    T dato;
    bool isOpe;
    NodoExpresion<T>*  der;
    NodoExpresion<T>*  izq;
public:
    bool buscar(T& n);
    bool eliminar(T _dato);
    bool insertarNodo(T _padre, T _dato);
    NodoExpresion();
    NodoExpresion(T& _dato);
    NodoExpresion<T>* getDerecha();
    NodoExpresion<T>* getIzquierda();
    ~NodoExpresion();
    T getDato();
    void setDato(T& val);
    void setDerecha(NodoExpresion<T>* nderecha);
    void setIzquierda(NodoExpresion<T>* nizquierda);
};

#include "NodoExpresion.hxx"


#endif // NodoExpresion_H_INCLUDED

