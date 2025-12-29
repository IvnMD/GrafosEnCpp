# Grafos y Algoritmos en C++ (ULL)

Proyecto académico desarrollado en C++ centrado en la implementación, gestión y prueba de estructuras de grafos y algoritmos clásicos de optimización. El código sigue las especificaciones de la asignatura de Optimización de la Universidad de La Laguna.

## Autor
* **Iván Mesa Domínguez**
* GitHub: https://github.com/IvnMD
* Universidad de La Laguna – Ingeniería Informática

## Objetivos del proyecto
* Implementar la clase GRAFO mediante estructuras eficientes (listas de adyacencia).
* Aplicar algoritmos clásicos como Kruskal, BFS y DFS.
* Procesar instancias de grafos desde ficheros externos .gr.
* Validar resultados mediante pruebas controladas y separación de implementación.

## Estructura del repositorio

El repositorio se organiza por módulos correspondientes a las diferentes etapas de la asignatura:

* **OPT3_2024:** Implementación base de la clase GRAFO y carga básica de datos.
* **OPT4_2024:** Implementación de algoritmos de optimización, incluyendo el algoritmo de Kruskal.
* **OPT5_2024:** Grafos avanzados y nuevos escenarios de prueba.

## Especificaciones de los archivos .gr

Los archivos con extensión .gr son ficheros de texto plano utilizados para definir la estructura del grafo. El programa procesa estos archivos siguiendo un formato estricto:

### 1. Cabecera de configuración
La primera línea del fichero establece las propiedades globales:
`n m esdirigido?`

* n: Número total de nodos.
* m: Número total de arcos o aristas.
* esdirigido?: Valor booleano (1 para grafos dirigidos, 0 para no dirigidos).

### 2. Definición de conexiones
Las siguientes m líneas definen los elementos del grafo:
`i j c`

* i: Nodo de origen (vértice inicial).
* j: Nodo de destino (vértice final).
* c: Coste o peso asociado a la conexión.

### 3. Ejemplo de formato
Para un grafo con 5 nodos, 7 arcos y de tipo dirigido:
```text
5 7 1
1 2 1
1 3 2
1 5 -3
...

```

## Detalles de Implementación Técnica

### Estructura de Almacenamiento

Para optimizar el uso de memoria, se evita la matriz de adyacencia y se utiliza un vector de vectores de registros.

* **ElementoLista:** Estructura que contiene el nodo destino (j) y el coste (c).
* **LA_nodo:** Vector de ElementoLista que representa la lista de un nodo.

### Lógica de Procesamiento (Método Build)

* **Indexación:** El usuario trabaja con nodos del 1 al n. Internamente, el programa resta una unidad a cada nodo para ajustarse al indexado 0 a n-1 de C++.
* **Grafos Dirigidos:** Se realiza la carga simétrica en las listas de sucesores (LS) y predecesores (LP).
* **Grafos No Dirigidos:** Se utiliza la lista de adyacencia (LS). Para cada arista (i, j), se añade j como adyacente de i, e i como adyacente de j (excepto en bucles, donde solo se realiza una inserción).

## Compilación y ejecución

Para compilar el proyecto utilizando el compilador g++ en entornos Linux o Windows:

```bash
g++ mainGrafo2024.cpp grafo2024.cpp -o grafo
./grafo

```

## Tecnologías utilizadas

* Lenguaje: C++
* Paradigma: Programación modular y orientada a objetos
* Herramientas: g++ y entornos compatibles con POSIX/Windows

```

```
