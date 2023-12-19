//alumno.cc
//Aqui estan las funciones de alumno

#include "usuario.h"
#include "alumno.h"
#include "act_academica.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

Alumno::Alumno(std::string correo, std::string password, std::string carrera){
    SetCorreo(correo);
    SetPassword(password);
    SetRol(1);
    SetCarrera(carrera);
}

void Alumno::VerBandeja(){
    std::string correo= GetCorreo();
    correo.erase(correo.length()-7);
    correo = "src/BD/" + correo + ".txt";
    std::string linea;
    std::cout<<"\n";
    std::ifstream DataMail(correo);
    if(DataMail.is_open()){
        while(std::getline(DataMail,linea)){
            std::cout<<linea<<"\n";
        }
    }
    DataMail.close();
}

bool Alumno::VerDetalles(int id_act){
    std::string correo= GetCorreo();
    correo.erase(correo.length()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo.c_str());
    std::string linea, id_str;
    int id;
    bool fnd= false;
    std::getline(DataMail,linea);
    while(std::getline(DataMail,linea)){
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss,id_str,'|');
        id= std::stoi(id_str);
        if(id==id_act){
            fnd= true;
        }
    }

    DataMail.close();
    
    if(fnd){
        Act_academica A1;
        A1.RellenarDatosFAc(id_act);
        A1.ImprimirDatos();
    }
    return fnd;
}

bool Alumno::VerPreInscrip(){
    std::string correo= GetCorreo();
    correo.erase(correo.length()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo.c_str());
    int contador = 0;
    if(!DataMail.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataMail, linea);
    while(std::getline(DataMail, linea)){
        // Suponemos que el formato del archivo es "|IdActividad|Titulo|Estado|"
        std::istringstream ss(linea);
        ss.ignore(1);
        std::string id_str;
        std::getline(ss,id_str,'|');
        int id= std::stoi(id_str);
        std::string estado = "preinscrito";
        std::string l_estado;
        std::getline(ss,l_estado,'|');
        std::getline(ss,l_estado,'|');

        if(l_estado== estado){ 
            std::ifstream DataAct("src/BD/ActAcademicas.txt");
            if(!DataAct.is_open()) {
                std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
                return false;
            }
            std::string linea_1;
            std::getline(DataAct, linea_1);
            if(contador==0){
                std::cout<<"\n                                MIS PREINSCRIPCIONES\n";
                std::cout<<linea_1;
            }
            while(std::getline(DataAct, linea_1)) {
                std::istringstream ss1(linea_1);
                ss1.ignore(1);
                std::string id_str;
                std::getline(ss1, id_str, '|');
                int id_comprobar= std::stoi(id_str);
                if(id == id_comprobar){
                    std::cout << "\n" <<linea_1;
                    contador++;
                }
            }
            DataAct.close();
        }
    }
    DataMail.close();
    std::cout<<"\n\n";
    if(contador == 0){
        return false;
    }
    else{
        return true;
    }
}

bool Alumno::VerInscrip(){
    std::string correo= GetCorreo();
    correo.erase(correo.length()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo.c_str());
    int contador = 0;
    if(!DataMail.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataMail, linea);
    while(std::getline(DataMail, linea)){
        // Suponemos que el formato del archivo es "|IdActividad|Titulo|Estado|"
        std::istringstream ss(linea);
        ss.ignore(1);
        std::string id_str;
        std::getline(ss,id_str,'|');
        int id= std::stoi(id_str);
        std::string estado_1 = "inscrito";
        std::string estado_2= "inscrito_en_espera";
        std::string l_estado;
        std::getline(ss,l_estado,'|');
        std::getline(ss,l_estado,'|');

        if(l_estado== estado_1 || l_estado== estado_2){ 
            std::ifstream DataAct("src/BD/ActAcademicas.txt");
            if(!DataAct.is_open()) {
                std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
                return false;
            }
            std::string linea_1;
            std::getline(DataAct, linea_1);
            if(contador==0){
                std::cout<<"\n                                  MIS INSCRIPCIONES\n";
                std::cout<<linea_1;
            }
            while(std::getline(DataAct, linea_1)) {
                std::istringstream ss1(linea_1);
                ss1.ignore(1);
                std::string id_str;
                std::getline(ss1, id_str, '|');
                int id_comprobar= std::stoi(id_str);
                if(id == id_comprobar){
                    std::cout << "\n" <<linea_1;
                    contador++;
                }
            }
            DataAct.close();
        }
    }
    DataMail.close();
    std::cout<<"\n\n";
    if(contador == 0){
        return false;
    }
    else{
        return true;
    }
}

