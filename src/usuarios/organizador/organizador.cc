#include "organizador.h"
#include "string"
#include "vector"
#include "usuario.h"
#include "act_academica.h"

void Organizador::CrearActAcademica()
{
    Act_academica a1;
    a1.SetId();
    a1.RellenarDatos();
}

bool Organizador::ModificarActAcademica(int id_act)
{
    Act_academica a1(id_act);
    std::cout << "Modificando actividad académica con ID " << id_act << ":\n";
    a1.RellenarDatosT();
    return a1.ModificarActF("../BD/comunicacion.txt");
}

bool Organizador::VerActAcademicasConf()
{
    std::ifstream archivo("../BD/ActAcademicas.txt");

    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
        return false;
    }

    std::string linea;
    int contador = 0;

    while (getline(archivo, linea))
    {
        ++contador;
        std::cout <<linea << "\n";
    }

    archivo.close();

    if (contador > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool VerActAcademicasNoConf() {
    std::ifstream archivo("../BD/ActAcademicas.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
        return false;
    }

    std::string linea;git
    int contador = 0;

    while (getline(archivo, linea)) {
        ++contador;
        std::cout <<linea << "\n";
    }

    archivo.close();
    if (contador > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}