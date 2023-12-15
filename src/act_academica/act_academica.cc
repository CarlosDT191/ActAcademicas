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
        std::string linea1;
        std::streampos posIn1= DataAct.tellg();
        DataAct.seekg(0,std::ios::end);
        std::streampos posFin1= DataAct.tellg();
        std::streamsize finArchivo1= posFin1-posIn1;
        DataAct.seekg(-finArchivo1,std::ios::end);
        while(std::getline(DataAct, linea1)){
            std::istringstream ss1(linea1);
            ss1.ignore(1);
            int idef_a;
            std::getline(ss1,idef_a,'|');
        }
        DataAct.close();
    }
    std::ifstream DataCom("../BD/comunicacion.txt");
    if(DataCom.is_open()){
        std::string linea2;
        std::streampos posIn2= DataCom.tellg();
        DataCom.seekg(0,std::ios::end);
        std::streampos posFin2= DataCom.tellg();
        std::streamsize finArchivo2= posFin2-posIn2;
        DataCom.seekg(-finArchivo2,std::ios::end);
        while(std::getline(DataCom, linea2)){
            std::istringstream ss2(linea2);
            ss2.ignore(1);
            int idef_c;
            std::getline(ss2,idef_c,'|');
        }
        DataCom.close();
    }

    if(idef_c >= idef_a){
        idef_c++;
        id_= idef_c;
    }
    else{
        idef_a++;
        id_= idef_a;
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
                std::cout<<"Introduzca una breve descripcion:\nDebe incluir ponentes, fecha, ubicacion y más detalles\n";
                std::cin>>descripcion;
                descripcion_=descripcion;
                if(valor!=1){
                    break;
                }
            case 3:
                std::cout<<"Introduzca el precio de la actividad:\n";
                std::cin>>precio;
                precio_=precio;
                if(valor!=1){
                    break;
                }
            case 4:
                std::cout<<"Introduzca el aforo maximo de la actividad:\n";
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


bool Act_academica::RellenarDatosFAc(int id_act){
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
                    ss.ignore(1);
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

bool Act_academica::RellenarDatosFCom(int id_act){
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
                    ss.ignore(1);
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

bool Act_academica::ModificarActF(std::string direccion){
    std::fstream DataAct(direccion);
    std::string linea;
    std::getline(DataAct,linea);
    while(std::getline(DataAct,linea)){
        std:istringstream ss(linea);
        int id;
        ss.ignore(1);
        std::getline(ss, id, '|');
        if(id_==id){
            ss.str("");
            ss<<<<"|"<<id_<<"|"<<titulo_<<"|"<<descripcion_<<"|"<<precio_<<"|"<<aforomax_<<"|"<<carrera_<<"|\n";
            DataAct.seekp(DataAct.tellg());
            DataAct<<ss;
            DataAct.close();
            return true;
        }
    }
    DataAct.close();
    return false;
}

void Act_academica::ImprimirDatos(){
    std::cout<<"ACT ACADEMICA ID= "<<id_<<"\n";
    std::cout<<"TITULO: "<<titulo_<<"\n";
    std::cout<<"DESCRIPCION: \n"<<descripcion_<<"\n";
    std::cout<<"PRECIO: "<<precio_<<"\n";
    std::cout<<"AFORO: "<<aforomax_<<"\n";
    std::cout<<"TITULO: "<<carrera_<<"\n";
}