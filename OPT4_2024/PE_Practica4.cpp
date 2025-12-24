void GRAFO::Kruskal()
{
unsigned head = 0; // POSICION DE LA ARISTA DE MENOR COSTE DE CADA ITERACION
unsigned cont = 0; // CONTADOR DE ARISTAS INSERTADAS EN EL MST
int pesoMST = 0; // coste del MST

  //Bucle principal del algoritmo de Kruskal
  do {
    // Ponemos en la posicion head del vector Aristas la arista de menos coste
    // Para ello recorremos las aristas desde la posicion head+1 hasta la m-1 intercambiando la de menor coste
    // con la que esta en la posicion head, salvo que head ya apunte a la ultima arista (la de la posicion m-1)
    if (head < m -1) {
      for (unsigned i = head + 1; i < m; i++) {
        //si el peso en la posicion head es > que el peso de la arista en la posicion i, entonces
        // intercambiamos Aristas[i] y Aristas[head]
      };
    };
  // Miramos si los extremos de la arista en la posicion head estan en ccxas distintas, y si es asi, metemos esa arista en el
  // MST fusionando las ccxas, es decir, unificando etiquetas.
    if (Raiz[Aristas[head].extremo1] != Raiz[Aristas[head].extremo2]) {
      kill = Raiz[Aristas[head].extremo1];
      para todo nodo k desde 0 hasta n-1, hacer 
        si raiz[k] == kill entonces raiz [k] = Raiz[Aristas[head].extremo2];
    
      // Incrementamos el contador de aristas en el MST
      cont++;

      // Mostramos la arista incorporada al MST
      cout << "Arista numero " << cont << " incorporada (" << Aristas[head].extremo1 << ", " << Aristas[head].extremo2
      << "), con peso " << Aristas[head].peso << endl;

      // Actualizamos el peso del MST
      pesoMST = pesoMST + Aristas[head].peso;
    };
    // Pasamos a la siguiente arista
    head++;
  } while ((cont < (n - 1)) && (head < m));
}


// // //! PRIMER INTENTO


// // void GRAFO::Kruskal()
// // {
// //   unsigned head = 0; // POSICION DE LA ARISTA DE MENOR COSTE DE CADA ITERACION
// //   unsigned cont = 0; // CONTADOR DE ARISTAS INSERTADAS EN EL MST
// //   int pesoMST = 0; // coste del MST
// //   // Inicializa el vector de aristas
// //   std::vector<AristaPesada> Aristas; // m es el numero de aristas en el grafo
// //    // Inicializa el vector de raíces
// //   std::vector<int> Raiz(n); // n es el número de nodos en el grafo
// //   for (unsigned i = 0; i < n; i++) {
// //     Raiz[i] = i;
// //   }


// //   //Bucle principal del algoritmo de Kruskal
// //   do {
// //     // Ponemos en la posicion head del vector Aristas la arista de menos coste
// //     // Para ello recorremos las aristas desde la posicion head+1 hasta la m-1 intercambiando la de menor coste
// //     // con la que esta en la posicion head, salvo que head ya apunte a la ultima arista (la de la posicion m-1)
// //     if (head < m -1) {
// //       for (unsigned i = head + 1; i < m; i++) {
// //         //si el peso en la posicion head es > que el peso de la arista en la posicion i, entonces
// //         // intercambiamos Aristas[i] y Aristas[head]
// //         if (Aristas[head].peso > Aristas[i].peso) {
// //           AristaPesada aux = Aristas[head];
// //           Aristas[head] = Aristas[i];
// //           Aristas[i] = aux;
// //         }
// //       }
// //     }
// //     // Miramos si los extremos de la arista en la posicion head estan en ccxas distintas, y si es asi, metemos esa arista en el
// //     // MST fusionando las ccxas, es decir, unificando etiquetas.
// //     if (Raiz[Aristas[head].extremo1] != Raiz[Aristas[head].extremo2]) {
// //       int kill = Raiz[Aristas[head].extremo1];
// //       for (unsigned k = 0; k < n; k++) {
// //         if (Raiz[k] == kill) {
// //           Raiz[k] = Raiz[Aristas[head].extremo2];
// //         }
// //       }
// //       // Incrementamos el contador de aristas en el MST
// //       cont++;

// //       // Mostramos la arista incorporada al MST
// //       std::cout << "Arista numero " << cont << " incorporada (" << Aristas[head].extremo1;
// //       std::cout << ", " << Aristas[head].extremo2 << "), con peso " << Aristas[head].peso << std::endl;

// //       // Actualizamos el peso del MST
// //       pesoMST = pesoMST + Aristas[head].peso;
// //     }
// //     // Pasamos a la siguiente arista
// //     head++;
// //   } while ((cont < (n - 1)) && (head < m));
// // }


// // void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
// // {
// // 	visitado[i] = true;
// //     prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
// //     for (unsigned j = 0; j < L[i].size(); j++)
// //              if (!visitado[L[i][j].j])
// //                 {
// //                 dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
// //                 };
// //     postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
// // }

// // void GRAFO::RecorridoProfundidad() {
// //   // 1. Declaración de variables
// //   unsigned num_nod; // Almacena el nodo inicial elegido por el usuario (sin ajustar)
// //   vector<bool> visitado(n); // Vector para marcar nodos visitados (tamaño n)
// //   vector<unsigned> prenum(n); // Vector para almacenar el orden de pre-visita (tamaño n)
// //   unsigned prenum_ind = 0; // Índice para asignar valores a prenum (inicializado a 0)
// //   vector<unsigned> postnum(n); // Vector para almacenar el orden de post-visita (tamaño n)
// //   unsigned postnum_ind = 0; // Índice para asignar valores a postnum (inicializado a 0)

// //   // 2. Reserva de memoria para vectores
// //   visitado.resize(n); // Reserva memoria para 'visitado' con tamaño n
// //   prenum.resize(n); // Reserva memoria para 'prenum' con tamaño n
// //   postnum.resize(n); // Reserva memoria para 'postnum' con tamaño n

// //   // 3. Solicitar nodo inicial
// //   std::cout << "Elija el nodo de partida? [1-" << n << "]: ";
// //   std::cin >> num_nod;

// //   // 4. Ajuste del nodo inicial (de externo a interno)
// //   num_nod--; // Resta 1 para ajustar el nodo inicial al índice interno (0 a n-1)

// //   // 5. Llamada a la función dfs_num para el recorrido DFS
// //   dfs_num(num_nod, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);

// //   // 6. Imprimir orden de visita en preorden
// //   std::cout << "Orden de visita de los nodos en preorden" << std::endl;
// //   for (int i = 0; i < prenum.size(); ++i) {
// //     if (i < prenum.size() - 1) {
// //       std::cout << "[" << prenum[i] + 1 << "] -> "; // Imprime nodo en preorden + 1 (ajuste externo) y flecha
// //     } else {
// //       std::cout << "[" << prenum[i] + 1 << "]"; // Imprime el último nodo en preorden + 1 (ajuste externo)
// //     }
// //   }
// //   std::cout << std::endl;

// //   // 7. Imprimir orden de visita en postorden
// //   std::cout << "Orden de visita de los nodos en postorden" << std::endl;
// //   for (int i = 0; i < postnum.size(); ++i) {
// //     if (i < postnum.size() - 1) {
// //       std::cout << "[" << postnum[i] + 1 << "] -> "; // Imprime nodo en postorden + 1 y flecha
// //     } else {
// //       std::cout << "[" << postnum[i] + 1 << "]"; // Imprime el último nodo en postorden + 1 
// //     }
// //   }
// //   std::cout << std::endl;
// // }
