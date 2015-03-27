//Nodo Binario.hxx

#ifndef NodoExpresion_HXX_INCLUDED
#define NodoExpresion_HXX_INCLUDED

template <class T>
NodoExpresion<T>::NodoExpresion()
{

}

template <class T>
bool NodoExpresion<T>::getBool()
{
    return isOpe;
}

template <class T>
NodoExpresion<T>::NodoExpresion(T& _dato)
{
    dato = _dato;
    if((_dato == '*')||(_dato == '+')||(_dato == '-')||(_dato == '/')||(_dato == '%')||(_dato == '^'))
    {
        isOpe = true;
    }
    else
    {
        isOpe = false;
    }
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
    if((val == '*')||(val == '+')||(val == '-')||(val != '/')||(val == '%')||(val == '^'))
    {
        isOpe = true;
    }
    else
    {
        isOpe = false;
    }
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
bool NodoExpresion<T>::insertarNodo(NodoExpresion<T>* _dato)
{
    //+-+78/4*291
    if(_dato->getBool())//-+
    {
        if (izq == NULL)//-
        {
            izq = _dato;//-+
            return true;
        }
        else
        {
            if(!izq->getBool())
            {
                return false;
            }
            bool aux = izq->insertarNodo(_dato);
            if(!aux)
            {
                if(der == NULL)
                {
                    der = _dato;
                    return true;
                }
                else if(!der->getBool())
                {
                    return false;
                }
                else
                {
                    return der->insertarNodo(_dato);
                }
            }
            return aux;
        }
    }
    else
    {
        bool aux;
        if(izq == NULL)
        {
            //cout<<"yay";
            izq = _dato;
            return true;
        }
        else
        {
            if(izq->getBool())
            {
               // cout<<dato;
                aux = izq->insertarNodo(_dato);
            }
            else
            {
                if(der == NULL)
                {
                  //  cout<<"yay";
                    der = _dato;
                    return true;
                }
                else
                {

                    if(der->getBool())
                    {
                        aux = der->insertarNodo(_dato);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if(!aux)
            {
                return der->insertarNodo(_dato);;
            }
        }
        return aux;
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
