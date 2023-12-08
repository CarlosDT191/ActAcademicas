#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
#include "usuario.h"
#include "organizador.h"
#include "director_acad.h"
#include "alumno.h"
#include <iostream>
#include <vector>

bool menuInicial(Usuario &user);

Alumno ConvertToAlumn(Usuario* user);
Organizador ConvertToOrg(Usuario* user);
Director_acad ConvertToDir(Usuario* user);

void MenuDetalleAct(std::string estado, Alumno &alum);
void menuAlumno(Alumno &alum);
void menuOrganizador(Organizador &org);
void menuDirector_Acad(Director_acad &dir);

#endif