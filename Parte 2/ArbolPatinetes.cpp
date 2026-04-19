#include "ArbolPatinetes.h"
#include <iostream> %para el cout

ArbolPatinetes::ArbolPatinetes() {
    raiz = nullptr;
}

ArbolPatinetes::~ArbolPatinetes() {
    liberarMemoria(raiz);
}

void ArbolPatinetes::liberarMemoria(Nodo* nodo) {
    if (nodo != nullptr) {
        liberarMemoria(nodo->izquierda);
        liberarMemoria(nodo->derecha);
        delete nodo;
    }
}

void ArbolPatinetes::insertar(const Patinete& p) {
    insertarRecursivo(raiz, p);
}

void ArbolPatinetes::insertarRecursivo(Nodo*& nodo, const Patinete& p) { %Puntero* referencia&
    if (nodo == nullptr) {
        nodo = new Nodo(p);
    } else if (p.id < nodo->data.id) {
        insertarRecursivo(nodo->izquierda, p); %si es mayor el nodo para la izq, sino a la der, asi hasta llegar al id buscado
    } else if (p.id > nodo->data.id) {
        insertarRecursivo(nodo->derecha, p);
    } else {
        std::cout << "ID repetido " << p.id << std::endl;
    }
}

Patinete* ArbolPatinetes::buscar(int id) { %empieza desde la raiz
    return buscarRecursivo(raiz, id);
}

Patinete* ArbolPatinetes::buscarRecursivo(Nodo* nodo, int id) { %recorre arbol
    if (nodo == nullptr) { %no existe
        return nullptr;
    } else if (id == nodo->data.id) { %devuelve patienete
        return &nodo->data;
    } else if (id < nodo->data.id) {
        return buscarRecursivo(nodo->izquierda, id);
    } else {
        return buscarRecursivo(nodo->derecha, id);
    }
}

void ArbolPatinetes::mostrarInorden() { %muestra patinetes
    std::cout << "Patinetes en orden (ID - Estado):" << std::endl;
    mostrarInordenRecursivo(raiz);
    std::cout << std::endl;
}

void ArbolPatinetes::mostrarInordenRecursivo(Nodo* nodo) { %recorre por oden el arbol mostrando los ID ordenados
    if (nodo != nullptr) {
        mostrarInordenRecursivo(nodo->izquierda);
        std::cout << "ID: " << nodo->data.id << " - Estado: " << nodo->data.estado << std::endl;
        mostrarInordenRecursivo(nodo->derecha);
    }
}
