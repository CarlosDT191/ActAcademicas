#include "app.h"
#include "usuario.h"
#include "organizador.h"
#include "director_acad.h"
#include "alumno.h"
#include "act_academica.h"
#include "mailing.h"
#include "lista_asistencia.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

bool menuInicial(Usuario &user){
    int valor_entrada=0;
    std::ifstream DataAct("src/BD/ActAcademicas.txt");
    std::string linea;
    while(valor_entrada!=3){
        std::cout<<"SELECCIONE UNA OPCION:\n 1. Login\n 2. Acceder como invitado\n 3. |<- SALIR\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                return user.Login();
                break;
            case 2:
                std::cout<<"Como invitado unicamente puede ver las actividades academicas subidas\n";
                while(std::getline(DataAct,linea)){
                    std::cout<<linea<<"\n";
                }
                DataAct.close();
                std::cout<<"Saliendo del programa\n";
                return false;
                break;
            case 3:
                std::cout<<"Saliendo del programa\n";
                return false;
                break;
            default:
                std::cout<<"Valor introducido incorrecto, vuelva a introducirlo\n";
        }
    }
}

Alumno ConvertToAlumn(Usuario* user){
    Alumno alum(user->GetCorreo(),user->GetPassword(),user->GetCarrera());
    return alum;
}

Organizador ConvertToOrg(Usuario* user){
    Organizador org(user->GetCorreo(),user->GetPassword());
    return org;
}

Director_Acad ConvertToDir(Usuario* user){
    Director_Acad dir(user->GetCorreo(),user->GetPassword());
    return dir;
}

void MenuDetalleAct(std::string estado, Alumno &alum, int id_act){
    int valor=0;
    while(valor!=3){
        if(estado=="nada"){
            std::cout<<"Seleccione una opcion:\n 1. Preinscribirse\n 2. |<- VOLVER MENU INICIAL\n";
            std::cin>>valor;
            switch(valor){
                case 1:
                    alum.CambiarEstado(1, id_act);//NADA --->PREINSCRITO
                case 2:
                    valor++;
                    break;
                default:
                    std::cout<<"Valor introducido incorrecto, saliendo de acceder a una actividad academica\n";
            }
        }

        else if(estado=="preinscrito"){
            std::cout<<"Seleccione una opcion:\n 1. Cancelar preinscripcion\n2. Inscribirse\n 3. |<- VOLVER MENU INICIAL\n";
            std::cin>>valor;
            switch(valor){
                case 1:
                    if(alum.CambiarEstado(0, id_act)){//PREINSCRITO ---> NADA
                        std::cout<<"Estado cambiado correctamente\n";
                    }
                case 2:
                    if(alum.CambiarEstado(2, id_act)){//PREINSCRITO ---> INSCRITO
                        std::cout<<"Estado cambiado correctamente\n";
                    }
                    break;
                case 3:
                    break;
                default:
                    std::cout<<"Valor introducido incorrecto, saliendo de acceder a una actividad academica\n";
            }
        }

        else{
            std::cout<<"No se puede cambiar estado en esta actividad, volviendo al menu inicial\n";
        }
    }
}

void MenuDetalleControlInscrip(Director_Acad &dir){
    std::ifstream DataUsers("src/BD/cuentas.txt");
    if(DataUsers.is_open()){
        std::cout<<"\n                TODAS LAS CUENTAS CON ACCESO A INSCRIPCIONES\n";
        std::string linea;
        std::getline(DataUsers,linea);
        std::cout<<linea<<"\n";
        while(std::getline(DataUsers,linea)){
            std::istringstream ss(linea);
            std::string rol_str;
            ss.ignore(1);
            std::getline(ss,rol_str,'|');
            std::getline(ss,rol_str,'|');
            std::getline(ss,rol_str,'|');
            int rol= std::stoi(rol_str);
            if(rol==1){
                std::cout<<linea<<"\n";
            }
        }
    }
    DataUsers.close();
    bool error= true;
    while(error!=true){
        std::cout<<"\nEscriba el correo del alumno que quiera seleccionar para confirmar inscripcion:\n";
        std::string nombre;
        std::cin>>nombre;
        Alumno a1;
        if(!(a1.RellenarF(nombre))){//Si no encuentra el correo en "cuentas.txt"
            std::cout<<"Correo inexistente:\n 1. Seguir intentandolo\n 2. |<- VOLVER MENU INICIAL\n";
            int datsalir1;
            std::cin>>datsalir1;
            if(datsalir1==2){
                error= false;
            }
            else if(datsalir1!=1 && datsalir1!=2){
                std::cout<<"Dato incorrecto, volviendo al menu inicial\n";
                error= false;
            }
        }
        else{//Si encuentra el correo en "cuentas.txt"
            if(dir.VerSolicitudes(nombre)){
                    int opcion;
                    std::cout<<"Seleccione la inscripcion a confirmar: ";
                    std::cin>>opcion;
                    bool id_encontrado= false;
                    for(auto j : a1.VectorIdsInscrip()){
                        if(j==opcion){
                            id_encontrado= true;
                        }
                    }//Si hay fallo al recorrer alguno de estos vectores se puede cambiar funcion ConfirmarInscripcion

                    if(id_encontrado){//La inscripcion en espera a confirmar es correcta
                        if(dir.ConfirmarInscripcion(nombre, opcion)){
                            std::cout<<"Inscripcion confirmada correctamente\n";
                        }
                        else{
                            std::cout<<"Error al confirmar inscripcion\n";
                        }
                        error= true;
                    }

                    else{
                        std::cout<<"ID introducido incorrecto, volviendo al menu inicial\n";
                        error= true;
                    }
            }
            else{//Si la cuenta NO tiene inscripciones pendientes
                std::cout<<"No hay inscripciones pendientes de "<<a1.GetCorreo()<<"\n";
                std::cout<<"Seleccione una opcion:\n 1. Aceptar otra inscripcion\n 2. |<- VOLVER MENU INICIAL\n";
                int datsalir3;
                std::cin>>datsalir3;
                if(datsalir3==2){
                    error= false;
                }
                else if(datsalir3!=1 && datsalir3!=2){
                    std::cout<<"Dato incorrecto, volviendo al menu inicial\n";
                    error= false;
                }
            }
        }
    }
}


