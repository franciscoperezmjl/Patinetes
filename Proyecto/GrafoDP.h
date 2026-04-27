// Guards: Previene inclusiones múltiples
#ifndef GRAFODP_H
#define GRAFODP_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <string>

// Clase que implementa un Grafo Dirigido con Ponderado para representar la ciudad
class GrafoDP {
private:
    int numVertices;                                        // Número de estaciones (vértices)
    std::map<std::pair<int, int>, std::string> nombresRutas;  // Mapa que almacena nombres de rutas
    std::vector<std::list<std::pair<int, int>>> adjList;   // Lista de adyacencia: cada vértice tiene una lista de (destino, peso)
    
    // Método privado para Backtracking (encontrar todas las rutas)
    void dfsRutas(int current, int fin, std::vector<int>& path, std::vector<std::vector<int>>& rutas, std::vector<bool>& visited) const;

public:
    // Constructor: Inicializa el grafo con un número de vértices
    GrafoDP(int vertices);
    
    // Métodos públicos
    void agregarArista(int origen, int destino, int peso);              // Añade una arista bidireccional entre dos estaciones
    void imprimirGrafo();                                               // Muestra la estructura completa del grafo
    void caminoMinimoDijkstra(int origen, int destino);                 // Encuentra el camino más corto (Dijkstra)
    void arbolExpansionMinimaPrim(int inicio);                          // Calcula el árbol de expansión mínima (Prim)
    int gradoEntrada(int v) const;                                      // Calcula el grado de entrada de un vértice
    int gradoSalida(int v) const;                                       // Calcula el grado de salida de un vértice
    std::vector<std::pair<int, int>> getConexiones(int v) const;        // Obtiene todas las conexiones de un vértice
    std::vector<std::vector<int>> todasLasRutas(int inicio, int fin) const;  // Encuentra todas las rutas posibles entre dos estaciones
    void registrarNombreRuta(int origen, int destino, const std::string& nombre);  // Almacena un nombre para una ruta
    std::string obtenerNombreRuta(int origen, int destino) const;       // Recupera el nombre de una ruta
};

#endif