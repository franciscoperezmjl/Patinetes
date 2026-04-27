// Guards: Previene inclusiones múltiples del archivo
#ifndef USUARIO_H
#define USUARIO_H

// Incluir librería para usar strings
#include <string>

// Clase que representa un usuario del sistema
class Usuario {
public:
    int id;                    // ID único del usuario (clave para búsqueda binaria en árbol)
    std::string nombre;        // Nombre completo del usuario
    std::string email;         // Email de contacto del usuario
    
    // Constructor: Inicializa un usuario con su información completa
    Usuario(int id, std::string nombre, std::string email) 
        : id(id), nombre(nombre), email(email) {}
};

// Fin de los guards
#endif