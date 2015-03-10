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
    raiz = new NodoBinario<T>(val);
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
NodoBinario<T>* ArbolBinario<T>::obtenerRaiz()
{
    return raiz;
}
template <class T>
void ArbolBinario<T>::fijarRaiz(NodoBinario<T>* nraiz)
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
          	string direccion;
            cout << "Ingrese ( izq ) o ( der ) si quiere eliminar izquierda o derecha" << endl;
  			cin >> direccion;
            if(direccion == "izq")
			{
    			return raiz->insertarIzquierda(padre,n);
  			}
  			else
  			{
     			return raiz->insertarDerecha(padre,n);
  			}
        }

    }
}

template <class T>
bool ArbolBinario<T>::eliminar(T n)
{
  string direccion;
  if(raiz == NULL)
    return false;
  cout << "Ingrese ( izq ) o ( der ) si quiere eliminar izquierda o derecha" << endl;
  cin >> direccion;
  if(direccion == "izq")
  {
    return raiz->eliminarIzquierda(n);
  }
  else
  {
     return raiz->eliminarDerecha(n);
  }
  
  
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
int ArbolBinario<T>::alturaM(NodoBinario<T>* nodo)
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
int ArbolBinario<T>::tamano(NodoBinario<T>* inicio)
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
void ArbolBinario<T>::inOrden(NodoBinario<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        inOrden(inicio->getIzquierda());
        cout << inicio->getDato() << endl;
        inOrden(inicio->getDerecha());
    }
}

template <class T>
void ArbolBinario<T>::preOrden(NodoBinario<T>* inicio)
{
    if(inicio != NULL)
    {
        cout << inicio->getDato() << endl;
        preOrden(inicio->getIzquierda());
        preOrden(inicio->getDerecha());
    }
}
template <class T>
void ArbolBinario<T>::posOrden(NodoBinario<T>* inicio)
{
    if(inicio == NULL)
        return;
    else
    {
        posOrden(inicio->getIzquierda());
        posOrden(inicio->getDerecha());
        cout << inicio->getDato() << endl;
    }
}

template <class T>
void ArbolBinario<T>::nivelOrden(NodoBinario<T>* inicio)
{
    queue< NodoBinario<T>* > cola;
    cola.push(inicio);
    while(!cola.empty())
    {
        cout << cola.front()->getDato() << endl;
        if(cola.front()->getIzquierda() != NULL)
            cola.push(cola.front()->getIzquierda());
        if(cola.front()->getDerecha() != NULL)
            cola.push(cola.front()->getDerecha());

        cola.pop();
    }
}

#endif // ARBOLBINARIO_HXX_INCLUDED

