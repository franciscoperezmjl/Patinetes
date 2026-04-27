// Incluir la cabecera de la cola de prioridad
#include "ColaPrioridad.h"
// Incluir la librería de entrada/salida
#include <iostream>

// ESTRUCTURA TEÓRICA DE UN HEAP (árbol binario casi completo almacenado en array):
// La estructura normal de un árbol se "aplasta" en una lista simple (array)
// Se necesita usar matemática para saber dónde está la familia de cada nodo
// ¿Cómo se navega por el árbol si no hay punteros? Con un mapeo matemático de los índices del array

// ── HELPERS (GPS MATEMÁTICO DEL ÁRBOL) ──────────────────────────────────────────────

// Si un nodo está en la posición 'i', su padre siempre está en la posición (i-1)/2
static int padre(int i){ 
    return (i-1)/2; 
}

// Si un nodo está en la posición 'i', su hijo izquierdo está en la posición (2*i)+1
static int hijoIzq(int i){ 
    return 2*i+1; 
}

// Si un nodo está en la posición 'i', su hijo derecho está en la posición (2*i)+2
static int hijoDer(int i){ 
    return 2*i+2; 
}

// Función que intercambia dos averías de posición en el heap
// El & (referencia) permite modificar directamente los elementos originales
static void swap(Incidencia& a, Incidencia& b){ 
    // Guardamos el valor de 'a' en una variable temporal
    Incidencia t = a;  
    // Copiamos 'b' en 'a'
    a = b;  
    // Copiamos el valor temporal (original de 'a') en 'b'
    b = t;  
    // Nota: no se puede hacer directamente a=b porque perderíamos el valor de a
}

// O(log N): compara con padre y sube mientras gravedad del padre sea menor (MIN-HEAP)
void ColaPrioridad::flotar(int i){
    // Mientras no sea la raíz y el padre tenga mayor gravedad (menos prioridad)
    while(i > 0 && heap[i].gravedad < heap[padre(i)].gravedad){
        // Intercambia el nodo con su padre
        swap(heap[i], heap[padre(i)]);
        // Mueve el índice al padre para continuar flotando
        i = padre(i);
    }
}

// O(log N): compara con el hijo menor y baja mientras gravedad del hijo sea menor
void ColaPrioridad::hundir(int i){
    // Mientras el nodo tenga al menos un hijo izquierdo
    while(hijoIzq(i) < sz){
        // Asume que el hijo izquierdo es el menor
        int menor = hijoIzq(i);
        // Si existe hijo derecho y es menor que el izquierdo, actualiza 'menor'
        if(hijoDer(i) < sz && heap[hijoDer(i)].gravedad < heap[menor].gravedad)
            menor = hijoDer(i);
        // Si el nodo actual tiene menor o igual gravedad que el menor de sus hijos, la propiedad se cumple
        if(heap[i].gravedad <= heap[menor].gravedad) break;
        // Intercambia el nodo con su hijo menor
        swap(heap[i], heap[menor]);
        // Mueve el índice al hijo para continuar hundiendo
        i = menor;
    }
}

// ── MÉTODOS PÚBLICOS ───────────────────────────────────────────────

// Verifica si la cola de prioridad está vacía
bool ColaPrioridad::estaVacia(){ 
    return sz == 0; 
}

// Encola una incidencia (avería) en la cola de prioridad
void ColaPrioridad::encolar(int id, std::string desc, int grav){
    // Si la cola está llena, muestra error y retorna
    if(sz >= MAX_HEAP){ 
        std::cout << "Heap lleno\n"; 
        return; 
    }
    // Crea una nueva incidencia y la coloca al final del heap
    heap[sz++] = Incidencia(id, desc, grav);
    // Flota el nuevo elemento hasta su posición correcta O(log N)
    flotar(sz-1);
}

// Desencola la incidencia de máxima prioridad (menor gravedad)
Incidencia ColaPrioridad::desencolar(){
    // Si la cola está vacía, muestra error y retorna una incidencia por defecto
    if(estaVacia()){ 
        std::cout << "Heap vacio\n"; 
        return Incidencia(); 
    }
    // Guarda la incidencia de máxima prioridad (raíz del min-heap)
    Incidencia min = heap[0];
    // Mueve el último elemento a la raíz
    heap[0] = heap[--sz];
    // Si la cola no quedó vacía, hunde el nuevo elemento O(log N)
    if(sz) hundir(0);
    // Retorna la incidencia que fue removida
    return min;
}

// Muestra todas las incidencias en la cola de prioridad
void ColaPrioridad::mostrar(){
    // Si la cola está vacía, muestra mensaje y retorna
    if(estaVacia()){ 
        std::cout << "[vacia]\n"; 
        return; 
    }
    // Mensaje de encabezado
    std::cout << "--- Cola (top=max prioridad) ---\n";
    // Crea una copia temporal del heap para no destruir el original
    ColaPrioridad tmp = *this;
    // Desencola y muestra todas las incidencias
    while(!tmp.estaVacia()){
        // Extrae la incidencia de máxima prioridad
        Incidencia inc = tmp.desencolar();
        // Muestra el ID del patinete y su gravedad
        std::cout << "[P" << inc.idPatinete << "] g=" << inc.gravedad << "\n";
    }
}