#ifndef MAILING_H
#define MAILING_H

#include <iostream>
#include <vector>
#include <string>

class Mailing{
    private:
        int id_act_m_;
        std::string titulo_act_;
        std::string estado_;
        std::string carrera_act_;
    public:
        // Getters
        int GetId_Act(){return id_act_m_;}
        std::string GetTitulo_Act(){return titulo_act_;}
        std::string GetEstado(){return estado_;}
        std::string GetCarrera_Act(){return carrera_act_;}

        //Funcion que almacena en los datos privados lo que hay almacenado en ActAcademicas con el id= id_act
        bool AlmacenarFAc(int id_act);
        //Envia lo que hay almacenado en la clase el mensaje a la persona con el correo= correo
        bool EnviarCorreo(std::string correo);    
};

#endif