//lista_asistencia.h
//Se crea la clase lista de asistencia

#ifndef LISTAASISTENCIA_H
#define LISTAASISTENCIA_H

#include <string>
#include "act_academica.h"
#include "alumno.h"
#include <iostream>

class Lista_asistencia{
    private:
        int id_academica_;
        int aforo_restante_;
        std::vector<alumno> vec_alum_;
    public:
        lista_asistencia(int id_academica){id_academica_=id_academica;}
        int GetId_academica(){return id_academica_;}
};

#endif //LISTAASISTENCIA_H