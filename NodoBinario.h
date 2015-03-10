//Nodo Binario.h

#ifndef NODOBINARIO_H_INCLUDED
#define NODOBINARIO_H_INCLUDED

using namespace std;

template< class T >
class NodoBinario
{
protected:
    T dato;
    NodoBinario<T>*  der;
    NodoBinario<T>*  izq;
public:
    NodoBinario();
    NodoBinario(T& _dato);
    ~NodoBinario();
    T getDato();
    void setDato(T& val);
    NodoBinario<T>* getIzquierda();
    void setIzquierda(NodoBinario<T>* nizquierda);
    NodoBinario<T>* getDerecha();
    void setDerecha(NodoBinario<T>* nderecha);
    bool buscar(T& n);
    bool insertarNodo(T _padre, T _dato);
    bool eliminar(T _dato);
};

#include "NodoBinario.hxx"


#endif // NODOBINARIO_H_INCLUDED

