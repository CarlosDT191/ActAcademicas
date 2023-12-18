#ifndef ACTACADEMICA_H
#define ACTACADEMICA_H
#include <iostream>
#include <string>
#include <vector>

class Act_academica{
    private:
        int id_;
        std::string titulo_;
        std::vector<std::string> ponentes_;
        std::string fecha_;
        std::string ubicacion_;
        float precio_;
        int aforomax_;
        std::string carrera_;
    public:
        Act_academica(int id_act=0);
        //Getters
        int GetId(){return id_;}
        std::string GetTitulo(){return titulo_;}
        std::vector<std::string> GetPonentes(){return ponentes_;}
        std::string GetFecha(){return fecha_;}
        std::string GetUbicacion(){return ubicacion_;}
        float GetPrecio(){return precio_;}
        int GetAforoMax(){return aforomax_;}
        //Setters
        void SetId();
        void SetCarrera(std::string carrera){carrera_= carrera;}
        //Funciones Propias
        void RellenarDatosT();//Rellena los atributos de la clase leidos por texto
        bool RellenarDatosFAc(int id_act);//Rellena la clase con el identificador id_act del fichero ActAcademicas.txt 
        bool RellenarDatosFCom(int id_act);//Rellena la clase con el identificador id_act del fichero comunicacion.txt        
        bool ModificarActFCom();//Modifica la actividad academica del fichero de comunicacion
        void ImprimirDatos();//Imprime los datos por pantalla
        bool EliminarActCom(int id_act);//Elimina la actividad con id=id_act del fichero "comunicacion.txt"
        void ImprimirFAc();//Imprime los datos que tiene guardados la clase en el fichero "ActAcademicas.txt"
        void ImprimirFCom();//Imprime los datos que tiene guardados en la clase en el fichero "comunicacion.txt"
};


#endif