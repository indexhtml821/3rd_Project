#include "planilla.h"
/*Planilla::Planilla(){
/*
    Empleado *empleadoBase = new Empleado(2,
                   "stringnombre",
                   "sss",
                   "dsas", 
                   int tizzzyyo,
                   int idSupervisor);
    this->supervisor = new Nodo()}
  
 
 */
Planilla::~Planilla()
{
    int cantidadIndices = indicePlanilla.size();

    supervisor->~Nodo();
    for (int i = 1; i < cantidadIndices; i++)
    {
        indicePlanilla.erase(i);
    }
}

void Planilla::InsertarEmpleado(Empleado *empleadoAInsertar)
{
    Empleado *empleado = empleadoAInsertar;
    int id = empleadoAInsertar->ObtenerIdEmpleado();
    int idSupervisor = empleado->ObtenerIdSupervisor();
    Nodo *nodoEmpleado = new Nodo(id, empleado);

    if (id == 1)
    {

        supervisor = new Nodo(id,empleado);
        this->supervisor->InsertarSupervisar(nodoEmpleado);
        this->indicePlanilla.insert(std::pair<int, Nodo *>(id, nodoEmpleado));

        
    }
    Nodo *nodoSupervisor = this->indicePlanilla.at(idSupervisor);
    nodoSupervisor->InsertarSupervisar(nodoEmpleado);
    nodoEmpleado->InsertarSupervisor(nodoSupervisor);

    this->indicePlanilla.insert(std::pair<int, Nodo *>(id, nodoEmpleado));
}

Empleado *Planilla::ObtenerEmpleado(int id)
{

    Empleado *empleadoSolicitado = indicePlanilla.at(id)->DevolverEmpleado();
    return empleadoSolicitado;
}

map<int, Nodo *>  Planilla:: devolverIndicePlanilla(){


return this->indicePlanilla;

}
