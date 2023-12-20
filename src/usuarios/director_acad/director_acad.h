#ifndef DIRECTORACAD_H_
#define DIRECTORACAD_H_
#include "usuario.h"
#include "act_academica.h"
#include "lista_asistencia.h"
#include <iostream>
#include <vector>
#include <string>

class Director_Acad : public Usuario
{
private:

public:
    //Constructor
    Director_Acad(std::string correo, std::string password);
    // Función para ver todas las actividades pendientes en "comunicacion.txt"
    void VerActPen();
    // Funcion eliminar act acad
    bool ConfirmarAct(int id_act);
    //Funcion para ver solicitudes
    bool VerSolicitudes(std::string correo);
    //Función para confimar inscripción
    void ConfirmarInscripcion(std::string correo, int id_act);
    /*
    bool EnviarAct(int id_act);*/
};

#endif
