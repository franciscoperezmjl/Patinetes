#include "ColaPrioridad.h"
#include <iostream>

// ── helpers ──────────────────────────────────────────────
static inline int padre(int i){ return (i-1)/2; }
static inline int hijoIzq(int i){ return 2*i+1; }
static inline int hijoDer(int i){ return 2*i+2; }
static inline void swap(Incidencia& a, Incidencia& b){ Incidencia t=a; a=b; b=t; }

// O(log N): compara con padre y sube mientras gravedad sea menor
void ColaPrioridad::flotar(int i){
    while(i>0 && heap[i].gravedad < heap[padre(i)].gravedad){
        swap(heap[i], heap[padre(i)]);
        i = padre(i);
    }
}

// O(log N): compara con el hijo menor y baja mientras gravedad sea mayor
void ColaPrioridad::hundir(int i){
    while(hijoIzq(i) < sz){
        int menor = hijoIzq(i);
        if(hijoDer(i) < sz && heap[hijoDer(i)].gravedad < heap[menor].gravedad)
            menor = hijoDer(i);
        if(heap[i].gravedad <= heap[menor].gravedad) break;
        swap(heap[i], heap[menor]);
        i = menor;
    }
}

// ── público ───────────────────────────────────────────────
bool ColaPrioridad::estaVacia(){ return sz == 0; }

void ColaPrioridad::encolar(int id, std::string desc, int grav){
    if(sz >= MAX_HEAP){ std::cout << "Heap lleno\n"; return; }
    heap[sz++] = Incidencia(id, desc, grav);
    flotar(sz-1);                          // O(log N)
}

Incidencia ColaPrioridad::desencolar(){
    if(estaVacia()){ std::cout << "Heap vacio\n"; return Incidencia(); }
    Incidencia min = heap[0];
    heap[0] = heap[--sz];
    if(sz) hundir(0);                      // O(log N)
    return min;
}

void ColaPrioridad::mostrar(){
    if(estaVacia()){ std::cout << "[vacia]\n"; return; }
    std::cout << "--- Cola (top=max prioridad) ---\n";
    // Copia temporal para no destruir el heap
    ColaPrioridad tmp = *this;
    while(!tmp.estaVacia()){
        Incidencia inc = tmp.desencolar();
        std::cout << "[P" << inc.idPatinete << "] g=" << inc.gravedad
                  << " | " << inc.descripcion << "\n";
    }
}
