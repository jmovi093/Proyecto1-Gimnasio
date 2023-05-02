#include "HistorialPagos.h"


HistorialPagos::HistorialPagos(double montoPendiente, double montoPagado, Fecha* fechaPagos) :montoPendiente(montoPendiente), montoPagado(montoPagado), fechaPagos(fechaPagos) {

}

HistorialPagos::~HistorialPagos() {

}

double HistorialPagos::getMontoPendiente() {
	return montoPendiente;
}

double HistorialPagos::getMontoPagado() {
	return montoPagado;
}


string HistorialPagos::toString() {
	stringstream r;

	r << "El pago fue realizado la fecha: " << fechaPagos->toString() << endl;
	r << "El cliente quedo debiendo: " << montoPendiente << endl;
	r << "El cliente pago: " << montoPagado << endl;

	return r.str();
}