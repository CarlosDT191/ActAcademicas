#ifndef DIRECTORACAD_H_
#define DIRECTORACAD_H_
#include "usuarios.h"
#include "act_academica.h"
#include <iostream>
#include <vector>
#include <string>

class DirectorAcademico : public Usuario
{
private:
std::rol_=2;
public:
    // Función para ver todas las actividades pendientes en "comunicacion.txt"
    void VerActPen()
    // Funcion eliminar act acad
    bool ConfirmarAct(int id_act);
    //Funcion para ver solicitudes
    bool VerSolicitudes(const std::string& correo);
};

#endif
