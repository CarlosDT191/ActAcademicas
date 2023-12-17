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
        int id_act_;
        int aforo_restante_;
        std::vector<std::string> vec_alum_;
    public:
        Lista_asistencia(int id_academica){id_academica_=id_academica;}
        int GetId_academica(){return id_academica_;}
        bool RecogerListaAct(int id_act);
        bool AnadirAlumno(int id_act, std::string correo);
};

#endif //LISTAASISTENCIA_H