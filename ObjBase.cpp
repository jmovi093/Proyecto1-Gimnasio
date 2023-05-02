#include "ObjBase.h"


ObjBase::~ObjBase() {

}

ostream& operator << (ostream& salida, const ObjBase& obj) {
	salida << obj.toString();
	return salida;
}