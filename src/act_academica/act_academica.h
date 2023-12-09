#ifndef ACTACADEMICA_H
#define ACTACADEMICA_H
#include "lista_asistencia.h"
#include <iostream>
#include <string>

class Act_academica{
    private:
        int id_;
        std::string titulo_;
        std::string descripcion_;
        std::string carrera_;
        float precio_;
        int aforomax_;
    public:
        //Getters
        int GetId(){return id_;}
        std::string GetTitulo(){return titulo_;}
        std::string GetDesc(){return descripcion_;}
        float GetPrecio(){return precio_;}
        int GetAforoMax(){return aforomax_;}
        //Setters
        void SetId();
        void SetCarrera(int carrera){carrera_=carrera;}
        //Funciones Propias
        void RellenarDatosT();//Recoge datos de la interfaz con el usuario y los guarda en la clase
        bool RellenarDatosFAc(int id_act);//Recoge los datos del del fichero ActAcademicas y los guarda en la clase
        bool RellenarDatosCom(int id_act);//Recoge los datos del fichero comunicacion y los guarda en la clase
};


#endif