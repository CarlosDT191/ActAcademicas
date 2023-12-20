#include "usuario.h"
#include "alumno.h"
#include <vector>
#include <iostream>


int main(){
    Alumno a1("i22lumas@uco.es","patata123","mecanica");
    /*
    std::cout<<"Correo: "<<a1.GetCorreo()<<"\n";
    std::cout<<"Contraseña: "<<a1.GetPassword()<<"\n";
    std::cout<<"Carrera: "<<a1.GetCarrera()<<"\n";

    a1.VerBandeja();
    a1.VerPreInscrip();
    a1.VerInscrip();
    std::cout<<"Estado de la act 3: "<<a1.VerEstadoAct(3)<<"\n";
    std::cout<<"Estado de la act 8: "<<a1.VerEstadoAct(8)<<"\n";
    if(!a1.VerDetalles(5)){
        std::cout<<"Acceso denegado\n";
    }
    if(!a1.VerDetalles(7)){
        std::cout<<"Acceso denegado\n";
    }

    */
    a1.CambiarEstado(2,5);

    /*
    std::vector<int> vec= a1.VectorIdsInscrip();
    std::cout<<"Ids en los que esta inscrito: ";
    for(int j: vec){
        std::cout<<j<<" ";
    }
    std::cout<<"\n";

    a1.RellenarF("e22calod@uco.es");
    std::cout<<"Correo: "<<a1.GetCorreo()<<"\n";
    std::cout<<"Contraseña: "<<a1.GetPassword()<<"\n";
    std::cout<<"Carrera: "<<a1.GetCarrera()<<"\n";
    */
    return 0;
}