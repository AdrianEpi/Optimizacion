/*=========================================================================
===========================================================================
    =            Nombre Archivo:    main.cpp                          =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         2018                                  =
    =            Asignatura:    Optimización                          =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/**

    Descripcion:
        El objetivo de esta actividad es añadir nuevas funcionalidades al menú de utilidades sobre
grafos de las prácticas anteriores. En este caso, para el caso de grafos dirigidos o digrafos
estudiaremos algoritmos para contruir los caminos mínimos de un nodo del grafo a todos los
demás. Los métodos a implementar son el algoritmo de Dijkstra y el algoritmo de
Bellman-End-Moore.

*/

/* Compile: g++ -o name main.cpp grafos.cpp */



/**  ===  MAKEFILE  ===
    
    compile:
        g++ main.cpp grafos.cpp -std=c++11 -o name

**/



/*----------  Libraries set  ----------*/
#include <iostream> 
#include <iomanip> 
#include "grafos.hpp"  
using namespace std;


/*====================================
=            MAIN PROGRAM            =
====================================*/
int main (void)
{ 
    char nombrefichero[85]; 
    int errorapertura = 0; 
    unsigned input; 
    cout << "Introduce el nombre completo del fichero de datos:" << endl; 
    cin >> nombrefichero; 
    cout << nombrefichero << endl; 
    GRAFO A(nombrefichero, errorapertura); 
    cout << "Actividad I, Optimización" << endl; 
 
    do
    { 
        if (A.Es_dirigido()==1)
        { 
            cout << "Opciones de carga de un Grafo dirigifo desde fichero:" << endl << "1. Cargar grafo desde fichero." << endl << "2. Mostrar la informacion basica del grafo." << endl << "3. Mostrar la lista de sucesores del grafo." << endl << "4. Mostrar la lista de predecesores del grafo." << endl << "0. Finalizar el programa." << endl << "Introduce el numero de la accion a ejetucar" << endl; 
            cin >> input; 
            switch (input)
            { 
                case 1: 
                    system("clear");
                    A.actualizar(nombrefichero, errorapertura); 
                    break; 
                case 2: 
                    system("clear");
                    A.Info_Grafo(); 
                    break; 
                case 3: 
                    system("clear");
                    A.Mostrar_Listas(0); 
                    break; 
                case 4: 
                    system("clear");
                    A.Mostrar_Listas(1); 
                    break;
                case 5:
                    system("clear");
                    A.Dijkstra();
                    break;
                case 6:
                    system("clear");
                    A.BellmanEndFord();
                    break;     
                case 0: 
                    system("clear");
                    cout << "Saliendo..." << endl; 
                    break; 
                default: 
                    break; 
            }//switch 
        }//if 
 
        else if (A.Es_dirigido()==0)
        { 
            cout << "Opciones de carga de un Grafo no dirigifo desde fichero:" << endl << "1. Cargar grafo desde fichero." << endl << "2. Mostrar la informacion basica del grafo." << endl << "3. Mostrar la lista de adyacencia del grafo." << endl << "4. Mostrar componentes conexas del grafo." << endl << "0. Finalizar el programa." << endl << "Introduce el numero de la accion a ejetucar" << endl; 
            cin >> input; 
            switch (input)
            { 
                case 1: 
                    system("clear");
                    A.actualizar(nombrefichero, errorapertura); 
                    break; 
                case 2: 
                    system("clear");
                    A.Info_Grafo(); 
                    break; 
                case 3: 
                    system("clear");
                    A.Mostrar_Listas(0); 
                    break; 
                case 4: 
                    system("clear");
                    A.ComponentesConexas(); 
                    break; 
                case 0: 
                    system("clear");
                    cout << "Saliendo..." << endl; 
                default: 
                    break; 
 
            }//switch 
        }//else if 
         
        else 
            cout << "Error del main" << endl; 

    }while (input !=0); 
    
    cout << "\nPrograma finalizado con éxito." << endl; 
}//main
/*==========================*/
/*=====  End of Main  ======*/
