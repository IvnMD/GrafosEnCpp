 /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo2024.h"

void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		A[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();
	A.clear();

}

void GRAFO :: build (char nombrefichero[85], int &errorapertura)
{
    ElementoLista     dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open())
    {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		//! los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n);
        LP.resize(n);
        A.resize(n+1);
        ElementoLista aux;
        aux.j = 0;
        aux.c = 0;

        for (int b = 0; b < n; ++b){
            for (int v = 0; v < n; ++v){
                A[b].push_back(aux);
            }
        }

	        // leemos los m arcos
		for (k=0;k<m;k++)
        {
			textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
            if (Es_dirigido()){
              dummy.j = j-1;
              LS[i-1].push_back(dummy);

              dummy.j = i-1;  
              LP[j-1].push_back(dummy);

            } else {                    //!    !Es_dirigido()
              if (i == j) {
                dummy.j = j-1;
                LS[i-1].push_back(dummy);
              } else {
                dummy.j = j-1;
                LS[i-1].push_back(dummy);

                dummy.j = i-1;
                LS[j-1].push_back(dummy);
              }
            }
            if (dirigido == 1){
                A[i-1][j-1].j = 1;

                A[i-1][j-1].c = dummy.c;

            } else if (dirigido == 0){
                A[i-1][j-1].j = 1;
                A[j-1][i-1].j = 1;

                A[i-1][j-1].c = dummy.c;
                A[j-1][i-1].c = dummy.c;
            }
        }
    }
}

void GRAFO::ListaPredecesores()
{

}

GRAFO::~GRAFO()
{
	destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
	build (nombrefichero, errorapertura);
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido()
{
    if (dirigido == 0){
        return 0; 
    } else 
        return 1;
}

void GRAFO::Info_Grafo()
{
    if (Es_dirigido()){
        std::cout << "Grafo dirigido  | nodos " << n << "  |  arcos " << m << std::endl;
    } else {
        std::cout << "Grafo no dirigido  | nodos " << n << "   |  aristas " << m << std::endl;
    } 
}

void Mostrar_Lista(vector<LA_nodo> L)
{
    for (int k = 0; k < L.size(); k++){
      std::cout << "[" << k+1 << "] : ";
      for (int l = 0; l < L[k].size(); l++)
          std::cout << L[k][l].j+1 << " : (" << L[k][l].c << ") ";
      
        if (!L[k].size())
          std::cout << "null";
      std::cout << std::endl;
    }
}

void GRAFO :: Mostrar_Listas (int l)
{
    if (l == 1 || l == 0)
      Mostrar_Lista(LS);
    else 
      Mostrar_Lista(LP);
}

void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
{
    std::cout << "Matriz de adyacencia" << std::endl;
    for (int i = 0; i < n; ++i){
      std::cout << " |  ";
      for (int t = 0; t < n; ++t){
        std::cout << A[i][t].j << "  ";
       }
    std::cout << "| " << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Matriz de costes" << std::endl;

    for (int i = 0; i < n; ++i){
      std::cout << " | ";
      for (int t = 0; t < n; ++t){
        if (dirigido == 1){
            if (A[i][t].j == 1){
                std::cout << A[i][t].c << " ";
            } else {
                std::cout << "# ";
            }
        }else {
            if (A[i][t].c != 0){
                std::cout << A[i][t].c << " ";
            } else 
                std::cout << "# ";
        }
      }
    std::cout << "| " << std::endl;
    }
}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
	visitado[i] = true;
    prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j = 0; j < L[i].size(); j++)
             if (!visitado[L[i][j].j])
                {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i

    // // for (int i = 0; i < prenum.size(); ++i){
    // //     std::cout << prenum[i] << " ";
    // // }
    // // std::cout << std::endl;
    // // for (int i = 0; i < postnum.size(); ++i){
    // //     std::cout << postnum[i] << " ";
    // // }
    // // std::cout << std::endl;   
    // // std::cout << prenum[0] << " " << prenum[1] << " " << prenum[2] ;
    // // std::cout << std::endl;

}

void GRAFO::RecorridoProfundidad()
{
    unsigned num_nod;
    vector<bool> visitado;
    vector<unsigned> prenum;
    unsigned prenum_ind = 0;
    vector<unsigned> postnum;
    unsigned postnum_ind = 0;

    visitado.resize(n);
    prenum.resize(n);
    postnum.resize(n);

    std::cout << "Elija el nodo de partida? [1-" << n << "]: ";
    std::cin >> num_nod;

    dfs_num(num_nod-1, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);


    std::cout << "Orden de visita de los nodos en preorden" << std::endl;
    for (int i = 0; i < prenum.size(); ++i)
      if (i < prenum.size()-1)
        std::cout << "[" << prenum[i]+1 << "] -> ";
      else 
        std::cout << "[" << prenum[i]+1 << "]";
    

    std::cout << std::endl;

    std::cout << "Orden de visita de los nodos en postorden" << std::endl;
    for (int i = 0; i < postnum.size(); ++i){ 
      if (i < postnum.size()-1)
        std::cout << "[" << postnum[i]+1 << "] -> ";
      else 
        std::cout << "[" << postnum[i]+1 << "]";
    }
  std::cout << std::endl;
}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construcci�n de pred y d: usamos la cola
{
    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);  
    visitado[i] = true;
 
    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1
 
    while (!cola.empty()) //al menos entra una vez al visitar el nodo i+1 y contin�a hasta que la cola se vac�e
    {   unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j=0;j<L[k].size();j++)
          {
            unsigned u = L[k][j].j; //Recorremos todos los nodos u adyacentes al nodo k+1
            if (!visitado[u])      //Si el nodo u no esta visitado
            {
            visitado[u] = true;  //Lo visitamos
            cola.push(u);       //Lo metemos en la cola
            pred[u] = k + 1;   //le asignamos el predecesor
            d[u] = d[k] + 1;  //le calculamos su etiqueta distancia
            };               //Hemos terminado pues la cola esta vacia
      };
  }
}


