#include "organizador.h"
#include "usuario.h"
#include "act_academica.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

Organizador::Organizador(std::string correo, std::string password, std::string carrera){
    SetCorreo(correo);
    SetPassword(password);
    SetRol(3);
    SetCarrera(carrera);
}

void Organizador::CrearActAcademica()
{
    Act_academica a1;
    a1.SetId();
    a1.RellenarDatosT();
    //Imprime en el fichero de "Comunicación.txt"
    a1.ImprimirFCom();
}

bool Organizador::ModificarActAcademica(int id_act)
{
    Act_academica a1(id_act);
    a1.RellenarDatosT();
    bool var = a1.ModificarActFCom();
    return var;
}

//Lee las actividades académicas confirmadas
bool Organizador::VerActAcademicasConf()
{
    std::ifstream DataActAcad("src/BD/ActAcademicas.txt");

    if (!DataActAcad.is_open())
    {
        std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
        return false;
    }

    std::string linea;
    int contador = 0;

    std::cout << "\n                          ACTIVIDADES CONFIRMADAS\n";
    while (std::getline(DataActAcad, linea))
    {
        ++contador;
        std::cout <<linea << "\n";
    }
    std::cout << "\n";
    DataActAcad.close();

    if (contador > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Lee las actividades académicas por confirmar
bool Organizador::VerActAcademicasNoConf() {
    std::ifstream DataActAcad("src/BD/comunicacion.txt");

    if (!DataActAcad.is_open()) {
        std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
        return false;
    }

    std::string linea;
    int contador = 0;
    std::cout << "\n                          ACTIVIDADES NO CONFIRMADAS\n";
    while (std::getline(DataActAcad, linea)) {
        ++contador;
        std::cout <<linea << "\n";
    }
    std::cout << "\n";
    DataActAcad.close();
    if (contador > 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}