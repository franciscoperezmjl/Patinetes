// Guards: Previene inclusiones múltiples
#ifndef ARBOLUSUARIOS_H
#define ARBOLUSUARIOS_H

#include "Usuario.h"

// Estructura que representa cada nodo del árbol binario de búsqueda de usuarios
struct NodoUsuario {
    Usuario data;               // Datos del usuario almacenado en este nodo
    NodoUsuario* izquierda;     // Puntero al hijo izquierdo
    NodoUsuario* derecha;       // Puntero al hijo derecho
    
    // Constructor: Crea un nodo con el usuario y sin hijos
    NodoUsuario(const Usuario& u) : data(u), izquierda(nullptr), derecha(nullptr) {}
};

// Clase que implementa un Árbol Binario de Búsqueda para almacenar usuarios
class ArbolUsuarios {
private:
    NodoUsuario* raiz;          // Puntero a la raíz del árbol
    
    // Métodos privados recursivos
    void insertarRecursivo(NodoUsuario*& nodo, const Usuario& u);      // Inserta recursivamente un usuario
    Usuario* buscarRecursivo(NodoUsuario* nodo, int id, int& pasos);   // Busca recursivamente por ID (cuenta pasos)
    void mostrarInordenRecursivo(NodoUsuario* nodo);                   // Muestra el árbol en recorrido inorden
    void liberarMemoria(NodoUsuario* nodo);                            // Libera la memoria de todos los nodos

public:
    // Constructor: Inicializa el árbol vacío
    ArbolUsuarios();
    
    // Destructor: Libera toda la memoria del árbol
    ~ArbolUsuarios();
    
    // Métodos públicos
    void insertar(const Usuario& u);            // Añade un usuario al árbol
    Usuario* buscar(int id, int& pasos);        // Busca un usuario (simula login) y cuenta los pasos
    void mostrarInorden();                      // Muestra todos los usuarios ordenados por ID
};

#endif