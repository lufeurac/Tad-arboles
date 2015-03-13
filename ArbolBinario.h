//Arbol Binario.h

#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

#include "NodoBinario.h"

template <class T>
class ArbolBinario
{
protected:
    NodoBinario<T>* raiz;
public:
    ArbolBinario();
    ArbolBinario(T val);
    ~ArbolBinario();
    bool buscar(T& n);
    bool eliminar(T n);
    bool esVacio();
    bool insertar(T padre, T n);
    int altura();
    int alturaM(NodoBinario<T>* inicio);
    int tamano(NodoBinario<T>* inicio);
    NodoBinario<T>* obtenerRaiz();
    void fijarRaiz(NodoBinario<T>* nraiz);
    void inOrden(NodoBinario<T>* inicio);
    void nivelOrden(NodoBinario<T>* inicio);
    void preOrden(NodoBinario<T>* inicio);
    void posOrden(NodoBinario<T>* inicio);
    T obtenerDatoRaiz();
};

#include "ArbolBinario.hxx"

#endif // ARBOLBINARIO_H_INCLUDED

