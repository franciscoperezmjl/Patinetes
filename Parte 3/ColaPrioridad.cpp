#include "ColaPrioridad.h"
#include <iostream>


// La estructura normal de un árbol se "aplasta" en una lista simple
// Se necesita usar matemática para saber dónde está la familia de cada nodo
// ¿cómo se navega por el árbol si no hay punteros?, Con un mapeo matemático de los índices del array 

// ── HELPERS (GPS MATEMÁTICO DEL ARBOL) ──────────────────────────────────────────────

// Si un nodo está en la posición 'i', su padre siempre está en la posición (i-1)/2
static  int padre(int i){ return (i-1)/2; }

// Si un nodo está en la posición 'i', su hijo izquierdo está en la posición (2*i)+1
static  int hijoIzq(int i){ return 2*i+1; }

// Si un nodo está en la posición 'i', su hijo derecho está en la posición (2*i)+2
static  int hijoDer(int i){ return 2*i+2; }

// función que intercambia dos averías de posición
//& para poder modificar directamente los elementos originales dentro de la lista cuando hacemos el intercambio.
static  void swap(Incidencia& a, Incidencia& b){ Incidencia t=a; a=b; b=t; } 
// no se puede hacer directamente a=b para cambiar la posicion, 
// porque perdemos el valor de a para luego pasarlo donde estaba b



// O(log N): compara con padre y sube mientras gravedad del padre sea menor
void ColaPrioridad::flotar(int i){
    while(i>0 && heap[i].gravedad < heap[padre(i)].gravedad){
        swap(heap[i], heap[padre(i)]);
        i = padre(i);
    }
}

// O(log N): compara con el hijo menor y baja mientras gravedad del hijo sea mayor
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

void ColaPrioridad::encolar(int id, int grav){
    if(sz >= MAX_HEAP){ std::cout << "Heap lleno\n"; return; }
    heap[sz++] = Incidencia(id, grav);
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
        std::cout << "[P" << inc.idPatinete << "] g=" << inc.gravedad << "\n";
                  
    }
}

