#include "GrafoDP.h"

using namespace std;

GrafoDP::GrafoDP(int vertices) {
    numVertices = vertices;
    adjList.resize(vertices); 
}

void GrafoDP::agregarArista(int origen, int destino, int peso) {
    adjList[origen].push_back(make_pair(destino, peso));
    adjList[destino].push_back(make_pair(origen, peso));
}

void GrafoDP::imprimirGrafo() {
    cout << "**** GRAFO DE LA CIUDAD ****\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "ESTACION : " << i << "\t Adyacentes : ";
        for (auto const& arista : adjList[i]) {
            cout << arista.first << "(" << arista.second << ") ";
        }
        cout << "\n";
    }
}

void GrafoDP::caminoMinimoDijkstra(int origen, int destino) {
    vector<int> dist(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[origen] = 0;
    pq.push(make_pair(0, origen));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto const& vecino : adjList[u]) {
            int v = vecino.first; 
            int peso = vecino.second;
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "--- RUTA MAS RAPIDA PARA EL FURGON [E" << origen << " -> E" << destino << "] ---\n";
    if (dist[destino] == INT_MAX) {
        cout << "No hay camino disponible.\n\n";
        return;
    }
    
    stack<int> camino;
    int actual = destino;
    while (actual != -1) {
        camino.push(actual);
        actual = parent[actual];
    }

    cout << "ESTACIONES : ";
    while (!camino.empty()) {
        cout << "E" << camino.top();
        camino.pop();
        if (!camino.empty()) cout << " -> ";
    }
    cout << "\nTIEMPO/COSTE : " << dist[destino] << " min\n\n";
}

void GrafoDP::arbolExpansionMinimaPrim(int inicio) {
    vector<int> costeMinimo(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);
    vector<bool> enMST(numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, inicio));
    costeMinimo[inicio] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (enMST[u]) continue;
        enMST[u] = true;

        for (auto const& vecino : adjList[u]) {
            int v = vecino.first;
            int peso = vecino.second;
            if (!enMST[v] && peso < costeMinimo[v]) {
                costeMinimo[v] = peso;
                pq.push(make_pair(costeMinimo[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "--- DISENO RED ELECTRICA MAS BARATA (PRIM) ---\n";
    int costeTotal = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (parent[i] != -1) {
            cout << "Cablear E" << parent[i] << " con E" << i << " (Coste: " << costeMinimo[i] << ")\n";
            costeTotal += costeMinimo[i];
        }
    }
    cout << "COSTE TOTAL: " << costeTotal << "\n\n";
}

void GrafoDP::dfsRutas(int current, int fin, vector<int>& path, vector<vector<int>>& rutas, vector<bool>& visited) const {
    visited[current] = true;
    path.push_back(current);

    if (current == fin) {
        rutas.push_back(path);
    } else {
        for (auto const& vecino : adjList[current]) {
            if (!visited[vecino.first]) {
                dfsRutas(vecino.first, fin, path, rutas, visited);
            }
        }
    }
    path.pop_back();
    visited[current] = false;
}

vector<vector<int>> GrafoDP::todasLasRutas(int inicio, int fin) const {
    vector<vector<int>> rutas;
    vector<int> path;
    vector<bool> visited(numVertices, false);
    dfsRutas(inicio, fin, path, rutas, visited);
    return rutas;
}

void GrafoDP::registrarNombreRuta(int origen, int destino, const string& nombre) {
    nombresRutas[make_pair(origen, destino)] = nombre;
    nombresRutas[make_pair(destino, origen)] = nombre; 
}

string GrafoDP::obtenerNombreRuta(int origen, int destino) const {
    auto it = nombresRutas.find(make_pair(origen, destino));
    return (it != nombresRutas.end()) ? it->second : "";
}
