//Nodo AVLhxx

#ifndef NODOAVL_HXX_INCLUDED
#define NODOAVL_HXX_INCLUDED

#include <algorithm>


template <class T>
NodoAVL<T>::NodoAVL()
{

}


template <class T>
NodoAVL<T>::NodoAVL(T& _dato)
{
    dato = _dato;
    izq = NULL;
    der = NULL;
}


template <class T>
NodoAVL<T>::NodoAVL(T& _dato, int nalt)
{
    dato = _dato;
    alt = nalt;
    izq = NULL;
    der = NULL;
}


template <class T>
NodoAVL<T>::~NodoAVL()
{

}


template <class T>
T NodoAVL<T>::getDato()
{
    return dato;
}

template <class T>
void NodoAVL<T>::setDato(T& val)
{
    dato = val;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::getDerecha()
{
    return der;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::getIzquierda()
{
    return izq;
}

template <class T>
void NodoAVL<T>::setDerecha(NodoAVL<T>* nderecha)
{
    der = nderecha;
}

template <class T>
void NodoAVL<T>::setIzquierda(NodoAVL<T>* nizquierda)
{
    izq = nizquierda;
}


template <class T>
int NodoAVL<T>::getAltura()
{
    return alt;
}


template <class T>
void NodoAVL<T>::setAltura(int val)
{
    alt = val;
}


template < class T >
bool NodoAVL<T>::buscar(T& n)
{
    if(dato == n)
        return true;
    else
    {
        bool res = false;
        if(dato < n)
        {
            if(izq != NULL)
            {
                res = izq->buscar(n);
                if(res)
                {
                    return res;
                }
            }
            return res;
        }
        else
        {
            if(der != NULL)
            {
                res = der->buscar(n);
                if(res)
                {
                    return res;
                }
            }
            return res;
        }
        return res;
    }
}


template <class T>
bool NodoAVL<T>::insertarNodo(T _dato)
{
    if((izq != NULL)&&(der != NULL))
    {
        if(dato == _dato)
        {
            return false;
        }
        else
        {
            if(_dato > dato)
            {
                bool res = der->insertarNodo(_dato);
                return res;
            }
            else
            {
                bool res =izq->insertarNodo(_dato);
                return res;
            }
        }
    }
    else
    {
        if((_dato < dato)&&(izq != NULL))
        {
            bool res = izq->insertarNodo(_dato);
            return res;
        }
        if((_dato > dato)&&(der != NULL))
        {
            bool res = der->insertarNodo(_dato);
            return res;
        }
        if((_dato < dato)&&(izq == NULL))
        {
            izq = new NodoAVL<T>(_dato);
            return true;
        }
        if((_dato > dato)&&(der == NULL))
        {
            der = new NodoAVL<T>(_dato);
            return true;
        }
    }
}


template <class T>
bool NodoAVL<T>::eliminarNodo(T _dato)
{
    if(dato == _dato)
    {
        if((izq != NULL)&&(der != NULL))
        {
            if(der->getIzquierda() == NULL)
            {
                der->setIzquierda(izq);
                this = der;
                return true;
            }
            else
            {
                //TO DO: recursion mover el arbol
            }
        }
        else
        {
            if((izq != NULL)&&(der == NULL))
            {
                this = izq;
                return true;
            }
            if((izq == NULL)&&(der != NULL))
            {
                this = der;
                return true;
            }
        }
        if((izq == NULL)&&(der == NULL))
        {
            delete this;
            return true;
        }
    }
}


#endif // NODOAVL_HXX_INCLUDED

