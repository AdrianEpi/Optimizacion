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
        El objetivo de esta actividad es un primer uso de la clase GRAFO que se implementó en la
primera actividad, dotada de lo esencial para poder codificar los grafos y trabajar con ellos
bajo distintos algoritmos. Ampliaremos el menú en sus opciones para grafos no dirigidos,
permitiendo que se identifiquen las componentes conexas.

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
    /*----------  Declaración de variables  ----------*/
    
    char nombrefichero[85]; 
    int errorapertura = 0; 
    unsigned input; 

    /*----------  Carga del fichero grafo  ----------*/
    
    cout << "Introduce el nombre completo del fichero de datos:" << endl; 
    cin >> nombrefichero; 
    cout << nombrefichero << endl; 
    GRAFO A(nombrefichero, errorapertura); 
    cout << "Actividad I, Optimización" << endl; 
 
    do
    { 
        /*----------  Si es dirigido entramos en este menu  ----------*/
        
        if (A.Es_dirigido()==1)
        { 
            cout << "Opciones de carga de un Grafo dirigifo desde fichero:" << endl; 
            cout << "1. Cargar grafo desde fichero." << endl; 
            cout << "2. Mostrar la informacion basica del grafo." << endl; 
            cout << "3. Mostrar la lista de sucesores del grafo." << endl; 
            cout << "4. Mostrar la lista de predecesores del grafo." << endl; 
            cout << "0. Finalizar el programa." << endl; 
            cout << "Introduce el numero de la accion a ejetucar" << endl; 
            cin >> input; 
            switch (input)
            { 
                case 1: 
                    A.actualizar(nombrefichero, errorapertura); 
                    break; 
                case 2: 
                    A.Info_Grafo(); 
                    break; 
                case 3: 
                    A.Mostrar_Listas(0); 
                    break; 
                case 4: 
                    A.Mostrar_Listas(1); 
                    break;     
                case 0: 
                    cout << "Saliendo..." << endl; 
                    break; 
                default: 
                    break; 
            }//switch 
        }//if 
        
        /*----------  Si no es dirigido entramos en el siguiente menu  ----------*/
        
        else if (A.Es_dirigido()==0)
        { 
            cout << "Opciones de carga de un Grafo no dirigifo desde fichero:" << endl; 
            cout << "1. Cargar grafo desde fichero." << endl; 
            cout << "2. Mostrar la informacion basica del grafo." << endl; 
            cout << "3. Mostrar la lista de adyacencia del grafo." << endl; 
            cout << "4. Mostrar componentes conexas del grafo." << endl; 
            cout << "0. Finalizar el programa." << endl; 
            cout << "Introduce el numero de la accion a ejetucar" << endl; 
            cin >> input; 
            switch (input)
            { 
                case 1: 
                    A.actualizar(nombrefichero, errorapertura); 
                    break; 
                case 2: 
                    A.Info_Grafo(); 
                    break; 
                case 3: 
                    A.Mostrar_Listas(0); 
                    break; 
                case 4: 
                    A.ComponentesConexas(); 
                    break; 
                case 0: 
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
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2018
 *
 *
**/
