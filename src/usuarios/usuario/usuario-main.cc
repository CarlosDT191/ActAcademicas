#include "usuario.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    Usuario u1;
    if(u1.Login()){
        std::cout << "Correo: " << u1.GetCorreo() << "\nContraseña: " << u1.GetPassword() << "\n Rol: " << u1.GetRol() << "\nCarrera: " << u1.GetCarrera() << std::endl;
    }
    return 0;
}