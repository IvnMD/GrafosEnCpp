# Grafos y Algoritmos en C++ (ULL)

Proyecto académico desarrollado en C++ centrado en la implementación, gestión y prueba de estructuras de grafos y algoritmos clásicos de optimización. El código sigue las especificaciones de la asignatura de Optimización de la Universidad de La Laguna.

## Autor

- **Iván Mesa Domínguez**
- GitHub: https://github.com/IvnMD
- Universidad de La Laguna – Ingeniería Informática
- Año: 2024-2025

## Objetivos del proyecto

- Implementar la clase GRAFO mediante estructuras eficientes (listas de adyacencia).
- Aplicar algoritmos clásicos de grafos: Kruskal, Prim, Dijkstra, Bellman-Ford, Floyd-Warshall, DFS, BFS y PDM.
- Procesar instancias de grafos desde ficheros externos `.gr`.
- Validar resultados mediante pruebas controladas y separación de implementación.

## Estructura del repositorio

El repositorio se organiza por módulos correspondientes a las diferentes etapas de la asignatura:

```
GrafosEnCpp/
├── OPT5_2024/
│   ├── mainGrafo.cpp       # Programa principal con menú interactivo
│   ├── grafo.cpp           # Implementación de la clase GRAFO
│   ├── grafoCabecera.h     # Definición de la clase GRAFO y estructuras
│   └── *.gr                # Archivos de prueba de grafos
├── README.md               # Este archivo
├── LICENSE                 # Licencia Apache 2.0
└── .gitignore             # Archivos ignorados por Git
```

- **OPT5_2024:** Versión más reciente con todos los algoritmos implementados

## Algoritmos Implementados

### Algoritmos de Recorrido
- **DFS (Depth-First Search):** Recorrido en profundidad con orden prenum y postnum
- **BFS (Breadth-First Search):** Recorrido en amplitud con cálculo de distancias

### Algoritmos de Caminos Mínimos
- **Dijkstra:** Caminos mínimos desde un origen (grafos dirigidos con pesos no negativos)
- **Bellman-Ford End:** Caminos mínimos con detección de ciclos negativos
- **Floyd-Warshall:** Caminos mínimos entre todos los pares de nodos
- **PDM (Programación Dinámica de Mínimos):** Algoritmo optimizado con deque

### Algoritmos de Árbol Generador Mínimo (MST)
- **Prim:** MST para grafos no dirigidos
- **Kruskal:** MST con unión-find y ordenamiento de aristas

### Herramientas Adicionales
- **Comparativa Dijkstra vs Bellman-Ford:** Análisis de eficiencia
- **Verificación de Conectividad:** Comprobación si el grafo es conexo

## Especificaciones de los archivos .gr

Los archivos con extensión `.gr` son ficheros de texto plano utilizados para definir la estructura del grafo. El programa procesa estos archivos siguiendo un formato estricto:

### 1. Cabecera de configuración

La primera línea del fichero establece las propiedades globales:
```
n m dirigido
```

- **n:** Número total de nodos
- **m:** Número total de arcos o aristas
- **dirigido:** Valor booleano (1 para grafos dirigidos, 0 para no dirigidos)

### 2. Definición de conexiones

Las siguientes `m` líneas definen los elementos del grafo:
```
i j c
```

- **i:** Nodo de origen (vértice inicial, numeración 1 a n)
- **j:** Nodo de destino (vértice final, numeración 1 a n)
- **c:** Coste o peso asociado a la conexión

### 3. Ejemplo de formato

Para un grafo **no dirigido** con 5 nodos y 7 aristas:

```
5 7 0
1 2 10
1 3 15
2 3 20
2 4 25
3 4 30
3 5 35
4 5 40
```

Para un grafo **dirigido** con 4 nodos y 5 arcos (puede incluir pesos negativos):

```
4 5 1
1 2 5
1 3 2
2 4 -3
3 2 1
3 4 7
```

## Detalles de Implementación Técnica

### Estructura de Almacenamiento

Para optimizar el uso de memoria, se evita la matriz de adyacencia densa y se utiliza un **vector de listas de adyacencia**.

#### Estructuras principales:

```cpp
typedef struct {
    unsigned j;  // Nodo destino
    int c;       // Coste/peso de la arista
} ElementoLista;

typedef vector<ElementoLista> LA_nodo;
```

#### Miembros de la clase GRAFO:

- **LS (Lista de Sucesores):** `vector<LA_nodo>` - Para todos los grafos
- **LP (Lista de Predecesores):** `vector<LA_nodo>` - Solo para grafos dirigidos
- **A (Matriz de Adyacencia):** `vector<LA_nodo>` - Representación matricial para ciertos algoritmos
- **n:** Número de nodos
- **m:** Número de arcos/aristas
- **dirigido:** 0 para no dirigido, 1 para dirigido