void GRAFO::Floyd_Warhall(){

  vector <LA_nodo> P; //Usaremos la misma estructura de datos de LS para guardar P y D
  //Inicializamos P y D en P
  //Creamos P
  P.resize(n); //Ya tenemos las posiciones P[0] a P[n-1]

  for (unsigned i=0; i<n; i++)
    P[i].resize(n); //Ya tenemos la matriz cuadrada
  for (unsigned i=0;i<n;i++){
    for (unsigned j=0;j<n;j++){
      //Inicializaci�n base
      if (i != j) {
        P[i][j].j = 0; //en el campo .j ponemos el predecesor
        P[i][j].c = maxint; // en el campo .c ponemos el coste
      } else {
          P[i][j].c = 0; //El coste en el caso de un bucle
          P[i][j].j = i+1; //El predecesor en el caso de un bucle
        }
      };
  }
  //Recorremos LS para inicializar P, su predecesor en .j y su distancia en .c
  for (unsigned i=0;i<n;i++){
    for (unsigned j=0;j<LS[i].size();j++) {
      P[i][LS[i][j].j].j = i+1;
      P[i][LS[i][j].j].c= LS[i][j].c;
    };
  }
//Con las matrices ya inicializadas, vamos ahora a realizar las k comparativas...
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        if (i!=k) {
          for (int j = 0; j < n; j++) {
            if (j!=k) {
              if ((P[i][j].c > P[i][k].c + P[k][j].c) && (P[i][k].c != maxint) && (P[k][j].c != maxint)) {
                P[i][j].c = P[i][k].c + P[k][j].c;
                P[i][j].j = P[k][j].j;
              }
            }
          }
        }
      }
    }

std::cout << "Matriz de Distancias finales" << std::endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (P[i][j].c >= 1000000){
                std::cout << "Inf | ";
            }
            else if (P[i][j].c >= 0){
                std::cout << P[i][j].c << " | ";
            }
            else if (P[i][j].c <= 0){
                std::cout << P[i][j].c << " | ";
            }
        }
    std::cout << std::endl;
    }
std::cout << std::endl;

std::cout << "Matriz de Predecesores finales" << std::endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (P[i][j].j == 0){
                std::cout << "- | ";                
            }
            else{
            std::cout << P[i][j].j << " | ";
            }
        }
    std::cout << std::endl;
    }

std::cout << std::endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(P[i][j].c < 10000 && i != j) { //si es mayor de 10000 significa que el coste es infinito, y en la diagonal, los predecesores son los mismos nodos
                vector<int> predecesores;
                int aux = j;
                cout<<"Camino minimo de "<<i+1<<" a "<<j+1<<" coste "<<P[i][j].c<<" : ";
                while(aux != i) {
                    predecesores.push_back(P[i][aux].j);
                    aux = P[i][aux].j-1; //salta a la columna del predecesor
                    if(aux == j) break;
                }
                for(int i = predecesores.size()-1; i >= 0; i--) {
                    cout<<predecesores[i]<<" - ";
                }
                cout<<j+1<<"\n";
            }
        }
    }
}



