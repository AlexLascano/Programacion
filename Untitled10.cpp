/*10)	Un club deportivo necesita organizar sus equipos y jugadores. Cada equipo tiene un entrenador y varios jugadores asociados. El sistema debe permitir gestionar tanto los equipos como los jugadores de manera dinámica.
Requerimientos del programa
El programa debe ofrecer un menú con las siguientes operaciones:
1.	Registrar equipo
o	Datos: id, nombre, entrenador.
o	Inicialmente el equipo se crea con un vector vacío de jugadores.
2.	Agregar jugador a un equipo
o	Datos: id, nombre, posición, edad.
o	Se agrega al vector de jugadores dentro del equipo correspondiente.
3.	Listar equipos con sus jugadores
o	Mostrar todos los equipos y, dentro de cada uno, los jugadores registrados.
4.	Buscar equipo por ID
o	Mostrar detalles del equipo y su lista de jugadores.
5.	Eliminar jugador de un equipo
o	Buscar por ID de jugador y eliminarlo del vector de jugadores del equipo.
6.	Filtrar equipos por entrenador
o	Mostrar solo los equipos dirigidos por un entrenador específico.
7.	Eliminar equipo completo
"	Eliminar un equipo y todos sus jugadores asociados.
Structs sugeridos:

struct Jugador {
    int id;
    string nombre;
    string posicion; // Ej: "Portero", "Defensa", etc.
    int edad;
};

struct Equipo {
    int id;
    string nombre;
    string entrenador;
    vector<Jugador> jugadores; // anidado
};
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Jugador {
    int id;
    string nombre;
    string posicion;
    int edad;
};

struct Equipo {
    int id;
    string nombre;
    string entrenador;
    vector<Jugador> jugadores;
};

void registrarEquipo(vector<Equipo>& equipos) {
    Equipo nuevoEquipo;
    cout << "\n--- REGISTRAR EQUIPO ---" << endl;
    cout << "ID del equipo: ";
    cin >> nuevoEquipo.id;
    cin.ignore();
    cout << "Nombre del equipo: ";
    getline(cin, nuevoEquipo.nombre);
    cout << "Nombre del entrenador: ";
    getline(cin, nuevoEquipo.entrenador);
    
    equipos.push_back(nuevoEquipo);
    cout << "Equipo registrado exitosamente!" << endl;
}

void agregarJugador(vector<Equipo>& equipos) {
    int idEquipo;
    cout << "\n--- AGREGAR JUGADOR ---" << endl;
    cout << "ID del equipo: ";
    cin >> idEquipo;
    
    bool encontrado = false;
    for (int i = 0; i < equipos.size(); i++) {
        if (equipos[i].id == idEquipo) {
            encontrado = true;
            Jugador nuevoJugador;
            cout << "ID del jugador: ";
            cin >> nuevoJugador.id;
            cin.ignore();
            cout << "Nombre del jugador: ";
            getline(cin, nuevoJugador.nombre);
            cout << "Posicion: ";
            getline(cin, nuevoJugador.posicion);
            cout << "Edad: ";
            cin >> nuevoJugador.edad;
            
            equipos[i].jugadores.push_back(nuevoJugador);
            cout << "Jugador agregado exitosamente" << endl;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "Equipo no encontrado" << endl;
    }
}

void listarEquipos(vector<Equipo>& equipos) {
    cout << "\n--- LISTA DE EQUIPOS ---" << endl;
    if (equipos.empty()) {
        cout << "No hay equipos registrados." << endl;
        return;
    }
    
    for (int i = 0; i < equipos.size(); i++) {
        cout << "Equipo ID: " << equipos[i].id << endl;
        cout << "Nombre: " << equipos[i].nombre << endl;
        cout << "Entrenador: " << equipos[i].entrenador << endl;
        cout << "Jugadores:" << endl;
        
        if (equipos[i].jugadores.empty()) {
            cout << "  (Sin jugadores)" << endl;
        } else {
            for (int j = 0; j < equipos[i].jugadores.size(); j++) {
                cout << "  - ID: " << equipos[i].jugadores[j].id 
                     << " | " << equipos[i].jugadores[j].nombre 
                     << " | " << equipos[i].jugadores[j].posicion 
                     << " | " << equipos[i].jugadores[j].edad << " años" << endl;
            }
        }
    }
}

void buscarEquipoPorID(vector<Equipo>& equipos) {
    int idEquipo;
    cout << "\n--- BUSCAR EQUIPO ---" << endl;
    cout << "ID del equipo: ";
    cin >> idEquipo;
    
    bool encontrado = false;
    for (int i = 0; i < equipos.size(); i++) {
        if (equipos[i].id == idEquipo) {
            encontrado = true;
            cout << "\nEquipo encontrado:" << endl;
            cout << "ID: " << equipos[i].id << endl;
            cout << "Nombre: " << equipos[i].nombre << endl;
            cout << "Entrenador: " << equipos[i].entrenador << endl;
            cout << "Jugadores:" << endl;
            
            if (equipos[i].jugadores.empty()) {
                cout << "  (Sin jugadores)" << endl;
            } else {
                for (int j = 0; j < equipos[i].jugadores.size(); j++) {
                    cout << "  - ID: " << equipos[i].jugadores[j].id 
                         << " | " << equipos[i].jugadores[j].nombre 
                         << " | " << equipos[i].jugadores[j].posicion 
                         << " | " << equipos[i].jugadores[j].edad << " años" << endl;
                }
            }
            break;
        }
    }
    
    if (!encontrado) {
        cout << "Equipo no encontrado!" << endl;
    }
}

void eliminarJugador(vector<Equipo>& equipos) {
    int idEquipo, idJugador;
    cout << "\n--- ELIMINAR JUGADOR ---" << endl;
    cout << "ID del equipo: ";
    cin >> idEquipo;
    cout << "ID del jugador: ";
    cin >> idJugador;
    
    bool equipoEncontrado = false;
    bool jugadorEncontrado = false;
    
    for (int i = 0; i < equipos.size(); i++) {
        if (equipos[i].id == idEquipo) {
            equipoEncontrado = true;
            for (int j = 0; j < equipos[i].jugadores.size(); j++) {
                if (equipos[i].jugadores[j].id == idJugador) {
                    jugadorEncontrado = true;
                    equipos[i].jugadores.erase(equipos[i].jugadores.begin() + j);
                    cout << "Jugador eliminado exitosamente!" << endl;
                    break;
                }
            }
            break;
        }
    }
    
    if (!equipoEncontrado) {
        cout << "Equipo no encontrado!" << endl;
    } else if (!jugadorEncontrado) {
        cout << "Jugador no encontrado en este equipo!" << endl;
    }
}

void filtrarPorEntrenador(vector<Equipo>& equipos) {
    string nombreEntrenador;
    cout << "\n--- FILTRAR POR ENTRENADOR ---" << endl;
    cin.ignore();
    cout << "Nombre del entrenador: ";
    getline(cin, nombreEntrenador);
    
    bool encontrado = false;
    for (int i = 0; i < equipos.size(); i++) {
        if (equipos[i].entrenador == nombreEntrenador) {
            encontrado = true;
            cout << "\nEquipo ID: " << equipos[i].id << endl;
            cout << "Nombre: " << equipos[i].nombre << endl;
            cout << "Entrenador: " << equipos[i].entrenador << endl;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontraron equipos con ese entrenador." << endl;
    }
}

void eliminarEquipo(vector<Equipo>& equipos) {
    int idEquipo;
    cout << "\n--- ELIMINAR EQUIPO ---" << endl;
    cout << "ID del equipo: ";
    cin >> idEquipo;
    
    bool encontrado = false;
    for (int i = 0; i < equipos.size(); i++) {
        if (equipos[i].id == idEquipo) {
            encontrado = true;
            equipos.erase(equipos.begin() + i);
            cout << "Equipo eliminado exitosamente!" << endl;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "Equipo no encontrado!" << endl;
    }
}

void mostrarMenu() {
    cout << "\n====== MENU PRINCIPAL ======" << endl;
    cout << "1. Registrar equipo" << endl;
    cout << "2. Agregar jugador a un equipo" << endl;
    cout << "3. Listar equipos con sus jugadores" << endl;
    cout << "4. Buscar equipo por ID" << endl;
    cout << "5. Eliminar jugador de un equipo" << endl;
    cout << "6. Filtrar equipos por entrenador" << endl;
    cout << "7. Eliminar equipo completo" << endl;
    cout << "8. Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    vector<Equipo> equipos;
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                registrarEquipo(equipos);
                break;
            case 2:
                agregarJugador(equipos);
                break;
            case 3:
                listarEquipos(equipos);
                break;
            case 4:
                buscarEquipoPorID(equipos);
                break;
            case 5:
                eliminarJugador(equipos);
                break;
            case 6:
                filtrarPorEntrenador(equipos);
                break;
            case 7:
                eliminarEquipo(equipos);
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida!" << endl;
        }
    } while(opcion != 8);
    
    return 0;
}
