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
    bool buscar(T& n);
    bool eliminar(T _dato);
    bool insertarNodo(T _padre, T _dato);
    NodoBinario();
    NodoBinario(T& _dato);
    NodoBinario<T>* getDerecha();
    NodoBinario<T>* getIzquierda();
    ~NodoBinario();
    T getDato();
    void setDato(T& val);
    void setDerecha(NodoBinario<T>* nderecha);
    void setIzquierda(NodoBinario<T>* nizquierda);
};

#include "NodoBinario.hxx"


#endif // NODOBINARIO_H_INCLUDED

