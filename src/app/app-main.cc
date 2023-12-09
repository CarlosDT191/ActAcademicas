#include "app.h"
#include "usuario.h"
#include "organizador.h"
#include "director_acad.h"
#include "alumno.h"
#include "act_academica.h"
#include <iostream>
#include <vector>
#include <fstream>

int main(){
    Usuario user;
    std::cout<<"|----------------------------------------|\n";
    std::cout<<"|      Bienvenid@ a Actividades UCO      |\n";
    std::cout<<"|----------------------------------------|\n";
    if(menuInicial(user)){
        switch(user.GetRol()){
            case 1:
                Alumno alum= ConvertToAlumn(&user);
                menuAlumno(alum);
                break;
            case 2:
                Director_acad dir= ConvertToDir(&user);
                menuDirector_Acad(dir);
                break;
            case 3:
                Organizador org= ConvertToOrg(&user);
                menuOrganizador(org);
                break;
        }
    }
    return 0;
}