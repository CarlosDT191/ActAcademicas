//alumno.cc
//Aqui estan las funciones de alumno

#include "usuario.h"
#include "alumno.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

void Alumno::verDetalles(int id_act){
    Act_academica A1;
    A1.RellenarDatosFAc(id_act);
    A1.ImprimirDatos();
}

bool Alumno::verInscrip(){
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo);
    int contador = 0;
    if (!DataMail.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataMail, linea);
    while (std::getline(DataMail, linea)) {
        // Suponemos que el formato del archivo es "|IdActividad|Titulo|Estado|"
        std::istringstream ss(linea);
        std::string l_estado = "inscrito";
        std::string k_estado = "inscrito en espera"
        std::string estado;
        std::string id_actacademica;
        size_t primera_pos = linea.find('|');
        size_t segunda_pos = linea.find('|', primera_pos + 1);
        size_t tercera_pos = linea.find('|', segunda_pos + 1);
        size_t cuarta_pos = linea.find('|', tercera_pos + 1);
        size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
        estado = linea.substr(tercera_pos + 1, longitud_cadena);
        if(l_estado = estado || k_estado = estado){
            ss.ignore(1); 
            std::getline(ss, id_actacademica, '|');
        }
        std::ifstream ActAcademicasFile("./BD/ActAcademicas.txt");
        if (!ActAcademicasFile.is_open()) {
            std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
            return false;
        }
        std::string linea_1;
        std::getline(ActAcademicasFile, linea_1);
        while (std::getline(ActAcademicasFile, linea_1)) {
            std::istringstream ss1(linea_1);
            ss1.ignore(1);
            std::getline(ss1, id_comprobar, '|');
            if(id_comprobar = id_actacademica){
                std::cout << linea_1 << std::endl;
                contador++;
            }
        }
        ActAcademicasFile.close();
    }
    DataMail.close();
    if(contador = 0){
        return false;
    }
    else{
        return true;
    }
}

bool Alumno::verPreInscrip(){
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo);
    int contador = 0;
    if (!DataMail.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataMail, linea);
    while (std::getline(DataMail, linea)) {
        // Suponemos que el formato del archivo es "|IdActividad|Titulo|Estado|"
        std::istringstream ss(linea);
        std::string l_estado = "preinscrito";
        std::string estado;
        std::string id_actacademica;
        size_t primera_pos = linea.find('|');
        size_t segunda_pos = linea.find('|', primera_pos + 1);
        size_t tercera_pos = linea.find('|', segunda_pos + 1);
        size_t cuarta_pos = linea.find('|', tercera_pos + 1);
        size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
        estado = linea.substr(tercera_pos + 1, longitud_cadena);
        if(l_estado = estado){
            ss.ignore(1); 
            std::getline(ss, id_actacademica, '|');
        }
        std::ifstream ActAcademicasFile("./BD/ActAcademicas.txt");
        if (!ActAcademicasFile.is_open()) {
            std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
            return false;
        }
        std::string linea_1;
        std::getline(ActAcademicasFile, linea_1);
        while (std::getline(ActAcademicasFile, linea_1)) {
            std::istringstream ss1(linea_1);
            ss1.ignore(1);
            std::getline(ss1, id_comprobar, '|');
            if(id_comprobar = id_actacademica){
                std::cout << linea_1 << std::endl;
                contador++;
            }
        }
        ActAcademicasFile.close();
    }
    DataMail.close();
    if(contador = 0){
        return false;
    }
    else{
        return true;
    }
}

std::string Alumno::verEstadoAct(int id_act){
    std::string id_str;
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo);
    if (!DataMail.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataMail, linea);
    while (std::getline(DataMail, linea)) {
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss, id_str, '|');
        int id_actacademica = std::stoi(id_str); 
        if(id_actacademica = id_act){
            size_t primera_pos = linea.find('|');
            size_t segunda_pos = linea.find('|', primera_pos + 1);
            size_t tercera_pos = linea.find('|', segunda_pos + 1);
            size_t cuarta_pos = linea.find('|', tercera_pos + 1);
            size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
            std::string estado = linea.substr(tercera_pos + 1, longitud_cadena);
            DataMail.close();
            return estado;
        }
    }
    DataMail.close();
}

bool Alumno::CambiarEstado(int state, int id_act){
    std::string correo;
    bool fnd = false;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo);
    std::ofstream DataAux("src/BD/aux.txt");
    if (!DataMail.is_open() || !DataAux.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(DataMail, linea);
    DataAux << linea;
    while (std::getline(DataMail, linea)) {
        std::istringstream ss(linea);
        std::string id_str;
        std::string estado;
        std::string titulo;
        ss.ignore(1);
        std::getline(ss, id_str, '|'); 
        int id_actacademica = std::stoi(id_str);
        if(id_actacademica = id_act){
            std::getline(ss, titulo, '|');
            switch (state){
                case 0: 
                    estado = "preinscrito";
                    break;
                case 1:
                    estado = "nada";
                    break;    
                case 2:                 
                    estado = "inscrito_en_espera";
                    break;
            }
            DataAux << "\n|" << id_actacademica << "|" << titulo << "|" << estado << "|";
            fnd = true;
        }
        else{
            DataAux << "\n" << linea;
        }
    }
    DataMail.close();
    DataAux.close();
    remove(correo);
    rename("src/BD/aux.txt", correo);
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
        std::getline(ss, correo_comprobar, '|');
        if(correo_comprobar = correo){
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
    correo.erase(correo.lenght()-7);
    correo = "src/BD/" + correo + ".txt";
    std::ifstream DataMail(correo);
    if (!DataMail.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
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
        if(estado = "inscrito_en_espera"){
            vec_int.push_back(id_actacademica);
        }
    }
    DataMail.close();
    return vec_int;
}
