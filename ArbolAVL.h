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
    bool buscar(T& n);
    NodoBinario<T>* getIzquierda();
    void setIzquierda(NodoBinario<T>* nizquierda);
    NodoBinario<T>* getDerecha();
    void setDerecha(NodoBinario<T>* nderecha);
    bool agregarNodoIzquierda(T dato);
    bool agregarNodoDerecha(T dato);
    bool eliminarNodoIzquierda(T _dato);
    void eliminarHijosIzquierda();
    void eliminarHijosDerecha();
    bool eliminarNodoDerecha(T dato);
};

#include "NodoBinario.hxx"


#endif // NODOBINARIO_H_INCLUDED

