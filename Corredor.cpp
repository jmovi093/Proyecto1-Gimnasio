#include "Corredor.h"

Corredor::Corredor(string cedula, string nombre, string telefono, Fecha* fechaDeNacimiento, char sexo, double estatura) :
	Deportista(cedula, nombre, telefono, fechaDeNacimiento), sexo(sexo), estatura(estatura) {

}

Corredor::~Corredor() {

}

string Corredor::toString() const {
	stringstream r;

	r << "El sexo de la persona es: " << sexo << endl;
	r << "La estatura es: " << estatura << endl;

	return r.str();
}