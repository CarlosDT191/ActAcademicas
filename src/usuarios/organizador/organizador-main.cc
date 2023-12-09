#include "organizador.h"
#include "string"
#include "vector"
#include "usuario.h"
#include "act_academica.h"
#include <iostream>

int main()
{
    Organizador organizador("Organizador1", "organizador1@example.com");

    // Crear una nueva actividad académica
    ActividadAcademica nuevaActividad(1, "Ciencia de Datos", 50,
                                      25.0, 0, 100, "Conferencia de Ciencia de Datos",
                                      "Una conferencia sobre las últimas tendencias en Ciencia de Datos.Ponentes,ubicación materiales...");


    std::cout << "\nActividades académicas no confirmadas:\n";
    if (!VerActAcademicasNoConf())
    {
        std::cout << "No hay actividades académicas no confirmadas.\n";
    }

    std::cout << "\nActividades académicas confirmadas:\n";
    if (!VerActAcademicasConf())
    {
        std::cout << "No hay actividades académicas confirmadas.\n";
    }

    return 0;
}