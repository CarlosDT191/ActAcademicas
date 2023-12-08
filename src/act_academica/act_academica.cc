#include "act_academica.h"
#include <fstream>
#include <iostream>
#include <sstream>

Act_academica::act_academica(std::string titulo, std::string descripcion, float precio, int aforomax){
    titulo_=titulo;
    descripcion_=descripcion;
    precio_= precio;
    aforomax_=aforomax;
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