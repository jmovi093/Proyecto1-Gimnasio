#include "Gym.h"


Gym::Gym() :clientes(new Lista<Triatlonista>()), cursos(new Lista<Curso>()), mensualidad(40000), actFecha(nullptr) {
    
  

}

Gym::~Gym() {
 /*   delete clientes;
    delete cursos;*/
}

void Gym::addActFecha() {
    int dia, mes, anno;

    time_t tiempo_actual = time(nullptr);
    tm fecha_local;
    localtime_s(&fecha_local, &tiempo_actual);

    dia = fecha_local.tm_mday;
    mes = fecha_local.tm_mon + 1;
    anno = fecha_local.tm_year + 1900;

    actFecha = new Fecha(dia, mes, anno);

    cout << "La fecha actual es: " << actFecha->toString() << endl;
}

void Gym::addCliente() {

    string cedula, nombre, numeroTell;
    int dia, mes, anno, horasEntrenamiento, cantParticEnIronMan, cantTriatGanados;
    double temPromedio, estatura, masaMuscular, peso, porcGrasaCorporal;
    char sexo;

    cout << "Digite su numero de cedula: " << endl;
    cin >> cedula;
    cout << "Digite su nombre: " << endl;
    cin >> nombre;
    cout << "Digite su numero de telefono: " << endl;
    cin >> numeroTell;
    cout << "Digite su fecha de nacimiento" << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: "; 
    cin >> mes;
    cout << "Anno: "; 
    cin >> anno;
    cout << "Digite sus horas de entrenamiento: " << endl;
    cin >> horasEntrenamiento;
    cout << "Digite su tem promedio: " << endl;
    cin >> temPromedio;
    cout << "Digite M si su sexo masculino o F si su sexo es femenino: " << endl;
    cin >> sexo;
    cout << "Digite su estatura: " << endl;
    cin >> estatura;
    cout << "Digite su masa muscular: " << endl;
    cin >> masaMuscular;
    cout << "Digite su peso: " << endl;
    cin >> peso;
    cout << "Digite su porcentaje de masa corporal: " << endl;
    cin >> porcGrasaCorporal;
    cout << "Digite su cantidad de participaciones en eventos Ironman: " << endl;
    cin >> cantParticEnIronMan;
    cout << "Digite su cantidad de participaciones en triatlones: " << endl;
    cin >> cantTriatGanados;

    Fecha* fechaNacimiento = new Fecha(dia, mes, anno);
    Ciclista* ciclista = new Ciclista(cedula, nombre, numeroTell, fechaNacimiento, horasEntrenamiento, temPromedio);
    Corredor* corredor = new Corredor(cedula, nombre, numeroTell, fechaNacimiento, sexo, estatura);
    Nadador* nadador = new Nadador(cedula, nombre, cedula, fechaNacimiento, masaMuscular, peso, porcGrasaCorporal);
    Triatlonista* triatlonista = new Triatlonista(cedula, nombre, numeroTell, fechaNacimiento, horasEntrenamiento, temPromedio, sexo, estatura, masaMuscular, peso, porcGrasaCorporal, cantParticEnIronMan, cantTriatGanados);

    clientes.agregar(triatlonista);

}

void Gym::agregarCursos() {
    string nombre, descripcion, nivel, hora;
    int opc, dia, mes, anno, cupoMaximo;

    cout << "Digite el nombre del curso: " << endl;
    cin >> nombre;
    cout << "Escriba una descripcion del curso: " << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, descripcion);
    cout << "Indique el nivel del curso: " << endl;
    cout << "1. Principiante" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Avanzado" << endl;
    while (true) {
        cin >> opc;
        if (opc == 1) {
            nivel = "Principiante";
            break;
        }
        else if (opc == 2) {
            nivel = "Intermedio";
            break;
        }
        else if (opc == 3) {
            nivel = "Avanzado";
            break;
        }
        else {
            cout << "Error seleccione una opcion que se encuentre en el menu" << endl;
            continue;
        }
    }
    cout << "Digite la fecha del curso" << endl;
    while (true) {
        cout << "Dia: "; cin >> dia;
        cout << "Mes: "; cin >> mes;
        cout << "Anno: "; cin >> anno;
        if (anno < actFecha->getAnno() ||
            (anno == actFecha->getAnno() && mes < actFecha->getMes()) ||
            anno == actFecha->getAnno() && mes < actFecha->getMes() && dia < actFecha->getDia()) {
            cout << "La fecha digitada es incorrecta, por favor ingrese una fecha valida" << endl;
            continue;
        }
        else {
            break;
        }
    }
    cout << "Digite la hora del curso: " << endl;
    cin >> hora;
    cout << "Digite el cupo maximo del curso: " << endl;
    cin >> cupoMaximo;

    Fecha* fechaDelCurso = new Fecha(dia, mes, anno);
    Curso* curso = new Curso(nombre, descripcion, nivel, fechaDelCurso, hora, cupoMaximo);

    cursos.agregar(curso);
}

