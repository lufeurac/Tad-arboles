//Arbol AVL.hxx

#ifndef ARBOLAVL_HXX_INCLUDED
#define ARBOLAVL_HXX_INCLUDED
#include <queue>
using namespace std;

template <class T>
ArbolAVL<T>::ArbolAVL()
{

}
template <class T>
ArbolAVL<T>::ArbolAVL(T val)
{
    raiz = new NodoAVL<T>(val);
}
template <class T>
ArbolAVL<T>::~ArbolAVL()
{

}
template <class T>
bool ArbolAVL<T>::esVacio()
{
    if(raiz == NULL)
        return true;
    return false;
}
template <class T>
NodoAVL<T>* ArbolAVL<T>::obtenerRaiz()
{
    return raiz;
}
template <class T>
void ArbolAVL<T>::fijarRaiz(NodoAVL<T>* nraiz)
{
    raiz = nraiz;
}

template <class T>
T ArbolAVL<T>::obtenerDatoRaiz()
{
    return raiz->getDato();
}

template<class T>
bool ArbolAVL<T>::insertar(T _dato)
{
    if(raiz->insertarNodo(_dato))
        return true;
    else
        return false;
}

template <class T>
bool ArbolAVL<T>::eliminar(T n)
{
    if(raiz == NULL)
        return false;
    else
    {
        raiz->eliminar(n);
    }
}


template <class T>
bool ArbolAVL<T>::buscar(T& n)
{
    if(raiz == NULL)
        return false;
    else
        return raiz->buscar(n);

}

template <class T>
int ArbolAVL<T>::altura()
{
    return alturaM(raiz) - 1;
}

template <class T>
int ArbolAVL<T>::alturaM(NodoAVL<T>* nodo)
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

/*template <class T>
int ArbolAVL<T>::tamano(NodoAVL<T>* inicio)
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
}*/

template <class T>
void ArbolAVL<T>::inOrden(NodoAVL<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        inOrden(inicio->getIzquierda());
        cout << inicio->getDato() << " ";
        inOrden(inicio->getDerecha());
    }
}

template <class T>
void ArbolAVL<T>::preOrden(NodoAVL<T>* inicio)
{
    if(inicio != NULL)
    {
        cout << inicio->getDato() << " ";
        preOrden(inicio->getIzquierda());
        preOrden(inicio->getDerecha());
    }
}
template <class T>
void ArbolAVL<T>::posOrden(NodoAVL<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        posOrden(inicio->getIzquierda());
        posOrden(inicio->getDerecha());
        cout << inicio->getDato() << " ";
    }
}

template <class T>
void ArbolAVL<T>::nivelOrden(NodoAVL<T>* inicio)
{
    queue< NodoAVL<T>* > cola;
    cola.push(inicio);
    while(!cola.empty())
    {
        cout << cola.front()->getDato() << " ";
        if(cola.front()->getIzquierda() != NULL)
            cola.push(cola.front()->getIzquierda());
        if(cola.front()->getDerecha() != NULL)
            cola.push(cola.front()->getDerecha());

        cola.pop();
    }
}

#endif // ARBOLAVL_HXX_INCLUDED

