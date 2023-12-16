#ifndef ORGANIZADOR_H_
#define ORGANIZADOR_H_
#include "usuarios.h"
#include "act_academica"
#include <iostream>
#include <vector>
#include <string>

// Clase base Usuario
class Usuario
{
private:
    std::string nombre_;
    std::string correo_;
    std::string rol_;

public:
    Usuario(const std::string &nombre, const std::string &correo, const std::string &rol)
        : nombre(nombre_), correo(correo_), rol(rol_) {}

    // Getters
    std::string getNombre() const
    {
        return nombre_;
    }

    std::string getCorreo() const
    {
        return correo_;
    }

    std::string getRol() const
    {
        return rol_;
    }

    // Setter para cambiar el rol
    void setRol(const std::string &nuevoRol)
    {
        rol_= nuevoRol;
    }
};

// Clase derivada Organizador
class Organizador : public Usuario
{
public:
    Organizador(const std::string &nombre, const std::string &correo)
        : Usuario(nombre, correo, "organizador") {}

    
        void crearActAcademica(const ActividadAcademica& nuevaActividad);

    // Función para modificar una actividad académica
    void modificarActAcademica(ActividadAcademica& actividad);
    
    };


#endif
