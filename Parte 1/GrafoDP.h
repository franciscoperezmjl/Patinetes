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

class GrafoDP {
private:
    int numVertices;
    std::map<std::pair<int, int>, std::string> nombresRutas;
    std::vector<std::list<std::pair<int, int>>> adjList;
    
    // Método privado para Backtracking
    void dfsRutas(int current, int fin, std::vector<int>& path, std::vector<std::vector<int>>& rutas, std::vector<bool>& visited) const;

public:
    GrafoDP(int vertices);
    void agregarArista(int origen, int destino, int peso);
    void imprimirGrafo();
    void caminoMinimoDijkstra(int origen, int destino);
    void arbolExpansionMinimaPrim(int inicio);
    int gradoEntrada(int v) const;
    int gradoSalida(int v) const;
    std::vector<std::pair<int, int>> getConexiones(int v) const;
    std::vector<std::vector<int>> todasLasRutas(int inicio, int fin) const;
    void registrarNombreRuta(int origen, int destino, const std::string& nombre);
    std::string obtenerNombreRuta(int origen, int destino) const;
};

#endif
