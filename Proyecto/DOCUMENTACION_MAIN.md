# Documentación de Main.cpp - Explicación por Líneas

## Secciones Principales

### Inclusiones (Líneas 1-10)
- `#include <iostream>`: Librería para entrada/salida estándar
- `#include <string>`: Librería para manejo de strings/cadenas
- Inclusiones de cabeceras: GrafoDP, ArbolPatinetes, ColaPrioridad, ArbolUsuarios

### Inicialización de Estructuras de Datos (Líneas 13-60)

#### PARTE 1: Grafo de la Ciudad (Líneas 13-20)
- `GrafoDP ciudad(6)`: Crea un grafo con 6 estaciones (vértices)
- `ciudad.agregarArista(...)`: Agrega conexiones bidireccionales entre estaciones con tiempo en minutos

#### PARTE 2: Árbol BST de Patinetes (Líneas 22-30)
- `ArbolPatinetes inventario`: Árbol binario de búsqueda para inventario
- `inventario.insertar(Patinete(ID, "estado"))`: Inserta cada patinete con su ID único y estado

#### PARTE 3: Cola de Prioridad del Taller (Línea 32)
- `ColaPrioridad taller`: Cola de prioridad (min-heap) para gestionar reparaciones

#### PARTE 4: Árbol BST de Usuarios (Líneas 34-90)
- `ArbolUsuarios sistemaUsuarios`: Árbol para almacenar más de 40 usuarios del sistema
- Cada usuario tiene: ID (clave), nombre y email

### Menú Principal (Líneas 92-115)
```cpp
do {
    // Muestra el menú con 5 opciones:
    // 1. Estaciones de la Ciudad (Grafo + Dijkstra + Prim)
    // 2. Inventario de Patinetes (Árbol BST)
    // 3. Taller de Reparaciones (Cola de Prioridad)
    // 4. Gestión de Usuarios (Árbol BST + Login)
    // 0. SALIR
} while (opcionPrincipal != 0);
```

### Case 1: Estaciones de la Ciudad (Líneas 117-133)
- Imprime el grafo completo
- Pide origen y destino
- Calcula ruta más rápida usando **Dijkstra**
- Calcula árbol de expansión mínima usando **Prim**

### Case 2: Inventario de Patinetes (Líneas 135-160)
- Opción 1: Muestra todos los patinetes en orden (inorden)
- Opción 2: Busca un patinete por ID
- Opción 3: Cambia el estado de un patinete (manualmente)

### Case 3: Taller de Reparaciones (Líneas 162-190)
- Opción 1: Encola una avería con ID, descripción y gravedad
  - Integración: Automáticamente marca el patinete como "mantenimiento"
- Opción 2: Atiende la avería más urgente (desencola)
  - Integración: Automáticamente marca el patinete como "disponible"
- Opción 3: Muestra la cola de averías

### Case 4: Gestión de Usuarios (Líneas 192+)
- Simula un login: busca un usuario por ID
- Muestra cuántos "pasos" tardó en encontrarlo (rendimiento del árbol)
- Muestra todos los usuarios registrados

## Flujo de Integración entre Estructuras

1. **Usuario reporta avería** → Se encola en el Taller (ColaPrioridad)
2. **Patinete se registra como "mantenimiento"** → Se actualiza en el Inventario (ArbolPatinetes)
3. **Taller atiende la avería** → Se desencola
4. **Patinete vuelve a "disponible"** → Se actualiza en el Inventario
5. **Sistema verifica disponibilidad** → Búsqueda O(log N) en el árbol

## Complejidades de Algoritmos

| Operación | Estructura | Complejidad | Línea |
|-----------|-----------|-------------|-------|
| Buscar usuario (login) | Árbol BST | O(log N) | ~210 |
| Insertar patinete | Árbol BST | O(log N) | ~25 |
| Buscar patinete | Árbol BST | O(log N) | ~145 |
| Encolar avería | Cola Prioridad | O(log N) | ~172 |
| Desencolar avería | Cola Prioridad | O(log N) | ~179 |
| Dijkstra | Grafo | O((V+E)logV) | ~120 |
| Prim | Grafo | O(V² o (E+V)logV) | ~124 |