void GRAFO::RecorridoAmplitud() //Construye un recorrido en amplitud desde un nodo inicial
{
    int nodo{0};

    std::cout << "Vamos a construir un recorrido en en amplitud" << endl;
    std::cout << "Elija nodo de partida ? [1 - " << n << "]: " ;
    std::cin >> nodo;
    
    vector<unsigned> pred;
    vector<unsigned> d;
    bfs_num(nodo - 1, LS, pred, d);
    unsigned e = 0;
    std::cout << "Nodos segun distancia al nodo inicial en numero de aristas" << endl;
    std::cout << "Distancia de 0 aristas : " << nodo << std::endl;
    for(unsigned a = 0; a < n; ++a) {
        if (d[a] > e) {
            e = d[a];
        }
    }
    for (unsigned b = 1; b <= e; b++) {
        std::cout << "Distancia de " << b << " aristas";
        for (unsigned c = 0; c < n; c++) {
            if (b == d[c]){
              std::cout << " : " << c + 1;  
            }
        }
        std::cout << std::endl;
    }
    std::cout << "La lista de predecesores es la siguiente:\n";
    for (unsigned i = 0; i < n; ++i) {
        if (pred[i] == 0) {
            std::cout << "Predecesor del nodo " << i + 1 << " : -" << endl;
        } else {
            std::cout << "Predecesor del nodo " << i + 1 << " : " << pred[i] << endl;
    }
  }
}




void GRAFO::Prim(){
  unsigned peso = 0;
  unsigned nodo_inicio{0};
  std::cout << "Vamos a utilizar el algoritmo de Prim para buscar el camino minimo (MST)" << std::endl;
  // // std::cout << "Ingrese el nodo inicial: ";
  // // unsigned nodo_inicio;
  // // std::cin >> nodo_inicio{0};
  // // nodo_inicio--; // Restamos 1 al nodo inicial para ajustar al índice del vector
  unsigned contador_T = 0; // T en pseudocodigo
  std::vector<int> coste; // Vector que almacena el coste mínimo para llegar a cada nodo desde el nodo inicial
  std::vector<unsigned> pred; // Vector que almacena el predecesor de cada nodo en el camino mínimo encontrado
  coste.resize(n, maxint); // Inicializamos el vector coste con valores infinitos, ya que no sabemos el costo de llegar a cada nodo
  pred.resize(n, 0); // Inicializamos el vector pred con 0 en cada posición, ya que aún no conocemos los predecesores
  std::vector<bool> M; // Vector que indica si un nodo ha sido visitado o no
  M.resize(n, false); // Inicializamos M en falso, ya que aún no hemos visitado ningún nodo
  coste[nodo_inicio] = 0; // Inicializamos el costo del nodo inicial a 0, ya que no tiene costo llegar a él mismo
  pred[nodo_inicio] = 0; // El predecesor del nodo inicial es él mismo
  M[nodo_inicio] = true; // Marcamos el nodo inicial como visitado

  while(contador_T != (n - 1)) { // Mientras no hayamos visitado todos los nodos
    for(int i = 0; i < LS[nodo_inicio].size(); i++) { // Iteramos por la lista de adyacencia del nodo actual
      if(M[LS[nodo_inicio][i].j] == false) { // Si el nodo adyacente no ha sido visitado
        if(coste[LS[nodo_inicio][i].j] > LS[nodo_inicio][i].c ){ // Si el costo para llegar al nodo adyacente es mayor que el costo de la arista que lo conecta
          coste[LS[nodo_inicio][i].j] = LS[nodo_inicio][i].c; // Actualizamos el costo mínimo para llegar al nodo adyacente
          pred[LS[nodo_inicio][i].j] = nodo_inicio; // Actualizamos el predecesor del nodo adyacente en el camino mínimo
        }
      }
    }
    int comparacion_menor_coste = maxint; // Inicializamos el valor para encontrar el nodo con el menor costo
    for(int j = 0; j < coste.size(); j++) { // Iteramos por todos los nodos para encontrar el nodo con el menor costo
      if((comparacion_menor_coste >= coste[j]) && (M[j] == false)){ // Si el costo del nodo es menor que el valor actual y no ha sido visitado
        nodo_inicio = j; // Actualizamos el nodo inicial al nodo con el menor costo
        comparacion_menor_coste = coste[j]; // Actualizamos el valor para encontrar el nodo con el menor costo
      }
    }
    peso = peso + coste[nodo_inicio]; // Sumamos el costo del nodo actual al peso total del MST
    M[nodo_inicio] = true; // Marcamos el nodo actual como visitado

    std::cout << " Nodo destino = (" << nodo_inicio + 1 << ") | Nodo origen = (" << pred[nodo_inicio] + 1 << ") | coste = [" << coste[nodo_inicio] << "]\n";
    contador_T++;
  }
  std::cout << "El peso del MST encontrado es: " << peso;
  std::cout << endl;
}

