//Arbol binario.hxx

#ifndef ARBOLBINARIO_HXX_INCLUDED
#define ARBOLBINARIO_HXX_INCLUDED
#include <queue>
using namespace std;

template <class T>
ArbolBinario<T>::ArbolBinario()
{

}


template <class T>
ArbolBinario<T>::ArbolBinario(T val)
{
    raiz = new NodoExpresion<T>(val);
}


template <class T>
ArbolBinario<T>::~ArbolBinario()
{

}


template <class T>
bool ArbolBinario<T>::esVacio()
{
    if(raiz == NULL)
        return true;
    return false;
}


template <class T>
NodoExpresion<T>* ArbolBinario<T>::obtenerRaiz()
{
    return raiz;
}


template <class T>
T ArbolBinario<T>::obtenerDatoRaiz()
{
    return raiz->getDato();
}


template <class T>
void ArbolBinario<T>::fijarRaiz(NodoExpresion<T>* nraiz)
{
    raiz = nraiz;
}


template<class T>
bool ArbolBinario<T>::insertar(T padre, T n)
{
    if(raiz == NULL)
        return false;
    else
    {
        if(buscar(padre))
        {
            return raiz->insertarNodo(padre,n);
        }
    }
}


template <class T>
bool ArbolBinario<T>::eliminar(T n)
{
  string direccion;
  if(raiz == NULL)
    return false;
  /*cout << "Ingrese ( izq ) o ( der ) si quiere eliminar izquierda o derecha" << endl;
  cin >> direccion;*/
  /*if(direccion == "izq")
  {*/
    return raiz->eliminar(n);
  //}
  /*else
  {
     return raiz->eliminarDerecha(n);
  }*/
}


template <class T>
bool ArbolBinario<T>::buscar(T& n)
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
int ArbolBinario<T>::alturaM(NodoExpresion<T>* nodo)
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
int ArbolBinario<T>::tamano(NodoExpresion<T>* inicio)
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
void ArbolBinario<T>::inOrden(NodoExpresion<T>* inicio)
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
void ArbolBinario<T>::preOrden(NodoExpresion<T>* inicio)
{
    if(inicio != NULL)
    {
        cout << inicio->getDato();
        preOrden(inicio->getIzquierda());
        preOrden(inicio->getDerecha());
    }
}


template <class T>
void ArbolBinario<T>::posOrden(NodoExpresion<T>* inicio)
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
void ArbolBinario<T>::nivelOrden(NodoExpresion<T>* inicio)
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

#endif // ARBOLBINARIO_HXX_INCLUDED

