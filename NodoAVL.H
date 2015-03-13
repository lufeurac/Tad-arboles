//Nodo AVL.h

#ifndef NODOAVL_H_INCLUDED
#define NODOAVL_H_INCLUDED

using namespace std;

template< class T >
class NodoAVL
{
protected:
    int alt;
    NodoAVL<T>*  der;
    NodoAVL<T>*  izq;
    T dato;
public:
    bool buscar(T& n);
    bool eliminarNodo(T _dato);
    bool insertarNodo(T _dato);
    int getAltura();
    NodoAVL();
    NodoAVL(T& _dato);
    NodoAVL(T& _dato, int nalt);
    NodoAVL<T>* getDerecha();
    NodoAVL<T>* getIzquierda();
    ~NodoAVL();
    T getDato();
    void setAltura(int val);
    void setDato(T& val);
    void setDerecha(NodoAVL<T>* nderecha);
    void setIzquierda(NodoAVL<T>* nizquierda);
};

#include "NodoAVL.hxx"


#endif // NODOAVL_H_INCLUDED