void menuAlumno(Alumno &alum){
    std::string nombre= alum.GetCorreo();
    nombre.erase(nombre.length()-7);
    std::cout<<"\nBienvenido de vuelta "<<nombre<<"\n";
    int valor_entrada=0;
    while(valor_entrada!=5){
        std::cout<<"\n|                       MENU INICIAL                      |\n";
        std::cout<<"|---------------------------------------------------------|\n";
        std::cout<<"Seleccione una opcion:\n 1. Ver bandeja\n 2. Ver en detalle una actividad academica\n";
        std::cout<<" 3. Ver pre-inscripciones\n 4. Ver inscripciones\n 5. |<- SALIR\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                alum.VerBandeja();
                break;        
            case 2:
                std::cout<<"¿Qué actividad académica quiere ver en detalle? ";
                int id_actividad, opcion_act;
                std::cin>>id_actividad;
                alum.VerDetalles(id_actividad);
                std::cout<<"¿Quiere cambiar su estado respecto a esta actividad? (Preinscripcion e inscripcion)\n";
                std::cout<<" 1. Si\n 2. |<- VOLVER AL MENU INICIAL\n";
                std::cin>>opcion_act;
                if(opcion_act==1){
                    std::string estado=alum.VerEstadoAct(id_actividad);
                    MenuDetalleAct(estado, alum, id_actividad);
                }
                else if(opcion_act!=1 && opcion_act!=2){
                    std::cout<<"Valor introducido incorrecto, volviendo al menu inicial\n";
                }
                break;
            case 3:
                if(!alum.VerPreInscrip()){
                    std::cout<<"No hay ninguna pre-inscripcion\n";
                }
                break;
            case 4:
                if(!alum.VerInscrip()){
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


void menuDirector_Acad(Director_Acad &dir){
    std::string nombre= dir.GetCorreo();
    nombre.erase(nombre.length()-7);
    std::cout<<"\nBienvenido de vuelta "<<nombre<<"\n";
    int valor_entrada=0;
    while(valor_entrada!=3){
        std::cout<<"\n|                       MENU INICIAL                      |\n";
        std::cout<<"|---------------------------------------------------------|\n";
        std::cout<<"Seleccione una opcion:\n 1. Ver actividades academicas sin confirmar\n";
        std::cout<<" 2. Confirmar y enviar actividad academica\n 3. Confirmar inscripcion\n 4. |<- SALIR\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                if(!dir.VerActPen()){
                    std::cout<<"No hay actividades pendientes de confirmar\n";
                }
                break;
            case 2:
                int id_act;
                std::cout<<"Seleccione el id de la actividad a confirmar: \n";
                std::cin>>id_act;
                if(dir.ConfirmarAct(id_act)){
                    if(dir.EnviarAct(id_act)){
                        std::cout<<"Actividad enviada y confirmada correctamente\n";
                    }
                }
                else{
                    std::cout<<"Error al confirmar la actividad, no existe la actividad en Actividades Pendientes.\n";
                }
                break;
            case 3:
                MenuDetalleControlInscrip(dir);
                break;
            case 4:
                std::cout<<"Saliendo del programa\n";
                break;
            default:
                std::cout<<"Ha escrito un valor incorrecto, vuelva a intentarlo\n";
        }
    }
}


void menuOrganizador(Organizador &org){
    std::string nombre= org.GetCorreo();
    nombre.erase(nombre.length()-7);
    std::cout<<"\nBienvenido de vuelta "<<nombre<<"\n";
    int valor_entrada=0;
    while(valor_entrada!=5){
        std::cout<<"\n|                       MENU INICIAL                      |\n";
        std::cout<<"|---------------------------------------------------------|\n";
        std::cout<<"\nSeleccione una opcion:\n 1. Crear actividad academica nueva\n";
        std::cout<<" 2. Ver actividades academicas creadas sin confirmar\n 3. Modificar actividad sin confirmar\n";
        std::cout<<" 4. Ver actividades academicas enviadas y confirmadas\n 5. |<- SALIR\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                org.CrearActAcademica();
                std::cout<<"Actividad creada de manera correcta\n";
                break;
            case 2:
                if(!org.VerActAcademicasNoConf()){
                    std::cout<<"                     No hay ninguna actividad pendiente de confirmar\n";
                }
                break;
            case 3:
                int id_act;
                std::cout<<"Escriba la actividad que quiere editar: ";
                std::cin>>id_act;
                if(!org.ModificarActAcademica(id_act)){
                    std::cout<<"Error al intentar modificar la actividad\n";
                }
                else{
                    std::cout<<"Actividad modificada de manera correcta\n";
                }
                break;
            case 4:
                if(!org.VerActAcademicasConf()){
                    std::cout<<"                   No hay ninguna actividad confirmada y enviada\n";
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