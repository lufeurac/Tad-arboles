#include<iostream>
#include<bits/stdc++.h>
#include "ArbolExpresion.h"
using namespace std;

int main()
{
    ArbolExpresion<char> expresion;
    ifstream cin("in.txt");
    int opc;
        cout << endl;
        cout << "1. Insertar Expresion" << endl;
        cout << "2. Pre Orden" << endl;
        cout << "3. In-Orden" << endl;
        cout << "4. Pos-Orden" << endl;
        cout << "5. Nivel-Orden" << endl;
        do{
        cin >> opc;
        switch(opc)
        {
            case 1:
            {
                    string linea;
                    cout << "Ingrese la expresion" << endl;
                    cin >> linea;
                    cout << " La expresion es: " << linea << endl;
                    for(int i = 0 ; i < linea.size() ; i++)
                    {
                        expresion.insertar(linea[i]);
                    }
                    cout << endl;
                    break;
            }
            case 2:
                    expresion.preOrden(expresion.obtenerRaiz());
                    cout << endl;
                    break;
            case 3:
                    expresion.inOrden(expresion.obtenerRaiz());
                    cout << endl;
                    break;
            case 4:
                    expresion.posOrden(expresion.obtenerRaiz());
                    cout << endl;
                    break;
            case 6:
            expresion.nivelOrden(expresion.obtenerRaiz());
                    cout << endl;
                    break;
                    }

        }while(opc != 6);
    return 0;
}
