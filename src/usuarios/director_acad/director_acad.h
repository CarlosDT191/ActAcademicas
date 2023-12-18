#ifndef DIRECTORACAD_H_
#define DIRECTORACAD_H_
#include "usuario.h"
#include "act_academica.h"
#include <iostream>
#include <vector>
#include <string>

class Director_Acad : public Usuario
{
private:
std::string rol_="2";
public:
    // Función para ver todas las actividades pendientes en "comunicacion.txt"
    void VerActPen();
    // Funcion eliminar act acad
    bool ConfirmarAct(int id_act);
    //Funcion para ver solicitudes
    bool VerSolicitudes(std::string& correo);
    //Función para confimar inscripción
    void ConfirmarInscripcion(std::string correo, int id_act);
};

#endif
