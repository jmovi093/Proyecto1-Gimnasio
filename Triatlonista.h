#pragma once
#include "Deportista.h"
#include "Ciclista.h"
#include "Corredor.h"
#include "Nadador.h"
class Triatlonista :public Deportista {
public:
	Triatlonista(string, string, string, Fecha*, int, double, char, double, double, double, double, int, int);
	virtual ~Triatlonista();
	virtual string toString() const ;
private:
	int cantParticEnIronMan;
	int cantTriatGanados;
	Ciclista* ciclista;
	Corredor* corredor;
	Nadador* nadador;

};

