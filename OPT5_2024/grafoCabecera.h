/*
 * Proyecto: Grafos y Algoritmos en C++
 * Autor: Iván Mesa Domínguez
 * GitHub: https://github.com/IvnMD
 * Año: 2024
 *
 * Descripción:
 * Implementación de estructuras de grafos y algoritmos asociados
 * (Kruskal, lectura de grafos desde fichero, pruebas y validaciones).
 *
 * Contexto académico:
 * Universidad de La Laguna – Ingeniería Informática
 *
 * Creado por IvnMD
 */


#ifndef _GRAPH_H
#define _GRAPH_H


#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <deque>

using namespace std;

const unsigned UERROR = 65000; //Para ciertos algoritmos es necesario codificar este valor de error
const int maxint = 1000000; //Para ciertos algoritmos es necesario codificar este valor de m�ximo



// definicion de un elemento de la lista de adyacencia
typedef struct
{
	unsigned j; //! nodo
	int      c; //! atributo para expresar los costes, pesos, las longitudes, las inversiones, etc...
} ElementoLista;



// definicion del tipo de una lista de adyacencia de un nodo
typedef vector<ElementoLista> LA_nodo;



// definicion de Arista Pesada para ordenacion en algoritmo de Kruskal
typedef struct 
{
unsigned extremo1, extremo2; 
int peso;
} AristaPesada;




class GRAFO
 {
	unsigned            dirigido;  //0 si el grafo es no dirigido y 1 si es dirigido
	unsigned            n;         // numero de NODOS
	unsigned            m;         // numero de ARCOS
	vector<LA_nodo>     LS;        // Lista de adyacencia de los sucesores: es una matriz dode cada fila posiblemente es posiblemente de distinto tama�o
	vector<LA_nodo>     LP;        // Lista de adyacencia de los predecesores: es una matriz dode cada fila posiblemente es posiblemente de distinto tama�o
	vector<LA_nodo>     A;         // Matriz de adyacencia, tanto adyacencia como costes
	void destroy();                // Destructor del LS, A, y LP, en su caso
	void build (char nombrefichero[85], int &errorapertura); //Crea LS, A y LP en su caso, desde la lectura del fichero
	void dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind); //Recorrido en profundidad recursivo con recorridos enum y postnum
     void bfs_num(unsigned i, vector<LA_nodo>  L, vector<unsigned> &pred, vector<unsigned> &d); //Recorrido en amplitud con calculo de pred y d
     

public:
     GRAFO(char nombrefichero[], int &errorapertura);
     void BellmanFordEnd_(double &comparaciones, unsigned s); //double &comparaciones, unsigned int s
     void Dijkstra_(double &comparaciones, unsigned s); //double &comparaciones, unsigned int s
     void actualizar (char nombrefichero[], int &errorapertura);
     unsigned Es_dirigido(); // devuelve 0 si el grafo es no dirigido y 1 si es dirigido
     void Info_Grafo(); // devuelve informaci�n b�sica del grafo
     void Mostrar_Listas(int l);  //Muestra la lista de adyacencia
     void Mostrar_Matriz(); //Muestra la matriz de adyacencia: nodos y costes
     void ListaPredecesores(); //Recorre la lista de sucesores LS para construir la de predecesores, LP
     void RecorridoProfundidad(); //Construye un recorrido en profundidad desde un nodo inicial
     void RecorridoAmplitud(); //Construye un recorrido en amplitud desde un nodo inicial
     void Floyd_Warhall();
     void Prim();
     void ComparativaCM();
     void Kruskal();
     bool EsConexo();
     void PDM(); 
     ~GRAFO(); //Destructor del objeto grafo
};

#endif
