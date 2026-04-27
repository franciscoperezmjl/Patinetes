// Guards: Previene inclusiones múltiples
#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include <string>
// Máximo tamaño del heap (cola de prioridad)
#define MAX_HEAP 50

// Estructura que representa una incidencia (averia) en el taller
struct Incidencia {
    int    idPatinete;              // ID del patinete con la averia
    std::string descripcion;        // Descripción de la averia
    int    gravedad;                // Nivel de gravedad (1=máxima prioridad, 5=mínima)
    
    // Constructor: Inicializa una incidencia (valores por defecto si no se pasan parámetros)
    Incidencia(int id=0, std::string d="", int g=0): idPatinete(id), descripcion(d), gravedad(g){}
};

// Clase que implementa una cola de prioridad basada en Min-Heap
class ColaPrioridad {
private:
    Incidencia heap[MAX_HEAP];   // Array que almacena las incidencias en estructura de heap
    int sz;                       // Cantidad actual de elementos en el heap

    // Métodos privados para mantener la propiedad del min-heap
    void flotar(int i);           // O(log N): sube un nodo hacia la raíz si es menor que su padre
    void hundir(int i);           // O(log N): baja un nodo hacia las hojas si es mayor que sus hijos

public:
    // Constructor: Inicializa la cola vacía
    ColaPrioridad(): sz(0) {}
    
    // Métodos públicos
    bool      estaVacia();                                          // Verifica si la cola está vacía
    void      encolar(int idPatinete, std::string desc, int gravedad);  // Añade una incidencia a la cola
    Incidencia desencolar();                                        // Extrae la incidencia de máxima prioridad
    void      mostrar();                                            // Muestra todas las incidencias en la cola
};
#endif