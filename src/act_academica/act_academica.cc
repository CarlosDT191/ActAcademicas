#include "act_academica.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Act_academica::Act_academica(int id_act){
    id_=id_act;
}

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
    int aforomax, valor=1, fin=0;
    while(valor!=5){
        switch(valor){
            case 1:
                std::cout<<"Introduzca el titulo de la actividad:\n";
                std::cin>>titulo;
                titulo_= titulo;
                if(valor==1 && fin!=0){
                    break;
                }
            case 2:
                std::cout<<"\nIntroduzca una breve descripcion:\n";
                std::cin>>descripcion;
                descripcion_=descripcion;
                if(valor!=1){
                    break;
                }
            case 3:
                std::cout<<"\nIntroduzca el precio de la actividad:\n";
                std::cin>>precio;
                precio_=precio;
                if(valor!=1){
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
            std::cout<<" 3. Editar precio\n 4. Editar aforo maximo\n 5. Guardar cambios\n";
            std::cin>>valor;
            fin= 1;
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
                    ss.ignore(1,'|');
                    std::getline(ss,l_titulo, '|');
                    titulo_= l_titulo;
                    ss.ignore(1,'|');
                    std::getline(ss,l_descripcion, '|');
                    descripcion_= l_descripcion;
                    ss.ignore(1,'|');
                    std::getline(ss,l_precio, '|');
                    precio_= l_precio;
                    ss.ignore(1,'|');
                    std::getline(ss,l_aforo, '|');
                    aforomax_= l_aforo;
                    ss.ignore(1, '|');
                    std::getline(ss,l_carrera, '|');
                    carrera_= l_carrera;
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

bool RellenarDatosFCom(int id_act){
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
                    ss.ignore(1,'|');
                    std::getline(ss,l_titulo, '|');
                    titulo_= l_titulo;
                    ss.ignore(1,'|');
                    std::getline(ss,l_descripcion, '|');
                    descripcion_= l_descripcion;
                    ss.ignore(1,'|');
                    std::getline(ss,l_precio, '|');
                    precio_= l_precio;
                    ss.ignore(1,'|');
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

void Act_academica::ImprimirFAc(){
    std::ifstream DataAct("../BD/ActAcademicas.txt");
    std::string linea;
    if(DataAct.is_open()){
        std::getline(DataAct, linea);
        std::cout<<linea<<"\n";
    }
}

bool Act_academica::ModificarActF(std::string direccion){
    std::fstream DataAct(direccion);
    std::string linea;
    std::getline(DataAct,linea)
    while(std::getline(DataAct,linea)){
        std:istringstream ss(linea);
        int id;
        ss.ignore(1);
        std::getline(ss, id, '|');
        if(id_==id){
            ss.str("");
            ss<<<<"|"<<id_<<"|"<<titulo_<<"|"<<descripcion_<<"|"<<precio_<<"|"<<aforomax_<<"|"<<carrera_<<"|";
            DataAct.seekp(DataAct.tellg());
            DataAct<<ss;
            DataAct.close();
            return true;
        }
    }
    DataAct.close();
    return false;
}