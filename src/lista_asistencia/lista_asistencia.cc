//lista_asistencia.cc
//Aqui estan las funciones de lista de asistencia (agregar alumno, eliminar alumno, leer y mostrar lista de asistencia)

#include <iostream>
#include <fstream>

#include "lista_asistencia.h" // Incluye la declaración de la clase lista_asistencia

// Función para agregar un alumno al fichero de texto
void agregarAlumno(const alumno& usuario) {
    std::ofstream fichero("../BD/ListaAsistencia.txt", std::ios::app); // Abre el archivo en modo de apéndice

    if (fichero.is_open()) {
        // Escribe los datos del alumno en el fichero
        fichero << "ID Académica: " << alumno.GetId_academica() << ", Aforo Restante: " << alumno.GetAforoRestante() << ", Correo: " << correo << "\n";

        std::cout << "Alumno agregado correctamente.\n";
    } else {
        std::cerr << "No se pudo abrir el archivo.\n";
    }

    fichero.close(); // Cierra el archivo
}

void agregarAlumnoAlFichero(const alumno& usuario, const std::string& nombreFichero) {
    std::ofstream fichero("../BD/ListaAsistencia.txt", std::ios::app);

    if (fichero.is_open()) {
        fichero << "Actividad: " << usuario.GetActividad() << ", ";
        fichero << "Aforo Restante: " << usuario.GetAforoRestante() << ", ";
        fichero << "Correo: " << usuario.GetCorreo() << "\n";
        fichero.close();
        std::cout << "Alumno agregado correctamente al fichero.\n";
    } else {
        std::cerr << "Error al abrir el fichero.\n";
    }
}













// Función para leer y mostrar el contenido del fichero
void mostrarListaAsistencia() {
    std::ifstream fichero("../BD/ListaAsistencia.txt");

    if (fichero.is_open()) {
        std::string linea;
        while (std::getline(fichero, linea)) {
            std::cout << linea << "\n";
        }
        fichero.close();
    } else {
        std::cerr << "No se pudo abrir el archivo.\n";
    }
}
