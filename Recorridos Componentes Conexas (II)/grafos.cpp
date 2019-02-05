/*=========================================================================
===========================================================================
    =            Nombre Archivo:    grafos.cpp                        =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         2018                                  =
    =            Asignatura:    Optimización                          =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/

/*----------  Libraries set  ----------*/
#include <vector> 
#include "grafos.hpp" 
#include <fstream> 
 
using namespace std;


/*====================================
=            Functions               =
====================================*/
/*----------  Constructor del grafo  ----------*/

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{//Constructor 
    ElementoLista temp; 
    ifstream textfile; 
    textfile.open(nombrefichero); 
 
        if (textfile.is_open())
        { 
            textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido; 
            int i, j, k; 
            LS.resize(n); 
 
            for (k=0; k<m; k++) //Leemos el fichero
            { 
                textfile >> (unsigned &) i >> (unsigned &) j; 
                i--; 
                j--; 
                temp.j = j; 
                LS[i].push_back(temp);  //añado j a los sucesores de i (si el grafo es no dirigo --> adyacentes) 
 
                if (dirigido == 0 & i != j)
                { 
                    temp.j = i; 
                    LS[j].push_back(temp);  //si el grafo es no dirigido añado i a los adyacentes de j 
                }//if 
 
            }//for 
 
            textfile.close(); 
 
            if (dirigido==1) 
                ListaPredecesores(); //En caso de ser dirigido calculamos su lista de predecesores
 
            errorapertura = 1; 
 
        }//if 
 
        else //En caso de no abrirse nos lanza un error
            cout << "Error 404. File not found." << endl;
            errorapertura = 0; 
 
}// GRAFO 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/ 
/*----------  Destructor del grafo  ----------*/

GRAFO::~GRAFO()
{//Destructor 
     n = 0; 
     m = 0; 
     dirigido = 0; 
     LS.clear(); 
     LP.clear(); 
 
}//~Grafo 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/ 
/*----------  Funcion para cargar nuevo grafo  ----------*/

void GRAFO::actualizar(char nombrefichero[], int &errorapertura)
{ 
    n = 0; 
    m = 0; 
    dirigido = 0; 
    LS.clear(); //Limpiamos la lista de sucesores
    LP.clear(); //Limpiamos la lista de predecesores
    ElementoLista temp; 
    ifstream textfile; //Introducimos el nombre del nuevo fichero
    textfile.open(nombrefichero); //Abrimos el nuevo fichero
        //Implementamos un constructor para el nuevo fichero
        if (textfile.is_open())
        { 
            textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido; 
            int i, j, k; 
            LS.resize(n); 
 
            for (k=0; k<m; k++) //Leemos el fichero
            { 
                textfile >> (unsigned &) i >> (unsigned &) j; 
                i--; 
                j--; 
                temp.j = j; 
                LS[i].push_back(temp);  //añado j a los sucesores de i (si el grafo es no dirigo --> adyacentes) 
 
                if (dirigido == 0 & i != j)
                { 
                    temp.j = i; 
                    LS[j].push_back(temp);  //si el grafo es no dirigido añado i a los adyacentes de j 
                }//if 
 
            }//for 
 
            textfile.close(); 
 
            if (dirigido==1) 
                ListaPredecesores(); //En caso de ser dirigido calculamos su lista de predecesores
 
            errorapertura = 1; 
 
        }//if 
 
        else //En caso de no abrirse nos lanza un error
            cout << "Error 404. File not found." << endl;
            errorapertura = 0; 

}//void actualizar 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/ 
/*----------  Funcion para comprobar si el grafo es dirigido  ----------*/

unsigned GRAFO::Es_dirigido()
{ 
    return dirigido; 
}//unsigned Es_Dirigido 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/ 
/*----------  Funcion para mostrar informacion basica del grafo(Nº nodos y arcos/aristas)  ----------*/

void GRAFO::Info_Grafo(void)
{ 
    cout << "Informacion básica del grafo" << endl; 
    if (dirigido == 1) 
        cout << "Es Dirigido" << "\t\t || Nodos:" << n << "\t\t || Arcos:" << m << endl; 
 
    else if (dirigido == 0) 
        cout << "No es Dirigido" << "\t\t || Nodos:" << n << "\t\t || Aristas:" << m << endl; 
 
}//void Info_Grafo 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/ 
/*----------  Funcion para mostrar las listas de sucesores y predecesores  ----------*/

void GRAFO::Mostrar_Listas(int l)
{ 
    switch(l)
    { 
        case 0: 
            cout << endl; 
            for (int i=0; i<n; i++)
            { 
                cout << "\t Nodo[" << i+1 << "]"; //Recorre el vector nodos y muestra cada uno. 
                for (int j=0; j<LS[i].size(); j++)  // Recorre el vector de sucesores/predecesores. 
                    cout << LS[i][j].j+1 << "||"; 

                cout << endl; 
            }//for 
            break; 
 
        case 1: 
            cout << endl; 
            for (int i=0; i<n; i++)
            { 
                cout << "[" << i+1 << "]"; //Recorre el vector nodos y muestra cada uno. 
                for (int j=0; j<LP[i].size(); j++) // Recorre el vector de sucesores/predecesores. 
                    cout << LP[i][j].j+1 << "||"; 

                cout << endl; 
            }//for 
            break; 
 
        default: 
            break; 
    }//switch 
}// void Mostar_Listas 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/ 
/*----------  Funcion que calcula la lista de predecesores  ----------*/

void GRAFO::ListaPredecesores()
{ 
    ElementoLista temp; 
    LP.clear(); //Limpiamos la lista de predecesores
    LP.resize(n); //Asignamos un tamaño N a la lista de predecesores
    for (int i=0; i<n; i++)
    { 
        for (int j=0; j<LS[i].size(); j++)//Recorremos el vector y vamos almacenando en LP el predecesor
        { 
            temp.j = i; 
            LP[LS[i][j].j].push_back(temp); //Para LP cogemos el elemento anterior a LS
        }//for 
    }//for 
}//void ListaPredecesores  
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/ 
/*----------  Funcion DFS  ----------*/

void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{ 
    visitado[i] = true; //Iniciamos la variable visitado a true
    cout << i+1 << ", "; 
    for (unsigned j=0;j<LS[i].size();j++){

        if (visitado[LS[i][j].j] == false) 
             dfs(LS[i][j].j, visitado); //Creamos el DFS del grafo con la lista de Sucesores

    }//for 
}//void dfs 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/
/*----------  Funcion que calcula las componentes conexas  ----------*/

void GRAFO::ComponentesConexas(){ 
    unsigned i, cc = 0; //Creamos una variable unsigned i y otra cc(componente conexa)
    vector <bool> visitado; //Creamos un vector booleano llamado visitado
    visitado.resize (n, false); //Haccemos visitado de tamaño n e inicializado a false
    for (i=0; i<n; i++)
    { 
        if (visitado[i] == false) 
        { 
            cc++; //Implementamos el contador de la componente conexa
            cout << "\nLos nodos de la Componente Conexa " << cc << " son: " << " { " ; 
            dfs(i, visitado); 
            cout << " }\n" << endl; 
        }//if 
    }//for 
}//ComponentesConexas 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/
/*===============================*/
/*=====  End of Functions  ======*/
