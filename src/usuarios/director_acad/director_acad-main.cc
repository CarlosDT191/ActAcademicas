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
    Director_Acad d1("orgmajog@uco.es","organizadorsoy");
    /*
    d1.VerActPen();
    d1.VerSolicitudes("i22lumas@uco.es");
    d1.ConfirmarInscripcion("i22lumas@uco.es",1);
    */
    d1.ConfirmarAct(2);
    d1.EnviarAct(2);
    return 0;
} 