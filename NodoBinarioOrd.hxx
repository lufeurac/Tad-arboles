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
void NodoBinarioOrd<T>::setIt(NodoBinarioOrd<T>* n)
{
    dato = n->getDato();
    izq = n->getDerecha();
    der = n->getIzquierda();
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
    {
        return true;
    }
    else
    {
        bool res = false;
        if(izq != NULL)
        {
            res = izq->buscar(n);
            if(res)
            {
                return res;
            }
        }
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
                bool res = izq->insertarNodo(_dato);
                return res;
            }
        }
    }
    else
    {
        if((_dato < dato)&&(izq != NULL))
        {
            if((izq->getDato()) > _dato)
            {
                bool res = izq->insertarNodo(_dato);
                return res;
            }
            else
            {
                der = new NodoBinarioOrd<T>(_dato);
                return true;
            }
        }
        if((_dato > dato)&&(der != NULL))
        {
            if((der->getDato()) < _dato)
            {
                bool res = der->insertarNodo(_dato);
                return res;
            }
            else
            {
                izq = new NodoBinarioOrd<T>(_dato);
                return true;
            }
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
    if(buscar(_dato))
    {

        if(dato == _dato)
        {
            if((izq != NULL)&&(der != NULL))
            {
                if(izq->getDerecha() == NULL)
                {
                    izq->setDerecha(der);
                    this->setIt(izq);
                    return true;
                }
                else
                {
                    bool es = rotaciones(der,izq);
                    this->setIt(izq);
                    return es;
                }
            }
            else
            {
                if((izq != NULL)&&(der == NULL))
                {
                    this->setIt(izq);
                    return true;
                }
                if((izq == NULL)&&(der != NULL))
                {
                    this->setIt(izq);
                    return true;
                }
            }
            if((izq == NULL)&&(der == NULL))
            {
                this->~NodoBinarioOrd();
                return true;
            }
        }
        if((_dato < dato))
        {
            bool res = izq->eliminarNodo(_dato);
            return res;
        }
        if((_dato > dato))
        {
            bool res = der->eliminarNodo(_dato);
            return res;
        }
    }
    else
    {
        return false;
    }
}

template <class T>
bool NodoBinarioOrd<T>::rotaciones(NodoBinarioOrd<T>* dato, NodoBinarioOrd<T>* nod)
{
    if((nod->getDerecha() == NULL) && (nod->getIzquierda() == NULL))
    {
        nod->setDerecha(dato);
        return true;
    }
    else
    {
        NodoBinarioOrd<T>* temp1;
        if((nod->getDerecha() != NULL) && (nod->getIzquierda() != NULL))
        {
            temp1=nod->getDerecha();
            nod->setDerecha(dato);
            nod = nod->getIzquierda();
            return rotaciones(temp1,nod);
        }
        else
        {
            if((nod->getDerecha() == NULL) && (nod->getIzquierda() != NULL))
            {
                nod->setDerecha(dato);
                return true;
            }
        }
    }
}
#endif // NODOBINARIOORD_HXX_INCLUDED

