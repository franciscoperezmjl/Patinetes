#include <iostream>
#include <string>

// Incluimos todas nuestras cabeceras
#include "GrafoDP.h"
#include "ArbolPatinetes.h"
#include "ColaPrioridad.h"
#include "ArbolUsuarios.h"

using namespace std;

int main() {

    GrafoDP ciudad(6);
    ciudad.agregarArista(0, 1, 5);
    ciudad.agregarArista(1, 2, 10);
    ciudad.agregarArista(2, 3, 3);
    ciudad.agregarArista(0, 3, 20);
    ciudad.agregarArista(3, 4, 2);
    ciudad.agregarArista(4, 5, 8);

    ArbolPatinetes inventario;
    inventario.insertar(Patinete(105, "disponible"));
    inventario.insertar(Patinete(87, "mantenimiento"));
    inventario.insertar(Patinete(123, "ocupado"));
    inventario.insertar(Patinete(45, "disponible"));
    inventario.insertar(Patinete(156, "disponible"));
    inventario.insertar(Patinete(92, "mantenimiento"));
    inventario.insertar(Patinete(78, "ocupado"));
    inventario.insertar(Patinete(134, "disponible"));

    ColaPrioridad taller;

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
        cout << "             SISTEMA de UrbanMove              " << endl;
        cout << "===============================================" << endl;
        cout << "1. Estaciones de la Ciudad " << endl;
        cout << "2. Inventario de Patinetes " << endl;
        cout << "3. Taller de Reparaciones " << endl;
        cout << "4. Gestion de Usuarios " << endl;
        cout << "0. SALIR DEL PROGRAMA" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Seleccione una parte para evaluar: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            
            case 1: { 
                cout << "\n>>> Camino de estaciones <<<" << endl;
                ciudad.imprimirGrafo();
                
                int origen, destino;
                cout << "\nIntroduce la estacion de origen (0-5): ";
                cin >> origen;
                cout << "Introduce la estacion de destino (0-5): ";
                cin >> destino;
                
                cout << "\nCalculando ruta mas rapida entre E" << origen << " y E" << destino << "..." << endl;
                ciudad.caminoMinimoDijkstra(origen, destino);
                
                cout << "\nCalculando" << endl;
                ciudad.arbolExpansionMinimaPrim(0);
                break;
            }

            case 2: { // INTEGRACIÓN PARTE 2
                int opt2;
                do {
                    cout << "\n--- SUBMENU DEL INVENTARIO ---" << endl;
                    cout << "1. Mostrar inventario\n2. Buscar patinete\n3. Cambiar estado manualmente\n4. Agregar nuevo patinete\n0. Volver" << endl;
                    cin >> opt2;
                    
                    if(opt2 == 1) {
                        inventario.mostrarInorden();
                    } else if(opt2 == 2) {
                        int idBusqueda;
                        cout << "ID a buscar: "; cin >> idBusqueda;
                        Patinete* p = inventario.buscar(idBusqueda);
                        if(p) cout << "Encontrado - Estado actual: " << p->estado << endl;
                        else cout << "Patinete no encontrado." << endl;
                    } else if(opt2 == 3) {
                        int idCambio;
                        string nuevoEstado;
                        cout << "ID del patinete a modificar: "; cin >> idCambio;
                        Patinete* p = inventario.buscar(idCambio);
                        
                        if(p) {
                            cout << "Estado actual es '" << p->estado << "'." << endl;
                            cout << "Escribe el nuevo estado (ej. ocupado, disponible, mantenimiento): ";
                            cin >> nuevoEstado;
                            p->estado = nuevoEstado; // Actualizamos el estado
                            cout << "[SISTEMA] Estado actualizado correctamente." << endl;
                        } else {
                            cout << "[ERROR] Patinete no encontrado." << endl;
                        }
                        
                        } else if(opt2 == 4) { 
                        int nuevoId;
                        string nuevoEstado;
                        cout << "Introduce el ID del nuevo patinete: "; 
                        cin >> nuevoId;
                        
                        if(inventario.buscar(nuevoId) != nullptr) {
                            cout << "[AVISO] Ya existe un patinete con el ID " << nuevoId << ". No se admiten duplicados." << endl;
                        } else {
                            cout << "Introduce el estado (disponible/ocupado/mantenimiento): ";
                            cin >> nuevoEstado;
                            inventario.insertar(Patinete(nuevoId, nuevoEstado));
                            cout << "[SISTEMA] Patinete " << nuevoId << " agregado correctamente." << endl;
                        }
                    }
                } while(opt2 != 0);
                break;
            }

            case 3: { // INTEGRACIÓN PARTE 3
                int opt3;
                do {
                    cout << "\n--- SUBMENU TALLER ---" << endl;
                    cout << "1. Encolar averia\n2. Atender urgente\n3. Ver cola\n0. Volver" << endl;
                    cin >> opt3;
                    if(opt3 == 1) {
                        int id, grav;
                        cout << "ID Patinete: "; cin >> id;
                        cout << "Gravedad (1-5): "; cin >> grav;
                        taller.encolar(id, "Averia reportada", grav);
                        
                        // --- MAGIA AQUI ---
                        Patinete* p = inventario.buscar(id);
                        if (p != nullptr) {
                            p->estado = "mantenimiento";
                            cout << "[SISTEMA] Estado del patinete " << id << " actualizado a 'mantenimiento'." << endl;
                        } else {
                            cout << "[AVISO] El patinete no existe en el inventario." << endl;
                        }
                        
                    } else if(opt3 == 2) {
                        if(!taller.estaVacia()){
                            Incidencia inc = taller.desencolar();
                            cout << "Atendido Patinete: " << inc.idPatinete << endl;
                            
                            // --- MAGIA AQUI ---
                            Patinete* p = inventario.buscar(inc.idPatinete);
                            if (p != nullptr) {
                                p->estado = "disponible";
                                cout << "[SISTEMA] El patinete " << inc.idPatinete << " vuelve a estar 'disponible'." << endl;
                            }
                        } else cout << "Vacio." << endl;
                    } else if(opt3 == 3) {
                        taller.mostrar();
                    }
                } while(opt3 != 0);
                break;
            }

            case 4: {
                cout << "\n>>> Usuarios <<<" << endl;
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
