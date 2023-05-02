#pragma once
#include "Fecha.h" 
#include "Lista.h"

#include "Deportista.h"
using namespace std;

class Curso {
public:
	Curso(string, string, string, Fecha*, string, int);
	virtual ~Curso();
	string getNombre() const;
	void matricularDeportista(Deportista* deportista);
	string toString();
	virtual string getNombresMatriculados() ;

private:
	string nombre;
	string descripcion;
	string nivel;
	Fecha* fechaCurso;
	string hora;
	int cupoMaximo;
	Lista<Deportista>* matriculados;
};
