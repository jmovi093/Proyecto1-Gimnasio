#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
using std::stringstream;



template <class T>
class Lista;
template <class T>
class Nodo;
template <class T>
class IteradorLista;

template <class T>
class Lista
{
public:
	Lista();
	virtual ~Lista();
	virtual void agregar(T*);
	virtual int getCantidad() const; 
	T* buscarPorNombre(string);
	virtual IteradorLista<T>* obtenerIterador() const;
	virtual string toString() ;
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
	int cantidad;
	string nombre;
	
};

template <class T>
Lista<T>::Lista() : primero(NULL), actual(NULL), cantidad(0) {

}

template <class T>
Lista<T>::~Lista() {

}

template <class T>
void Lista<T>::agregar(T* dato) {
	if (primero == NULL) {
		primero = new Nodo<T>(dato, primero);
	}
	else {
		actual = primero;
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(new Nodo<T>(dato, NULL));
	}
	cantidad++;
}

template <class T>
int Lista<T>::getCantidad() const {
	return cantidad;
}


template <class T>
T* Lista<T>::buscarPorNombre(string nombre)  {

	actual = primero;
	while (actual != NULL) {
		T* dato = actual->getDato();
		if (dato->getNombre() == nombre) {
			return dato;
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}




template <class T>
IteradorLista<T>* Lista<T>::obtenerIterador() const {
	return new IteradorLista<T>(primero);
}

template <class T>
class Nodo {
public:
	Nodo(T*, Nodo<T>*);
	virtual ~Nodo();
	virtual T* getDato();
	virtual Nodo<T>* getSiguiente();
	virtual void setSiguiente(Nodo<T>*);
private:
	T* dato;
	Nodo<T>* siguiente;

};

template <class T>
Nodo<T>::Nodo(T* dato, Nodo<T>* siguiente)
	: dato(dato), siguiente(siguiente) {

}

template <class T>
Nodo<T>::~Nodo() {

}

template <class T>
T* Nodo<T>::getDato() {
	return dato;
}

template <class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return siguiente;
}

template <class T>
void Nodo<T>::setSiguiente(Nodo<T>* sig) {
	siguiente = sig;
}

template <class T>
class IteradorLista {
public:
	IteradorLista(Nodo<T>*);
	virtual ~IteradorLista();
	virtual bool masElementos() const;
	virtual T* proximoElemento();
private:
	Nodo<T>* cursor;
};

template <class T>
IteradorLista<T>::IteradorLista(Nodo<T>* primero)
	: cursor(primero) {

}

template <class T>
IteradorLista<T>::~IteradorLista() {

}

template <class T>
bool IteradorLista<T>::masElementos() const {
	return (cursor != NULL);
}

template <class T>
T* IteradorLista<T>::proximoElemento() {
	T* r = cursor->getDato();
	cursor = cursor->getSiguiente();
	return r;
}



template <class T>
string Lista<T>::toString() {
	stringstream ss;
	IteradorLista<T>* iter = obtenerIterador();
	while (iter->masElementos()) {
		T* dato = iter->proximoElemento();
		ss << dato->toString() << endl;
	}
	delete iter;
	return ss.str();
}