string Gym::mostrarClientes() {
    return clientes.toString();
}

string Gym::mostrarCursos() {
    return cursos.toString();
}

void Gym::matricCurso() {
    Curso* curso;
    Deportista* deportista;
    string nombreDeportista, nombreCurso;

    cout << "Digite el nombre del curso que desea matricular: " << endl;
    cin >> nombreCurso;
    if (cursos.buscarPorNombre(nombreCurso) != nullptr) {
        curso = cursos.buscarPorNombre(nombreCurso);
        cout << "Digite el nombre del cliente que desea matricular a un curso: " << endl;
        cin >> nombreDeportista;
        if (clientes.buscarPorNombre(nombreDeportista) != nullptr) {
            deportista = clientes.buscarPorNombre(nombreDeportista);
            curso->matricularDeportista(deportista);
        }
        else {
            cout << "El nombre del cliente no ha sido encontrado" << endl;
        }
    }
    else {
        cout << "El curso no ha sido encontrado" << endl;
    }

}

string Gym::deportistaMatriculados() {
    Curso* curso;
    string  nombreCurso;

    cout << "Digite el nombre del curso que desea ver los clientes matriculados: " << endl;
    cin >> nombreCurso;
    if (cursos.buscarPorNombre(nombreCurso) != nullptr) {
        curso = cursos.buscarPorNombre(nombreCurso);
        return curso->getNombresMatriculados();
    }
    else {
        return "El curso no tiene clientes matriculados";
    }
}

void Gym::realizarPago() {
    HistorialPagos* historialPago;
    Deportista* deportista;
    string nombreDeportista, estadoCliente;
    double montoPagado = 0, montoPendiente = 0, vuelto = 0;
    int dia, mes, anno;

    cout << "Digite el nombre del cliente que desea pagar su mensualidad: " << endl;
    cin >> nombreDeportista;
    if (clientes.buscarPorNombre(nombreDeportista) != nullptr) {
        deportista = clientes.buscarPorNombre(nombreDeportista);
        cout << "Digite el monto del pago: " << endl;
        while (true) {
            cin >> montoPagado;
            if (montoPagado < mensualidad) {
                montoPendiente = mensualidad - montoPagado;
                break;
            }
            else if (montoPagado > mensualidad) {
                vuelto = montoPagado - mensualidad;
                montoPendiente = 0;
                cout << "Su vuelto es: " << vuelto << endl;
                break;
            }
            else if (montoPagado == 40000) {
                montoPendiente = mensualidad - montoPagado;
                break;
            }
            else {
                cout << "Digite un monto correcto" << endl;
                continue;
            }
        }
        if (montoPendiente > 0) {
            estadoCliente = "Pendiente";
        }
        else if (montoPendiente == 0) {
            estadoCliente = "Activo";
        }
        else if (montoPendiente == 40000) {
            estadoCliente = "Inactivo";
        }
        cout << "Digite la fecha que esta realizando el pago" << endl;
        cout << "Dia: "; cin >> dia;
        cout << "Mes: "; cin >> mes;
        cout << "Anno: "; cin >> anno;

        historialPago = new HistorialPagos(montoPendiente, montoPagado, actFecha);
        deportista->agregarPago(historialPago);
        deportista->cambiarEstadoCliente(estadoCliente);
    }
    else {
        cout << "El nombre del cliente no ha sido encontrado" << endl;
    }

}

string Gym::mostrarHistorialPagosCliente() {
    Deportista* deportista;
    string  nombreDeportista;

    cout << "Digite el nombre del cliente que desea ver su historial de pagos: " << endl;
    cin >> nombreDeportista;
    if (clientes.buscarPorNombre(nombreDeportista) != nullptr) {
        deportista = clientes.buscarPorNombre(nombreDeportista);
        return deportista->mostrarHistorialPagos();
    }
    else {
        return "No hay ningun cliente registrado con ese nombre";
    }
}