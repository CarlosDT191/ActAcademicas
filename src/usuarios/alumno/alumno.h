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
    public:
        //Constructor de la clase alumno
        Alumno(std::string correo, std::string password, std::string carrera);
        //Muestra la bandeja de entrada del correo del alumno
        void VerBandeja();
        //Muestra en detalle la informacion de la actividad
        bool VerDetalles(int id_act);
        //Muestra las actividades en las que está inscrito
        bool VerInscrip();
        //Muestra las actividades en las que está preinscrito
        bool VerPreInscrip();
        //Devuelve el estado de inscripcion del alumno a la actividad con id id_act
        std::string VerEstadoAct(int id_act);
        //Funcion que cambia los estados de la persona respecto a una actividad academica
        //Si state= 0 ; estado= "nada"
        //Si state= 1 ; estado= "preinscrito"
        //Si state= 2 ; estado= "inscrito_en_espera"
        bool CambiarEstado(int state, int id_act);
        //Funcion que rellena la clase Alumno con la informacion almacenada en "cuentas.txt"
        bool RellenarF(std::string correo);
        //Devuelve un vector con los Ids de las act. academicas en las que esta inscrito
        std::vector<int> VectorIdsInscrip();
};

#endif