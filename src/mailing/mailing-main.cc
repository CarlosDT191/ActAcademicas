#include "mailing.h"
#include <iostream>

int main() {
    std::vector<Alumno> alumnos = {
        {"Juan", "juan@ucomail.es", "Ingeniería Informática"},
        {"María", "maria@ucomail.es", "Ingeniería Informatica"},
        {"Carlos", "carlos@ucomail.es", "Medicina"}
        // Agrega más alumnos según sea necesario
    };

    int opcion = -1;  // Inicializamos la opción con un valor que no sea 0 ni 1 ni 2
    while (opcion != 0) {
        std::cout << "\nSeleccione una opción:\n";
        std::cout << "1. Enviar correo por carrera\n";
        std::cout << "2. Enviar correo a todos\n";
        std::cout << "0. Salir\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la carrera: ";
                std::string carrera;
                std::cin >> carrera;
                enviarCorreoCarrera(alumnos, carrera);
                break;
            case 2:
                enviarCorreoATodos(alumnos);
                break;
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    }

    return 0;
}