#include "organizador.h"
#include "string"
#include "vector"
#include "usuarios.h"
#include "act_academica"
#include <iostream>

int main() {
    Organizador organizador("Organizador1", "organizador1@example.com");

    // Crear una nueva actividad académica
    ActividadAcademica nuevaActividad(1, "Ciencia de Datos",50, "Auditorio A",
                                      25.0, 0, 100, "Conferencia de Ciencia de Datos",
                                      "Una conferencia sobre las últimas tendencias en Ciencia de Datos.");

    // Llamar a la función crearActAcademica con el objeto creado
    organizador.crearActAcademica(nuevaActividad);

    organizador.mostrarActividades();

    // Modificar la actividad académica creada
    organizador.modificarActAcademica(nuevaActividad);

    organizador.mostrarActividades();



    return 0;
}