// Se define la función MostrarCamino, que se utiliza para mostrar el camino desde el nodo de partida hasta un nodo dado.
void MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred) 
{
	if (i != s) // Si el nodo actual no es igual al nodo de partida, se ejecuta el siguiente bloque de código.
    {
		MostrarCamino(s,pred[i],pred); // Se llama recursivamente a la función para mostrar el camino desde el nodo de partida hasta el nodo predecesor.
		cout << pred[i]+1 << " - ";  // Se muestra el nodo predecesor y se agrega un guion para separar los nodos del camino.
    }
}




// Esta función implementa el algoritmo de Dijkstra para encontrar el camino más corto desde un nodo de origen hasta todos los demás nodos en un grafo ponderado.
// El parámetro "comparaciones" se utiliza para contar el número de comparaciones que se hacen durante la ejecución del algoritmo.
// El parámetro "s" es el nodo de origen desde el que se inicia la búsqueda del camino más corto.
void GRAFO::Dijkstra_(double &comparaciones, unsigned s) {
  vector<bool> PermanentementeEtiquetado;// Se crean tres vectores para almacenar información sobre los nodos: PermanentementeEtiquetado para marcar los nodos que ya se han etiquetado de forma permanente.
  vector<int> d;                        // d para almacenar las etiquetas de distancia y pred para almacenar los predecesores en el camino más corto.
  vector<unsigned> pred;               // pred para almacenar los predecesores en el camino más corto.
  int min;
  unsigned candidato = s;
  // Al principio no hay nodos permanente etiquetados
  PermanentementeEtiquetado.resize(n,false); // n, numero de nodos
  // Al principio todas las etiquetas distancia son infinitas
  d.resize(n,maxint);
  // Al principio el pred es null == predecesores
  pred.resize(n,UERROR);
  // La etiqueta distancia del nodo origen es 0, y es su propio pred
  d[s] = 0;
  pred[s] = s;
  comparaciones = 0; 
  // Se inicia un bucle que se ejecuta mientras haya nodos que no estén etiquetados de forma permanente.
  do {
  min = maxint;
  /* Buscamos un nodo candidato a ser permanentemente etiquedado: aquel de
  entre los no permanentemente etiquetados, es decir, en el almacén con menor
  etiqueta distancia no infinita. */
 
  // Evaluamos los caminos.
  // Si existe ese candidato, lo etiquetamos permanentemente y usamos los arcos de la lista de sucesores para buscar atajos.Esto lo hacemos mientras haya candidatos

    for (unsigned k = 0; k < LS[candidato].size(); k++){ // Este bucle recorre los sucesores del nodo candidato en el grafo.
      if(PermanentementeEtiquetado[LS[candidato][k].j] == false){ // Comprueba si el sucesor no está permanentemente etiquetado.
        comparaciones++;
        if ((d[LS[candidato][k].j]) > (d[candidato] + LS[candidato][k].c)){   // Comprueba si se encuentra un camino más corto a través del nodo candidato.
          d[LS[candidato][k].j] = (d[candidato] + LS[candidato][k].c);
          pred[LS[candidato][k].j] = candidato;
        }
      }
    }
  for(int i = 0; i < n; i++) { // Este bucle busca el nodo no permanentemente etiquetado con la etiqueta de distancia mínima.
    if ((PermanentementeEtiquetado[i] == false) && (d[i] < min)) {
      candidato = i;
      min = d[i];
    }
  }

  PermanentementeEtiquetado[candidato] = true; // Se marca el nodo candidato como permanentemente etiquetado.
 
  } while (min < maxint); // Se repite el bucle mientras haya nodos no permanentemente etiquetados con etiquetas de distancia finitas.
    std::cout << endl; // Se imprimen los resultados de los caminos más cortos y sus longitudes.
    for (unsigned i = 0; i < n; i++) {
      if (i != s) {
        if(PermanentementeEtiquetado[i] == true) {
          std::cout << "El camino desde " << s + 1 << " al nodo " << i + 1 << " es: ";
          MostrarCamino(s, i, pred);
          std::cout << i + 1 << " de longitud " << d[i] << endl;
        } else {
        std::cout << "ERROR. No hay camino desde: " << s + 1 <<" al nodo " << i + 1 <<endl;
        }
      }    
    }
    std::cout << endl;
    std::cout << "Ha realizado un total de: " << comparaciones << " comparaciones." << endl; // Se muestra el número total de comparaciones realizadas durante la ejecución del algoritmo.
}



