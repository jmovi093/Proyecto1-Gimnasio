#pragma once
#include"Deportista.h"

class conjuntoDeportista
{

private:
	struct Nodo {

		/*Nodo(Deportista);
		Deportista cliente;
		Nodo* siguiente;*/
	};
	

public:
	class Iterador {
	public:
		Iterador(Nodo*);
		Deportista& operator*();
		Iterador& operator++();
		bool operator!=(const Iterador& otro);
	private:
		Nodo* nodo;
	};


	

	Iterador begin();
	Iterador end();

	string toString();

private:

	Nodo* cabeza;
	
};

