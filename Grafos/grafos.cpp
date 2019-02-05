/*=========================================================================
===========================================================================
    =			 Nombre Archivo:	grafos.cpp					      =
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


/*====================================
=            FUNCTIONS  GRAFO        =
====================================*/
using namespace std;
GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
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

}
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
 *
 *
**/
GRAFO::~GRAFO()
{
	 n = 0;
	 m = 0;
	 dirigido = 0;
	 LS.clear();
	 LP.clear();

}
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
 *
 *
**/
void GRAFO::actualizar(char nombrefichero[], int &errorapertura)
{
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
}
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
 *
 *
**/
unsigned GRAFO::Es_dirigido()
{
	return dirigido;
}
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
 *
 *
**/
void GRAFO::Info_Grafo(void)
{
	cout << "Informacion básica del grafo" << endl;
	if (dirigido == 1)
		cout << "Es Dirigido" << "\t\t || Nodos:" << n << "\t\t || Arcos:" << m << endl;

	else if (dirigido == 0)
		cout << "No es Dirigido" << "\t\t || Nodos:" << n << "\t\t || Aristas:" << m << endl;

}
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
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
				for (int j=0; j<LS[i].size(); j++) // Recorre el vector de sucesores/predecesores.
					cout << LS[i][j].j+1 << "||";
				
				cout << endl;
			}
			break;

		case 1:
			cout << endl;
			for (int i=0; i<n; i++)
			{
				cout << "[" << i+1 << "]"; //Recorre el vector nodos y muestra cada uno.
				for (int j=0; j<LP[i].size(); j++) // Recorre el vector de sucesores/predecesores.
					cout << LP[i][j].j+1 << "||";
				cout << endl;
			}
			break;

		default:
			break;
	}


}
/**
 *
 *
 *   Fecha: 2018
 *   Autor: Adrián Epifanio R.H
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
		}
	}
}
/*=====================================*/
/*=====  End of FUNCTIONS GRAFOS  ======*/
