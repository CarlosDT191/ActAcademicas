//lista_asistencia.h
//Se crea la clase lista de asistencia

#ifndef LISTAASISTENCIA_H
#define LISTAASISTENCIA_H

#include <string>
#include "act_academica.h"
#include <iostream>
#include <vector>

class Lista_asistencia{
    private:
        int id_act_;
        int aforo_restante_;
        std::vector<std::string> vec_alum_;
    public:
        Lista_asistencia(int id_act=0){id_act_=id_act;}
        int GetId_academica(){return id_act_;}
        int GetAforoRes(){return aforo_restante_;}
        std::vector<std::string> GetInscritos(){return vec_alum_;} 
        bool RecogerListaAct(int id_act);
        bool AnadirAlumno(int id_act, std::string correo);
};

#endif //LISTAASISTENCIA_H