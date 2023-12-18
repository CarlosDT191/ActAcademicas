#ifndef ORGANIZADOR_H_
#define ORGANIZADOR_H_
#include "usuarios.h"
#include "act_academica"
#include <iostream>
#include <vector>
#include <string>

// Clase derivada Organizador
class Organizador : public Usuario
{
private:
std::string rol_=3;
public:
    void CrearActAcademica();

// Función para modificar una actividad académica
    bool Organizador::ModificarActAcademica(int id_act);

    bool Organizador::VerActAcademicasConf();
    };


#endif
