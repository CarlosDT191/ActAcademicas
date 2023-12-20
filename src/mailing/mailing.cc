#include "mailing.h"
#include "alumno.h"
#include "usuario.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool Mailing::AlmacenarFAc(int id_act){
    std::ifstream DataAct("src/BD/ActAcademicas.txt");
    std::string linea, id_str, l_titulo, l_carrera;

    if(!DataAct.is_open()){
        std::cout<<"Error al abrir el fichero 'ActAcademicas.txt'\n";
        return false;
    }
    std::getline(DataAct,linea);
    while(std::getline(DataAct,linea)){
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss,id_str,'|');
        int id_prov= std::stoi(id_str);
        if(id_prov==id_act){
            id_act_m_= id_act;
            std::getline(ss,l_titulo,'|');
            titulo_act_= l_titulo;
            estado_= "nada";
            for(int i=0; i<6; i++){
                std::getline(ss,l_carrera,'|');
            }
            carrera_act_= l_carrera;
            DataAct.close();
            return true;
        }
    }
    DataAct.close();
    return false;
}


bool Mailing::EnviarCorreo(std::string correo){
    Alumno a1;
    a1.RellenarF(correo);
    if(a1.GetRol()==1){
        if(carrera_act_== a1.GetCarrera() || carrera_act_== "todas"){
            correo.erase(correo.length()-7);
            correo = "src/BD/" + correo + ".txt";
            std::ofstream DataMail(correo.c_str(),std::ios::app);
            if(!DataMail.is_open()){
                std::cout<<"Fallo al intentar abrir el correo personal\n";
                return false;
            }
            DataMail<<"\n|"<<id_act_m_<<"|"<<titulo_act_<<"|"<<estado_<<"|";
            DataMail.close();
            return true;
        }
    }
    return false;
}