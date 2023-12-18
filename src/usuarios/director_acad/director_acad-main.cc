#include "director_acad.h"
#include "usuario.h"
#include "act_academica.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int main()
{
    Director_acad d1;
    d1.VerActPen();
    d1.ConfirarAct(id_act);
    d1.VerSolicitudes(correo);
    d1.ConfirmarInscripcion(id_act,correo);



}