#include "director_acad.h"
#include "usuario.h"
#include "act_academica.h"
#include "lista_asistencia.h"
#include "mailing.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
    
    //Constructor
    Director_Acad::Director_Acad(std::string correo, std::string password)
    {
    SetCorreo(correo);
    SetPassword(password);
    SetRol(2);
    SetCarrera("nada");
    }
    //Funcion para ver las actividades pendientes
    bool Director_Acad::VerActPen()
    {
        std::ifstream DataComunicacion("src/BD/comunicacion.txt");
        int contador=0;

        if (!DataComunicacion.is_open())
        {
            std::cerr << "Error al abrir el archivo 'comunicacion.txt'\n";
            return false;
        }

        std::string linea;

        std::cout << "\n                            ACTIVIDADES PENDIENTES   \n";

        while (std::getline(DataComunicacion, linea))
        {
            std::cout << linea << "\n";
            contador++;
        }
        std::cout << "\n";
        DataComunicacion.close();
        if(contador<2){
            return false;
        }
        else{
            return true;
        }
    }

    
    bool  Director_Acad::ConfirmarAct(int id_act)
    {
        Act_academica a1;
       bool var= a1.EliminarActCom(id_act);
        if(var)
        {
            a1.ImprimirFAc();
        }
        
        return var;
    }

 bool Director_Acad::VerSolicitudes(std::string correo) 
    {
        std::ifstream DataMail("src/BD/" + correo.erase(correo.length()-7) + ".txt");
        std::string linea_1;
        bool fnd= false;
        if (!DataMail.is_open()){
            std::cerr << "Error al abrir el archivo 'datamail.txt' " << "\n";
            return false;
        }
        std::cout << "\nSolicitudes de inscripción pendientes de " << correo << "\n";
        std::getline(DataMail,linea_1);
        std::cout<<linea_1<<"\n";
        //Imprimimos el contenido de los fichero de los correos sin el @uco.es y comprobamos los estados
        while (std::getline(DataMail,linea_1))
        {
           std::istringstream iss2(linea_1);
           std::string id;
           iss2.ignore(1);
           std::getline(iss2,id,'|');
           std::string titulo;
           std::getline(iss2,titulo,'|');
           std::string estado;
           std::getline(iss2,estado,'|');
           if (estado=="inscrito_en_espera")
           {
                std::cout<<linea_1<<"\n";
                fnd= true;
           }
        }
        std::cout <<"\n";
        DataMail.close();
        return fnd;
    }

    bool Director_Acad::ConfirmarInscripcion(std::string correo, int id_act) {
        std::string correo_dominio=correo;
        std::string direccion=("src/BD/" + correo.erase(correo.length()-7) + ".txt");
        //Abrimos los archivos del correo sin el @uco.es y creamos un fichero temporal para guardar los datos
        std::ifstream DataMail(direccion);
        std::ofstream DataTemp("src/BD/temp.txt");

        if (!DataMail.is_open()) {
            std::cerr << "Error al abrir el archivo 'datamail.txt' " << "\n";
            return false;
        }

        if (!DataTemp.is_open()) {
            std::cerr << "Error al abrir el archivo temporal 'temp.txt'\n";
            DataMail.close();
            return false;
        }

        std::string linea_1;
        bool fnd = false;

        std::getline(DataMail, linea_1);
        DataTemp<<linea_1;
        // Leer y procesar cada línea del archivo
        while (std::getline(DataMail, linea_1)) {
            std::istringstream iss(linea_1);
            std::string id_str;
            iss.ignore(1);
            std::getline(iss,id_str,'|');
            int id=std::stoi(id_str);
            std::string titulo;   
            std::getline(iss,titulo,'|');
            std::string estado;
            std::getline(iss,estado,'|');

            if(id_act == id && estado=="inscrito_en_espera") {
                // Encontramos la línea correspondiente a la actividad
                // Actualizar el estado a "Inscripcion"
                DataTemp << "\n|"<<id_act << "|" << titulo << "|" <<"inscrito|";
                fnd = true;
            } 
            else {
                DataTemp << "\n" <<linea_1 ;
            }
        }

        DataMail.close();
        DataTemp.close();

        // Verificar si se encontró y actualizó la actividad
        if (!fnd) {
            std::remove("src/BD/temp.txt");  // Eliminar el archivo temporal
            return fnd;
        }

        // Renombrar el archivo temporal al archivo original
        std::remove(direccion.c_str());
        std::rename("src/BD/temp.txt",direccion.c_str());

        // Añadir al alumno en listaasistencia.txt
        Lista_asistencia l1;
        return l1.AnadirAlumno(id_act, correo_dominio);
    }
  

bool Director_Acad::EnviarAct(int id_act){
    Mailing M;
    M.AlmacenarFAc(id_act);
    std::ifstream DataCuentas("src/BD/cuentas.txt");
    if(!DataCuentas.is_open()){
        std::cout<<"Error al intentar abrir el fichero de 'cuentas.txt'\n";
        return false;
    }
    std::string linea;
    std::getline(DataCuentas,linea);
    while(std::getline(DataCuentas,linea)){
        std::istringstream ss(linea);
        ss.ignore(1);
        std::string correo;
        std::getline(ss,correo,'|');
        M.EnviarCorreo(correo);
    }
    DataCuentas.close();

    std::ofstream ListData("src/BD/ListaAsistencia.txt",std::ios::app);
    if(!ListData.is_open()){
        std::cout<<"Ha ocurrido un error intentando leer el fichero 'ListaAsistencia.txt'\n";
        return false;
    }
    Act_academica A;
    A.RellenarDatosFAc(id_act);
    ListData<<"\n|"<<id_act<<"|"<<A.GetAforoMax()<<"|"<<" |";
    ListData.close();
    return true;
}