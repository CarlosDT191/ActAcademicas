#ifndef ORGANIZADOR_H_
#define ORGANIZADOR_H_
#include "usuario.h"
#include "act_academica.h"
#include <iostream>
#include <vector>
#include <string>

// Clase derivada Organizador
class Organizador : public Usuario{
    private:
    public:
        Organizador(std::string correo, std::string password, std::string carrera);
        void CrearActAcademica();

    // Función para modificar una actividad académica
        bool ModificarActAcademica(int id_act);

        bool VerActAcademicasConf();

        bool VerActAcademicasNoConf();
        };


#endif
