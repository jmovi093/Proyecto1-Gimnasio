#include "Ciclista.h"


Ciclista::Ciclista(string cedula, string nombre, string telefono, Fecha* fechaDeNacimiento, int horasEntrenamiento, double temPromedio)
	: Deportista(cedula, nombre, telefono, fechaDeNacimiento), horasEntrenamiento(horasEntrenamiento), temPromedio(temPromedio) {

}

Ciclista::~Ciclista() {

}

string Ciclista::toString() const {
	stringstream r;

	r << "La cantidad de horas de entrenamiento son: " << horasEntrenamiento << endl;
	r << "El tiempo promedio es: " << temPromedio << endl;

	return r.str();
}






