/*6)	Escriba una función que reciba una expresión matemática y separe sus componentes, por ejemplo al ingresar (2*3)-5=1 
el resultado será:
Números: 2, 3, 5
Operadores: *, -
Otros: ( , )
*/

#include <iostream>
#include <string>
using namespace std;

void separarExpresion(string expresion) {

    string numeros = "";
    string operadores = "";
    string otros = "";

    for (int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];
        if (c >= '0' && c <= '9') {
            if (numeros != "") {
                numeros += ", ";
            }
            numeros += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {

            if (operadores != "") {
                operadores += ", ";
            }
            operadores += c;
        }
        else if (c != ' ') { 
            if (otros != "") {
                otros += ", ";
            }
            otros += c;
        }
    }
    
    cout << "\n=== RESULTADO ===" << endl;
    
    if (numeros != "") {
        cout << "Numeros: " << numeros << endl;
    }
    if (operadores != "") {
        cout << "Operadores: " << operadores << endl;
    }
    if (otros != "") {
        cout << "Otros: " << otros << endl;
    }
}

int main() {

    string expresion;
    
    cout << "=== SEPARADOR DE EXPRESIONES MATEMATICAS ===" << endl;
    cout << "Ingresa una expresion matematica: ";
    getline(cin, expresion);
    
    cout << "\nExpresion ingresada: " << expresion << endl;
    separarExpresion(expresion);
    
    return 0;
}
