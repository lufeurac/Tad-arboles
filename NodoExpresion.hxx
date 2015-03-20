//Nodo Binario.hxx

#ifndef NodoExpresion_HXX_INCLUDED
#define NodoExpresion_HXX_INCLUDED

template <class T>
NodoExpresion<T>::NodoExpresion()
{

}

template <class T>
NodoExpresion<T>::NodoExpresion(T& _dato)
{
    dato = _dato;
    izq = NULL;
    der = NULL;
}


template <class T>
NodoExpresion<T>::~NodoExpresion()
{

}


template <class T>
T NodoExpresion<T>::getDato()
{
    return dato;
}


template <class T>
void NodoExpresion<T>::setDato(T& val)
{
    dato = val;
}


template <class T>
NodoExpresion<T>* NodoExpresion<T>::getIzquierda()
{
    return izq;
}


template <class T>
void NodoExpresion<T>::setIzquierda(NodoExpresion<T>* nizquierda)
{
    izq = nizquierda;
}


template <class T>
NodoExpresion<T>* NodoExpresion<T>::getDerecha()
{
    return der;
}


template <class T>
void NodoExpresion<T>::setDerecha(NodoExpresion<T>* nderecha)
{
    der = nderecha;
}


template < class T >
bool NodoExpresion<T>::buscar(T& n)
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
bool NodoExpresion<T>::insertarNodo(T _padre , T _dato)
{
    if(_padre == dato)
    {
        if(izq == NULL)
        {
            izq = new NodoExpresion<T>(_dato);
            return true;
        }
        else
{
            if(der == NULL)
            {
                der = new NodoExpresion<T>(_dato);
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
bool NodoExpresion<T>::eliminar(T _dato)
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
        {
            bool res = izq->eliminar(_dato);
        }
    }
    if(der != NULL)
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
            return der->eliminar(_dato);
    }
    else
        return false;
}
#endif // NodoExpresion_HXX_INCLUDED
