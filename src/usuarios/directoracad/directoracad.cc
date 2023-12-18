#include "directoracad.h"
#include "usuarios.h"
#include "act_academica.h"
#include <iostream>
#include <vector>
#include <string>

    //Funcion para ver las actividades pendientes
    void DirectorAcad::VerActPen()
    {
        std::ifstream DataComunicacion("comunicacion.txt");

        if (!DataComunicacion.is_open())
        {
            std::cerr << "Error al abrir el archivo 'comunicacion.txt'\n";
            return;
        }

        std::string linea;

        std::cout << "Actividades pendientes:\n";

        while (getline(DataComunicacion, linea))
        {
            std::cout << linea << "\n";
        }

        DataComunicacion.close();
    }

    // Funcion eliminar act acad
    bool DirectorAcad::ConfirmarAct(int id_act)
    {
        std::ifstream DataComunicacion("../BD/comunicacion.txt");
        std::ofstream DataTemp("../BD/temp.txt");

        if (!DataComunicacion.is_open() || !DataTemp.is_open())
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
            std::getline(iss, id_prov,'|');
            if (actividad.GetId() != id_prov)
            {
                DataTemp << linea << "\n";
                actividadEncontrada = true;
            }
        }

        DataComunicacion.close();
        DataTemp.close();

        if (!actividadEncontrada)
        {
            std::cout << "No se encontró una actividad con ID " << id_act << ".\n";
            remove("../BD/temp.txt");
            return false;
        }

        remove("../BD/comunicacion.txt");
        rename("../BD/temp.txt", "../BD/comunicacion.txt");

        std::ofstream DataAct("../BD/ActAcademicas.txt", std::ios::app);

        if (!DataAct.is_open())
        {
            std::cerr << "Error al abrir el archivo 'ActAcademicas.txt'\n";
            return false;
        }

        DataAct << "/n|" << actividad.GetId() << "|" << actividad.GetTitulo() << "|";
        DataAct.close();

        std::cout << "Actividad con ID " << id_act << " confirmada y movida a 'ActAcademicas.txt'.\n";

        // FATA ENVIAR A FICHEROS PERSONALES
        return true;
    }
    
    bool  DirectorAcad::ConfirmarAct(int id_act)
    {
        std::ifstream DataComunicacion("../BD/comunicacion.txt");
        std::ofstream DataAux("../BD/aux.txt");

        if (!DataComunicacion.is_open() || !DataAux.is_open())
        {
            std::cerr << "Error al abrir los archivos.\n";
            return false;
        }

        Act_academica actividad;
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

        archivoActConfirmadas << "/n|" << actividad.GetId() << "|" << actividad.GetTitulo() << "|" << actividad.GetDescripcion() << "|" << actividad.GetPrecio() << "|" << actividad.GetAforoMax() << "|" << actividad.GetCarrera() << "|";
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
                std::getline(iss2, correo,'|');
                // RECOGER UNICAMENTE EL CORREO SIN @UCO.ES Y LO GUARDA EN CORREO Y SE CONCATENA CON LA DIRECCION "../BD" + CORREO + ".TXT"
                std::ofstream DataMail("../BD" + correo.erase(correo.length()-7) + ".txt", std::ios::app);
                DataMail << "/n|" << actividad.GetId() << "|" <<actividad.GetTitulo()<< "|" << "nada" << "|\n"; 
                    DataMail.close();
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
            std::getline(iss2, correo,'|');
            // RECOGER UNICAMENTE EL CORREO SIN @UCO.ES Y LO GUARDA EN CORREO Y SE CONCATENA CON LA DIRECCION "../BD" + CORREO + ".TXT"
            ss.ignore(1);
            std::getline(iss2, password,'|'); 
            ss.ignore(1);
            std::getline(iss2, rol,'|');
            ss.ignore(1);
            std::getline(iss2, carrera,'|');
            if (actividad.GetCarrera() == carrera_2)
            {
                std::ofstream DataMail("../BD" + correo.erase(correo.length()-7) + ".txt", std::ios::app);
                DataMail << "/n|" << actividad.GetId() << "|" <<actividad.GetTitulo()<< "|" << "nada" << "|"; 
                    DataMail.close();
            }
        }

        return true;
    }

 bool DirectorAcad::VerSolicitudes(const std::string& correo) 
    {
        std::ifstream DataMail("../BD" + correo.erase(correo.length()-7) + ".txt", std::ios::app);
        std::string linea_1;
        bool fnd= false;
        if (!DataMail.is_open()){
            std::cerr << "Error al abrir el archivo 'datamail.txt' " << "'\n";
            return false;
        }

        std::getline(DataMail,linea_1);
        std::cout<<linea_1<<"\n";
        //Imprimimos el contenido de los fichero de los correos sin el @uco.es y comprobamos los estados
        while (std::getline(DataMail,linea_1))
        {
           istringstream iss2(linea_1);
           std::string id;
           ss.ignore(1);
           std::getline(ss,id,'|');
           std::string titulo;
           std::getline(ss,titulo,'|');
           std::string estado;
           std::getline(ss,estado,'|');
           if (estado=="inscrito")
           {
                std::cout<<linea_1<<"\n";
                fnd= true;
           }
        }
        DataMail.close();
        return fnd;
    }

    void ConfirmarInscripcion(std::string correo, int id_act) {
        //Abrimos los archivos del correo sin el @uco.es y creamos un fichero temporal para guardar los datos
        std::ifstream DataMail("../BD" + correo.erase(correo.length()-7) + ".txt", std::ios::app);
        std::ofstream DataTemp("../BD/temp.txt");

        if (!DataMail.is_open()) {
            std::cerr << "Error al abrir el archivo 'datamail.txt' " << "'\n";
            return;
        }

        if (!DataTemp.is_open()) {
            std::cerr << "Error al abrir el archivo temporal 'temp.txt'\n";
            DataMail.close();
            return;
        }

        std::string linea_1;
        bool fnd = false;

        std::getline(DataMail, linea_1);
        DataTemp<<linea_1;
        // Leer y procesar cada línea del archivo
        while (std::getline(DataMail, linea_1)) {
            std::istringstream iss(linea);
            std::string id;
            ss.ignore(1);
            std::getline(ss,id,'|');
            std::string titulo;   
            std::getline(ss,titulo,'|');
            std::string estado;
            std::getline(ss,estado,'|');

            if(id_act == id) {
                // Encontramos la línea correspondiente a la actividad
                // Actualizar el estado a "Inscripcion"
                DataTemp << "/n|"<<id_act << "|" << titulo << "|" <<"inscrito" << "|";
                fnd = true;
            } 
            else {
                DataTemp << "\n|" << linea ;
            }
        }

        DataMail.close();
        DataTemp.close();

        // Verificar si se encontró y actualizó la actividad
        if (!fnd) {
            std::cerr << "No se encontró una actividad con ID " << id_act << " para el usuario " << correo << ".\n";
            std::remove("../BD/temp.txt");  // Eliminar el archivo temporal
            return;
        }

        // Renombrar el archivo temporal al archivo original
        std::remove("../BD" + correo.erase(correo.length()-7) + ".txt");
        std::rename("../BD/temp.txt", "../BD" + correo.erase(correo.length()-7) + ".txt");

        // Añadir al alumno en listaasistencia.txt
        Lista_asistencia l1;
        return l1.AnadirAlumno(id_act, correo);
    }  
