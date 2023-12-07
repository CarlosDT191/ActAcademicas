#ifndef MAILING_H
#define MAILING_H

#include <iostream>
#include <vector>
#include <string>
#include "alumno.h"
class Alumno {
private:
    std::string nombre;
    std::string correo;
    std::string carrera;

public:
    // Constructor
    Alumno(const std::string& nombre, const std::string& correo, const std::string& carrera)
        : nombre(nombre), correo(correo), carrera(carrera) {}

    // Funciones públicas para acceder a los atributos
    std::string getNombre() const {
        return nombre;
    }

    std::string getCorreo() const {
        return correo;
    }

    std::string getCarrera() const {
        return carrera;
    }
};

// Función para enviar correos a alumnos de una carrera específica
void enviarCorreoCarrera(const std::vector<Alumno>& alumnos, const std::string& carrera) {
    std::cout << "Enviando correo a los alumnos de la carrera " << carrera << ":\n";
    for (const Alumno& alumno : alumnos) {
        if (alumno.getCarrera() == carrera) {
            std::cout << "Enviando correo a: " << alumno.getNombre() << " (" << alumno.getCorreo() << ")\n";
            // Aquí iría la lógica real para enviar correos
        }
    }
    std::cout << "Correos enviados a la carrera " << carrera << " exitosamente.\n";
}

// Función para enviar correos a todos los alumnos
void enviarCorreoATodos(const std::vector<Alumno>& alumnos) {
    std::cout << "Enviando correo a todos los alumnos:\n";
    for (const Alumno& alumno : alumnos) {
        std::cout << "Enviando correo a: " << alumno.getNombre() << " (" << alumno.getCorreo() << ")\n";
        // Aquí iría la lógica real para enviar correos
    }
    std::cout << "Correos enviados a todos los alumnos exitosamente.\n";
}

#endif