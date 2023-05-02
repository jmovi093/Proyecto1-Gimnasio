#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anno) :dia(dia), mes(mes), anno(anno) {

}

Fecha::~Fecha() {

}

Fecha::Fecha(ifstream& entrada) {
	entrada >> dia;
	entrada >> mes;
	entrada >> anno;
}

bool Fecha::guardar(ofstream& salida) {
	salida << " " << dia << "/" << mes << "/" << anno << endl;
	salida.flush();
	if (salida.good())
		return true;
	return false;
}

int Fecha::getDia() {
	return dia;
}

int Fecha::getMes() {
	return mes;
}

int Fecha::getAnno() {
	return anno;
}

string Fecha::toString() {
	stringstream r;
	r << " " << dia << "/" << mes << "/" << anno << endl;
	return r.str();
}