// Se inicia la función BellmanFordEnd_, que calcula el camino más corto desde un nodo de origen utilizando el algoritmo de Bellman-Ford.
void GRAFO::BellmanFordEnd_(double &comparaciones, unsigned s) {
  // Se crean los vectores para almacenar las distancias y los predecesores.
  vector<int> d;
  vector<unsigned> pred;
  unsigned numeromejoras = 0;
  bool mejora;
 // Se establece el tamaño de los vectores de distancias y predecesores.
  d.resize(n,maxint);
  pred.resize(n,UERROR);
  // Se inicializa la distancia del nodo de origen como 0 y se establece como su propio predecesor.
  d[s]=0; 
  pred[s]=s; 
  comparaciones = 0;
  do { // Se inicia el bucle principal del algoritmo de Bellman-Ford.
    mejora = false;
    // Se recorren todos los arcos del grafo. (i, j)
    for(unsigned i = 0; i < n; i++) { // Se recorren todos los arcos del grafo. (i, j)
      for(unsigned j = 0; j < LS[i].size(); j++){
        unsigned destino = LS[i][j].j;
        int peso = LS[i][j].c;
        comparaciones++;
        // Si se encuentra una distancia más corta al destino, se actualizan las distancias y predecesores.
        if(d[destino] > (d[i] + peso)){
          d[destino] = d[i] + peso;
          pred[destino] = i;
          mejora = true;
          numeromejoras++;
        }
      }
    }
  } 
  while ((numeromejoras < n + 1 && mejora)); 
  // Se muestra el resultado del algoritmo
    for (unsigned i = 0; i < n; i++) {
      if (i != s && pred[i] != UERROR) {
        if(mejora == false) {
          std::cout << "El camino desde " << s + 1 << " al nodo " << i + 1 << " es: ";
          MostrarCamino(s, i, pred);
          std::cout << i + 1 << " de longitud " << d[i] << endl;
        } else {
        std::cout << "ERROR. No hay camino desde: " << s + 1 <<" al nodo " << i + 1 <<endl;
        }
      }
    } // Se muestra el número total de comparaciones realizadas durante la ejecución del algoritmo.
    std::cout << "Ha realizado un total de: " << comparaciones << " comparaciones." << endl;    
}



// Se inicia la función ComparativaCM, que realiza una comparativa entre los algoritmos de Dijkstra y Bellman-Ford.
void GRAFO::ComparativaCM(){
  unsigned s; // Variable para almacenar el nodo de partida.
  double CompDijkstra = 0.0; // Variable para contar las comparaciones realizadas por el algoritmo de Dijkstra.
  double CompBellman = 0.0;  // Variable para contar las comparaciones realizadas por el algoritmo de Bellman-Ford.
  std::cout << "Camino mínimo  de un nodo al resto:\n";
  std::cout << "Nodo de partida? [1-" << n << "]: "; // Se solicita al usuario el nodo de partida.

  std::cin >> s;
  // Se muestra el encabezado y se ejecuta el algoritmo de Dijkstra.
  std::cout << "Resultados del algoritmo de Dijktra." << endl;
  std::cout << "Soluciones:\n";
  Dijkstra_(CompDijkstra, s - 1);

  // Se muestra el encabezado y se ejecuta el algoritmo de Bellman-Ford.
  std::cout << "\nResultados del algoritmo de Bellman Ford End." << endl;
  std::cout << "Soluciones:\n";
  BellmanFordEnd_(CompBellman, s - 1);
  
  std::cout << endl;
  // Se muestra la comparativa entre los algoritmos de Dijkstra y Bellman-Ford.
  std::cout << "El algoritmo de general basado en la condición de optimalidad, Bellman, Ford, End, ha realizado ";
  std::cout << CompBellman / CompDijkstra;
  std::cout << " veces más comparaciones para mejorar la etiqueta distancia que Dijkstra\n" << std::endl;;
}
