#include "Curso.h"


Curso::Curso(string nombre, string descripcion, string nivel, Fecha* fechaCurso, string hora, int cupoMaximo) :nombre(nombre), descripcion(descripcion), nivel(nivel), fechaCurso(fechaCurso), hora(hora), cupoMaximo(cupoMaximo), matriculados(new Lista<Deportista>()) {

}

Curso::~Curso() {
    delete matriculados;
}

void Curso::matricularDeportista(Deportista* deportista) {
    if (matriculados->getCantidad() < cupoMaximo) {
        if (deportista->getEstadoCliente() == "Activo") {
            if (deportista->getCantCursos() < 4) {
                matriculados->agregar(deportista);
                deportista->CursoMatriculado();
            }
            else {
                cout << "Lo siento, no puede matricular mas cursos, ya que ha excedido el límite permitido" << endl;
            }
        }
        else {
            cout << "Lo siento, no podemos procesar la matricula en este momento" << endl;
            cout << "Para poder matricularse, debe estar activo y al dia con los pagos correspondientes" << endl;
        }
    }
    else {
        cout << "El curso no tiene cupo disponible" << endl;
    }

}

string Curso::getNombre() const {
    return nombre;
}



string Curso::toString() {
    stringstream r;

    r << "El nombre del curso es: " << nombre << endl;
    r << "La descripcion del curso es: " << descripcion << endl;
    r << "El nivel del curso es: " << nivel << endl;
    r << "La fecha del curso es: " << fechaCurso->toString() << endl;
    r << "La hora del curso es: " << hora << endl;
    r << "El cupo maximo de este curso es: " << cupoMaximo << endl;

    return r.str();
}

string Curso::getNombresMatriculados()  {
    stringstream r;
    IteradorLista<Deportista>* iterador = matriculados->obtenerIterador();
    r << toString();
    r << "La lista de los estudiantes matriculados es: " << endl;
    while (iterador->masElementos()) {
        Deportista* deportista = iterador->proximoElemento();
        r << "/n" << deportista->getNombre() + ", ";
    }
    delete iterador;
    return r.str();
}