### Lógica de Procesamiento (Método Build)

#### Indexación
El usuario trabaja con nodos del **1 al n**. Internamente, el programa resta una unidad a cada nodo para ajustarse al indexado **0 a n-1** de C++.

#### Grafos Dirigidos
Se realiza la carga en dos listas:
- **LS[i]:** Contiene los sucesores del nodo i
- **LP[j]:** Contiene los predecesores del nodo j

#### Grafos No Dirigidos
Se utiliza únicamente la lista de adyacencia (LS). Para cada arista `(i, j)`:
- Se añade `j` como adyacente de `i`
- Se añade `i` como adyacente de `j`
- **Excepción:** En bucles (i == j), solo se realiza una inserción

### Características Especiales

1. **Validación de entrada:** Todos los algoritmos validan que los nodos estén en el rango [1, n]
2. **Detección de ciclos negativos:** Implementada en Bellman-Ford
3. **Verificación de conectividad:** Kruskal verifica que el grafo sea conexo antes de ejecutarse
4. **Optimización de Kruskal:** Utiliza `std::sort` con lambda para ordenamiento eficiente
5. **Compatibilidad multiplataforma:** Funciones `clrscr()` y `pressanykey()` adaptadas para Windows y Unix

## Compilación y ejecución

### Requisitos
- Compilador g++ con soporte para C++11 o superior
- Sistema operativo: Linux, macOS o Windows

### Compilación

En el directorio del proyecto (OPT5_2024):

```bash
g++ -std=c++11 mainGrafo.cpp grafo.cpp -o grafos
```

### Ejecución

#### Con archivo especificado como argumento:
```bash
./grafos archivo.gr
```

#### Sin argumentos (solicita el archivo interactivamente):
```bash
./grafos
```

### Ejemplo de sesión

```
Introduce el nombre completo del fichero de datos: grafo1.gr
Grafo cargado correctamente desde el fichero grafo1.gr

=====================================================
  Optimizacion en Grafos, 2024-2025
  Ivan Mesa Dominguez
=====================================================

c. [c]argar grafo desde fichero
i. Mostrar [i]nformacion basica del grafo
a. Mostrar la lista de [a]dyacencia del grafo
k. Mostrar MST: [k]ruskal
g. Mostrar camino minimo usando el al[g]oritmo de Prim
y. Mostrar la matriz de ad[y]acencia del grafo
r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo
m. Realizar un recorrido en a[m]plitud del grafo desde un nodo
q. Finalizar el programa

Introduce la letra de la accion a ejecutar > i
```

## Menú de opciones

### Para grafos NO dirigidos (dirigido = 0):
- **c:** Cargar nuevo grafo desde fichero
- **i:** Mostrar información básica (nodos, aristas, tipo)
- **a:** Mostrar lista de adyacencia
- **g:** Ejecutar algoritmo de Prim (MST)
- **k:** Ejecutar algoritmo de Kruskal (MST)
- **y:** Mostrar matriz de adyacencia
- **r:** Recorrido en profundidad (DFS)
- **m:** Recorrido en amplitud (BFS)
- **q:** Salir del programa

### Para grafos dirigidos (dirigido = 1):
- **c:** Cargar nuevo grafo desde fichero
- **i:** Mostrar información básica (nodos, arcos, tipo)
- **s:** Mostrar lista de sucesores
- **p:** Mostrar lista de predecesores
- **f:** Ejecutar Floyd-Warshall (todos los caminos mínimos)
- **d:** Ejecutar PDM (caminos mínimos desde un origen)
- **t:** Comparativa Dijkstra vs Bellman-Ford
- **y:** Mostrar matriz de adyacencia
- **r:** Recorrido en profundidad (DFS)
- **m:** Recorrido en amplitud (BFS)
- **q:** Salir del programa

## Tecnologías utilizadas

- **Lenguaje:** C++ (estándar C++11)
- **Paradigma:** Programación modular y orientada a objetos
- **Estructuras de datos:** Vectores, listas de adyacencia, colas, deques
- **Herramientas:** g++, compiladores compatibles con C++11+
- **Sistemas operativos:** Linux, macOS, Windows

## Licencia

Este proyecto está bajo la licencia Apache 2.0. Consulta el archivo [LICENSE](LICENSE) para más detalles.

## Notas adicionales

- Los algoritmos están optimizados para grafos con miles de nodos
- Se incluye manejo de errores para archivos inválidos o corruptos
- La implementación sigue las especificaciones académicas de la ULL
- El código está documentado con comentarios en español

## Contacto

Para preguntas, sugerencias o reportar problemas:
- Perfil GitHub: https://github.com/IvnMD

---

**Desarrollado como proyecto académico para la asignatura de Optimización**  
**Universidad de La Laguna - Ingeniería Informática - 2024-2025**
