#include "empleado.h"
using namespace std;

Empleado::~Empleado() {}
Empleado::Empleado(){

};

Empleado::Empleado(int idEmpleado,
                   string nombre,
                   string apellido,
                   string email,
                   int tipoEmpleado,
                   int idSupervisor)
{

    this->idEmpleado = idEmpleado;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->idSupervisor = idSupervisor;
}

int Empleado::ObtenerTipoEmpleado()
{
    return tipoEmpleado;
}

int Empleado::ObtenerIdEmpleado()
{
    return idEmpleado;
}
int Empleado::ObtenerIdSupervisor()
{
    return idSupervisor;
}

string Empleado::ObtenerNombre()
{

    return this->nombre;
}