/*4)Eres un alquimista y tienes un libro de recetas de pociones. Cada poción tiene un nombre, una lista de ingredientes, 
un tiempo de preparación en minutos y su efecto mágico. Debes definir una estructura PocionMagica y los ingredientes deben ser 
un vector<string> dentro del propio struct. Pide al usuario que ingrese 3 pociones diferentes con sus recetas (valores quemados). 
Luego, el programa debe permitir al usuario escribir el nombre de un ingrediente (ej. "Raíz de mandrágora") y mostrar todas las opciones 
que lo utilizan. */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct pocionMagica{
	string nombre;
	vector<string> ingredientes;
	int tiempoPreparacion;
	string efectoMagico;
};

void ingresarPocion(pocionMagica &pocion){
	cout<< "Nombre de la pocion: ";
	getline(cin, pocion.nombre);
	
	int cantidadIngredientes;
	cout<< "¿Cuantos ingredientes tiene: ?";
	cin>> cantidadIngredientes;
	cin.ignore();
	
	for(int i=0;i<cantidadIngredientes;i++){
		string ingredientes;
		cout<< "Ingredientes "<< (i+1) << ": ";
		getline(cin, ingredientes);
		pocion.ingredientes.push_back(ingredientes);
		 
	}
	cout<< "Tiempo de preparacion (minutos): ";
	cin>>pocion.tiempoPreparacion;
	cin.ignore();
	
	cout<< "Efecto magico: ";
	getline(cin, pocion.efectoMagico);
	
	
}
void buscarPorIngrediente(pocionMagica pociones[], int tam, string ingredientes){
	cout<< "Pociones que usan "<<  ingredientes << ":" << endl;
	cout<< "====================================="<< endl;
	bool encontrado= false;
	for(int i=0;i<tam;i++){
		for(int j=0;j<pociones[i].ingredientes.size();j++){
			if(pociones[i].ingredientes[j]==ingredientes){
				cout<< "\n-"<<pociones[i].nombre<< endl;
				encontrado=true;
				break;
			}
		}
	}
	if(!encontrado){
		cout<< "No se encontraron pociones con ese ingrediente.."<< endl;
	}
}


int main(){
	
	pocionMagica pociones[3];
	string ingredienteBuscar;
	for(int i=0;i<3;i++){
		cout<< "\n === POCION "<< (i+1) << "===\n";
		ingresarPocion(pociones[i]);
	}
	
	cout<<"==============================\n";
	cout<<"Ingresar un ingrediente para buscar: ";
	getline(cin, ingredienteBuscar);
	
	buscarPorIngrediente(pociones, 3, ingredienteBuscar);
	
	
	return 0;
}
