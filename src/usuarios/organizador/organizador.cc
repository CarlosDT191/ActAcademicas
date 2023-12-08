#include "organizador.h"
#include "string"
#include "vector"
#include "usuarios.h"
#include "act_academica"

void Organizador::enviarCorreoCarrera(const std::vector<Alumno>& alumnos, const std::string& carrera) {
    std::cout << "Enviando correo a los alumnos de la carrera " << carrera << ":\n";
    for (const Alumno& alumno : alumnos) {
        if (alumno.getCarrera() == carrera) {
            std::cout << "Enviando correo a: " << alumno.getNombre() << " (" << alumno.getCorreo() << ")\n";
            // Aquí iría la lógica real para enviar correos
        }
    }
    std::cout << "Correos enviados a la carrera " << carrera << " exitosamente.\n";
}

void Organizador::crearActAcademica(const ActividadAcademica& nuevaActividad) {
        actividades.push_back(nuevaActividad);
        std::cout << "Creando actividad académica:\n"
                  << "ID: " << nuevaActividad.id << ", Temática: " << nuevaActividad.tematica << ", Fecha: " << nuevaActividad.fecha << "\n\n";
    }

void Organizador::modificarActAcademica(ActividadAcademica& actividad) {
        std::cout << "Modificando actividad académica con ID " << actividad.id << ":\n";

        int opcion;
        do {
            std::cout << "Seleccione el atributo a modificar:\n";
            std::cout << "1. Temática\n";
            std::cout << "2. Fecha\n";
            std::cout << "3. Aforo\n";
            std::cout << "4. Ubicación\n";
            std::cout << "5. Precio\n";
            std::cout << "6. Nombre de la Actividad\n";
            std::cout << "7. Descripción de la Actividad\n";
            std::cout << "0. Salir\n";
            std::cout << "Opción: ";
            std::cin >> opcion;

            switch (opcion) {
                case 1:
                    std::cout << "Nueva Temática: ";
                    std::cin >> actividad.tematica;
                    break;
                case 2:
                    std::cout << "Nueva Fecha: ";
                    std::cin >> actividad.fecha;
                    break;
                case 3:
                    std::cout << "Nuevo Aforo: ";
                    std::cin >> actividad.aforo;
                    break;
                case 4:
                    std::cout << "Nueva Ubicación: ";
                    std::cin >> actividad.ubicacion;
                    break;
                case 5:
                    std::cout << "Nuevo Precio: ";
                    std::cin >> actividad.precio;
                    break;
                case 6:
                    std::cout << "Nuevo Nombre de la Actividad: ";
                    std::cin.ignore(); // Limpiar el buffer del teclado antes de leer la línea completa
                    std::getline(std::cin, actividad.nombreAct);
                    break;
                case 7:
                    std::cout << "Nueva Descripción de la Actividad: ";
                    std::cin.ignore(); // Limpiar el buffer del teclado antes de leer la línea completa
                    std::getline(std::cin, actividad.descripcionAct);
                    break;
                case 0:
                    std::cout << "Saliendo del menú de modificaciones.\n";
                    break;
                default:
                    std::cout << "Opción no válida. Intente nuevamente.\n";
            }
        } while (opcion != 0);
    }