/*1)Crea una estructura llamada Vehiculo que contenga los siguientes campos: marca (string), 
modelo (string), anio (int). Luego, declara un arreglo de 5 vehículos. Escribe un programa que 
permita al usuario ingresar los datos de cada vehículo y luego muestre la información del vehículo más reciente.*/

#include <iostream>
#include <string>
using namespace std;
struct vehiculos{
	string marca;
	string modelo;
	int anio;
};

void ingresoDatos(vehiculos arr[], int tamanio){
	for(int i=0;i<tamanio;i++){

		cout<< "VEHICULO "<< (i+1)<<" :"<< endl;
		cout<<"Marca: ";
		getline(cin, arr[i].marca);
		
		cout<<"Modelo: ";
		getline(cin, arr[i].modelo);
		
		cout<<"Anio: "
		cin>> arr[i].anio;
		cin.ignore();
	}
}
int masReciente(vehiculos arr[], int tamanio){
	
	int reciente=0;
	for(int i=1; i<tamanio; i++){
		if(arr[i].anio > arr[reciente].anio){
			reciente = i;
		}
	}
	return reciente;
}
void mostrarVehiculo(vehiculos vehiculoR){
	cout<< "=== VEHICULO MAS RECIENTE === "<< endl;
	cout<< "Marca: "<< vehiculoR.marca<< endl;
	cout<< "Modelo: "<< vehiculoR.modelo<< endl;
	cout<< "Anio: "<< vehiculoR.anio<< endl;
}
int main(){
	vehiculos arr[5];
	ingresoDatos(arr, 5);
	int indicie= masReciente(arr, 5);
	mostrarVehiculo(arr[indicie]);
	
	return 0;
}
