//usuario.h
//Se crea la clase usuario

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "act_academica.h"
#include <iostream>

class Usuario{
    private:
        std::string correo_;
        std::string password_;
        int rol_;
        std::string carrera_;
    public:
        std::string GetCorreo(){return correo_;}
        std::string GetPassword(){return password_;}
        int GetRol(){return rol_;}
        std::string GetCarrera(){return carrera_;}

        void SetCorreo(std::string correo){correo_ = correo;}
        void SetPassword(std::string password){password_ = password;}
        void SetRol(int rol){rol_ = rol;}
        void SetCarrera(std::string carrera){carrera_ = carrera}

        bool Login();
};


#endif //usuario.h