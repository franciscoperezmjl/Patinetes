// Incluir la cabecera del grafo dirigido ponderado
#include "GrafoDP.h"

// Usar el espacio de nombres std para evitar escribir std:: cada vez
using namespace std;

// Constructor: Inicializa el grafo con un número de vértices (estaciones)
GrafoDP::GrafoDP(int vertices) {
    // Almacena el número de vértices del grafo
    numVertices = vertices;
    // Redimensiona la lista de adyacencia para tener un espacio por cada vértice
    adjList.resize(vertices); 
}

// Añade una arista bidireccional entre dos estaciones con un peso (tiempo/distancia)
void GrafoDP::agregarArista(int origen, int destino, int peso) {
    // Añade el destino con su peso a la lista de adyacencia del origen
    adjList[origen].push_back(make_pair(destino, peso));
    // Añade el origen con su peso a la lista de adyacencia del destino (bidireccional)
    adjList[destino].push_back(make_pair(origen, peso));
}

// Imprime toda la estructura del grafo de la ciudad
void GrafoDP::imprimirGrafo() {
    // Encabezado del gráfo
    cout << "**** Estaciones de la ciudad ****\n";
    // Itera sobre cada estación
    for (int i = 0; i < numVertices; ++i) {
        // Muestra el número de la estación
        cout << "ESTACION : " << i << "\t Adyacentes : ";
        // Itera sobre todas las estaciones adyacentes
        for (auto const& arista : adjList[i]) {
            // Muestra el ID de la estación adyacente y el peso (tiempo)
            cout << arista.first << "(" << arista.second << ") ";
        }
        cout << "\n";
    }
}

