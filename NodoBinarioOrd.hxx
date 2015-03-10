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
NodoBinarioOrd<T>* NodoBinarioOrd<T>::getIzquierda()
{
    return izq;
}

template <class T>
void NodoBinarioOrd<T>::setIzquierda(NodoBinarioOrd<T>* nizquierda)
{
    izq = nizquierda;
}

template <class T>
NodoBinarioOrd<T>* NodoBinarioOrd<T>::getDerecha()
{
    return der;
}

template <class T>
void NodoBinarioOrd<T>::setDerecha(NodoBinarioOrd<T>* nderecha)
{
    der = nderecha;
}

template < class T >
bool NodoBinarioOrd<T>::buscar(T& n)
{
    if(dato == n)
        return true;
    else
    {
        bool res = false;
        if(izq != NULL)
        {
            res = izq->buscar(n);
            if(res)
                return res;
        }
        if(der != NULL)
            res = der->buscar(n);

        return res;
    }
}

template <class T>
bool NodoBinarioOrd<T>::insertarNodoIzquierda(T _padre , T _dato)
{
  if(_padre == dato)
  {
    if(izq == NULL)
    {
      izq = new NodoBinarioOrd<T>(dato);
      return true;
    }
    else
      return false;
  }
  else
  {
    if(izq == NULL)
      return false;
    else
      izq->insertarNodoIzquierda(padre,dato);
  }
}

template <class T>
bool NodoBinarioOrd<T>::eliminarNodoIzquierda(T _dato)
{
    if(dato == _dato)
    {
        eliminarHijosIzquierda();
        eliminarHijosDerecha();
        izq = NULL;
        der = NULL;
        return true;
    }
    else
    {
        bool res = false;
        res = izq->eliminarNodoIzquierda(_dato);
        return res;
    }
}

template <class T>
bool NodoBinarioOrd<T>::eliminarNodoDerecha(T _dato)
{
    if(dato == _dato)
    {
        eliminarHijosIzquierda();
        eliminarHijosDerecha();
        izq = NULL;
        der = NULL;
        return true;
    }
    else
    {
        bool res = false;
        res = der->eliminarNodoDerecha(_dato);
        return res;
    }
}

template <class T>
void NodoBinarioOrd<T>::eliminarHijosIzquierda()
{
    if(izq->getIzquierda() == NULL)
    {
        izq = NULL;
    }
    else
        izq->eliminarHijosIzquierda();
}

template <class T>
void NodoBinarioOrd<T>::eliminarHijosDerecha()
{
    if(der->getDerecha() == NULL)
    {
        delete der;
    }
    else
        der->eliminarHijosDerecha();
}

template <class T>
bool NodoBinarioOrd<T>::agregarNodoDerecha(T dato)
{
    if(der == NULL)
    {
        der = new NodoBinarioOrd<T>(dato);
        return true;
    }
    else
        return false;
}

#endif // NODOBINARIOORD_HXX_INCLUDED

