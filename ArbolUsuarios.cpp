#include <iostream>
#include "ArbolUsuarios.h"

using namespace std;

// Constructor: Inicializa el árbol vacío
ArbolUsuarios::ArbolUsuarios() {
    raiz = nullptr;
}

// Destructor: Llama a la función que borra todos los nodos para evitar Memory Leaks
ArbolUsuarios::~ArbolUsuarios() {
    liberarMemoria(raiz);
}

// Función recursiva para liberar memoria (Recorrido Post-orden)
void ArbolUsuarios::liberarMemoria(NodoUsuario* nodo) {
    if (nodo != nullptr) {
        liberarMemoria(nodo->izquierda);
        liberarMemoria(nodo->derecha);
        delete nodo; // ¡Aquí usamos el delete obligatorio de la asignatura!
    }
}

// Método público de inserción
void ArbolUsuarios::insertar(const Usuario& u) {
    insertarRecursivo(raiz, u);
}

// Lógica recursiva de inserción (O(log N))
void ArbolUsuarios::insertarRecursivo(NodoUsuario*& nodo, const Usuario& u) {
    // Si llegamos a un hueco vacío, creamos el nodo con 'new'
    if (nodo == nullptr) {
        nodo = new NodoUsuario(u);
    }
    // Si el ID es menor, nos vamos por la rama izquierda
    else if (u.id < nodo->data.id) {
        insertarRecursivo(nodo->izquierda, u);
    }
    // Si el ID es mayor, nos vamos por la rama derecha
    else if (u.id > nodo->data.id) {
        insertarRecursivo(nodo->derecha, u);
    }
    // Si el ID ya existe, no hacemos nada (no se admiten duplicados)
}

// Método público de búsqueda (Simula el Login)
Usuario* ArbolUsuarios::buscar(int id) {
    return buscarRecursivo(raiz, id);
}

// Lógica recursiva de búsqueda
Usuario* ArbolUsuarios::buscarRecursivo(NodoUsuario* nodo, int id) {
    // Caso base: no se encontró o el árbol está vacío
    if (nodo == nullptr) {
        return nullptr; 
    }
    // Caso base: ¡Lo encontramos! Devolvemos la dirección de memoria de los datos
    if (nodo->data.id == id) {
        return &(nodo->data);
    }
    // Búsqueda binaria: decidimos si ir a la izquierda o a la derecha
    if (id < nodo->data.id) {
        return buscarRecursivo(nodo->izquierda, id);
    } else {
        return buscarRecursivo(nodo->derecha, id);
    }
}

// Método público para mostrar
void ArbolUsuarios::mostrarInorden() {
    mostrarInordenRecursivo(raiz);
    cout << endl;
}

// Lógica recursiva para mostrar ordenado de menor a mayor ID
void ArbolUsuarios::mostrarInordenRecursivo(NodoUsuario* nodo) {
    if (nodo != nullptr) {
        mostrarInordenRecursivo(nodo->izquierda);
        cout << "[ID: " << nodo->data.id << "] " << nodo->data.nombre << " -> ";
        mostrarInordenRecursivo(nodo->derecha);
    }
}