/*7)Luego de una pericia informática, se han extraído los chats de whatsapp de tu expareja, 
mismos que vienen en un arreglo con el siguiente formato: */

#include <iostream>
#include <string>
using namespace std;

string extraerHora(string mensaje){
	int posicion= mensaje.find("//");
	string hora= mensaje.substr(0, posicion);
	
	return hora;
}
string extrarUsuario(string mensaje){
	int primerSeparador= mensaje.find("//");
	int segundoSeparador= mensaje.find("//", primerSeparador + 2);
	int inicio= primerSeparador + 2;
	int longitud= segundoSeparador - inicio;
	string usuario= mensaje.substr(inicio, longitud);
	
	return usuario;
	
}
string extraerMensaje(string mensaje){
	int primerSeparador= mensaje.find("//");
	int segundoSeparador= mensaje.find("//", primerSeparador + 2);
	string texto= mensaje.substr(segundoSeparador + 2);
	
	return texto;
	
}
int contarMensajesPorUsuarios(string usuarios[], int tamanio, string nombre){
	int contador=0;
	for(int i=0;i<tamanio;i++){
		if(usuarios[i]==nombre){
			contador++;
		}
	}
	return contador;
}
void procesarChats(string chat[], int tamanio){
	string horas[100];
	string usuarios[100];
	string mensajes[100];
	
	cout<<" ===EXTRAYENDO INFORMACON DE LOS CHATS===\n";
	cout<<" \n";
	
	for(int i=0;i<tamanio;i++){
		horas[i] = extraerHora(chat[i]);
		usuarios[i]= extrarUsuario(chat[i]);
		mensajes[i]= extraerMensaje(chat[i]);
		
		cout<<"["<< horas[i] << "]"<< usuarios[i]<< ": "<< mensajes[i]<<endl;
		 
	}
    int mensajesRoberto = contarMensajesPorUsuarios(usuarios, tamanio, "Roberto");
    int mensajesBelen = contarMensajesPorUsuarios(usuarios, tamanio, "Belen");
    
    cout << "\n=== REPORTE DE MENSAJES ===" << endl;
    cout << "Total de mensajes en el chat: " << tamanio << endl;
    cout << "Mensajes enviados por Roberto: " << mensajesRoberto << endl;
    cout << "Mensajes enviados por Belen: " << mensajesBelen << endl;
    
    cout << "\n=== ARREGLO DE HORAS ===" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "horas[" << i << "] = " << horas[i] << endl;
    }
    
    cout << "\n=== ARREGLO DE USUARIOS ===" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "usuarios[" << i << "] = " << usuarios[i] << endl;
    }
    
    cout << "\n=== ARREGLO DE MENSAJES ===" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "mensajes[" << i << "] = " << mensajes[i] << endl;
	    }
}




int main() {
    // Arreglo con los mensajes del chat
    string chat[] = {
        "08:15//Roberto//Hola perdida, ¿como estas?",
        "08:17//Belen//Bien, gracias. ¿Y tu?",
        "08:20//Roberto//Aqui pensandote. ¿Quieres salir al cine hoy?",
        "08:21//Belen//Tu novia, ¿si te da permiso?",
        "08:22//Roberto//Cual novia?. Es una amiga nomas",
        "08:23//Roberto//mejor tu pide permiso a tu novio?"
    };
    
    // Calculamos cuántos mensajes hay en el chat
    int tamanio = 6;
    
    cout << "=== ANALIZADOR DE CHATS DE WHATSAPP ===" << endl;
    cout << "Analizando " << tamanio << " mensajes..." << endl;
    
    // Llamamos a la función que procesa todo
    procesarChats(chat, tamanio);
    
    return 0;
}
