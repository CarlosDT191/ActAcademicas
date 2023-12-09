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

bool Organizador::ModificarActAcademica(int id_ac)
{
    Act_academica a1(id_ac);
    std::cout << "Modificando actividad académica con ID " << id_Ac << ":\n";
    a1.RellenarDatosT();
    if (!(a1.ModificarActF("../BD/comunicacion.txt")))
    {
        if (!(a1.ModificarActF("../BD/comunicacion.txt")))
        {
            return false;
            else
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }
}

bool Organizador::VerActAcademicasConf()
{
    std::ifstream archivo("../BD/comunicacion.txt");

    if (!archivo.is_open())
    {
        std::cerr << "Error al abrir el archivo 'comunicacion.txt'\n";
        return false;
    }

    std::string linea;
    int contador = 0;

    while (getline(archivo, linea))
    {
        ++contador;
        std::cout << "Actividad " << contador << ": " << linea << "\n";
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
    std::ifstream archivo("../BD/comunicacion.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo 'comunicacion.txt'\n";
        return false;
    }

    std::string linea;
    int contador = 0;

    while (getline(archivo, linea)) {
        ++contador;
        std::cout << "Actividad " << contador << ": " << linea << "\n";
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