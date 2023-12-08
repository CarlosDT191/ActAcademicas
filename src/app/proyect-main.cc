#include "prototipos.h"
#include "usuario.h"
#include <iostream>

int main(){
    Usuario user;
    std::cout<<"|--------------------------------------|\n";
    std::cout<<"|     Bienvenido a Actividades UCO     |\n";
    std::cout<<"|--------------------------------------|\n";
    if(menuInicial(user)){
        switch(user.GetRol()){
            case 1:
                Alumno alum= ConvertToAlumn(&user);
                menuAlumno(alum);//HECHO
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