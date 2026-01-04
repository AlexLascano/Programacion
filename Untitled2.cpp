/*2)Willy Wonka te ha contratado para monitorear una de sus máquinas. La máquina produce tabletas de chocolate de 4x6. 
Cada celda de la matriz representa un trozo de chocolate y puede tener un número del 1 al 9, que indica su nivel de 
dulzura. Tu programa debe pedir al usuario que llene la matriz con los niveles de dulzura y luego calcular y mostrar 
cuál es el nivel de dulzura promedio de toda la tableta.*/

#include <iostream>
using namespace std;

void ingresarDulzura(int matriz[][6], int filas, int columnas){
	cout<< "=== INGRESE LOS NIVELES DE DULZURA (1 al 9) ===" << endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<< "Fila "<< (i+1) << " Columna "<< (j+1) << ": ";
			cin>> matriz[i][j];
			
			while(matriz[i][j] < 1 || matriz[i][j] > 9){
				cout<<"Error. Debe ser entre 1 y 9. Intentelo de nuevo. ";
				cin>> matriz[i][j];
			}
		}
	}
	cout<< endl;
}
float calcularPromedio(int matriz[][6], int filas, int columnas){
	int suma=0;
	int totalCeldas= filas*columnas;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			suma += matriz[i][j];
		}
	}
	float promedio = (float)suma/totalCeldas;
	
	return promedio;
	
}
void mostrarPromedio(float promedio){
	cout<<" === RESULTADO === "<< endl;
	cout<<"El nivel de dulzura es: " << promedio<< endl;
}
int main(){
	int filas= 4;
	int columnas= 6;
	int tabletas[4][6];
	
	ingresarDulzura(tabletas, filas, columnas);
	float promedio= calcularPromedio(tabletas, filas, columnas);
	mostrarPromedio(promedio);
	
	return 0;
	
}