std::string Alumno::VerEstadoAct(int id_act){
    std::string id_str;
    std::string correo;
    std::string estado;
    correo = GetCorreo();
    correo.erase(correo.length()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo.c_str());
    if (!DataMail.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return estado;
    }
    std::string linea;
    std::getline(DataMail, linea);
    while (std::getline(DataMail, linea)) {
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss, id_str, '|');
        int id_actacademica = std::stoi(id_str); 
        if(id_actacademica == id_act){
            size_t primera_pos = linea.find('|');
            size_t segunda_pos = linea.find('|', primera_pos + 1);
            size_t tercera_pos = linea.find('|', segunda_pos + 1);
            size_t cuarta_pos = linea.find('|', tercera_pos + 1);
            size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
            estado = linea.substr(tercera_pos + 1, longitud_cadena);
            DataMail.close();
            return estado;
        }
    }
    estado= "No existe esta actividad en la bandeja";
    DataMail.close();
    return estado;
}

bool Alumno::CambiarEstado(int state, int id_act){
    std::string correo;
    bool fnd = false;
    correo = GetCorreo();
    correo.erase(correo.length()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo.c_str());
    std::ofstream DataAux("src/BD/aux.txt");
    if(!DataMail.is_open() || !DataAux.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataMail, linea);
    DataAux << linea;
    while (std::getline(DataMail, linea)) {
        std::istringstream ss(linea);
        std::string id_str;
        std::string titulo;
        std::string estado;
        ss.ignore(1);
        std::getline(ss, id_str, '|'); 
        int id = std::stoi(id_str);
        if(id == id_act){
            std::getline(ss, titulo, '|');
            switch (state){
                case 0: 
                    estado = "nada";
                    break;
                case 1:
                    estado = "preinscrito";
                    break;    
                case 2:                 
                    estado = "inscrito_en_espera";
                    break;
            }
            DataAux << "\n|" << id << "|" << titulo << "|" << estado << "|";
            fnd = true;
        }
        else{
            DataAux << "\n" << linea;
        }
    }
    DataMail.close();
    DataAux.close();
    remove(correo.c_str());
    rename("src/BD/aux.txt", correo.c_str());
    return fnd;
}

bool Alumno::RellenarF(std::string correo){
    std::ifstream DataCuentas("src/BD/cuentas.txt");
    if (!DataCuentas.is_open()) {
        std::cout << "Error al abrir el archivo de cuentas." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataCuentas, linea);
    while (std::getline(DataCuentas, linea)) {
        std::istringstream ss(linea);
        ss.ignore(1);
        std::string correo_comprobar;
        std::getline(ss, correo_comprobar, '|');
        if(correo_comprobar == correo){
            SetCorreo(correo_comprobar);
            std::string password;
            std::getline(ss, password, '|');
            SetPassword(password);
            std::string rol_string;
            std::getline(ss, rol_string, '|');
            int rol_int = std::stoi(rol_string);
            SetRol(rol_int);
            std::string carrera;
            std::getline(ss, carrera, '|');
            SetCarrera(carrera);
            return true;
        }    
    }              
}

std::vector<int> Alumno::VectorIdsInscrip(){
    std::vector<int> vec_int;
    std::string id_str;
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.length()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo);
    if (!DataMail.is_open()){
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return vec_int;
    }
    std::string linea;
    std::getline(DataMail, linea);
    while (std::getline(DataMail, linea)) {
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss, id_str, '|');
        int id_actacademica = std::stoi(id_str); 
        size_t primera_pos = linea.find('|');
        size_t segunda_pos = linea.find('|', primera_pos + 1);
        size_t tercera_pos = linea.find('|', segunda_pos + 1);
        size_t cuarta_pos = linea.find('|', tercera_pos + 1);
        size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
        std::string estado = linea.substr(tercera_pos + 1, longitud_cadena);
        if(estado == "inscrito_en_espera"){
            vec_int.push_back(id_actacademica);
        }
    }
    DataMail.close();
    return vec_int;
}