#include "Deportista.h"


Deportista::Deportista(string cedula, string nombre, string telefono, Fecha* fechaDeNacimiento) :cedula(cedula), nombre(nombre), telefono(telefono), fechaDeNacimiento(fechaDeNacimiento), listaPagos(new Lista<HistorialPagos>()), estadoCliente("Pendiente"), cantCursos(0) {

}

Deportista::~Deportista() {
	delete listaPagos;
}

Deportista::Deportista(ifstream& entrada) {
	Fecha* fecha;

	entrada >> cedula;
	entrada >> nombre;
	entrada >> telefono;
	entrada >> estadoCliente;
	fecha = new Fecha(entrada);
}

bool Deportista::guardar(ofstream& salida) {
	salida << "El numero de cedula es : " << cedula << endl;
	salida << "El nombre es: " << nombre << endl;
	salida << "El numero de telefono es: " << telefono << endl;
	salida << "El estado del cliente es: " << estadoCliente << endl;
	fechaDeNacimiento->guardar(salida);

	if (salida.good()) {
		return true;
	}
	return false;
}

string Deportista::getNombre() const {
	return nombre;
}

string Deportista::getEstadoCliente() {
	return estadoCliente;
}

int Deportista::getCantCursos() {
	return cantCursos;
}

void Deportista::agregarPago(HistorialPagos* pago) {
	listaPagos->agregar(pago);
}

void Deportista::cambiarEstadoCliente(string dato) {
	estadoCliente = dato;
}

void Deportista::CursoMatriculado() {
	cantCursos++;
}

string Deportista::toString() const {
	stringstream r;

	r << "El numero de cedula es: " << cedula << endl;
	r << "El nombre es: " << nombre << endl;
	r << "El numero de telefono es: " << telefono << endl;
	r << "La fecha de nacimiento es: " << fechaDeNacimiento->toString() << endl;
	r << "El estado del cliente es: " << estadoCliente << endl;

	return r.str();
}

string Deportista::mostrarHistorialPagos() {
	stringstream r;
	r << "El historial de pagos de " << nombre << " es " << endl;
	IteradorLista<HistorialPagos>* iterador = listaPagos->obtenerIterador();
	while (iterador->masElementos()) {
		r << iterador->proximoElemento()->toString() << endl;
	}
	delete iterador;
	return r.str();
}


