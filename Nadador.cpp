#include "Nadador.h"



Nadador::Nadador(string cedula, string nombre, string telefono, Fecha* fechaDeNacimiento, double masaMuscular, double peso, double porcGrasaCorporal) :
	Deportista(cedula, nombre, telefono, fechaDeNacimiento), masaMuscular(masaMuscular), peso(peso), porcGrasaCorporal(porcGrasaCorporal) {

}

Nadador::~Nadador() {

}

string Nadador::toString() const {
	stringstream r;

	r << "La masa muscular es: " << masaMuscular << endl;
	r << "El peso es: " << peso << endl;
	r << "El porcentaje de grasa corporal es: " << porcGrasaCorporal << endl;

	return r.str();
}