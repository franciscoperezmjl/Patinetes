// Guards: Previene inclusiones múltiples
#ifndef ARBOLPATINETES_H
#define ARBOLPATINETES_H

#include <string>

class Patinete {
public:
    int id;                           // Identificador único del patinete
    std::string estado;               // Estado actual (disponible, ocupado, mantenimiento, etc)
    
    // Constructor: Inicializa un patinete con su ID y estado
    Patinete(int id, std::string estado) : id(id), estado(estado) {}
};
// Estructura que representa cada nodo del árbol binario de búsqueda
struct Nodo {
    Patinete data;              // Datos del patinete almacenado en este nodo
    Nodo* izquierda;            // Puntero al hijo izquierdo
    Nodo* derecha;              // Puntero al hijo derecho
    
    // Constructor: Crea un nodo con el patinete y sin hijos
    Nodo(const Patinete& p) : data(p), izquierda(nullptr), derecha(nullptr) {}
};

// Clase que implementa un Árbol Binario de Búsqueda para almacenar patinetes
class ArbolPatinetes {
private:
    Nodo* raiz;                 // Puntero a la raíz del árbol
    
    // Métodos privados recursivos
    void insertarRecursivo(Nodo*& nodo, const Patinete& p);   // Inserta recursivamente un patinete
    Patinete* buscarRecursivo(Nodo* nodo, int id);            // Busca recursivamente por ID
    void mostrarInordenRecursivo(Nodo* nodo);                 // Muestra el árbol en recorrido inorden
    void liberarMemoria(Nodo* nodo);                          // Libera la memoria de todos los nodos

public:
    // Constructor: Inicializa el árbol vacío
    ArbolPatinetes();
    
    // Destructor: Libera toda la memoria del árbol
    ~ArbolPatinetes();
    
    // Métodos públicos
    void insertar(const Patinete& p);       // Añade un patinete al árbol
    Patinete* buscar(int id);               // Busca un patinete por su ID
    void mostrarInorden();                  // Muestra todos los patinetes ordenados por ID
};

#endif