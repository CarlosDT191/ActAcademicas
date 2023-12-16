//alumno.cc
//Aqui estan las funciones de alumno

#include "usuario.h"
#include "alumno.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

void verDetalles(int id_act){
    Act_academica A1;
    A1.RellenarDatosFAc(id_act);
    A1.ImprimirDatos();
}

bool verInscrip(){
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "../BD/" + correo + ".txt";
    std::ifstream BandejaPersonalFile(correo);
    int contador = 0;
    if (!BandejaPersonalFile.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string line;
    std::getline(BandejaPersonalFile, line);
    while (std::getline(BandejaPersonalFile, line)) {
        // Suponemos que el formato del archivo es "|IdActividad|Titulo|Estado|"
        std::istringstream ss(line);
        std::string l_estado = "inscrito";
        std::string k_estado = "inscrito en espera"
        std::string estado;
        std::string id_actacademica;
        size_t primera_pos = line.find('|');
        size_t segunda_pos = line.find('|', primera_pos + 1);
        size_t tercera_pos = line.find('|', segunda_pos + 1);
        size_t cuarta_pos = line.find('|', tercera_pos + 1);
        size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
        estado = line.substr(tercera_pos + 1, longitud_cadena);
        if(l_estado = estado || k_estado = estado){
            ss.ignore(1); 
            std::getline(ss, id_actacademica, '|');
        }
        std::ifstream ActAcademicasFile("./BD/ActAcademicas.txt");
        if (!ActAcademicasFile.is_open()) {
            std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
            return false;
        }
        std::string linea;
        std::getline(ActAcademicasFile, linea);
        while (std::getline(ActAcademicasFile, linea)) {
            std::istringstream ss1(linea);
            ss1.ignore(1);
            std::getline(ss1, id_comprobar, '|');
            if(id_comprobar = id_actacademica){
                std::cout << linea << std::endl;
                contador++;
            }
        }
        ActAcademicasFile.close();
    }
    BandejaPersonalFile.close();
    if(contador = 0){
        return false;
    }
    else{
        return true;
    }
}

bool verPreInscrip(){
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "../BD/" + correo + ".txt";
    std::ifstream BandejaPersonalFile(correo);
    int contador = 0;
    if (!BandejaPersonalFile.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string line;
    std::getline(BandejaPersonalFile, line);
    while (std::getline(BandejaPersonalFile, line)) {
        // Suponemos que el formato del archivo es "|IdActividad|Titulo|Estado|"
        std::istringstream ss(line);
        std::string l_estado = "preinscrito";
        std::string estado;
        std::string id_actacademica;
        size_t primera_pos = line.find('|');
        size_t segunda_pos = line.find('|', primera_pos + 1);
        size_t tercera_pos = line.find('|', segunda_pos + 1);
        size_t cuarta_pos = line.find('|', tercera_pos + 1);
        size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
        estado = line.substr(tercera_pos + 1, longitud_cadena);
        if(l_estado = estado){
            ss.ignore(1); 
            std::getline(ss, id_actacademica, '|');
        }
        std::ifstream ActAcademicasFile("./BD/ActAcademicas.txt");
        if (!ActAcademicasFile.is_open()) {
            std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
            return false;
        }
        std::string linea;
        std::getline(ActAcademicasFile, linea);
        while (std::getline(ActAcademicasFile, linea)) {
            std::istringstream ss1(linea);
            ss1.ignore(1);
            std::getline(ss1, id_comprobar, '|');
            if(id_comprobar = id_actacademica){
                std::cout << linea << std::endl;
                contador++;
            }
        }
        ActAcademicasFile.close();
    }
    BandejaPersonalFile.close();
    if(contador = 0){
        return false;
    }
    else{
        return true;
    }
}

std::string verEstadoAct(int id_act){
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "../BD/" + correo + ".txt";
    std::ifstream BandejaPersonalFile(correo);
    if (!BandejaPersonalFile.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(BandejaPersonalFile, linea);
    while (std::getline(BandejaPersonalFile, linea)) {
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss, id_actacademica, '|'); 
        if(id_actacademica = id_act){
            size_t primera_pos = linea.find('|');
            size_t segunda_pos = linea.find('|', primera_pos + 1);
            size_t tercera_pos = linea.find('|', segunda_pos + 1);
            size_t cuarta_pos = linea.find('|', tercera_pos + 1);
            size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
            std::string estado = linea.substr(tercera_pos + 1, longitud_cadena);
            return estado;
        }
    }
    BandejaPersonalFile.close();
}

bool CambiarEstado(int state, int id_act){
    std::string correo;
    correo = GetCorreo();
    correo.erase(correo.lenght()-7);
    correo = "../BD/" + correo + ".txt";
    std::fstream BandejaPersonalFile(correo, std::ios::in | std::ios::out);
    if (!BandejaPersonalFile.is_open()) {
        std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
        return false;
    }
    std::string linea;
    std::getline(BandejaPersonalFile, linea);
    while (std::getline(BandejaPersonalFile, linea)) {
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss, id_actacademica, '|'); 
        if(id_actacademica = id_act){
            size_t primera_pos = linea.find('|');
            size_t segunda_pos = linea.find('|', primera_pos + 1);
            size_t tercera_pos = linea.find('|', segunda_pos + 1);
            size_t cuarta_pos = linea.find('|', tercera_pos + 1);
            size_t longitud_cadena = cuarta_pos - tercera_pos - 1;
            switch (state){
                case 0: 
                    linea.erase(tercera_pos + 1, longitud_cadena);
                    linea.insert(tercera_pos + 1, "preinscrito");
                break;
                case 1:
                    linea.erase(tercera_pos + 1, longitud_cadena);
                    linea.insert(tercera_pos + 1, "nada");
                break;    
                case 2:                 
                    inea.erase(tercera_pos + 1, longitud_cadena);
                    linea.insert(tercera_pos + 1, "inscrito en espera");
                    break;
            }
            BandejaPersonalFile.seekp(0);
            BandejaPersonalFile << linea << std::endl;
            std::cout << "Estado modificado correctamente." << std::endl;
            break; //Ya la ha encontrado no necesita seguir buscando
        }
    }
    BandejaPersonalFile.close();
    return true;
}

bool RellenarF(std::string correo){
    std::ifstream BandejaPersonalFile(correo);
        int contador = 0;
        if (!BandejaPersonalFile.is_open()) {
            std::cout << "Error al abrir el archivo de la bandeja personal." << std::endl;
            return false;
        }
        std::string line;
        std::getline(BandejaPersonalFile, line);
        while (std::getline(BandejaPersonalFile, line)) {
                
}