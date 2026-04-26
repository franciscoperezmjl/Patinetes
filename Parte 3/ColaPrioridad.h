#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H
#include <string>
#define MAX_HEAP 50

struct Incidencia {
    int    idPatinete;
    std::string descripcion;
    int    gravedad; // 1=máxima prioridad
    Incidencia(int id=0, std::string d="", int g=0): idPatinete(id), descripcion(d), gravedad(g){}
};

class ColaPrioridad {
    Incidencia heap[MAX_HEAP];
    int sz;

    void flotar(int i);  // O(log N): sube nodo hasta restaurar propiedad min-heap
    void hundir(int i);  // O(log N): baja nodo hasta restaurar propiedad min-heap

public:
    ColaPrioridad(): sz(0) {}
    bool      estaVacia();
    void      encolar(int idPatinete, std::string desc, int gravedad);
    Incidencia desencolar();
    void      mostrar();
};
#endif
