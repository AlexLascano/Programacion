/*5)	Escribe una función que cuente cuántas palabras contiene una cadena. 
Considera que las palabras están separadas por espacios. Ejm: "El martes tengo prueba de programacion".*/

#include <iostream>
#include <string>
using namespace std;

int contarPalabras(string texto){
	int contador=0;
	bool espacios=false;
	
	for(int i=0;i<texto.length();i++){
		if(texto[i]==' '){
			espacios=false;
		}else{
			if(!espacios){
				contador++;
				espacios=true;
				
			}
		}
	}
	return contador;
}


int main(){
	
	string frase;
	int totalPalabras;
	
	cout <<" ====CONTADOR DE PALABRAS==="<< endl;
	cout <<" Ingrese una frase: ";
	
	getline(cin, frase);
	totalPalabras=contarPalabras(frase);
	
	cout <<" La frase: \""<< frase << "\"" << endl;
	cout <<" Tiene " << totalPalabras<< " palabras";
	
}
