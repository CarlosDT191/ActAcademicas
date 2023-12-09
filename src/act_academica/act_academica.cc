#include "act_academica.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void Act_academica::SetId(){
    std::ifstream DataAct("../BD/ActAcademicas.txt");
    if(DataAct.is_open()){
        std::string linea;
        std::streampos posIn= DataAct.tellg();
        DataAct.seekg(0,std::ios::end);
        std::streampos posFin= DataAct.tellg();
        std::streamsize finArchivo= posFin-posIn;
        DataAct.seekg(-finArchivo,std::ios::end);
        while(std::getline(DataAct, linea)){
            std::istringstream ss(linea);
            ss.ignore(1);
            int idef;
            std::getline(ss,idef,'|');
            id_= ++ifed;
        }
        DataAct.close();
    }
}

void Act_academica::RellenarDatosT(){
    std::string titulo, descripcion;
    float precio;
    int aforomax, valor=0;
    while(valor!=5){
        switch(valor){
            case 1:
                std::cout<<"Introduzca el titulo de la actividad:\n";
                std::cin>>titulo;
                titulo_= titulo;
                if(valor!=0){
                    break;
                }
            case 2:
                std::cout<<"\nIntroduzca una breve descripcion:\n";
                std::cin>>descripcion;
                descripcion_=descripcion;
                if(valor!=0){
                    break;
                }
            case 3:
                std::cout<<"\nIntroduzca el precio de la actividad:\n";
                std::cin>>precio;
                precio_=precio;
                if(valor!=0){
                    break;
                }
            case 4:
                std::cout<<"\nIntroduzca el aforo maximo de la actividad:\n";
                std::cin>>aforomax;
                aforomax_=aforomax;
                break;
            case 5:
                std::cout<<"Saliendo de la asignacion de valores.\n";
                break;
            default:
                std::cout<<"Dato incorrecto, seleccione de nuevo\n";
                break;
        }

        if(valor!=5){
            std::cout<<"¿Que desea realizar ahora?\n1. Editar titulo\n 2. Editar descripcion\n";
            std::cout<<" 3. Editar precio\n 4. Editar aforo maximo\n 5. Salir\n";
            std::cin>>valor;
        }
    }
}


bool RellenarDatosFAc(int id_act){
    std::ifstream DataAct("../BD/ActAcademicas.txt");
    if(DataAct.is_open()){
        std::string linea;
        std::getline(DataAct,linea);
        while(std::getline(DataAct,linea)){
            std:istringstream ss(linea);
            std::string l_titulo, l_descripcion, l_carrera;
            float l_precio;
            int l_aforomax, l_identific;
            if(std::getline(ss, l_identific, '|')){
                if(l_identific==id_act){
                    id_=id_act;
                    std::getline(ss,l_titulo, '|');
                    titulo_= l_titulo;
                    std::getline(ss,l_descripcion, '|');
                    descripcion_= l_descripcion;
                    std::getline(ss,l_precio, '|');
                    precio_= l_precio;
                    std::getline(ss,l_aforo, '|');
                    aforomax_= l_aforo;
                    std::getline(ss,l_carrera, '|');
                    carrera_= l_arrera;
                    DataAct.close();
                    return true;
                }
            }
        }
        DataAct.close();
        return false;
    }
    return false;
}

bool RellenarDatosCom(int id_act){
    std::ifstream DataAct("../BD/comunicacion.txt");
    if(DataAct.is_open()){
        std::string linea;
        std::getline(DataAct,linea);
        while(std::getline(DataAct,linea)){
            std:istringstream ss(linea);
            std::string l_titulo, l_descripcion;
            float l_precio;
            int l_aforomax, l_identific;
            if(std::getline(ss, l_identific, '|')){
                if(l_identific==id_act){
                    id_=id_act;
                    std::getline(ss,l_titulo, '|');
                    titulo_= l_titulo;
                    std::getline(ss,l_descripcion, '|');
                    descripcion_= l_descripcion;
                    std::getline(ss,l_precio, '|');
                    precio_= l_precio;
                    std::getline(ss,l_aforo, '|');
                    aforomax_= l_aforo;
                    DataAct.close();
                    return true;
                }
            }
        }
        DataAct.close();
        return false;
    }
    return false;
}