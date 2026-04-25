#ifndef ARBOLPATINETES_H
#define ARBOLPATINETES_H

#include "Patinete.h"

struct Nodo {
    Patinete data;
    Nodo* izquierda;
    Nodo* derecha;
    
    Nodo(const Patinete& p) : data(p), izquierda(nullptr), derecha(nullptr) {} // la & hace referencia y const es para no modificar pero recibirlo
};

class ArbolPatinetes {
private:
    Nodo* raiz; // primer nodo
    
    void insertarRecursivo(Nodo*& nodo, const Patinete& p); // mete patienetes
    Patinete* buscarRecursivo(Nodo* nodo, int id); // si coincide se queda, sino baja a la izq o der
    void mostrarInordenRecursivo(Nodo* nodo); // muestra el Inorden
    void liberarMemoria(Nodo* nodo);

public:
    ArbolPatinetes();
    ~ArbolPatinetes();
    void insertar(const Patinete& p); // añade patientes al arbol
    Patinete* buscar(int id); // busca patienetes por id
    void mostrarInorden();
};

#endif
