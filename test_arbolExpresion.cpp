#include<iostream>
#include<bits/stdc++.h>
#include "ArbolExpresion.h"
using namespace std;

int main()
{
    ArbolExpresion<char> expresion;
    ArbolExpresion<char> evaluar;
    //ifstream cin("in.txt");
    string linea;
    cout << "Ingrese la expresion" << endl;
    getline(cin, linea);
    stringstream ss(linea);
    string s,l;
    while (getline(ss, s, ' '))
    {
        l=l+s;
        //cout << s << endl;
    }
    int opc;
    cout << endl;
    cout << "1. si es Expresion polaca" << endl;
    cout << "2. si es Expresion polaca inversa" << endl;
    cout << "3. Salir" << endl;
    cout << "Nota: si se selecciona una de las dos expresiones"<<endl;
    cout << " y se desea revisar una nueva toca reiniciar el programa" << endl<< endl;
    do
    {
        cin >> opc;
        switch(opc)
        {
        case 1:
        {
            cout << " La expresion es: " << l << endl;
            for(unsigned int i = 0 ; i<l.size() ; i++)
            {
                expresion.insertarPre(l[i]);
            }
            cout << endl;
            cout <<"Pre-Orden"<< endl;
            expresion.preOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"in-Orden"<< endl;
            expresion.inOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"pos-Orden"<< endl;
            expresion.posOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"nivel-Orden"<< endl;
            expresion.nivelOrden(expresion.obtenerRaiz());
            cout << endl;
            string  *ptrCad;
            string  cadena;
            ptrCad = &cadena;
            expresion.posOrdenEval(expresion.obtenerRaiz(), ptrCad);
            cout<<endl<<endl<<"Evaluar el pos-fijo de la expresion: "<<endl;
            cout<<"posfijo = "<<cadena<<endl;
            reverse(cadena.begin(),cadena.end());
            for(unsigned int i = 0 ; i<cadena.size() ; i++)
            {
                evaluar.insertarPos(cadena[i]);
            }
            cout <<"Pre-Orden"<< endl;
            expresion.preOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"in-Orden"<< endl;
            expresion.inOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"pos-Orden"<< endl;
            expresion.posOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"nivel-Orden"<< endl;
            expresion.nivelOrden(expresion.obtenerRaiz());
            cout << endl;
            break;
        }
        case 2:
        {
            cout << " La expresion es: " << l << endl;
            reverse(l.begin(),l.end());
            // cout << " La expresion es: " << l<< endl;
            for(unsigned int i = 0; i<l.size() ; i++)
            {
                //cout<<l[i]<<" ";
                expresion.insertarPos(l[i]);
            }
            cout << endl;
            cout <<"Pre-Orden"<< endl;
            expresion.preOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"in-Orden"<< endl;
            expresion.inOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"pos-Orden"<< endl;
            expresion.posOrden(expresion.obtenerRaiz());
            cout << endl;
            cout <<"nivel-Orden"<< endl;
            expresion.nivelOrden(expresion.obtenerRaiz());
            cout << endl;
            string  *ptrCad;
            string  cadena;
            ptrCad = &cadena;
            expresion.preOrdenEval(expresion.obtenerRaiz(), ptrCad);
            //reverse(cadena.begin(),cadena.end());
            cout<<endl<<endl<<"Evaluar el pre-fijo de la expresion: "<<endl;
            cout<<"prefijo = "<<cadena<<endl;
            for(unsigned int i = 0 ; i<cadena.size() ; i++)
            {
                evaluar.insertarPre(cadena[i]);
            }
            cout <<"Pre-Orden"<< endl;
            evaluar.preOrden(evaluar.obtenerRaiz());
            cout << endl;
            cout <<"in-Orden"<< endl;
            evaluar.inOrden(evaluar.obtenerRaiz());
            cout << endl;
            cout <<"pos-Orden"<< endl;
            evaluar.posOrden(evaluar.obtenerRaiz());
            cout << endl;
            cout <<"nivel-Orden"<< endl;
            evaluar.nivelOrden(evaluar.obtenerRaiz());
            cout << endl;
            break;
        }
        }
    }
    while(opc != 3);
    return 0;
}
