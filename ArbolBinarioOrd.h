//Arbol Binario Ord.h

#ifndef ARBOLBINARIOORD_H_INCLUDED
#define ARBOLBINARIOORD_H_INCLUDED

#include "NodoBinarioOrd.h"

template <class T>
class ArbolBinarioOrd
{
    protected:
        NodoBinarioOrd<T>* raiz;
    public:
        ArbolBinarioOrd();
        ArbolBinarioOrd(T val);
        ~ArbolBinarioOrd();
        bool esVacio();
        NodoBinarioOrd<T>* obtenerRaiz();
        void fijarRaiz(NodoBinarioOrd<T>* nraiz);
        bool buscar(T& n);
        bool insertar(T _dato);
        bool eliminar(T n);
        int altura();
        int alturaM(NodoBinarioOrd<T>* inicio);
        int tamano(NodoBinarioOrd<T>* inicio);
        T obtenerDatoRaiz();
        void inOrden(NodoBinarioOrd<T>* inicio);
        void preOrden(NodoBinarioOrd<T>* inicio);
        void posOrden(NodoBinarioOrd<T>* inicio);
        void nivelOrden(NodoBinarioOrd<T>* inicio);
};

#include "ArbolBinarioOrd.hxx"

#endif // ARBOLBINARIO_H_INCLUDED

