#include "Triatlonista.h"

Triatlonista::Triatlonista(string cedula, string nombre, string telefono, Fecha* fechaDeNacimiento, int horasEntrenamiento, double temPromedio, char sexo, double estatura, double masaMuscular, double peso, double porcGrasaCorporal, int cantParticEnIronMan, int cantTriatGanados) :
	Deportista(cedula, nombre, telefono, fechaDeNacimiento),
	ciclista(new Ciclista(cedula, nombre, telefono, fechaDeNacimiento, horasEntrenamiento, temPromedio)),
	corredor(new Corredor(cedula, nombre, telefono, fechaDeNacimiento, sexo, estatura)),
	nadador(new Nadador(cedula, nombre, telefono, fechaDeNacimiento, masaMuscular, peso, porcGrasaCorporal)),
	cantParticEnIronMan(cantParticEnIronMan), cantTriatGanados(cantTriatGanados) {

}

Triatlonista::~Triatlonista() {
	delete ciclista;
	delete corredor;
	delete nadador;
}

string Triatlonista::toString() const {
	stringstream r;

	r << Deportista::toString();
	r << ciclista->toString();
	r << corredor->toString();
	r << nadador->toString();
	r << "La cantidad de participaciones en IronMan son: " << cantParticEnIronMan << endl;
	r << "La cantidad de triatlones ganados son: " << cantTriatGanados << endl;

	return r.str();
}