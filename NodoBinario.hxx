//Nodo Binario.hxx

#ifndef NODOBINARIO_HXX_INCLUDED
#define NODOBINARIO_HXX_INCLUDED

#include <algorithm>

template <class T>
NodoBinario<T>::NodoBinario()
{

}

template <class T>
NodoBinario<T>::NodoBinario(T& _dato)
{
    dato = _dato;
    izq = NULL;
    der = NULL;
}
template <class T>
NodoBinario<T>::~NodoBinario()
{

}

template <class T>
T NodoBinario<T>::getDato()
{
    return dato;
}
template <class T>
void NodoBinario<T>::setDato(T& val)
{
    dato = val;
}
template <class T>
NodoBinario<T>* NodoBinario<T>::getIzquierda()
{
    return izq;
}

template <class T>
void NodoBinario<T>::setIzquierda(NodoBinario<T>* nizquierda)
{
    izq = nizquierda;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::getDerecha()
{
    return der;
}

template <class T>
void NodoBinario<T>::setDerecha(NodoBinario<T>* nderecha)
{
    der = nderecha;
}

template < class T >
bool NodoBinario<T>::buscar(T& n)
{
    //cout<<n<<" "<<dato<<endl; //verificar los datos que recibe la funcion
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
bool NodoBinario<T>::insertarNodo(T _padre , T _dato)
{
    if(_padre == dato)
    {
        if(izq == NULL)
        {
            izq = new NodoBinario<T>(_dato);
            return true;
        }
        else
{
            if(der == NULL)
            {
                der = new NodoBinario<T>(_dato);
                return true;
            }
        }
            return false;
    }
    else
    {
        if(izq == NULL)
            return false;
        else
        {
            bool res = izq->insertarNodo(_padre,_dato);
            if(!res)
            {
                if(der == NULL)
                    return false;
                else
                    return der->insertarNodo(_padre,_dato);
            }
            return res;
        }

    }
}

template <class T>
bool NodoBinario<T>::eliminar(T _dato)
{
    if(izq != NULL)
    {
        if(izq->getDato() == _dato)
        {
            if(izq->getIzquierda() != NULL && izq->getDerecha() == NULL)
                izq = izq->getIzquierda();
            else if(izq->getIzquierda() == NULL && izq->getDerecha() != NULL)
                izq = izq->getDerecha();
            else if(izq->getIzquierda() != NULL && izq->getDerecha() != NULL)
                return false;
            else if(izq->getIzquierda() == NULL && izq->getDerecha() == NULL)
                izq = NULL;
            return true;
        }
        else
            return izq->eliminar(dato);
    }
    else if(der != NULL)
    {
        if(der->getDato() == _dato)
        {
            if(der->getIzquierda() != NULL && der->getDerecha() == NULL)
                der = der->getIzquierda();
            else if(der->getIzquierda() == NULL && der->getDerecha() != NULL)
                der = der->getDerecha();
            else if(der->getIzquierda() != NULL && der->getDerecha() != NULL)
                return false;
            else if(der->getIzquierda() == NULL && der->getDerecha() == NULL)
                der = NULL;
            return true;
        }
        else
            return der->eliminar(dato);
    }


}
#endif // NODOBINARIO_HXX_INCLUDED
