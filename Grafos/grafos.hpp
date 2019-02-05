/*=========================================================================
===========================================================================
	=			 Nombre Archivo:	grafos.hpp					      =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         2018                                  =
    =            Asignatura:    Optimización                          =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/


/*----------  Libraries set  ----------*/
#pragma once
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>


/*====================================
=            CLASS GRAFO             =
====================================*/
using namespace std;

const unsigned UERROR = 65000;
const int maxint = 1000000;
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
 *
 *
**/
typedef struct
{
	unsigned j; // nodo
	int c; // atributo para expresar su peso, longitud, coste…
} ElementoLista;

typedef vector<ElementoLista> LA_nodo;
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
 *
 *
**/

/*----------  Declaración clase grafo  ----------*/


class GRAFO
{
	/*----------  Declaramos variables de cla clase grafo  ----------*/
	
	unsigned n; // número de nodos o vértices
	unsigned m; // número de arcos o aristas
	unsigned dirigido; // almacena 0 si el grafo es no dirigido, 1 en otro caso
	vector<LA_nodo> LS; // lista de sucesores o de adyacencia
	vector<LA_nodo> LP; // lista de predecesores

	/*----------  Declaramos los métodos publicos de la clase grafo  ----------*/
	
	public:
		GRAFO(char nombrefichero[], int &errorapertura); //Constructor, se encarga de leer el problema del fichero de texto "nombrefichero" de tipo "ifstream" y de asignar los atributos de la clase GRAFO, devolviendo 0 en "errorapertura" si no ha habido incidencia alguna y 1 si ha habido. Es necesario, por tanto, añadir la linea "#include <fstream>"
		void actualizar (char nombrefichero[], int &errorapertura);
		unsigned Es_dirigido(); //devuelve 0 si el grafo es no dirigido, 1 en otro caso
		void Info_Grafo();	//Muestra la informacion del grafo
		void Mostrar_Listas(int l);	//Muestra las listas de predecesores y sucesores
		void ListaPredecesores();	//Calcula la lista de predecesores
		~GRAFO();	//Destructor del grafo

};

/*=================================*/
/*=====  End of CLASS GRAFO  ======*/

