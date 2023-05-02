#pragma once
#include "Fecha.h"
#include <string>
#include <sstream>
using std::stringstream;

class HistorialPagos
{
public:
	HistorialPagos(double, double, Fecha*);
	virtual ~HistorialPagos();
	double getMontoPendiente();
	double getMontoPagado();
	string getEstadoCliente();
	string toString();
private:
	double montoPendiente;
	double montoPagado;
	Fecha* fechaPagos;

};

	