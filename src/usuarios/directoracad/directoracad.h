#include "usuarios.h"
#include "act_academica"
#include <iostream>
#include <vector>
#include <string>

#include <iostream>
#include <fstream>
#include <string>

class DirectorAcademico
{
public:
    // Función para ver todas las actividades pendientes en "comunicacion.txt"
    void VerActPen() const
    {
        std::ifstream archivo("comunicacion.txt");

        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo 'comunicacion.txt'\n";
            return;
        }

        std::string linea;

        std::cout << "Actividades pendientes:\n";

        while (getline(archivo, linea))
        {
            std::cout << linea << "\n";
        }

        archivo.close();
    }

    // Funcion eliminar act acad
    bool ConfirmarAct(int id_act)
    {
        std::ifstream archivoEntrada("../BD/comunicacion.txt");
        std::ofstream archivoSalidaTemp("../BD/temp.txt");

        if (!archivoEntrada.is_open() || !archivoSalidaTemp.is_open())
        {
            std::cerr << "Error al abrir los archivos.\n";
            return false;
        }

        ActividadAcademica actividad;
        std::string linea;
        bool actividadEncontrada = false;
        actividad.RellenarDatosFCom(id_act);

        while (getline(archivoEntrada, linea))
        {
            std::istringstream iss(linea);
            iss.ignore(1);
            int id_prov;
            std::getline(iss, id_prov);
            if (actividad.GetId() != id_prov)
            {
                archivoSalidaTemp << linea << "\n";
                actividadEncontrada = true;
            }
        }

        archivoEntrada.close();
        archivoSalidaTemp.close();

        if (!actividadEncontrada)
        {
            std::cout << "No se encontró una actividad con ID " << id_act << ".\n";
            remove("../BD/temp.txt");
            return false;
        }

        remove("../BD/comunicacion.txt");
        rename("../BD/temp.txt", "../BD/comunicacion.txt");

        std::ofstream archivoActConfirmadas("../BD/ActAcademicas.txt", std::ios::app);

        if (!archivoActConfirmadas.is_open())
        {
            std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
            return false;
        }

        archivoActConfirmadas << "|" << actividad.GetId() << "|" << actividad.GetTitulo() << "\n";
        archivoActConfirmadas.close();

        std::cout << "Actividad con ID " << id_act << " confirmada y movida a 'ActAcademicas.txt'.\n";

        // FATA ENVIAR A FICHEROS PERSONALES
        return true;
    }
    // Funcion eliminar act acad
    bool ConfirmarAct(int id_act)
    {
        std::ifstream DataComunicacion("../BD/comunicacion.txt");
        std::ofstream DataAux("../BD/aux.txt");

        if (!DataComunicacion.is_open() || !DataAux.is_open())
        {
            std::cerr << "Error al abrir los archivos.\n";
            return false;
        }

        ActividadAcademica actividad;
        std::string linea;
        bool actividadEncontrada = false;
        actividad.RellenarDatosFCom(id_act);

        while (getline(DataComunicacion, linea))
        {
            std::istringstream iss(linea);
            iss.ignore(1);
            int id_prov;
            std::getline(iss, id_prov);
            if (actividad.GetId() != id_prov)
            {
                archivoSalidaTemp << linea << "\n";
            }
            else
            {
                actividadEncontrada = true;
            }
        }

        DataComunicacion.close();
        DataAux.close();

        if (!actividadEncontrada)
        {
            std::cout << "No se encontró una actividad con ID " << id_act << ".\n";
            remove("../BD/aux.txt");
            return false;
        }

        remove("../BD/comunicacion.txt");
        rename("../BD/aux.txt", "../BD/comunicacion.txt");

        std::ofstream DataActAcademicas("../BD/ActAcademicas.txt", std::ios::app);

        if (!archivoActConfirmadas.is_open())
        {
            std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
            return false;
        }

        archivoActConfirmadas << "|" << actividad.GetId() << "|" << actividad.GetTitulo() < < < < < < < < < < "\n";
        archivoActConfirmadas.close();

        std::cout << "Actividad con ID " << id_act << " confirmada y movida a 'ActAcademicas.txt'.\n";

        std::ifstream DataCuentas("../BD/cuentas.txt");
        std::string linea_2;
        std::getline(DataCuentas, linea_2);

        if (actividad.GetCarrera() == "todos")
        {
            while (std::getline(DataCuentas, linea_2))
            {
                istringstream iss2(linea_2);
                std::string correo;
                ss.ignore(1);
                std::getline(iss2, correo);
                // RECOGER UNICAMENTE EL CORREO SIN @UCO.ES Y LO GUARDA EN CORREO Y SE CONCATENA CON LA DIRECCION "../BD" + CORREO + ".TXT"
                std::ofstream MailPersonal("../BD" + correo.erase(correo.length()-7) + ".TXT", std::ios::app);
                MailPersonal << "|" << actividad.GetId() << "|" <<actividad.GetTitulo()<< "|" << "nada" << "|\n"; 
                    MailPersonal.close();
            }
        }

        else
        {
            istringstream iss3(linea_2);
            std::string correo_2;
            std::string password_2;
            std::string rol_2;
            std::string carrera_2;
            ss.ignore(1);
            std::getline(iss2, correo);
            // RECOGER UNICAMENTE EL CORREO SIN @UCO.ES Y LO GUARDA EN CORREO Y SE CONCATENA CON LA DIRECCION "../BD" + CORREO + ".TXT"
            ss.ignore(1);
            std::getline(iss2, password); 
            ss.ignore(1);
            std::getline(iss2, rol);
            ss.ignore(1);
            std::getline(iss2, carrera);
            if (actividad.GetCarrera() == carrera_2)
            {
                std::ofstream MailPersonal("../BD" + correo.erase(correo.length()-7) + ".TXT", std::ios::app);
                MailPersonal << "|" << actividad.GetId() << "|" <<actividad.GetTitulo()<< "|" << "nada" << "|\n"; 
                    MailPersonal.close();
            }
        }

        return true;
    }
};
#endif