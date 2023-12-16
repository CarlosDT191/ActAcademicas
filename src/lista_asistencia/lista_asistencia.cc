//lista_asistencia.cc
//Aqui estan las funciones de lista de asistencia (agregar alumno, eliminar alumno, leer y mostrar lista de asistencia)

#include "lista_asistencia.h"
#include "alumno.h"
#include <fstream>
#include <iostream>
#include <sstream>


bool Lista_asistencia::RecogerListaAct(int id_act){
    std::istream ListData("../BD/ListaAsistencia.txt");
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
            std::string aforo_str;
            std::getline(ss,aforo_str,'|');
            aforo_restante_= std::stoi(aforo_str);
            std::string nombre_prov;
            while(ss>>nombre_prov){
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

    std::ifstream ListData("../BD/ListaAsistencia.txt");
    std::ofstream DataAux("../BD/aux.txt");
    std::string linea;

    if(!(ListData.is_open()) || !(DataAux.is_open())){
        std::cout<<"Error al abrir el fichero de lista de asistencia\n";
        return false;
    }

    while(std::getline(ListData,linea)){
        std::istringstream iss(linea);
        iss.ignore(1);
        int id_prov;
        std::getline(iss, id_prov);
        if(id_prov!= id_act_){
            DataAux<<linea<<"\n";
        }
        else{
            DataAux<<"|"<<id_act_<<"|"<<aforo_restante_<<"|";
            for(auto j : vec_alum_){
                DataAux<<j<<" ";
            }
            DataAux<<"\n";
        }
    }
    
    DataAux.close();
    ListData.close();

    remove("../BD/ListaAsistencia.txt");
    rename("../BD/aux.txt","../BD/ListaAsistencia.txt");
    return true;
}








// En vez de actualizar el fichero, se actualiza el vector de correos y lo metes directo en esa parte
/*Crear una funcion booleana (true/false), donde se abra el fichero en modo lectura, cambiar modo escritura
y escribo (preguntar primo), tiene que ir linea por linea y comparar el id de la actividad académica
(este numero lo obtenemos de otra funcion) con el que hay en el fichero, una vez coincidan, tienes que meterlo en el
ultimo apartado como si fuera un vector de nombres.*/



