//lista_asistencia.cc
//Aqui estan las funciones de lista de asistencia (agregar alumno, eliminar alumno, leer y mostrar lista de asistencia)

#include "lista_asistencia.h"
#include <fstream>
#include <iostream>
#include <sstream>


bool Lista_asistencia::RecogerListaAct(int id_act){
    std::ifstream ListData("src/BD/ListaAsistencia.txt");
    std::string linea;
    std::getline(ListData, linea);
    while(std::getline(ListData, linea)){
        std::istringstream ss(linea);
        ss.ignore(1);
        std::string id_A_str;
        std::getline(ss,id_A_str,'|');
        int id_A= std::stoi(id_A_str);
        if(id_act==id_A){
            id_act_= id_A;
            std::string aforo_str, nombres;
            std::getline(ss,aforo_str,'|');
            aforo_restante_= std::stoi(aforo_str);
            std::getline(ss,nombres,'|');
            std::string nombre_prov;
            std::istringstream ss2(nombres);
            vec_alum_.clear();
            while(std::getline(ss2,nombre_prov,' ')){
                vec_alum_.push_back(nombre_prov);
            }
            ListData.close();
            return true;
        }
    }
    ListData.close();
    return false;
}


bool Lista_asistencia::AnadirAlumno(int id_act, std::string correo){
    RecogerListaAct(id_act);
    aforo_restante_--;
    vec_alum_.push_back(correo);

    std::ifstream ListData("src/BD/ListaAsistencia.txt");
    std::ofstream DataAux("src/BD/aux.txt");
    std::string linea;

    if(!(ListData.is_open()) || !(DataAux.is_open())){
        std::cout<<"Error al abrir el fichero de lista de asistencia\n";
        return false;
    }

    std::getline(ListData,linea);
    DataAux<<linea;
    while(std::getline(ListData,linea)){
        std::istringstream iss(linea);
        iss.ignore(1);
        std::string id_str;
        std::getline(iss, id_str);
        int id_prov= std::stoi(id_str);
        if(id_prov!= id_act_){
            DataAux<<"\n"<<linea;
        }
        else{
            DataAux<<"\n|"<<id_act_<<"|"<<aforo_restante_<<"|";
            for(auto j : vec_alum_){
                DataAux<<j<<" ";
            }
            DataAux<<"|";
        }
    }
    
    DataAux.close();
    ListData.close();

    remove("src/BD/ListaAsistencia.txt");
    rename("src/BD/aux.txt","src/BD/ListaAsistencia.txt");
    return true;
}