#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
public:
    int id; // Sirve como clave de búsqueda para el árbol
    std::string nombre;
    std::string email; 
    
    // Constructor
    Usuario(int id, std::string nombre, std::string email) : id(id), nombre(nombre), email(email) {}
};

#endif
