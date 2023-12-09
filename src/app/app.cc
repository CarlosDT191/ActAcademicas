#include "app.h"
#include "usuario.h"
#include "organizador.h"
#include "director_acad.h"
#include "alumno.h"
#include "act_academica.h"
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

void MenuDetalleAct(std::string estado, Alumno &alum, int id_act){
    int valor=0;
    while(valor!=3){
        if(estado=="Nada"){
            std::cout<<"Seleccione una opcion:\n 1. Preinscribirse\n 2. Salir";
            std::cin>>valor;
            switch(valor){
                case 1:
                    alum.CambiarEstado(0, id_act);//NADA --->PREINSCRITO
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
                    if(alum.CambiarEstado(1, id_act)){//PREINSCRITO ---> NADA
                        std::cout<<"Estado cambiado correctamente\n";
                    }
                case 2:
                    if(alum.CambiarEstado(2, id_act)){//PREINSCRITO ---> INSCRITO
                        std::cout<<"Estado cambiado correctamente\n";
                    }
                case 3:
                    break;
                default:
                    std::cout<<"Valor introducido incorrecto, saliendo de acceder a una actividad academica\n";
            }
        }
    }
}


void menuAlumno(Alumno &alum){
    std::cout<<"Bienvenido de vuelta "<<alum.GetCorreo()<<"\n";
    int valor_entrada=0;
    while(valor_entrada!=5){
        std::cout<<"Seleccione una opcion:\n 1. Ver bandeja\n 2. Acceder a actividad academica\n";
        std::cout<<" 3. Ver pre-inscripciones\n 4. Ver inscripciones\n 5. Salir\n";
        std::cin>>valor_entrada;
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
                MenuDetalleAct(estado, alum, id_actividad);
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
            case 5:
                std::cout<<"Saliendo del programa\n";
                break;
            default:
                std::cout<<"Ha escrito un valor incorrecto, vuelva a intentarlo\n";
        }
    }

}


void menuDirector_Acad(Director_acad &dir){
    std::cout<<"Bienvenido de vuelta "<<dir.GetCorreo()<<"\n";
    int valor_entrada=0;
    while(valor_entrada!=3){
        std::cout<<"Seleccione una opcion:\n 1. Ver actividades academicas sin confirmar\n";
        std::cout<<" 2. Confirmar y enviar actividad academica\n 3. Salir\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                dir.VerActPen();
                break;
            case 2:
                int id_act;
                std::cout<<"Seleccione el id de la actividad a confirmar: \n";
                std::cin>>id_act;
                if(dir.ConfirmarAct(int id_act)){
                    std::cout<<"Actividad confirmada con exito\n";
                }
                else{
                    std::cout<<"Error al confirmar la actividad\n";
                }
                break;
            case 3:
                std::cout<<"Saliendo del programa\n";
                break;
            default:
                std::cout<<"Ha escrito un valor incorrecto, vuelva a intentarlo\n";
        }
    }
}


void menuOrganizador(Organizador &org){
    std::cout<<"Bienvenido de vuelta "<<org.GetCorreo()<<"\n";
    int valor_entrada=0;
    while(valor_entrada!=4){
        std::cout<<"Seleccione una opcion:\n 1. Crear actividad academica nueva\n";
        std::cout<<" 2. Ver actividades academicas creadas sin confirmar\n 3. Ver actividades academicas enviadas\n";
        std::cout<<" 4. Salir\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                org.CrearActAcademica();
                break;
            case 2:
                org.VerActAcademicasNoConf();
                break;
            case 3:
                org.VerActAcademicasConf();
                break;
            case 4:
                std::cout<<"Saliendo del programa\n";
                break;
            default:
                std::cout<<"Ha escrito un valor incorrecto, vuelva a intentarlo\n";
        }
    }

}