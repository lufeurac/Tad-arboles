//Nodo AVL.h

#ifndef NODOAVL_H_INCLUDED
#define NODOAVL_H_INCLUDED

using namespace std;

template< class T >
class NodoAVL
{
protected:
    T dato;
    NodoAVL<T>*  der;
    NodoAVL<T>*  izq;
public:
    NodoAVL();
    NodoAVL(T& _dato);
    ~NodoAVL();
    T getDato();
    void setDato(T& val);
    bool buscar(T& n);
    NodoAVL<T>* getIzquierda();
    void setIzquierda(NodoAVL<T>* nizquierda);
    NodoAVL<T>* getDerecha();
    void setDerecha(NodoAVL<T>* nderecha);
    bool agregarNodoIzquierda(T dato);
    bool agregarNodoDerecha(T dato);
    bool eliminarNodoIzquierda(T _dato);
    void eliminarHijosIzquierda();
    void eliminarHijosDerecha();
    bool eliminarNodoDerecha(T dato);
};

#include "NodoAVL.hxx"


#endif // NODOAVL_H_INCLUDED

