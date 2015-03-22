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
    bool buscar(T& n);
    bool eliminarNodo(T _dato);
    bool insertarNodo(T _dato);
    bool rotaciones(NodoBinarioOrd<T>* dato, NodoBinarioOrd<T>* nod);
    NodoBinarioOrd();
    NodoBinarioOrd(T& _dato);
    NodoBinarioOrd<T>* getDerecha();
    NodoBinarioOrd<T>* getIzquierda();
    ~NodoBinarioOrd();
    T getDato();
    void setDato(T& val);
    void setIt(NodoBinarioOrd<T>* n);
    void setDerecha(NodoBinarioOrd<T>* nderecha);
    void setIzquierda(NodoBinarioOrd<T>* nizquierda);
};

#include "NodoBinarioOrd.hxx"


#endif // NODOBINARIO_H_INCLUDED