// Algoritmo de Dijkstra: encuentra el camino más corto entre dos estaciones
void GrafoDP::caminoMinimoDijkstra(int origen, int destino) {
    // Vector que almacena la distancia más corta desde el origen a cada vértice
    vector<int> dist(numVertices, INT_MAX);
    // Vector que almacena el vértice anterior en el camino más corto
    vector<int> parent(numVertices, -1);
    // Cola de prioridad (min-heap) para procesar vértices con menor distancia primero
    // Almacena pares (distancia, vértice)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Inicializa: la distancia del origen a sí mismo es 0
    dist[origen] = 0;
    // Añade el origen a la cola con distancia 0
    pq.push(make_pair(0, origen));

    // Procesa vértices mientras haya en la cola
    while (!pq.empty()) {
        // Extrae el vértice con menor distancia
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Si la distancia es mayor, ya se encontró un camino más corto
        if (d > dist[u]) continue;

        // Revisa todos los vecinos del vértice actual
        for (auto const& vecino : adjList[u]) {
            int v = vecino.first;  // Vértice vecino
            int peso = vecino.second;  // Peso de la arista
            // Si se encuentra un camino más corto hacia v
            if (dist[u] + peso < dist[v]) {
                // Actualiza la distancia más corta
                dist[v] = dist[u] + peso;
                // Registra el vértice anterior en el camino
                parent[v] = u;
                // Añade el vértice a la cola con su nueva distancia
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Muestra el encabezado con el par origen-destino
    cout << "--- RUTA MAS RAPIDA [E" << origen << " -> E" << destino << "] ---\n";
    // Si la distancia es infinita, no hay camino disponible
    if (dist[destino] == INT_MAX) {
        cout << "No hay camino disponible.\n\n";
        return;
    }
    
    // Usa una pila para reconstruir el camino desde el destino al origen
    stack<int> camino;
    int actual = destino;
    // Retrocede desde el destino hasta el origen usando los "padres"
    while (actual != -1) {
        camino.push(actual);
        actual = parent[actual];
    }

    // Muestra las estaciones del camino
    cout << "ESTACIONES : ";
    while (!camino.empty()) {
        cout << "E" << camino.top();
        camino.pop();
        if (!camino.empty()) cout << " -> ";
    }
    // Muestra el tiempo/coste total del camino
    cout << "\nTIEMPO/COSTE : " << dist[destino] << " min\n\n";
}

// Algoritmo de Prim: encuentra el árbol de expansión mínima de la ciudad
void GrafoDP::arbolExpansionMinimaPrim(int inicio) {
    // Vector que almacena el costo mínimo para conectar cada vértice
    vector<int> costeMinimo(numVertices, INT_MAX);
    // Vector que almacena el vértice anterior que conectó a este vértice
    vector<int> parent(numVertices, -1);
    // Vector que marca qué vértices ya están incluidos en el árbol
    vector<bool> enMST(numVertices, false);
    // Cola de prioridad para procesar vértices con menor costo
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Inicia el algoritmo desde el vértice dado
    pq.push(make_pair(0, inicio));
    costeMinimo[inicio] = 0;

    // Procesa vértices mientras haya en la cola
    while (!pq.empty()) {
        // Extrae el vértice con menor costo
        int u = pq.top().second;
        pq.pop();

        // Si ya está incluido en el árbol, salta
        if (enMST[u]) continue;
        // Marca el vértice como incluido en el árbol
        enMST[u] = true;

        // Revisa todos los vecinos del vértice
        for (auto const& vecino : adjList[u]) {
            int v = vecino.first;  // Vértice vecino
            int peso = vecino.second;  // Peso de la arista
            // Si el vecino no está en el árbol y hay una arista de menor costo
            if (!enMST[v] && peso < costeMinimo[v]) {
                // Actualiza el costo mínimo para conectar este vértice
                costeMinimo[v] = peso;
                // Añade el vértice a la cola
                pq.push(make_pair(costeMinimo[v], v));
                // Registra qué vértice lo conectó
                parent[v] = u;
            }
        }
    }

    // Muestra el encabezado
    cout << "--- Tiempo por rutas ---\n";
    int costeTotal = 0;
    // Itera sobre cada vértice (excepto el inicial)
    for (int i = 0; i < numVertices; ++i) {
        // Si el vértice tiene un padre (está conectado)
        if (parent[i] != -1) {
            // Muestra la arista del árbol
            cout << "Cablear E" << parent[i] << " con E" << i << " (Coste: " << costeMinimo[i] << ")\n";
            // Suma al costo total
            costeTotal += costeMinimo[i];
        }
    }
    // Muestra el costo total del árbol
    cout << "COSTE TOTAL: " << costeTotal << "\n\n";
}

// Método privado: Búsqueda en profundidad para encontrar todas las rutas
void GrafoDP::dfsRutas(int current, int fin, vector<int>& path, vector<vector<int>>& rutas, vector<bool>& visited) const {
    // Marca el vértice actual como visitado
    visited[current] = true;
    // Añade el vértice actual al camino
    path.push_back(current);

    // Si llegamos al destino, guardamos este camino
    if (current == fin) {
        rutas.push_back(path);
    } else {
        // Explora todos los vecinos no visitados
        for (auto const& vecino : adjList[current]) {
            if (!visited[vecino.first]) {
                // Llamada recursiva para continuar el DFS
                dfsRutas(vecino.first, fin, path, rutas, visited);
            }
        }
    }
    // Retroceso: elimina el vértice actual del camino
    path.pop_back();
    // Desmarca el vértice para poder usarlo en otros caminos
    visited[current] = false;
}

// Encuentra todas las rutas posibles entre dos estaciones
vector<vector<int>> GrafoDP::todasLasRutas(int inicio, int fin) const {
    // Vector para almacenar todas las rutas encontradas
    vector<vector<int>> rutas;
    // Vector para el camino actual
    vector<int> path;
    // Vector para marcar qué vértices han sido visitados
    vector<bool> visited(numVertices, false);
    // Inicia la búsqueda en profundidad
    dfsRutas(inicio, fin, path, rutas, visited);
    // Retorna todas las rutas encontradas
    return rutas;
}

// Registra un nombre descriptivo para una ruta entre dos estaciones
void GrafoDP::registrarNombreRuta(int origen, int destino, const string& nombre) {
    // Almacena el nombre para la ruta origen->destino
    nombresRutas[make_pair(origen, destino)] = nombre;
    // Almacena el nombre para la ruta destino->origen (bidireccional)
    nombresRutas[make_pair(destino, origen)] = nombre; 
}

// Obtiene el nombre de una ruta entre dos estaciones
string GrafoDP::obtenerNombreRuta(int origen, int destino) const {
    // Busca el nombre de la ruta
    auto it = nombresRutas.find(make_pair(origen, destino));
    // Retorna el nombre si existe, sino retorna una cadena vacía
    return (it != nombresRutas.end()) ? it->second : "";
}