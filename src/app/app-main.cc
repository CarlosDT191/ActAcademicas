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

int main(){
    Usuario user;
    std::cout<<"|------------------------------------------------------|\n";
    std::cout<<"|             Bienvenid@ a Actividades UCO             |\n";
    std::cout<<"|------------------------------------------------------|\n";
    if(menuInicial(user)){
        Alumno alum= ConvertToAlumn(&user);
        Director_Acad dir= ConvertToDir(&user);
        Organizador org= ConvertToOrg(&user);
        switch(user.GetRol()){
            case 1:
                menuAlumno(alum);
                break;
            case 2:
                menuDirector_Acad(dir);
                break;
            case 3:
                menuOrganizador(org);
                break;
        }
    }
    return 0;
}