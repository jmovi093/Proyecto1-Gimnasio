#pragma once
#include "Lista.h"
#include "Deportista.h"
#include "Gym.h"

class Menu
{
public: 
	Menu();
	virtual ~Menu();
	virtual string optMenu();
	virtual void iniciar();

private:
	int opcion;
	

};

