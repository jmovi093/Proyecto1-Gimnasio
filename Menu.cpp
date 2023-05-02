#include "Menu.h"

Menu::Menu() :opcion(0){

}

Menu::~Menu() {

}

string Menu::optMenu() {
    stringstream r;
    r << "---------Sistema Gimnasio------------" << endl;
    r << "1. Agregar un cliente nuevo" << endl;
    r << "2. Agregar un curso nuevo" << endl;
    r << "3. Ver lista de clientes" << endl;
    r << "4. Ver lista de cursos" << endl;
    r << "5. Matricular curso" << endl;
    r << "6. Ver los clientes matriculados en un curso" << endl;
    r << "7. Realizar pago de mensualidad" << endl;
    r << "8. Mostrar historial de pagos de un cliente" << endl;
    r << "9. Salir" << endl;
	return r.str();
}

void Menu::iniciar() {
	Gym* Gimnasio_Montero = new Gym();
	
	do {
		system("cls");
		optMenu();
		cout << "\nDigite una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			
			system("pause");
			break;
		case 2:
			system("cls");
			
			system("pause");
			break;
		case 3:
			system("cls");

			system("pause");
			break;
		case 4:
			system("cls");
			
			system("pause");
			break;
		default:
			system("cls");
			cout << "\nOpcion no es valida.";
			system("pause");
			break;

		}

	} while (opcion != 4);
}



