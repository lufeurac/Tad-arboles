//Nodo Binario ord.h

#ifndef NODOBINARIOORD_H_INCLUDED
#define NODOBINARIOORD_H_INCLUDED

using namespace std;

template< class T >
class NodoBinarioOrd
{
protected:
    T dato;
    NodoBinarioOrd<T>*  der;
    NodoBinarioOrd<T>*  izq;
public:
    NodoBinarioOrd();
    NodoBinarioOrd(T& _dato);
    ~NodoBinarioOrd();
    T getDato();
    void setDato(T& val);
    bool buscar(T& n);
    NodoBinarioOrd<T>* getIzquierda();
    void setIzquierda(NodoBinarioOrd<T>* nizquierda);
    NodoBinarioOrd<T>* getDerecha();
    void setDerecha(NodoBinarioOrd<T>* nderecha);
    bool insertarNodoIzquierda(T _dato);
    bool insertarNodoDerecha(T _dato);
    bool eliminarNodoIzquierda(T _dato);
    void eliminarHijosIzquierda();
    void eliminarHijosDerecha();
    bool eliminarNodoDerecha(T dato);
};

#include "NodoBinarioOrd.hxx"


#endif // NODOBINARIO_H_INCLUDED

