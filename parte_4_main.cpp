#include <iostream>
#include "ArbolUsuarios.h"

using namespace std;

int main() {
    // 1. Instanciamos nuestra estructura (El Árbol)
    ArbolUsuarios arbol;

    /* ==========================================================================
     * BASE DE DATOS DE PRUEBA (MOCK DATA)
     * Nota: Para demostrar la eficiencia O(log N) del Árbol Binario de Búsqueda, 
     * se requiere un volumen de datos representativo.
     * Los siguientes 50 usuarios han sido generados utilizando Inteligencia 
     * Artificial (Gemini) como herramienta de generación de datos 
     * de prueba, agilizando el testeo del algoritmo.
     * ========================================================================== */
     
    arbol.insertar(Usuario(500, "Marcos Fernandez", "marcos.f@mail.com"));
    arbol.insertar(Usuario(250, "Lucia Garcia", "lucia.g@mail.com"));
    arbol.insertar(Usuario(750, "Alejandro Martinez", "alex.mtz@mail.com"));
    arbol.insertar(Usuario(120, "Sofia Rodriguez", "sofia.rod@mail.com"));
    arbol.insertar(Usuario(350, "Hugo Lopez", "hugo.lopez@mail.com"));
    arbol.insertar(Usuario(600, "Martina Sanchez", "martina.s@mail.com"));
    arbol.insertar(Usuario(850, "Mateo Perez", "mateo.p@mail.com"));
    arbol.insertar(Usuario(50, "Valeria Martin", "valeria.m@mail.com"));
    arbol.insertar(Usuario(180, "Daniel Gomez", "daniel.g@mail.com"));
    arbol.insertar(Usuario(290, "Julia Ruiz", "julia.ruiz@mail.com"));
    arbol.insertar(Usuario(420, "Pablo Hernandez", "pablo.h@mail.com"));
    arbol.insertar(Usuario(550, "Emma Diaz", "emma.diaz@mail.com"));
    arbol.insertar(Usuario(680, "Alvaro Alvarez", "alvaro.a@mail.com"));
    arbol.insertar(Usuario(780, "Carmen Moreno", "carmen.m@mail.com"));
    arbol.insertar(Usuario(920, "Adrian Miguez", "adrian.m@mail.com"));
    arbol.insertar(Usuario(20, "Alba Romero", "alba.r@mail.com"));
    arbol.insertar(Usuario(80, "David Alonso", "david.a@mail.com"));
    arbol.insertar(Usuario(150, "Noa Gutierrez", "noa.g@mail.com"));
    arbol.insertar(Usuario(210, "Diego Navarro", "diego.n@mail.com"));
    arbol.insertar(Usuario(270, "Claudia Torres", "claudia.t@mail.com"));
    arbol.insertar(Usuario(320, "Mario Dominguez", "mario.d@mail.com"));
    arbol.insertar(Usuario(380, "Marta Vazquez", "marta.v@mail.com"));
    arbol.insertar(Usuario(460, "Leo Ramos", "leo.ramos@mail.com"));
    arbol.insertar(Usuario(490, "Laura Gil", "laura.gil@mail.com"));
    arbol.insertar(Usuario(520, "Izan Ramirez", "izan.r@mail.com"));
    arbol.insertar(Usuario(580, "Irene Garrido", "irene.g@mail.com"));
    arbol.insertar(Usuario(630, "Javier Blanco", "javier.b@mail.com"));
    arbol.insertar(Usuario(660, "Sara Iglesias", "sara.i@mail.com"));
    arbol.insertar(Usuario(710, "Enzo Castro", "enzo.c@mail.com"));
    arbol.insertar(Usuario(730, "Elena Suarez", "elena.s@mail.com"));
    arbol.insertar(Usuario(760, "Luca Ortega", "luca.o@mail.com"));
    arbol.insertar(Usuario(820, "Daniela Rubio", "daniela.r@mail.com"));
    arbol.insertar(Usuario(880, "Gael Marin", "gael.m@mail.com"));
    arbol.insertar(Usuario(900, "Paula Sanz", "paula.s@mail.com"));
    arbol.insertar(Usuario(950, "Thiago Alcantara", "thiago.n@mail.com"));
    arbol.insertar(Usuario(980, "Carla Iglesias", "carla.i@mail.com"));
    arbol.insertar(Usuario(10, "Oliver Medina", "oliver.m@mail.com"));
    arbol.insertar(Usuario(40, "Vega Cortes", "vega.c@mail.com"));
    arbol.insertar(Usuario(70, "Bruno Castillo", "bruno.c@mail.com"));
    arbol.insertar(Usuario(90, "Mia Santos", "mia.s@mail.com"));
    arbol.insertar(Usuario(110, "Alex Lozano", "alex.l@mail.com"));
    arbol.insertar(Usuario(140, "Alma Guerrero", "alma.g@mail.com"));
    arbol.insertar(Usuario(170, "Eric Cano", "eric.c@mail.com"));
    arbol.insertar(Usuario(200, "Aitana Prieto", "aitana.p@mail.com"));
    arbol.insertar(Usuario(230, "Hector Mendez", "hector.m@mail.com"));
    arbol.insertar(Usuario(260, "Lola Cruz", "lola.c@mail.com"));
    arbol.insertar(Usuario(300, "Dario Calvo", "dario.c@mail.com"));
    arbol.insertar(Usuario(340, "Valentina Gallego", "valentina.g@mail.com"));
    arbol.insertar(Usuario(400, "Nicolas Vidal", "nicolas.v@mail.com"));
    arbol.insertar(Usuario(440, "Candela Leon", "candela.l@mail.com"));

    // 4. Mostramos el árbol (deberían salir ordenados por ID automáticamente)
    cout << "--- Base de Datos de Usuarios (Ordenados por ID) ---" << endl;
    arbol.mostrarInorden();
    cout << "----------------------------------------------------" << endl;

    // 5. Simulamos un inicio de sesión en O(log N)
    cout << "\n========================================================" << endl;
    cout << "       SISTEMA DE BUSQUEDA DE USUARIOS EN TIEMPO REAL       " << endl;
    cout << "========================================================" << endl;
    
    int idBuscado;
    cout << "Introduce el ID del usuario que deseas buscar: ";
    cin >> idBuscado; // Aquí el programa se pausa y espera a que escribas un número

    cout << "\nBuscando ID " << idBuscado << " en el Arbol Binario..." << endl;
    
    int pasos = 0;
    Usuario* encontrado = arbol.buscar(idBuscado, pasos);
    
    if (encontrado != nullptr) {
        cout << "Exito. Bienvenido al sistema, " << encontrado->nombre << "." << endl;
        cout << "\n[RENDIMIENTO] Operacion completada en tan solo " << pasos << " saltos." << endl;
    } else {
        cout << "Error: Usuario no registrado." << endl;
    }

    return 0; // Al terminar el main, se llama al destructor automáticamente y hace los 'delete'.
}