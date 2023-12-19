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
        std::cout<<"SELECCIONE UNA OPCION:\n 1. Login\n 2. Acceder como invitado\n 3. Salir\n";
        std::cin>>valor_entrada;
        switch(valor_entrada){
            case 1:
                return user.Login();
                break;
            case 2:
                std::cout<<"Como invitado unicamente puede ver las actividades academicas subidas\n";
                std::ifstream DataAct("../BD/ActAcademicas.txt");
                std::string linea;
                while(std::getline(DataAct,linea)){
                    std::cout<<linea;
                }
                DataAct.close();
                std::cout<<"Saliendo del programa\n";
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
                    if(alum.CambiarEstado(0, id_act)){//PREINSCRITO ---> NADA
                        std::cout<<"Estado cambiado correctamente\n";
                    }
                case 2:
                    if(alum.CambiarEstado(1, id_act)){//NADA ---> PREINSCRITO
                        std::cout<<"Estado cambiado correctamente\n";
                    }
                case 3:
                    if(alum.CambiarEstado(2, id_act)){//PREINSCRITO ---> INSCRITO
                        std::cout<<"Estado cambiado correctamente\n";
                    }
                    break;
                default:
                    std::cout<<"Valor introducido incorrecto, saliendo de acceder a una actividad academica\n";
            }
        }
    }
}

void MenuDetalleControlInscrip(Director_acad &dir){
    std::ifstream DataUsers("../BD/cuentas.txt");
    if(DataUsers.is_open()){
        while(std::getline(DataUsers,linea)){
            std::cout<<linea<<"\n";
        }
    }
    DataUsers.close();
    bool error= true;
    while(error!=true){
        std::cout<<"Escriba el correo del alumno que quiera seleccionar para confirmar inscripcion\n";
        std::string nombre;
        std::cin>>nombre;
        Alumno a1;
        if(!(a1.RellenarF(nombre))){//Si no encuentra el correo en "cuentas.txt"
            std::cout<<"Correo inexistente:\n 1. Seguir intentandolo\n 2. Salir";
            int datsalir1;
            std::cin>>datsalir1;
            if(datsalir1==2){
                error= false;
            }
            else if(datsalir1!=1 && datsalir1!=2){
                std::cout<<"Dato incorrecto, saliendo de la seccion\n";
                error= false;
            }
        }
        else{//Si encuentra el correo en "cuentas.txt"
            std::cout<<"Inscripciones pendientes de "<<a1.GetCorreo()<<": ";
            if((a1.VectorIdsInscrip).size()!=0){//Si la cuenta SÍ tiene inscripciones pendientes
                for(auto i : a1.VectorIdsInscrip()){
                    std::cout<<i<<" ";
                }
                std::cout<<"\n";
                int opcion;
                std::cout<<"Selecciona la inscripcion a confirmar: ";
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
                    std::cout<<"ID introducido incorrecto, saliendo de la seccion\n";
                    error= true;
                }
            }
            else{//Si la cuenta NO tiene inscripciones pendientes
                std::cout<<"No hay inscripciones pendientes de "<<a1.GetCorreo()<<"\n";
                std::cout<<"Seleccione una opcion\n 1. Aceptar otra inscripcion\n 2. Salir\n";
                int datsalir3;
                std::cin>>datsalir3;
                if(datsalir3==2){
                    error= false;
                }
                else if(datsalir3!=1 && datsalir3!=2){
                    std::cout<<"Dato incorrecto, saliendo de la seccion\n";
                    error= false;
                }
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
                a1.VerBandeja();
                break;        
            case 2:
                std::cout<<"¿Qué actividad académica quiere ver en detalle?\n";
                int id_actividad;
                std::cin>>id_actividad;
                alum.VerDetalles(id_actividad);
                std::string estado=alum.VerEstadoAct(id_actividad);
                MenuDetalleAct(estado, alum, id_actividad);
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


void menuDirector_Acad(Director_acad &dir){
    std::cout<<"Bienvenido de vuelta "<<dir.GetCorreo()<<"\n";
    int valor_entrada=0;
    while(valor_entrada!=3){
        std::cout<<"Seleccione una opcion:\n 1. Ver actividades academicas sin confirmar\n";
        std::cout<<" 2. Confirmar y enviar actividad academica\n 3. Confirmar pago\n 4. Salir\n";
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