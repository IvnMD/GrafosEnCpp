/*
 * Proyecto: Grafos y Algoritmos en C++
 * Autor: Ivan Mesa Dominguez
 * GitHub: https://github.com/IvnMD
 * Anyo: 2024
 *
 * Descripcion:
 * Implementacion de estructuras de grafos y algoritmos asociados
 * (Kruskal, lectura de grafos desde fichero, pruebas y validaciones).
 *
 * Contexto academico:
 * Universidad de La Laguna – Ingenieria Informatica
 *
 * Creado por IvnMD
 */

#include <string.h>
#include "grafoCabecera.h"


void clrscr()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pressanykey()
{
#ifdef _WIN32
    system("pause");
#else
    cout << "Presione Enter para continuar..." << endl;
    system("read dummy");
#endif
}

void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{
    cout << "Optimizacion en Grafos, 2023-2024 Ivan Mesa Dominguez" << endl;
    cout << "c. [c]argar grafo desde fichero" << endl;
    if (dirigido == 0) //Grafo no dirigido
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
            cout << "g. Mostrar camino minimo usando el al[g]oritmo de Prim" << endl;
            cout << "k. Mostrar MST: [k]ruskal" << endl;
	    //Aqui se anyaden mas opciones al menu del grafo no dirigido
            }
    else
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
            cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
            cout << "f. Caminos minimos: [f]loyd-warshall" << endl;
            cout << "d. Caminos minimos: [d]ijkstra" << endl;
            cout << "x. Caminos minimos: PDM" << endl;
            cout << "b. Caminos minimos: [b]ellman Ford End" << endl;
            cout << "t. Caminos minimos: Compara[t]iva Dijkstra vs Bellman Ford End" << endl;
	        
            };

    cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
    cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
    cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por predecesores" << endl;
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un menu inicial si no hay un grafo cargado
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;
    clrscr();
    //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
    if (argc > 1)
    {
	cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
    };
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
        pressanykey();
        clrscr();
    }
    else
    {
        cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
        pressanykey();
        clrscr();
        do
        {
            menu(G.Es_dirigido(), opcion);
            switch (opcion)
            {
                case 'c' :
                    clrscr();
         	    cout << "Introduce el nombre completo del fichero de datos" << endl;
                    cin >> nombrefichero;
                    G.actualizar(nombrefichero, error_apertura);
                    if (error_apertura == 1)
                    {
                        cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << endl;
                    }
                    else
                    {
                        cout << "Fichero cargado correctamente desde " << nombrefichero << endl;
                    };
                    pressanykey();
                    clrscr();
                    break;

                case 'i' :
                    clrscr();
		    cout << "Grafo cargado desde " << nombrefichero << endl;
                    G.Info_Grafo();
                    pressanykey();
                    clrscr();
                    break;

                case 's' :
                    clrscr();
            cout << "Nodos de la lista de sucesores  " << endl;
                    G.Mostrar_Listas(1);
                    pressanykey();
                    clrscr();
                    break;

                case 'p' :
                    clrscr();
            cout << "Nodos de la lista de predecesores  " << endl;
                    G.Mostrar_Listas(-1);
                    pressanykey();
                    clrscr();
                    break;

                case 'a' :
                    clrscr();
            cout << "Nodos de la lista de adyacentes  " << endl;
                    G.Mostrar_Listas(0);
                    pressanykey();
                    clrscr();
                    break;

                case 'r' :
                    clrscr();
            cout << "Vamos a construir un recorrido en profundidad" << endl;
                    G.RecorridoProfundidad();
                    pressanykey();
                    clrscr();
                    break;

                case 'y' :
                    clrscr();
                    G.Mostrar_Matriz();
                    pressanykey();
                    clrscr();
                    break;


                case 'f' :
                    clrscr();
                    G.Floyd_Warshall();
                    pressanykey();
                    clrscr();
                    break;

                case 'm' :
                    clrscr();
                    G.RecorridoAmplitud();
                    pressanykey();
                    clrscr();
                    break;

                case 'g' :
                    clrscr();
                    G.Prim();
                    pressanykey();
                    clrscr();
                    break;

                case 'd' :
                    clrscr();
                    {
                        unsigned s;
                        double comp;
                        cout << "Introduce el nodo de partida: ";
                        cin >> s;
                        G.Dijkstra_(comp, s - 1);
                    }
                    pressanykey();
                    clrscr();
                    break;

                case 'b' :
                    clrscr();
                    {
                        unsigned s;
                        double comp;
                        cout << "Introduce el nodo de partida: ";
                        cin >> s;
                        G.BellmanFordEnd_(comp, s - 1);
                    }
                    pressanykey();
                    clrscr();
                    break;

                case 't' :
                    clrscr();
                    G.ComparativaCM();
                    pressanykey();
                    clrscr();
                    break;

                case 'k' :
                    clrscr();
                    G.Kruskal();
                    pressanykey();
                    clrscr();
                    break;
                
                case 'x' :
                    clrscr();
                    G.PDM();
                    pressanykey();
                    clrscr();
                    break;
            }
        }
    while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};