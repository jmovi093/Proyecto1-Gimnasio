#pragma once
#include "Triatlonista.h"
#include "Lista.h"
#include "Fecha.h"
#include "Curso.h"

class Gym
{
public:
	Gym(); 
	virtual ~Gym();
	void addActFecha();
	void addCliente();
	void addCursos();
	void agregarCursos();
	string mostrarCursos();
	string mostrarClientes();
	void matricCurso();
	string deportistaMatriculados();
	void realizarPago();
	string mostrarHistorialPagosCliente();
private:
	Lista<Triatlonista> clientes;
	Lista<Curso> cursos;
	double mensualidad;
	Fecha* actFecha;

	
};


