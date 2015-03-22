//Arbol binario.hxx

#ifndef ArbolExpresion_HXX_INCLUDED
#define ArbolExpresion_HXX_INCLUDED
#include <queue>
using namespace std;

template <class T>
ArbolExpresion<T>::ArbolExpresion()
{
    raiz = NULL;
}


template <class T>
ArbolExpresion<T>::~ArbolExpresion()
{

}


template <class T>
bool ArbolExpresion<T>::esVacio()
{
    if(raiz == NULL)
        return true;
    return false;
}


template <class T>
NodoExpresion<T>* ArbolExpresion<T>::obtenerRaiz()
{
    return raiz;
}


template <class T>
T ArbolExpresion<T>::obtenerDatoRaiz()
{
    return raiz->getDato();
}


template <class T>
void ArbolExpresion<T>::fijarRaiz(NodoExpresion<T>* nraiz)
{
    raiz = nraiz;
}

template <class T>
int ArbolExpresion<T>::altura()
{
    return alturaM(raiz) - 1;
}


template <class T>
int ArbolExpresion<T>::alturaM(NodoExpresion<T>* nodo)
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
int ArbolExpresion<T>::tamano(NodoExpresion<T>* inicio)
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
void ArbolExpresion<T>::inOrden(NodoExpresion<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        inOrden(inicio->getIzquierda());
        cout << inicio->getDato();
        inOrden(inicio->getDerecha());
    }
}


template <class T>
void ArbolExpresion<T>::preOrden(NodoExpresion<T>* inicio)
{
    if(inicio != NULL)
    {
        cout << inicio->getDato();
        preOrden(inicio->getIzquierda());
        preOrden(inicio->getDerecha());
    }
}


template <class T>
void ArbolExpresion<T>::posOrden(NodoExpresion<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        posOrden(inicio->getIzquierda());
        posOrden(inicio->getDerecha());
        cout << inicio->getDato();
    }
}


template <class T>
void ArbolExpresion<T>::nivelOrden(NodoExpresion<T>* inicio)
{
    queue< NodoExpresion<T>* > cola;
    cola.push(inicio);
    while(!cola.empty())
    {
        cout << cola.front()->getDato();
        if(cola.front()->getIzquierda() != NULL)
            cola.push(cola.front()->getIzquierda());
        if(cola.front()->getDerecha() != NULL)
            cola.push(cola.front()->getDerecha());

        cola.pop();
    }
}

template <class T>
bool ArbolExpresion<T>::insertar(T _dato)
{
    NodoExpresion<T>* nodo = new NodoExpresion<T>(_dato);
    if(raiz == NULL)
    {
        raiz = nodo;
        return true;
    }
    else
    {
        return raiz->insertarNodo(nodo);
    }
}

#endif // ArbolExpresion_HXX_INCLUDED

