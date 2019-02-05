/*=========================================================================
===========================================================================
	=			 Nombre Archivo:	main.cpp					      =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         2018                                  =
    =            Asignatura:    Optimización                          =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/
/**

    Descripcion:
        El objetivo de esta actividad es escribir un programa que gestione la carga de los datos de un
grafo a partir de las estructuras de sucesores o predecesores, en el caso de los grafos
dirigidos, y con las adyacencias, en el caso de los grafos no dirigidos. Usaremos la clase
GRAFO que, desde esta primera actividad, estará dotada de lo esencial para poder codificar
los grafos y trabajar con ellos bajo distintos algoritmos. El programa de prueba tendrá forma
de menú, que interactúa con el usuario para ejecutar las distintas opciones posibles.   

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



/*====================================
=            MAIN PROGRAM            =
====================================*/
using namespace std;

int main (void)
{
	/*----------  Declaración de variables  ----------*/
	
	char nombrefichero[85];
	int errorapertura = 0;
	unsigned input;

	/*----------  Solicitamos el fichero  ----------*/
	
	cout << "Introduce el nombre completo del fichero de datos:" << endl;
	cin >> nombrefichero;
	cout << nombrefichero << endl;
	GRAFO A(nombrefichero, errorapertura);		//LLamamos al constructor de clase y llamamos A al objeto
	cout << "Actividad I, Optimización" << endl;

	do
	{

		/*----------  En caso de que el grafo sea dirigido entramos a este menu  ----------*/
		
		if (A.Es_dirigido()==1)
		{
			cout << "Opciones de carga de un Grafo dirigifo desde fichero:" << endl;
			cout << "1. Cargar grafo desde fichero." << endl;
			cout << "2. Mostrar la informacion basica del grafo." << endl;
			cout << "3. Mostrar la lista de sucesores del grafo." << endl;
			cout << "4. Mostrar la lista de predecesores del grafo." << endl;
			cout << "5. Finalizar el programa." << endl;
			cout << "Introduce el numero de la accion a ejetucar" << endl;
			cin >> input;
			switch (input)
			{
				case 1:
					A.~GRAFO();
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
				case 5:
					break;
				default:
					break;
			}	
		}

		/*----------  En caso de no ser dirigido entramos al siguiente menu  ----------*/
		
		else if (A.Es_dirigido()==0)
		{
			cout << "Opciones de carga de un Grafo no dirigifo desde fichero:" << endl;
			cout << "1. Cargar grafo desde fichero." << endl;
			cout << "2. Mostrar la informacion basica del grafo." << endl;
			cout << "3. Mostrar la lista de adyacencia del grafo." << endl;
			cout << "5. Finalizar el programa." << endl;
			cout << "Introduce el numero de la accion a ejetucar" << endl;
			cin >> input;
			switch (input)
			{
				case 1:
					A.~GRAFO();
					A.actualizar(nombrefichero, errorapertura);
					break;
				case 2:
					A.Info_Grafo();
					break;
				case 3:
					A.Mostrar_Listas(0);
					break;
				default:
					break;
			}
		}
		
		else
			cout << "Error del main" << endl;
	}while (input !=5);
}
/*==========================*/
/*=====  End of Main  ======*/

