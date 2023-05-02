#pragma once
#include <string>
using namespace std;
#include "Deportista.h"
class Corredor :public Deportista
{
public:
	Corredor(string cedula, string nombre, string telefono, Fecha* fechaDeNacimiento, char, double);
	virtual ~Corredor();
	virtual string toString() const;
private:
	char sexo;
	double estatura;

};

