#include "prototipos.h"
#include "usuario.h"
#include "organizador.h"
#include "director_acad.h"
#include "alumno.h"
#include <iostream>
#include <vector>
#include <fstream>

bool menuInicial(Usuario &user){
    int valor_entrada=0;
    while(valor_entrada!=3){
        std::cout<<"SELECCIONE UNA OPCION:\n 1. Login\n 2. Registrarse\n 3. Salir\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                return user.Login();
                break;
            case 2:
                return user.Register();
                break;
            case 3:
                std::cout<<"Saliendo del programa\n";
                return false;
                break;
            default:
                std::cout<<"Valor introducido incorrecto, vuelva a introducirlo\n";
                break;
        }
    }
}

Alumno ConvertToAlumn(Usuario* user){
    if(Alumno* alum= dynamic_cast<Alumno*>(user)){
        return *alum;
    }
}

Organizador ConvertToOrg(Usuario* user){
    if(Organizador* org= dynamic_cast<Organizador*>(user)){
        return *org;
    }
}

Director_acad ConvertToDir(Usuario* user){
    if(Director_acad* dir= dynamic_cast<Director_acad*>(user)){
        return *dir;
    }
}

void MenuDetalleAct(std::string estado, Alumno &alum){
    int valor=0;
    while(valor!=3){
        if(estado=="Nada"){
            std::cout<<"Seleccione una opcion:\n 1. Preinscribirse\n 2. Salir";
            std::cin>>valor;
            switch(valor){
                case 1:
                    alum.CambiarEstado(0);//NADA --->PREINSCRITO
                case 2:
                    valor++;
                    break;
                default:
                    std::cout<<"Valor introducido incorrecto, saliendo de acceder a una actividad academica\n";
            }
        }

        else if(estado="Preinscrito"){
            std::cout<<"Seleccione una opcion:\n 1. Cancelar preinscripcion\n2. Inscribirse\n 3. Salir";
            std::cin>>valor;
            switch(valor){
                case 1:
                    alum.CambiarEstado(1);//PREINSCRITO ---> NADA
                case 2:
                    alum.CambiarEstado(2);//PREINSCRITO ---> INSCRITO
                case 3:
                    break;
                default:
                    std::cout<<"Valor introducido incorrecto, saliendo de acceder a una actividad academica\n";
            }
        }
    }
}




void menuAlumno(alumno &alum){
    std::cout<<"Bienvenido de vuelta "<<alum.GetCorreo()<<"\n";
    int valor_entrada=0;
    std::cin>>valor_entrada;
    while(valor_entrada!=5){
        std::cout<<"Seleccione una opcion:\n 1. Ver bandeja\n 2. Acceder a actividad academica\n";
        std::cout<<" 3. Ver pre-inscripciones\n 4. Ver inscripciones\n 5. Salir\n";
        switch(valor_entrada){
            case 1:
                std::string directorio= "../BD/";
                std::string user= (alum.GetCorreo()).substr(0,(alum.GetCorreo()).size()-7);
                std::string direccion= directorio+user+".txt";
                std::string linea;
                std::ifstream DataMailing(direccion);
                if(DataMailing.is_open()){
                    while(std::getline(DataMailing,linea)){
                        std::cout<<linea<<"\n";
                    }
                }
                DataMailing.close();
                break;        
            case 2:
                std::cout<<"¿Qué actividad académica quiere ver en detalle?\n";
                int id_actividad;
                std::cin>>id_actividad;
                alum.verDetalles(id_actividad);
                std::string estado=alum.verEstadoAct(id_actividad);
                MenuDetalleAct(estado, alum);
                break;        
            case 3:
                if(!alum.verPreInscrip()){
                    std::cout<<"No hay ninguna pre-inscripcion\n";
                }
                break;
            case 4:
                if(!alum.verInscrip()){
                    std::cout<<"No hay ninguna inscripcion\n";
                }
                break;
            default:
                std::cout<<"Ha escrito un valor incorrecto\n";
        }
    }

}

