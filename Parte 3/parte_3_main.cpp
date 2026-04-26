#include <iostream>
#include <string>
#include "ColaPrioridad.h" // Solo dependemos de la Parte 3

using namespace std;

int main() {
    ColaPrioridad sistemaMantenimiento;
    int opcion;

    do {
        cout << "\n===============================================" << endl;
        cout << "   SISTEMA DE MANTENIMIENTO DINAMICO (PARTE 3)  " << endl;
        cout << "===============================================" << endl;
        cout << "  [1] Registrar nueva incidencia (Encolar)" << endl;
        cout << "  [2] Atender incidencia mas urgente (Desencolar)" << endl;
        cout << "  [3] Ver todas las incidencias pendientes" << endl;
        cout << "  [0] Salir" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int id, gravedad;

            cout << "\n--- NUEVA INCIDENCIA ---" << endl;
            cout << "ID del Patinete: ";
            cin >> id;

            cout << "Gravedad (1 = Critico, 5 = Leve): ";
            cin >> gravedad;

            // Llamamos a la funcion pasando un texto generico por defecto
            sistemaMantenimiento.encolar(id, "Averia reportada (Test)", gravedad);
            cout << "\n[OK] Incidencia registrada correctamente." << endl;

        } else if (opcion == 2) {
            if (sistemaMantenimiento.estaVacia()) {
                cout << "\n[!] No hay incidencias pendientes." << endl;
            } else {
                // Sacamos el que tiene gravedad mas baja (prioridad 1)
                Incidencia urgente = sistemaMantenimiento.desencolar();
                cout << "\n--- ATENDIENDO AHORA ---" << endl;
                cout << "Patinete ID: " << urgente.idPatinete << endl;
                cout << "Prioridad atendida: " << urgente.gravedad << endl;
            }

        } else if (opcion == 3) {
            cout << "\n--- LISTA DE ESPERA (Prioridad Heap) ---" << endl;
            sistemaMantenimiento.mostrar();
        }

    } while (opcion != 0);

    cout << "\nSaliendo del sistema de mantenimiento..." << endl;
    return 0;
}
