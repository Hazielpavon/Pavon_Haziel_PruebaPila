#include <iostream>
#include <string>
#include "Pila.h"
using namespace std;
// SOlo tomo en cuenta las minusculas ya que solo eso va a recibir 
bool EsLetraONumero(char z) {
	// Valores de la tabla ascii 
	if (z > 47 && z < 58 || z >96 && z < 123) {
		return true;
	}
	else {
		return false; 
	}
}


bool Validarpalindromo(const string frase) {
	string filtrado = "";
	Pila<char> pila(frase.length());

	//Valida si es un valor correcto si es correcto se le hace push a la pila 
	for (char c : frase) {
		c = tolower(c);
		if (EsLetraONumero(c)) {
			filtrado += c;
			pila.push(c);
		}
	}
	// Se recorre cada caracter filtrdo con la cima de la pila si no son iguales retorna false si son iguales se le hace pop si nunca entra a la condicion 
	// Se puede decir que es palindroma 
	for (char c : filtrado) {
		if (c != pila.GetTop()) {
			return false;
		}
		pila.pop();
	}

	return true;
}

void Proceso() {
	cout << "Bienvenido al programa" << endl;
	string frase;
	bool continuar = true;
	int opcion;
	while (continuar) {
		cout << "\nIngrese una frase o enter para salir: ";
		getline(cin, frase);
		if (frase == " " || frase == "") {
			continuar = false;
			break; 
		}
		if (Validarpalindromo(frase)) {
			cout << "La palabra es palindroma" << endl;
		}
		else {
			cout << "La palabra no es palindroma" << endl;
		}
		

	}
	cout << "Saliendo..." << endl;
}

int main() {
	Proceso();
	return 0;
}