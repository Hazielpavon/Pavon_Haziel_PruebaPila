#pragma once
using namespace std; 
#include <iostream>
template <typename T>
class Pila {
	T* lista;
	int tope, capacidad;

public:
	Pila(int size) {
		capacidad = size;
		lista = new T[capacidad];
		tope = -1;
	}
	void push(T dato) {
		if (IsFull()) {
			cout << "Pila llena\n";
			return;
		}
		lista[++tope] = dato;
	}
	void pop() {
		if (IsEmpty()) {
			cout << "Pila vacia\n";
			return;
		}
		tope--;
	}

	bool IsFull() {
		return tope == capacidad - 1; 
	}

	bool IsEmpty() {
		return tope == -1; 
	}

	T GetTop()  {
		if (!IsFull()) {
			return lista[tope];
		}
		return T();
	}

};
