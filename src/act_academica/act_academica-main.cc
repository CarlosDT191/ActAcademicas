#include "act_academica.h"
#include <iostream>
#include <string>

int main(){
    Act_academica a1;
    a1.SetId();
    std::cout<<"Id nuevo: "<<a1.GetId()<<"\n";

    a1.RellenarDatosT();
    a1.SetCarrera("todos");
    a1.ImprimirDatos();

    if(a1.RellenarDatosFAc(1)){
        a1.ImprimirDatos();
    }

    if(a1.RellenarDatosFCom(2)){
        a1.ImprimirDatos();
    }

    a1.SetCarrera("mecanica");
    a1.ModificarActFCom();
    
    a1.RellenarDatosFCom(4);
    a1.EliminarActCom(4);
    a1.ImprimirFAc();

    return 0;
}