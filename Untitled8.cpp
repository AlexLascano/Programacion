/*8)	Desarrolle un programa en C++ que permita gestionar estudiantes mediante las siguientes operaciones:
Registrar estudiante: Permite ingresar un nuevo estudiante con su ID, nombre completo, carrera y promedio académico.
Listar estudiantes: Muestra todos los estudiantes registrados con su información completa.
Buscar estudiante: Permite buscar un estudiante por su ID y mostrar sus datos.
Actualizar estudiante: Permite modificar los datos de un estudiante existente buscándolo por su ID.
Eliminar estudiante: Permite eliminar un estudiante del sistema mediante su ID.
Mostrar los estudiantes aprobados promedio >= 14;
Especificaciones Técnicas
o	Utilizar un struct llamado Estudiante con los campos: id (entero), nombre (cadena), carrera (cadena) y promedio (decimal).
o	Almacenar los estudiantes en un vector de tipo Estudiante.
o	La opción 6 debe implementarse mediante una función que retorne un vector con los estudiantes que cumplan el criterio de aprobación
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Estudiante{
	int id;
	string nombre;
	string carrera;
	float promedio;
	
};

void registrarEstudiante(vector<Estudiante> &estudiantes){
	Estudiante nuevoEstudiante;
	cout<<"=== REGISTRAR NUEVO ESTUDIANTE ==="<<endl;
	cout << "Ingrese ID: ";
	cin>> nuevoEstudiante.id;
	cin.ignore();
	cout<<"Ingese el nombre completo: ";
	getline(cin, nuevoEstudiante.nombre);
	cout<<"Ingrese la carrera: ";
	getline(cin, nuevoEstudiante.carrera);
	cout<<"Ingrese promedio: "; 
	cin>> nuevoEstudiante.promedio;
	estudiantes.push_back(nuevoEstudiante);
	
	cout<<"Estudiante registrado correctamente.."<< endl;
	
}
void listarEstudiantes(const vector<Estudiante> &estudiantes){
	if(estudiantes.empty()){
		cout<< "No hay estudiantes registrados. "<<endl;
		return;
	}
	cout<<"=== LISTA DE ESTUDIANTES ===\n";
	cout<<"\n";
	for(const auto &est: estudiantes){
		cout<< "ID: " <<est.id << endl;
		cout<< "Nombre: " <<est.nombre << endl;
		cout<< "Carrera: " <<est.carrera << endl;
		cout<< "Promedio: " <<est.promedio << endl;
		cout<<"---------------------------" <<endl;
	}
}
void buscarEstudiante(const vector<Estudiante> &estudiantes){
	if(estudiantes.empty()){
		cout<<"No hay estudiantes registrados para buscar. "<<endl;
		return;
	}
	int idBuscado;
	cout<<"=== BUSCAR ESTUDIANTE ===\n";
	cout<<"Ingrese el ID del estudiante a buscar: ";
	cin>> idBuscado;
	bool encontrado= false;
	for(const auto &est: estudiantes){
		if(est.id==idBuscado){
			cout<<"Estudiante encontrado.."<<endl;
			cout<<"ID: "<<est.id << endl;
			cout<<"Nombre: "<<est.nombre << endl;
			cout<<"Carrera: "<<est.carrera << endl;
			cout<<"Promedio: "<<est.promedio << endl;
			encontrado= true;
			break;
		}
	}
	if(!encontrado){
		cout<<"ERROR. No se encontro ningun estudiante con esa ID.";
	}
	
}
void actualizarEstudiante(vector<Estudiante> &estudiantes){
	if(estudiantes.empty()){
		cout<<"No hay estudiantes registrados para actualizar. "<<endl;
		return;
	}
	int idBuscado;
	cout<< "=== ACTUALIZAR ESTUDIANTE === \n";
	cout<< "Ingrese el ID del estudiante a actulizar.\n ";
	cin>> idBuscado;
	bool encontrado = false;
	for(int i = 0; i < estudiantes.size(); i++){
		if(estudiantes[i].id==idBuscado){
			cout<<"=== DATOS ACTUALES ==="<<endl;
			cout<<"ID: "<<estudiantes[i].id << endl;
			cout<<"Nombre: "<<estudiantes[i].nombre << endl;
			cout<<"Carrera: "<<estudiantes[i].carrera << endl;
			cout<<"Promedio: "<<estudiantes[i].promedio << endl;
			cout<<"\n";
			cout<<"=== INGRESAR NUEVOS DATOS ===\n";
			cin.ignore();
			cout<<"Ingrese nuevo nombre: \n";
			getline(cin, estudiantes[i].nombre);
			cout<<"Ingrese nueva carrera: \n";
			getline(cin, estudiantes[i].carrera);
			cout<<"Ingrese nuevo promedio: \n";
			cin>> estudiantes[i].promedio;
			cout<<"Estudiante actualizado correctamente..\n";
			encontrado=true;
			break;
			
		}
	}
	if(!encontrado){
		cout<<"ERROR. No se encnontro ningun estudiante con esa ID.";
	}
}
void eliminarEstudinate(vector<Estudiante> &estudiantes){
	if(estudiantes.empty()){
		cout<<"No hay estudiantes registrados para eliminar..\n";
		return;
	}
	int idBuscado;
	cout<<" === ELIMINAR ESTUDIANTE ===\n";
	cout<<" Ingrese el ID del estudiante a eliminar: ";
	cin>> idBuscado;
	bool encontrado= false;
	for(int i=0;i<estudiantes.size();i++){
		if(estudiantes[i].id ==idBuscado){
			cout<<"=== DATOS DEL ESTUDIANTE A ELIMINAR ===\n";
			cout<<"ID: "<<estudiantes[i].id << endl;
			cout<<"Nombre: "<<estudiantes[i].nombre << endl;
			cout<<"Carrera: "<<estudiantes[i].carrera << endl;
			cout<<"Promedio: "<<estudiantes[i].promedio << endl;
			
			char confirmacion;
			cout<< "Esta usted seguro de eliminar este estudiante (S/N): ";
			cin>> confirmacion;
			if(confirmacion == 's' || confirmacion== 'S'){
				estudiantes.erase(estudiantes.begin()+i);
				cout<<"Estudiante eliminado correctamente."<< endl;
			}else{
				cout<<"Operacion cancelada."<<endl;
			}
			encontrado= true;
			break;
		}
		if(!encontrado){
			cout<<"ERROR. No se encontro ningun estudiante con esa ID."<<endl;
		}
	}	
}
vector<Estudiante> estudiantesAprobados(const vector<Estudiante> &estudiantes){
	vector<Estudiante> aprobado;
	for(const auto &est:estudiantes){
		if(est.promedio>=14){
			aprobado.push_back(est);
		}
	}
	return aprobado;
}

int main(){
	vector<Estudiante> estudiantes;
	int opcion;
	do{
	
		cout<<"==== GESTION DE ESTUDIANTES ====\n";
		cout<<"1. Registrar estudiante\n";
		cout<<"2. Listar estudiantes\n";
		cout<<"3. Buscar estudiante\n";
		cout<<"4. Actualizar estudiante\n";
		cout<<"5. Eliminar estudiante\n";
		cout<<"6. Mostrar los estudiantes aprobados\n";
		cout<<"7. Salir\n";
		cout<<"Seleccione una opcion: ";
		cin>> opcion;
		
		switch (opcion) {
			case 1:
				registrarEstudiante(estudiantes);
				break;
			case 2:
				listarEstudiantes(estudiantes);
				break;
			case 3:
				buscarEstudiante(estudiantes);
				break;
			case 4:
				actualizarEstudiante(estudiantes);
				break;
			case 5:
				eliminarEstudinate(estudiantes);
				break;
			case 6:
				{
				vector<Estudiante> aprobado= estudiantesAprobados(estudiantes);
				if(aprobado.empty()){
					cout<<"No hay estudiantes aprobados. "<<endl;
				}else{
					cout<<" === ESTUDIANTES APROBADOS ===\n";
					cout<<"Total de aprobados: "<< aprobado.size()<<endl;
					listarEstudiantes(aprobado);
				}
				}
				break;
			case 7:
				cout<<"Finalizando programa.";
				break;
			default:
				cout<<"Opcion no valida";
				break;
		}
	}while(!opcion !=7);
	
	return 0;
}
