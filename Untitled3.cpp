/*3)	En un tablero de 6x6, un barco enemigo de 3 casillas de largo ha sido colocado horizontalmente en una fila aleatoria. 
Tu programa debe generar este tablero ('~'?para el agua,?'B'?para el barco). Luego, pide al usuario que ingrese una coordenada 
(fila y columna) para disparar un torpedo. El programa debe validar si fue tocado el barco o no. */

#include <iostream>
using namespace std;

void inicializarTablero(char tablero[][6], int tam){
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			tablero[i][j] = '~';	
		}
	}
}

void colocarBarco(char tablero[][6]){
	int filaBarco=2;
	int columnaInicio=1;
	
	for(int i=0;i<3;i++){
		tablero[filaBarco][columnaInicio+i] = 'B';
	}
}

void mostrarTablero(char tablero[][6], int tam){
	cout<< " === TABLERO === "<< endl;
	cout<< "0 1 2 3 4 5 "<< endl;
	for(int i=0;i<tam;i++){
		cout<< i << " ";
		for(int j=0;j<tam;j++){
			cout<< tablero[i][j]<<" ";
		}
		cout<< endl;
	}
	cout<< endl;
}

bool dispararTorpedo(char tablero[][6], int fila, int columna){
	if(tablero[fila][columna] == 'B'){
		return true;
	}else{
		return false;
	} 
}

void mostrarResultado(bool tocado){
	if(tocado){
		cout<< "!BIEN!, le diste al barco ";
	}else{
		cout<< "Fallaste..";
	}
}


int main(){
	
	char tablero[6][6];
	int tam= 6;
	int filaDisparo, columnaDisparo;
	
	
	inicializarTablero(tablero, tam);
	colocarBarco(tablero);
	mostrarTablero(tablero, tam);
	
	cout<< "Ingrese la fila para disparar (0, 5): ";
	cin>> filaDisparo;
	
	cout<< "Ingrese la columna para disparar (0, 5): ";
	cin>> columnaDisparo;
	
	bool tocado= dispararTorpedo(tablero, filaDisparo, columnaDisparo);
	mostrarResultado(tocado);
	
	return 0;
	
}
