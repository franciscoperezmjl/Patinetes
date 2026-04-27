// Incluir la cabecera del árbol de patinetes
#include "ArbolPatinetes.h"
// Incluir la librería para usar cout (entrada/salida)
#include <iostream>

// Constructor: Inicializa el árbol vacío (raiz apunta a nullptr)
ArbolPatinetes::ArbolPatinetes() {
    raiz = nullptr;
}

// Destructor: Libera toda la memoria del árbol al destruir el objeto
ArbolPatinetes::~ArbolPatinetes() {
    liberarMemoria(raiz);
}

// Función privada que libera recursivamente la memoria de todos los nodos (Post-orden)
void ArbolPatinetes::liberarMemoria(Nodo* nodo) {
    // Si el nodo no es nulo
    if (nodo != nullptr) {
        // Libera recursivamente el subárbol izquierdo
        liberarMemoria(nodo->izquierda);
        // Libera recursivamente el subárbol derecho
        liberarMemoria(nodo->derecha);
        // Libera la memoria del nodo actual
        delete nodo;
    }
}

// Método público para insertar un patinete (llamada inicial)
void ArbolPatinetes::insertar(const Patinete& p) {
    insertarRecursivo(raiz, p);
}

// Método privado que realiza la inserción recursiva en el árbol
// El & en Nodo*& permite modificar el puntero original (no una copia)
void ArbolPatinetes::insertarRecursivo(Nodo*& nodo, const Patinete& p) {
    // Si llegamos a un espacio vacío, creamos un nuevo nodo
    if (nodo == nullptr) {
        nodo = new Nodo(p);
    } 
    // Si el ID del patinete es menor, insertamos en la rama izquierda
    else if (p.id < nodo->data.id) {
        insertarRecursivo(nodo->izquierda, p);
    } 
    // Si el ID del patinete es mayor, insertamos en la rama derecha
    else if (p.id > nodo->data.id) {
        insertarRecursivo(nodo->derecha, p);
    } 
    // Si el ID ya existe, mostramos un mensaje de error (no permitimos duplicados)
    else {
        std::cout << "ID repetido " << p.id << std::endl;
    }
}

// Método público para buscar un patinete por su ID
Patinete* ArbolPatinetes::buscar(int id) {
    // Comienza la búsqueda desde la raíz
    return buscarRecursivo(raiz, id);
}

// Método privado que realiza la búsqueda recursiva en el árbol
Patinete* ArbolPatinetes::buscarRecursivo(Nodo* nodo, int id) {
    // Si el nodo es nulo, el patinete no existe
    if (nodo == nullptr) {
        return nullptr;
    } 
    // Si encontramos el ID, devolvemos un puntero a los datos del patinete
    else if (id == nodo->data.id) {
        return &nodo->data;
    } 
    // Si el ID buscado es menor, buscamos en la rama izquierda
    else if (id < nodo->data.id) {
        return buscarRecursivo(nodo->izquierda, id);
    } 
    // Si el ID buscado es mayor, buscamos en la rama derecha
    else {
        return buscarRecursivo(nodo->derecha, id);
    }
}

// Método público para mostrar todos los patinetes ordenados por ID (recorrido Inorden)
void ArbolPatinetes::mostrarInorden() {
    std::cout << "Patinetes en orden (ID - Estado):" << std::endl;
    mostrarInordenRecursivo(raiz);
    std::cout << std::endl;
}

// Método privado que muestra el árbol en recorrido Inorden (izq-raiz-der)
// Esto garantiza que los patinetes se muestren ordenados por ID
void ArbolPatinetes::mostrarInordenRecursivo(Nodo* nodo) {
    // Si el nodo no es nulo
    if (nodo != nullptr) {
        // Procesa recursivamente el subárbol izquierdo
        mostrarInordenRecursivo(nodo->izquierda);
        // Muestra los datos del nodo actual (ID y Estado)
        std::cout << "ID: " << nodo->data.id << " - Estado: " << nodo->data.estado << std::endl;
        // Procesa recursivamente el subárbol derecho
        mostrarInordenRecursivo(nodo->derecha);
    }
}
