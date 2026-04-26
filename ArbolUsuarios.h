#ifndef ARBOLUSUARIOS_H
#define ARBOLUSUARIOS_H

#include "Usuario.h"

struct NodoUsuario {
    Usuario data;
    NodoUsuario* izquierda;
    NodoUsuario* derecha;
    
    NodoUsuario(const Usuario& u) : data(u), izquierda(nullptr), derecha(nullptr) {}
};

class ArbolUsuarios {
private:
    NodoUsuario* raiz;
    
    void insertarRecursivo(NodoUsuario*& nodo, const Usuario& u);
    Usuario* buscarRecursivo(NodoUsuario* nodo, int id);
    void mostrarInordenRecursivo(NodoUsuario* nodo);
    void liberarMemoria(NodoUsuario* nodo);

public:
    ArbolUsuarios();
    ~ArbolUsuarios();
    
    void insertar(const Usuario& u);
    Usuario* buscar(int id); // Para el inicio de sesión
    void mostrarInorden();   // Para listar todos los usuarios registrados
};

#endif