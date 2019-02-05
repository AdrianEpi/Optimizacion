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
=            FUNCTIONS               =
====================================*/
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
 
            for (k=0; k<m; k++)
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
                ListaPredecesores(); 
 
            errorapertura = 1; 
 
        }//if 
 
        else 
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
void GRAFO::actualizar(char nombrefichero[], int &errorapertura)
{ 
     n = 0; 
     m = 0; 
     dirigido = 0; 
     LS.clear(); 
     LP.clear();    
    ElementoLista temp; 
    ifstream textfile; 
    textfile.open(nombrefichero); 
 
        if (textfile.is_open())
        { 
            textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido; 
            int i, j, k; 
            LS.resize(n); 
 
            for (k=0; k<m; k++)
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
                ListaPredecesores(); 
 
            errorapertura = 1; 
 
        }//if 
 
        else 
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
void GRAFO::Info_Grafo(void)
{ 
    cout << "Informacion básica del grafo" << endl; 
    if (dirigido == 1)
    { 
        cout << "Es Dirigido" << "\t\t || Nodos:" << n << "\t\t || Arcos:" << m << endl; 
 
    }//if 
    else if (dirigido == 0)
    { 
        cout << "No es Dirigido" << "\t\t || Nodos:" << n << "\t\t || Aristas:" << m << endl; 
 
    }//else if 
}//void Info_Grafo 
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/
void GRAFO::Mostrar_Listas(int l)
{ 
    switch(l)
    { 
        case 0: 
            cout << endl; 
            for (int i=0; i<n; i++)
            { 
                cout << "\t Nodo[" << i+1 << "]"; //Recorre el vector nodos y muestra cada uno. 
                for (int j=0; j<LS[i].size(); j++)
                { // Recorre el vector de sucesores/predecesores. 
                    cout << LS[i][j].j+1 << "||"; 
                }//for 
                cout << endl; 
            }//for 
            break; 
 
        case 1: 
            cout << endl; 
            for (int i=0; i<n; i++)
            { 
                cout << "[" << i+1 << "]"; //Recorre el vector nodos y muestra cada uno. 
                for (int j=0; j<LP[i].size(); j++)
                { // Recorre el vector de sucesores/predecesores. 
                    cout << LP[i][j].j+1 << "||"; 
                }//for 
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
void GRAFO::ListaPredecesores()
{ 
    ElementoLista temp; 
    LP.clear(); 
    LP.resize(n); 
    for (int i=0; i<n; i++)
    { 
        for (int j=0; j<LS[i].size(); j++)
        { 
            temp.j = i; 
            LP[LS[i][j].j].push_back(temp); 
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
void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{ 
    visitado[i] = true; 
    cout << i+1 << ", "; 
    for (unsigned j=0;j<LS[i].size();j++)
    { 
        if (visitado[LS[i][j].j] == false)
        { 
             dfs(LS[i][j].j, visitado); 
        }//if 
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
void GRAFO::ComponentesConexas()
{ 
    unsigned i, cc = 0; 
    vector <bool> visitado; 
    visitado.resize (n, false); 
    /*for (i=0; i<n; i++){ 
        visitado[i] = false; 
    }//for 
*/ 
    for (i=0; i<n; i++)
    { 
        if (visitado[i] == false)
        { 
            cc++; 
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
void GRAFO::Dijkstra()
{
    vector<bool> PermanentementeEtiquetado;     //Vector donde almacenamos los registros de los nodos etiquetados
    vector<int> d;      //Vector donde almacenamos los costes de cada lista
    vector<unsigned> pred;      // Vector donde almacenamos los predecesores
    int min;
    unsigned s, candidato;      //Indice de vector (s) candidato al camino (candidato)

    //Inicialmente no hay ningun nodo permanentemente etiquetado
    PermanentementeEtiquetado.resize(n,false);
    //Inicialmente todas las etiquetas distancias son infinito
    d.resize(n,maxint);
    //Inicialmente el pred es null
    pred.resize(n,UERROR);
    //Solicitamos al usuario nodo origen
    cout << endl;
    cout << "Caminos minimos: Dijkstra" << endl;
    cout << "Nodo de partida? [1-"<< n << "]: ";
    cin >> (unsigned &) s;
    //La etiqueta distancia del nodo origen es 0, y es su propio pred
    d[--s]=0; 
    pred[s]=s;
    do
    {
        min = maxint;
        for (int i = 0; i<n; i++)
        {
            if((PermanentementeEtiquetado[i] == false) and (d[i] < min))
            { 
                min = d[i]; //el minimo sera ahora esa etiqueta
                candidato = i; //el candidato sera ahora ese nodo
            }
        }
        if (min < maxint)
        {
            PermanentementeEtiquetado[candidato] = true;
            for (unsigned j = 0; j < LS[candidato].size(); j++)
            {
                if (PermanentementeEtiquetado[LS[candidato][j].j] == false)
                {
                    d[LS[candidato][j].j] = d[candidato] + LS[candidato][j].c;
                    pred[LS[candidato][j].j] = candidato;

                }   
            }
        }
    /*- Buscamos un nodo candidato a ser permanentemente etiquedado: aquel de
    entre los no permanentemente etiquetados con menor etiqueta
    distancia no infinita.
    - Si existe ese candidato, lo etiquetamos permanentemente y usamos los
    arcos de la lista de sucesores para buscar atajos.
    - Esto lo hacemos mientras haya candidatos*/
    }
    while (min < maxint);

    cout << "Soluciones:" << endl;

    bool solucion = false;
    for (int i = 0; i<n; i++)
    {
        if (d[i] < maxint)
        {
            solucion = true;
            cout << "Distancia = " << d[i] << "\tCamino: ";
            MostrarCamino(s, i, pred);
            cout << i+1 << endl;
        }
        else
        {
            cout << "No existe camino al nodo: ";
            cout << i+1 << endl;
        }
    }
    //En esta parte del código, mostramos los caminos mínimos, si los hay
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/
void GRAFO::BellmanEndFord() 
{
    vector<int> d;
    vector<unsigned> pred;
    unsigned s, i, j;
    unsigned numeromejoras = 0; //unsigned i, j
    bool mejora;

    //Idem que en el algoritmo de Dijkstra
    d.resize(n,maxint);
    pred.resize(n,UERROR);
    cout << endl;
    cout << "Caminos minimos: Bellman – End - Moore" << endl;
    cout << "Nodo de partida? [1-"<< n << "]: ";
    cin >> (unsigned &) s;
    d[--s]=0;
    pred[s]=s;
    do 
    {
        mejora = false;

        for ( i = 0; i<n; i++)
        {
            for ( j = 0; j<LS[i].size(); j++)
            {
                if (d[LS[i][j].c] < 0 and d[i] == maxint)
                {
                    d[LS[i][j].j] = d[i] + LS[i][j].c;
                    pred[LS[i][j].j] = i;
                    mejora = true;
                }
            }
        }
    // recorremos todos los arcos, y para cada (i, j), buscamos si d[j] > d[i] +
    //cij, y actualizamos d y pred
    //si al menos en una ocasion ha mejorado una etiqueta distancia, no hemos
    //terminado; contabilizamos los ciclos en los que ha habido mejoras
    }
    while ((numeromejoras < n) && (mejora == true));
    cout << "\nSoluciones: " << endl;
    bool solucion = false;
    cout << "Caminos minimos desde el nodo: " << s+1 << endl;
    if (mejora == false)
    {
        for (int i = 0; i<n; i++)
        {
            if (d[i] < maxint)
            {
                solucion = true;
                cout << "Distancia= " << d[i] << "\tCamino: ";
                MostrarCamino(s, i, pred);
                cout << i+1 << endl;
            }
            else
            {
                cout << "No existe camino al nodo: ";
                cout << i+1 << endl;
            }
        }
    }
    else
        cout << "El grafo contiene ciclos de coste negativos." << endl;

    /*/para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos
    realizado n+1 veces la relajacion con mejora; si mejora es false, pues
    tenemos solucion
    //Mostramos los caminos mínimos que se puedan haber encontrado, o advertimos
    de la existencia de un ciclo de coste negativo.*/
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/
void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred) 
{
    if (i != s)
    {
       MostrarCamino(s,pred[i],pred);
       cout << pred[i]+1 << " -> ";
    }
}
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
