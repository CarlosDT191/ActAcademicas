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
        std::cout << "Introduzca su correo (todo en minúscula): ";
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
            std::cout << "El formato del correo consta de 15 caracteres, los ultimos 7 son @uco.es \n ¿Que desea hacer? \n 1. Continuar con login \n 2. Salir"<< std::endl;
            std::cin >> error;
        }
    }
}

// register: comprobar que esta bien el formato, 2 veces la contraseña, carrera, correo, tiene que poder seleccionar el rol.

bool Usuario::Register(){
    std::string correo;
    std::string password;
    int rol = 0;
    std::string carrera;
    std::string password_comprobar;
    int error = 0;
    while(error != 2){
        //Introducir correo
        std::cout << "Introduzca su correo (todo en minúscula):" << std::endl;
        std::cin >> correo;
        if (correo.size() == 15 && correo.compare(correo.size()-7, 7, "@uco.es") == 0){
            std::cout << "Introduzca su contraseña:\n"
            std::cin >> password;
            std::cout << "Vuelva a introducir su contraseña para comprobar: \n";
            std::cin >> password_comprobar;
            for(int i = 0; i < 3; i++){
                if (password == password_comprobar){
                    do{
                        correo_ = correo;
                        password_ = password;
                        std::cout << "Introduzca su rol (1 = Alumno, 2 = Director Académico, 3 = Organizador)\n";
                        std::cin >> rol;
                    }while (rol != 1 || rol != 2 || rol != 3);
                    rol_ = rol;
                    switch(rol){
                        case 1: 
                            do{
                                std::cout << "Introduce tu carrera (Elegir entre: informatica, forestal, mecanica, electronica. SIN TILDES. TODO MINUSCULA)" << std::endl;
                                std::cin >> carrera;
                            }while(carrera != informatica || carrera != forestal || carrera != mecanica || carrera != electronica);
                        break;
                        case 2:
                            carrera = "nada";
                        break;
                        case 3: 
                            carrera = "nada";
                        break;
                        default: "Ese rol no existe" << std::;
                    }
                    carrera_ = carrera;
                    //Abrir archivo de cuentas
                    std::ofstream cuentasFile("../BD/cuentas.txt", std::ios::app);            
                    if (cuentasFile.is_open()) {
                        // Realiza operaciones de escritura en el archivo
                        cuentasFile << correo_ << "|" << password_ << "|" << rol_ << "|" << carrera_ << "|" << std::endl;
                        // Cierra el archivo después de realizar las operaciones
                        cuentasFile.close();
                        return true;
                    } else {
                        // Maneja la situación en la que no se pudo abrir el archivo
                        return false;
                    }
                }
                else{
                    std::cout << "La contraseña inicial es distinta, intentalo de nuevo. Quedan " << 2-i << " intentos." << std::endl;
                }                
            }
            return false;
 
        }
        else{
            std::cout << "El formato del correo consta de 15 caracteres, los ultimos 7 son @uco.es \n ¿Que desea hacer? \n 1. Continuar con register \n 2. Salir"<< std::endl;
            std::cin >> error;
        }
    }
    return false;
}











        //Abrir archivo de cuentas
        std::ofstream cuentasFile("../BD/cuentas.txt", std::ios::app);            
        if (cuentasFile.is_open()) {
            // Realiza operaciones de escritura en el archivo
            cuentasFile << "Nuevo contenido a añadir\n";
        
            // Cierra el archivo después de realizar las operaciones
            cuentasFile.close();
        } else {
            // Maneja la situación en la que no se pudo abrir el archivo
            std::cerr << "No se pudo abrir el archivo." << std::endl;
        }
    
