#pragma once
#include <string>
using namespace std;
#include "Deportista.h"
class Ciclista : public Deportista
{
public:
	Ciclista(string cedula, string nombre, string telefono, Fecha* fechaDeNacimeinto, int, double);
	virtual ~Ciclista();
	virtual string toString() const ;
private:
	int horasEntrenamiento;
	double temPromedio;

};

