#include <iostream>
#include <string>
#include <vector>
#include "lista_asistencia.h"

int main(){
    Lista_asistencia l1;

    if(l1.RecogerListaAct(5)){
        std::cout<<"ID: "<<l1.GetId_academica()<<"\n";
        std::cout<<"Aforo restante: "<<l1.GetAforoRes()<<"\n";
        std::vector<std::string> vec= l1.GetInscritos();
        std::cout<<"INSCRITOS: ";
        for(auto j: vec){
            std::cout<<j<<" ";
        }
        std::cout<<"\n";
    }

    l1.AnadirAlumno(1,"f22paror@uco.es");

    std::cout<<"ID: "<<l1.GetId_academica()<<"\n";
    std::cout<<"Aforo restante: "<<l1.GetAforoRes()<<"\n";
    std::vector<std::string> vec= l1.GetInscritos();
    std::cout<<"INSCRITOS: ";
    for(auto i: vec){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    
    return 0;
}