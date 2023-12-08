//usuario.cc
//Aqui están las funciones de usuario

#include "usuario.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

bool Usuario::Login(){
    std::string correo;
    std::string password;
    int error = 0;
    while(error != 2){
        //Pedir el correo
        std::cout << "Introduzca tu correo: ";
        std::cin >> correo;
        if (correo.size() == 15 && correo.compare(correo.size()-7, 7, "@uco.es") == 0){
            correo_= correo;
            //Abrir el archivo de cuentas
            std::ifstream cuentasFile("../BD/cuentas.txt");
            if (!cuentasFile.is_open()) {
                std::cerr << "Error al abrir el archivo de cuentas." << std::endl;
                return false;
            }

            // Buscar el correo en el archivo
            std::string line;
            bool CorrectPassword = false;
            while (std::getline(cuentasFile, line)) {
                // Suponemos que el formato del archivo es "|Correo|Contraseña"
                std::istringstream ss(line);
                std::string l_correo;
                std::string l_password;
                ss.ignore(1); 
                std::getline(ss, l_correo, '|');
                if(l_correo == correo_){
                    std::getline(ss, l_password, '|');
                    for (int i = 0; i < 3 && CorrectPassword == false; i++){
                        std::cout <<"Escriba la contraseña:" << std::endl;
                        std::cin >>password;
                        if (l_password == password){
                            password_ = password;
                            std::getline(ss, rol_, '|');
                            std::getline(ss, carrera_, '|');
                            cuentasFile.close();
                            return true;
                        }
                        else {
                            std::cout <<"Tienes: " << 2-i << " intentos" << std::endl;
                        }
                    }
                    cuentasFile.close();
                    return false;
                }
            }
            cuentasFile.close();
            std::cout << "Usuario no encontrado" << std::endl;
            return false;
        }
        else{
            std::cout << "¿Que desea hacer? \n 1. Continuar con login \n 2. Salir"<< std::endl;
            std::cin >> error;
        }
    }
}

// register: comprobar que esta bien el formato, 2 veces la contraseña, carrera, correo.
