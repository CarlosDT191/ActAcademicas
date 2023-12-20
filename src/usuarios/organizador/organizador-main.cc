#include "organizador.h"
#include "string"
#include "vector"
#include "usuario.h"
#include "act_academica.h"
#include <iostream>


int main() {
    // Crear un objeto Organizador
    Organizador organizador("organizador@mail.com", "contrasena");

    /* Llamar a la función CrearActAcademica
    organizador.CrearActAcademica();
    

    // Llamar a la función ModificarActAcademica
    bool resultado = organizador.ModificarActAcademica(5);

    // Verificar el resultado
    if (resultado) {
        std::cout << "La actividad académica se modificó exitosamente." << std::endl;
    } else {
        std::cout << "No se pudo modificar la actividad académica." << std::endl;
    }
    */

    // Llamar a la función VerActAcademicasConf
    bool actividadesConfirmadas = organizador.VerActAcademicasConf();

    // Verificar el resultado
    if (actividadesConfirmadas) {
        std::cout << "Actividades académicas confirmadas:\n";
        // Aquí puedes realizar cualquier otra acción que desees con las actividades confirmadas
    } else {
        std::cout << "No hay actividades académicas confirmadas.\n";
    }


    bool actividadesNoConfirmadas = organizador.VerActAcademicasNoConf();

    // Verificar el resultado
    if (actividadesNoConfirmadas) {
        std::cout << "Actividades académicas por confirmar:\n";
        // Aquí puedes realizar cualquier otra acción que desees con las actividades por confirmar
    } else {
        std::cout << "No hay actividades académicas por confirmar.\n";
    }

    return 0;
}
