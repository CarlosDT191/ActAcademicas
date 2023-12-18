#include "organizador.h"
#include "usuario.h"
#include "act_academica.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


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
    return a1.ModificarActFCom("src/BD/comunicacion.txt");
}

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

    while (std::getline(DataActAcad, linea))
    {
        ++contador;
        std::cout <<linea << "\n";
    }

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

bool Organizador::VerActAcademicasNoConf() {
    std::ifstream DataActAcad("src/BD/ActAcademicas.txt");

    if (!DataActAcad.is_open()) {
        std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
        return false;
    }

    std::string linea;
    int contador = 0;

    while (std::getline(DataActAcad, linea)) {
        ++contador;
        std::cout <<linea << "\n";
    }

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