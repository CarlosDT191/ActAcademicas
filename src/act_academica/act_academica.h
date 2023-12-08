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
        float precio_;
        int aforomax_;
    public:
        act_academica(std::string titulo, std::string descripcion, float precio, int aforomax);
        //Getters
        int GetId(){return id_;}
        std::string GetTitulo(){return titulo_;}
        std::string GetDesc(){return descripcion_;}
        float GetPrecio(){return precio_;}
        int GetAforoMax(){return aforomax_;}
        //Setters
        void SetId();
        void SetTitulo(std::string titulo){titulo_= titulo;}
        void SetDesc(std::string descripcion){descripcion_= descripcion;}
        void SetPrecio(float precio){precio_= precio;}
        void SetAforoMax(int aforomax){aforomax_= aforomax;}
        //Funciones Propias
};


#endif