//alumno.h
//Se crea la clase

#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <iostream>
#include "act_academica.h"
#include "usuario.h"

class Alumno: public Usuario{
    private:
        rol_ = 1;
    
    public:
        void verDetalles(int id_act);
        bool verInscrip();
        bool verPreInscrip();
        std::string verEstadoAct(int id_act);
        bool CambiarEstado(int state, int id_act);
        bool RellenarF(std::string correo);
        std::vector<int> VectorIdsInscrip();
};

#endif