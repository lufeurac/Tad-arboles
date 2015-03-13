//Nodo Binario Ord.hxx

#ifndef NODOBINARIOORD_HXX_INCLUDED
#define NODOBINARIOORD_HXX_INCLUDED

#include <algorithm>


template <class T>
NodoBinarioOrd<T>::NodoBinarioOrd()
{

}


template <class T>
NodoBinarioOrd<T>::NodoBinarioOrd(T& _dato)
{
    dato = _dato;
    izq = NULL;
    der = NULL;
}


template <class T>
NodoBinarioOrd<T>::~NodoBinarioOrd()
{

}


template <class T>
T NodoBinarioOrd<T>::getDato()
{
    return dato;
}

template <class T>
void NodoBinarioOrd<T>::setDato(T& val)
{
    dato = val;
}

template <class T>
NodoBinarioOrd<T>* NodoBinarioOrd<T>::getDerecha()
{
    return der;
}

template <class T>
NodoBinarioOrd<T>* NodoBinarioOrd<T>::getIzquierda()
{
    return izq;
}

template <class T>
void NodoBinarioOrd<T>::setDerecha(NodoBinarioOrd<T>* nderecha)
{
    der = nderecha;
}

template <class T>
void NodoBinarioOrd<T>::setIzquierda(NodoBinarioOrd<T>* nizquierda)
{
    izq = nizquierda;
}


template < class T >
bool NodoBinarioOrd<T>::buscar(T& n)
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
bool NodoBinarioOrd<T>::insertarNodo(T _dato)
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
            izq = new NodoBinarioOrd<T>(_dato);
            return true;
        }
        if((_dato > dato)&&(der == NULL))
        {
            der = new NodoBinarioOrd<T>(_dato);
            return true;
        }
    }
}


template <class T>
bool NodoBinarioOrd<T>::eliminarNodo(T _dato)
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


#endif // NODOBINARIOORD_HXX_INCLUDED

