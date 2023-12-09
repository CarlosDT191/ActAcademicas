#ifndef ORGANIZADOR_H_
#define ORGANIZADOR_H_
#include "string"
#include "vector"
#include "usuario.h"
#include "act_academica.h"

#include <iostream>
#include <vector>
#include <string>

// Clase derivada Organizador
class Organizador : public Usuario
{
public:
    Organizador(const std::string &nombre, const std::string &correo)
        : Usuario(nombre, correo, "organizador")
    {
        rol_ = 2;
    }

    void Organizador::CrearActAcademica();

    // Función para modificar una actividad académica

    void ModificarActAcademica(int id_ac);

    // Funciones para confimar actividades academicas
    bool VerActAcademicasConf();

    bool VerActAcademicasNoConf();
};

#endif