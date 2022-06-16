#include "procesador.h"
#include <iostream>
#include <fstream>


using namespace std;

int main()
{

    string archivoPersonas = "personas.txt";
    string archivoNomina = "nomina.txt";
    string archivoHorasTrabajadas = "horastrabajadas.txt";

    ifstream lectorPersonas(archivoPersonas, std::ifstream::in); // Por default abriendo como texto

    if (!lectorPersonas.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }

    ifstream lectorNomina(archivoNomina, std::ifstream::in); // Por default abriendo como texto

    if (!lectorNomina.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }

    ifstream lectorHorasTrabajadas(archivoHorasTrabajadas, std::ifstream::in); // Por default abriendo como texto

    if (!lectorHorasTrabajadas.is_open())
    {
        std::cerr << "Error leyendo archivo ejemplo.txt" << std::endl;
        return -1;
    }

    Procesador procesador(&lectorPersonas, &lectorNomina, &lectorHorasTrabajadas);

    procesador.anadirEmpleados();

    ofstream reporte("reportePlanilla.csv", std::ifstream::out); // Por default abriendo como texto

    if (!reporte.is_open())
    {
        std::cerr << "Error abriendo archivo reporteCatalogo.txt" << std::endl;
        return -1;
    }

    reporte << &procesador;
    reporte.close();

    lectorPersonas.close();
    lectorNomina.close();
    lectorHorasTrabajadas.close();
}