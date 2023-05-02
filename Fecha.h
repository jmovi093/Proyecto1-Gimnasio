#pragma once
#include <ctime>
#include <string>
using namespace std;
#include <sstream>
using std::stringstream;
#include <fstream>

class Fecha {
public:
	Fecha(int, int, int);
	Fecha(ifstream&);
	virtual ~Fecha();
	bool guardar(ofstream&);
	int getDia();
	int getMes();
	int getAnno();
	string toString();
private:
	int dia;
	int mes;
	int anno;
};

