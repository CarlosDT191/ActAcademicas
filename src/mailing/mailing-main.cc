#include "mailing.h"
#include <iostream>

int main() {
    Mailing M;
    M.AlmacenarFAc(1);
    std::cout<<"ID: "<<M.GetId_Act()<<"\nTITULO: "<<M.GetTitulo_Act()<<"\nESTADO: "<<M.GetEstado()<<"\nCARRERA: "<<M.GetCarrera_Act()<<"\n";

    M.EnviarCorreo("orgmajog@uco.es");
    return 0;
}