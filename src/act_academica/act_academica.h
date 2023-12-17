#ifndef ACTACADEMICA_H
#define ACTACADEMICA_H
#include <iostream>
#include <string>

class Act_academica{
    private:
        int id_;
        std::string titulo_;
        std::string descripcion_;
        float precio_;
        int aforomax_;
        std::string carrera_;
    public:
        Act_academica(int id_act=0);
        //Getters
        int GetId(){return id_;}
        std::string GetTitulo(){return titulo_;}
        std::string GetDesc(){return descripcion_;}
        float GetPrecio(){return precio_;}
        int GetAforoMax(){return aforomax_;}
        //Setters
        void SetId();
        void SetCarrera(int carrera){carrera_= carrera;}
        //Funciones Propias
        void RellenarDatosT();//Rellena los atributos de la clase leidos por texto
        bool RellenarDatosFAc(int id_act);//Rellena la clase con el identificador id_act del fichero ActAcademicas.txt 
        bool RellenarDatosFCom(int id_act);//Rellena la clase con el identificador id_act del fichero comunicacion.txt        
        bool ModificarActFCom();//Modifica la actividad academica del fichero de comunicacion
        void ImprimirDatos();//Imprime los datos por pantalla
};


#endif