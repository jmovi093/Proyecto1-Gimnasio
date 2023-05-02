#pragma once
#include <fstream>
#include <string>
using namespace std;
#include "ObjBase.h"
#include "Fecha.h"
#include <sstream>
#include "HistorialPagos.h"
#include "Lista.h"
using std::stringstream;


class Deportista : public ObjBase
{
public:
	Deportista(string, string, string, Fecha*);
	Deportista(ifstream&);
	virtual ~Deportista();
	bool guardar(ofstream&);
	string getNombre() const;
	string getEstadoCliente();
	int getCantCursos();
	void agregarPago(HistorialPagos*);
	void cambiarEstadoCliente(string);
	void CursoMatriculado();
	virtual string toString() const;
	string mostrarHistorialPagos();

	
private:
	string cedula;
	string nombre;
	string telefono;
	string estadoCliente;
	int cantCursos;
	Fecha* fechaDeNacimiento;
	Lista<HistorialPagos>* listaPagos;

};

