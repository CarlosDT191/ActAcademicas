#ifndef APP_H
#define APP_H
#include "app.h"
#include "usuario.h"
#include "organizador.h"
#include "director_acad.h"
#include "alumno.h"
#include "act_academica.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool menuInicial(Usuario &user);

Alumno ConvertToAlumn(Usuario* user);
Organizador ConvertToOrg(Usuario* user);
Director_Acad ConvertToDir(Usuario* user);

void MenuDetalleAct(std::string estado, Alumno &alum, int id_act);
void MenuDetalleControlInscrip(Director_Acad &dir);
void menuAlumno(Alumno &alum);
void menuDirector_Acad(Director_Acad &dir);
void menuOrganizador(Organizador &org);

#endif