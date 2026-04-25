#include <iostream>
#include "Patinete.h"
#include "ArbolPatinetes.h"

int main() {
    ArbolPatinetes arbol;
    
    std::cout << "=== Plataforma de consulta de patinetes ===" << std::endl;
    std::cout << "\nDatos de prueba" << std::endl;
    
    arbol.insertar(Patinete(105, "disponible"));
    arbol.insertar(Patinete(87, "mantenimiento"));
    arbol.insertar(Patinete(123, "ocupado"));          // USE ESTOS DE EJEMPLO PUES ANDO ALGO PERDIDO DE LA LISTA ESTA
    arbol.insertar(Patinete(45, "disponible"));
    arbol.insertar(Patinete(156, "disponible"));
    arbol.insertar(Patinete(92, "mantenimiento"));
    arbol.insertar(Patinete(78, "ocupado"));
    arbol.insertar(Patinete(134, "disponible"));
    
    arbol.mostrarInorden();
    
    std::cout << "\n=== Ejemplos de Busqueda ===" << std::endl; //los busqueda no llevan acento porq se ralla al ejecutarlo
    
    Patinete* resultado1 = arbol.buscar(123);
    if (resultado1 != nullptr) { // si lo encuentra muestra esto
        std::cout << "Busqueda exitosa - Patinete ID 123: Estado = " << resultado1->estado << std::endl; 
    } else {
        std::cout << "Patinete ID 123 no encontrado." << std::endl;
    }
    
    Patinete* resultado2 = arbol.buscar(999); // este no lo encuentra entonces lo dice
    if (resultado2 != nullptr) {
        std::cout << "Busqueda exitosa - Patinete ID 999: Estado = " << resultado2->estado << std::endl;
    } else {
        std::cout << "Patinete ID 999 no encontrado." << std::endl;
    }
    
    return 0;
}
