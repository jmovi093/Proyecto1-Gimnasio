#pragma once
#include <string>
using namespace std;
#include "Deportista.h"
class Nadador :public Deportista
{
public:
	Nadador(string cedula, string nombre, string telefono, Fecha* fechaDeNacimiento, double, double, double);
	virtual ~Nadador();
	virtual string toString() const ;
private:
	double masaMuscular;
	double peso;
	double porcGrasaCorporal;

};

