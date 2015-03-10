//Arbol binario ord.hxx

#ifndef ARBOLBINARIOORD_HXX_INCLUDED
#define ARBOLBINARIOORD_HXX_INCLUDED
#include <queue>
using namespace std;

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd()
{

}
template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(T val)
{
    raiz = new NodoBinarioOrd<T>(val);
}
template <class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd()
{

}
template <class T>
bool ArbolBinarioOrd<T>::esVacio()
{
    if(raiz == NULL)
        return true;
    return false;
}
template <class T>
NodoBinarioOrd<T>* ArbolBinarioOrd<T>::obtenerRaiz()
{
    return raiz;
}
template <class T>
void ArbolBinarioOrd<T>::fijarRaiz(NodoBinarioOrd<T>* nraiz)
{
    raiz = nraiz;
}

template<class T>
bool ArbolBinarioOrd<T>::insertar(T padre, T n)
{
    if(raiz == NULL)
        return false;
    else
    {
        if(buscar(padre) && padre < n)
        {
            raiz->setDerecha(padre);
        }
        if(buscar(padre) && padre > n)
        {
            raiz->setIzquierda(padre);
        }
    }
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T n)
{
    if(raiz == NULL)
        return false;
    else
    {
        raiz->eliminar(n);
    }
}


template <class T>
bool ArbolBinarioOrd<T>::buscar(T& n)
{
    if(raiz == NULL)
        return false;
    else
        return raiz->buscar(n);

}

template <class T>
int ArbolBinario<T>::altura()
{
    return alturaM(raiz) - 1;
}

template <class T>
int ArbolBinario<T>::alturaM(NodoBinario<T>* nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }

    int izq = alturaM(nodo->getIzquierda());
    int der = alturaM(nodo->getDerecha());

    if (izq > der)
        return 1 + izq;
    else
        return 1 + der;
}

template <class T>
int ArbolBinario<T>::tamano(NodoBinario<T>* inicio)
{
    int cont = 0;
    if(inicio == NULL)
    {
        return 0;
    }
    else
    {
        cont++;
        return cont + tamano(inicio->getIzquierda()) + tamano(inicio->getDerecha());
    }
}

template <class T>
void ArbolBinario<T>::inOrden(NodoBinario<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        inOrden(inicio->getIzquierda());
        cout << inicio->getDato() << endl;
        inOrden(inicio->getDerecha());
    }
}

template <class T>
void ArbolBinario<T>::preOrden(NodoBinario<T>* inicio)
{
    if(inicio != NULL)
    {
        cout << inicio->getDato() << endl;
        preOrden(inicio->getIzquierda());
        preOrden(inicio->getDerecha());
    }
}
template <class T>
void ArbolBinario<T>::posOrden(NodoBinario<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        posOrden(inicio->getIzquierda());
        posOrden(inicio->getDerecha());
        cout << inicio->getDato() << endl;
    }
}

template <class T>
void ArbolBinario<T>::nivelOrden(NodoBinario<T>* inicio)
{
    queue< NodoBinario<T>* > cola;
    cola.push(inicio);
    while(!cola.empty())
    {
        cout << cola.front()->getDato() << endl;
        if(cola.front()->getIzquierda() != NULL)
            cola.push(cola.front()->getIzquierda());
        if(cola.front()->getDerecha() != NULL)
            cola.push(cola.front()->getDerecha());

        cola.pop();
    }
}

#endif // ARBOLBINARIO_HXX_INCLUDED

