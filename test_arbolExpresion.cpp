#include<iostream>
#include<bits/stdc++.h>
#include "ArbolExpresion.h"
using namespace std;

int main()
{
    ArbolExpresion<char> expresion;
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
    cout << "3. Pre Orden" << endl;
    cout << "4. In-Orden" << endl;
    cout << "5. Pos-Orden" << endl;
    cout << "6. Nivel-Orden" << endl;
    cout << "7. Limpiar arbol (No implementado)" << endl;
    cout << "8. Resultado de la operacion:" << endl;
    cout << "9. Salir" << endl;
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
            break;
        }
        case 2:
        {
            cout << " La expresion es: " << l << endl;
            reverse(l.begin(),l.end());
            for(unsigned int i = 0; i<l.size() ; i++)
            {
                expresion.insertarPos(l[i]);
            }
            cout << endl;
            break;
        }
        case 3:
            cout <<"Pre-Orden"<< endl;
            expresion.preOrden(expresion.obtenerRaiz());
            cout << endl;
            break;
        case 4:
            cout <<"in-Orden"<< endl;
            expresion.inOrden(expresion.obtenerRaiz());
            cout << endl;
            break;
        case 5:
            cout <<"pos-Orden"<< endl;
            expresion.posOrden(expresion.obtenerRaiz());
            cout << endl;
            break;
        case 6:
            cout <<"nivel-Orden"<< endl;
            expresion.nivelOrden(expresion.obtenerRaiz());
            cout << endl;
            break;
        case 8:
            cout <<"respuesta"<< endl;
            break;
        case 7:
            expresion.~ArbolExpresion();
            ArbolExpresion<char> expresion;
            cout << endl;
            break;

        }

    }
    while(opc != 9);
    return 0;
}
