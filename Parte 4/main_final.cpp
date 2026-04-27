#include <iostream>
#include <string>

// Incluimos todas nuestras cabeceras
#include "GrafoDP.h"
#include "ArbolPatinetes.h"
#include "ColaPrioridad.h"
#include "ArbolUsuarios.h"

using namespace std;

int main() {
    // ---------------------------------------------------------
    // 1. INICIALIZACIÓN Y PRECARGA DE DATOS 
    // ---------------------------------------------------------
    
    // Parte 1: Grafo de la Ciudad con 6 estaciones
    GrafoDP ciudad(6);
    ciudad.agregarArista(0, 1, 5);
    ciudad.agregarArista(1, 2, 10);
    ciudad.agregarArista(2, 3, 3);
    ciudad.agregarArista(0, 3, 20);
    ciudad.agregarArista(3, 4, 2);
    ciudad.agregarArista(4, 5, 8);

    // Parte 2: Inventario de Patinetes 
    ArbolPatinetes inventario;
    inventario.insertar(Patinete(105, "disponible"));
    inventario.insertar(Patinete(87, "mantenimiento"));
    inventario.insertar(Patinete(123, "ocupado"));
    inventario.insertar(Patinete(45, "disponible"));
    inventario.insertar(Patinete(156, "disponible"));
    inventario.insertar(Patinete(92, "mantenimiento"));
    inventario.insertar(Patinete(78, "ocupado"));
    inventario.insertar(Patinete(134, "disponible"));

    // Parte 3: Taller (Heap vacío al inicio)
    ColaPrioridad taller;

    // Parte 4: Usuarios (Tus 50 usuarios de prueba)
    ArbolUsuarios sistemaUsuarios;
    sistemaUsuarios.insertar(Usuario(500, "Marcos Fernandez", "marcos.f@mail.com"));
    sistemaUsuarios.insertar(Usuario(250, "Lucia Garcia", "lucia.g@mail.com"));
    sistemaUsuarios.insertar(Usuario(750, "Alejandro Martinez", "alex.mtz@mail.com"));
    sistemaUsuarios.insertar(Usuario(120, "Sofia Rodriguez", "sofia.rod@mail.com"));
    sistemaUsuarios.insertar(Usuario(350, "Hugo Lopez", "hugo.lopez@mail.com"));
    sistemaUsuarios.insertar(Usuario(600, "Martina Sanchez", "martina.s@mail.com"));
    sistemaUsuarios.insertar(Usuario(850, "Mateo Perez", "mateo.p@mail.com"));
    sistemaUsuarios.insertar(Usuario(50, "Valeria Martin", "valeria.m@mail.com"));
    sistemaUsuarios.insertar(Usuario(180, "Daniel Gomez", "daniel.g@mail.com"));
    sistemaUsuarios.insertar(Usuario(290, "Julia Ruiz", "julia.ruiz@mail.com"));
    sistemaUsuarios.insertar(Usuario(420, "Pablo Hernandez", "pablo.h@mail.com"));
    sistemaUsuarios.insertar(Usuario(550, "Emma Diaz", "emma.diaz@mail.com"));
    sistemaUsuarios.insertar(Usuario(680, "Alvaro Alvarez", "alvaro.a@mail.com"));
    sistemaUsuarios.insertar(Usuario(780, "Carmen Moreno", "carmen.m@mail.com"));
    sistemaUsuarios.insertar(Usuario(920, "Adrian Miguez", "adrian.m@mail.com"));
    sistemaUsuarios.insertar(Usuario(20, "Alba Romero", "alba.r@mail.com"));
    sistemaUsuarios.insertar(Usuario(80, "David Alonso", "david.a@mail.com"));
    sistemaUsuarios.insertar(Usuario(150, "Noa Gutierrez", "noa.g@mail.com"));
    sistemaUsuarios.insertar(Usuario(210, "Diego Navarro", "diego.n@mail.com"));
    sistemaUsuarios.insertar(Usuario(270, "Claudia Torres", "claudia.t@mail.com"));
    sistemaUsuarios.insertar(Usuario(320, "Mario Dominguez", "mario.d@mail.com"));
    sistemaUsuarios.insertar(Usuario(380, "Marta Vazquez", "marta.v@mail.com"));
    sistemaUsuarios.insertar(Usuario(460, "Leo Ramos", "leo.ramos@mail.com"));
    sistemaUsuarios.insertar(Usuario(490, "Laura Gil", "laura.gil@mail.com"));
    sistemaUsuarios.insertar(Usuario(520, "Izan Ramirez", "izan.r@mail.com"));
    sistemaUsuarios.insertar(Usuario(580, "Irene Garrido", "irene.g@mail.com"));
    sistemaUsuarios.insertar(Usuario(630, "Javier Blanco", "javier.b@mail.com"));
    sistemaUsuarios.insertar(Usuario(660, "Sara Iglesias", "sara.i@mail.com"));
    sistemaUsuarios.insertar(Usuario(710, "Enzo Castro", "enzo.c@mail.com"));
    sistemaUsuarios.insertar(Usuario(730, "Elena Suarez", "elena.s@mail.com"));
    sistemaUsuarios.insertar(Usuario(760, "Luca Ortega", "luca.o@mail.com"));
    sistemaUsuarios.insertar(Usuario(820, "Daniela Rubio", "daniela.r@mail.com"));
    sistemaUsuarios.insertar(Usuario(880, "Gael Marin", "gael.m@mail.com"));
    sistemaUsuarios.insertar(Usuario(900, "Paula Sanz", "paula.s@mail.com"));
    sistemaUsuarios.insertar(Usuario(950, "Thiago Alcantara", "thiago.n@mail.com"));
    sistemaUsuarios.insertar(Usuario(980, "Carla Iglesias", "carla.i@mail.com"));
    sistemaUsuarios.insertar(Usuario(10, "Oliver Medina", "oliver.m@mail.com"));
    sistemaUsuarios.insertar(Usuario(40, "Vega Cortes", "vega.c@mail.com"));
    sistemaUsuarios.insertar(Usuario(70, "Bruno Castillo", "bruno.c@mail.com"));
    sistemaUsuarios.insertar(Usuario(90, "Mia Santos", "mia.s@mail.com"));
    sistemaUsuarios.insertar(Usuario(110, "Alex Lozano", "alex.l@mail.com"));
    sistemaUsuarios.insertar(Usuario(140, "Alma Guerrero", "alma.g@mail.com"));
    sistemaUsuarios.insertar(Usuario(170, "Eric Cano", "eric.c@mail.com"));
    sistemaUsuarios.insertar(Usuario(200, "Aitana Prieto", "aitana.p@mail.com"));
    sistemaUsuarios.insertar(Usuario(230, "Hector Mendez", "hector.m@mail.com"));
    sistemaUsuarios.insertar(Usuario(260, "Lola Cruz", "lola.c@mail.com"));
    sistemaUsuarios.insertar(Usuario(300, "Dario Calvo", "dario.c@mail.com"));
    sistemaUsuarios.insertar(Usuario(340, "Valentina Gallego", "valentina.g@mail.com"));
    sistemaUsuarios.insertar(Usuario(400, "Nicolas Vidal", "nicolas.v@mail.com"));
    sistemaUsuarios.insertar(Usuario(440, "Candela Leon", "candela.l@mail.com"));

    int opcionPrincipal;

    do {
        cout << "\n===============================================" << endl;
        cout << "      SISTEMA GLOBAL VIGO-SCOOT (PROYECTO)     " << endl;
        cout << "===============================================" << endl;
        cout << "1. PARTE 1: Grafo de la Ciudad (Rutas y Calles)" << endl;
        cout << "2. PARTE 2: Inventario de Patinetes (Arbol BST)" << endl;
        cout << "3. PARTE 3: Taller de Reparaciones (Min-Heap)" << endl;
        cout << "4. PARTE 4: Gestion de Usuarios (Login Eficiente)" << endl;
        cout << "0. SALIR DEL PROGRAMA" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Seleccione una parte para evaluar: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            
            case 1: { // INTEGRACIÓN PARTE 1
                cout << "\n>>> EJECUTANDO PRUEBAS DE GRAFOS (CIUDAD) <<<" << endl;
                ciudad.imprimirGrafo();
                cout << "\nCalculando ruta mas rapida entre E0 y E3..." << endl;
                ciudad.caminoMinimoDijkstra(0, 3);
                cout << "\nCalculando arbol de expansion minima (Prim)..." << endl;
                ciudad.arbolExpansionMinimaPrim(0);
                break;
            }

            case 2: { // INTEGRACIÓN PARTE 2
                cout << "\n>>> EJECUTANDO PRUEBAS DE INVENTARIO <<<" << endl;
                inventario.mostrarInorden();
                cout << "\nSimulando busqueda de ID 123..." << endl;
                Patinete* p = inventario.buscar(123);
                if(p) cout << "Encontrado: " << p->estado << endl;
                break;
            }

            case 3: { // INTEGRACIÓN PARTE 3 (Tu menú interactivo)
                int opt3;
                do {
                    cout << "\n--- SUBMENU TALLER (PARTE 3) ---" << endl;
                    cout << "1. Encolar averia\n2. Atender urgente\n3. Ver cola\n0. Volver" << endl;
                    cin >> opt3;
                    if(opt3 == 1) {
                        int id, grav;
                        cout << "ID Patinete: "; cin >> id;
                        cout << "Gravedad (1-5): "; cin >> grav;
                        taller.encolar(id, grav);
                    } else if(opt3 == 2) {
                        if(!taller.estaVacia()){
                            Incidencia inc = taller.desencolar();
                            cout << "Atendido Patinete: " << inc.idPatinete << endl;
                        } else cout << "Vacio." << endl;
                    } else if(opt3 == 3) taller.mostrar();
                } while(opt3 != 0);
                break;
            }

            case 4: { // INTEGRACIÓN PARTE 4
                cout << "\n>>> EJECUTANDO PRUEBAS DE USUARIOS (50 registros) <<<" << endl;
                int idBuscado, pasos = 0;
                cout << "Introduce ID para simular Login: ";
                cin >> idBuscado;
                Usuario* u = sistemaUsuarios.buscar(idBuscado, pasos);
                if(u) {
                    cout << "Bienvenido " << u->nombre << endl;
                    cout << "[RENDIMIENTO] Encontrado en " << pasos << " saltos." << endl;
                } else cout << "Usuario no existe." << endl;
                break;
            }
        }

    } while (opcionPrincipal != 0);

    cout << "\nPrograma finalizado correctamente." << endl;
    return 0;
}
