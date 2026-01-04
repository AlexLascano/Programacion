/*9)	Un cine necesita organizar su catálogo de películas.Crea un programa en C++ con un menú interactivo que permita cumplir los siguiente requerimientos:
1.	Registrar película: id, título, director, estado (en cartelera / fuera de cartelera).
2.	Listar películas.
3.	Buscar película por id.
4.	Cambiar estado (en cartelera ? fuera de cartelera).
5.	Eliminar película.
6.	Filtrar por estado.
Struct sugerido:
struct Pelicula {
int id;
string titulo;
string director;
bool enCartelera;
};
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pelicula {
    int id;
    string titulo;
    string director;
    bool enCartelera;
};

void registrarPelicula(vector<Pelicula> &peliculas) {
    Pelicula nuevaPelicula;
    
    cout << "\n=== REGISTRAR NUEVA PELICULA ===" << endl;
    
    cout << "Ingrese ID: ";
    cin >> nuevaPelicula.id;
    
    cin.ignore();
    cout << "Ingrese titulo: ";
    getline(cin, nuevaPelicula.titulo);
    
    cout << "Ingrese director: ";
    getline(cin, nuevaPelicula.director);
    
    char estado;
    cout << "¿Esta en cartelera? (s/n): ";
    cin >> estado;
    
    if (estado == 's' || estado == 'S') {
        nuevaPelicula.enCartelera = true;
    } else {
        nuevaPelicula.enCartelera = false;
    }
    
    peliculas.push_back(nuevaPelicula);
    
    cout << "\n¡Pelicula registrada exitosamente!" << endl;
}

void listarPeliculas(const vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas." << endl;
        return;
    }
    
    cout << "\n=== LISTA DE PELICULAS ===" << endl;
    cout << "\n";
    
    for (const auto &pel : peliculas) {
        cout << "ID: " << pel.id << endl;
        cout << "Titulo: " << pel.titulo << endl;
        cout << "Director: " << pel.director << endl;
        cout << "Estado: " << (pel.enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
        cout << "-------------------------" << endl;
    }
}

void buscarPelicula(const vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas para buscar." << endl;
        return;
    }
    
    int idBuscado;
    cout << "\n=== BUSCAR PELICULA ===" << endl;
    cout << "Ingrese el ID de la pelicula a buscar: ";
    cin >> idBuscado;
    
    bool encontrado = false;
    
    for (const auto &pel : peliculas) {
        if (pel.id == idBuscado) {
            cout << "\n=== PELICULA ENCONTRADA ===" << endl;
            cout << "ID: " << pel.id << endl;
            cout << "Titulo: " << pel.titulo << endl;
            cout << "Director: " << pel.director << endl;
            cout << "Estado: " << (pel.enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
            
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "\nError: No se encontró ninguna pelicula con ID " << idBuscado << endl;
    }
}

void cambiarEstado(vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas para cambiar estado." << endl;
        return;
    }
    
    int idBuscado;
    cout << "\n=== CAMBIAR ESTADO DE PELICULA ===" << endl;
    cout << "Ingrese el ID de la pelicula: ";
    cin >> idBuscado;
    
    bool encontrado = false;
    
    for (int i = 0; i < peliculas.size(); i++) {
        if (peliculas[i].id == idBuscado) {
            cout << "\n=== DATOS ACTUALES ===" << endl;
            cout << "ID: " << peliculas[i].id << endl;
            cout << "Titulo: " << peliculas[i].titulo << endl;
            cout << "Director: " << peliculas[i].director << endl;
            cout << "Estado actual: " << (peliculas[i].enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
            
            peliculas[i].enCartelera = !peliculas[i].enCartelera;
            
            cout << "\nEstado cambiado a: " << (peliculas[i].enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
            cout << "\n¡Estado actualizado exitosamente!" << endl;
            
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "\nError: No se encontró ninguna pelicula con ID " << idBuscado << endl;
    }
}

void eliminarPelicula(vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas para eliminar." << endl;
        return;
    }
    
    int idBuscado;
    cout << "\n=== ELIMINAR PELICULA ===" << endl;
    cout << "Ingrese el ID de la pelicula a eliminar: ";
    cin >> idBuscado;
    
    bool encontrado = false;
    
    for (int i = 0; i < peliculas.size(); i++) {
        if (peliculas[i].id == idBuscado) {
            cout << "\n=== DATOS DE LA PELICULA A ELIMINAR ===" << endl;
            cout << "ID: " << peliculas[i].id << endl;
            cout << "Titulo: " << peliculas[i].titulo << endl;
            cout << "Director: " << peliculas[i].director << endl;
            cout << "Estado: " << (peliculas[i].enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
            
            char confirmacion;
            cout << "\n¿Esta seguro que desea eliminar esta pelicula? (s/n): ";
            cin >> confirmacion;
            
            if (confirmacion == 's' || confirmacion == 'S') {
                peliculas.erase(peliculas.begin() + i);
                cout << "\n¡Pelicula eliminada exitosamente!" << endl;
            } else {
                cout << "\nOperacion cancelada." << endl;
            }
            
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "\nError: No se encontró ninguna pelicula con ID " << idBuscado << endl;
    }
}

vector<Pelicula> filtrarPorEstado(const vector<Pelicula> &peliculas, bool enCartelera) {
    vector<Pelicula> filtradas;
    
    for (const auto &pel : peliculas) {
        if (pel.enCartelera == enCartelera) {
            filtradas.push_back(pel);
        }
    }
    
    return filtradas;
}

int main() {
    vector<Pelicula> peliculas;
    int opcion;
    
    do {
        cout << "\n" << endl;
        cout << "========================================" << endl;
        cout << "   SISTEMA DE GESTION DE PELICULAS     " << endl;
        cout << "========================================" << endl;
        cout << "1. Registrar pelicula" << endl;
        cout << "2. Listar peliculas" << endl;
        cout << "3. Buscar pelicula por ID" << endl;
        cout << "4. Cambiar estado de pelicula" << endl;
        cout << "5. Eliminar pelicula" << endl;
        cout << "6. Filtrar por estado" << endl;
        cout << "7. Salir" << endl;
        cout << "========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                registrarPelicula(peliculas);
                break;
                
            case 2:
                listarPeliculas(peliculas);
                break;
                
            case 3:
                buscarPelicula(peliculas);
                break;
                
            case 4:
                cambiarEstado(peliculas);
                break;
                
            case 5:
                eliminarPelicula(peliculas);
                break;
                
            case 6:
                {
                    int opcionEstado;
                    cout << "\n=== FILTRAR POR ESTADO ===" << endl;
                    cout << "1. En cartelera" << endl;
                    cout << "2. Fuera de cartelera" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcionEstado;
                    
                    if (opcionEstado == 1) {
                        vector<Pelicula> enCartelera = filtrarPorEstado(peliculas, true);
                        
                        if (enCartelera.empty()) {
                            cout << "\nNo hay peliculas en cartelera." << endl;
                        } else {
                            cout << "\n=== PELICULAS EN CARTELERA ===" << endl;
                            cout << "Total: " << enCartelera.size() << endl;
                            listarPeliculas(enCartelera);
                        }
                    } else if (opcionEstado == 2) {
                        vector<Pelicula> fueraCartelera = filtrarPorEstado(peliculas, false);
                        
                        if (fueraCartelera.empty()) {
                            cout << "\nNo hay peliculas fuera de cartelera." << endl;
                        } else {
                            cout << "\n=== PELICULAS FUERA DE CARTELERA ===" << endl;
                            cout << "Total: " << fueraCartelera.size() << endl;
                            listarPeliculas(fueraCartelera);
                        }
                    } else {
                        cout << "\nOpcion invalida." << endl;
                    }
                }
                break;
                
            case 7:
                cout << "\n¡Gracias por usar el sistema! Hasta pronto." << endl;
                break;
                
            default:
                cout << "\nOpcion invalida. Por favor seleccione una opcion del 1 al 7." << endl;
                break;
        }
        
    } while(opcion != 7);
    
    return 0;
}
