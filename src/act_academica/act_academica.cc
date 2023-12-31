#include "act_academica.h"
#include "lista_asistencia.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Act_academica::Act_academica(int id_act){
    id_=id_act;
}

void Act_academica::SetId(){
    std::ifstream DataAct("src/BD/ActAcademicas.txt");
    std::ifstream DataCom("src/BD/comunicacion.txt");
    if(DataAct.is_open() || DataCom.is_open()){
        //Busca en el fichero "ActAcademicas.txt" el ultimo id y lo guarda en idef_a
        std::string linea1;
        int id_max_a= 0;
        std::getline(DataAct, linea1);
        while(std::getline(DataAct, linea1)){
            std::istringstream ss1(linea1);
            ss1.ignore(1);
            std::string idef_act_str;
            std::getline(ss1,idef_act_str,'|');
            int idef_a= std::stoi(idef_act_str);
            if(idef_a>id_max_a){
                id_max_a= idef_a;
            }
        }
        DataAct.close();


        //Busca en el fichero "comunicacion.txt" el ultimo id y lo guarda en idef_c
        std::string linea2;
        int id_max_c=0;
        std::getline(DataCom, linea2);
        while(std::getline(DataCom, linea2)){
            std::istringstream ss2(linea2);
            ss2.ignore(1);
            std::string idef_act_str_2;
            std::getline(ss2,idef_act_str_2,'|');
            int idef_c= std::stoi(idef_act_str_2);
            if(idef_c>id_max_c){
                id_max_c= idef_c;
            }
        }

        DataCom.close();

        if(id_max_c >= id_max_a){
            id_max_c++;
            id_= id_max_c;
        }

        else{
            id_max_a++;
            id_= id_max_a;
        }
    }
}

void Act_academica::RellenarDatosT(int modo){
    std::string titulo, ponente, fecha, ubicacion, carrera;
    float precio;
    int aforomax, valor=1, fin=0, cant_ponentes;
    while(valor!=8){
        if(modo==0){//modo= 0 creacion de act. modo==1 modificacion de act
            switch(valor){
                case 1:
                    std::cout<<"Introduzca el titulo de la actividad (Sin espacios):\n";
                    std::cin>>titulo;
                    titulo_= titulo;
                    if(valor==1 && fin!=0){
                        break;
                    }
                case 2:
                    if(valor==2){
                        ponentes_.clear();
                    }
                    std::cout<<"Cuantos ponentes tiene la actividad?\n";
                    std::cin>>cant_ponentes;
                    std::cout<<"Escribalo de la siguiente manera: Nombre_Apellido1\n";
                    for(int i=0; i<cant_ponentes; i++){
                        std::cout<<"Nombre de ponente "<<(i+1)<<": ";
                        std::cin>>ponente;
                        ponentes_.push_back(ponente);
                    }                
                    if(valor!=1){
                        break;
                    }
                case 3:
                    std::cout<<"Introduzca la fecha. Ejemplo: 25/03/2009\n";
                    std::cin>>fecha_;
                    if(valor!=1){
                        break;
                    }
                case 4:
                    std::cout<<"Introduzca la ubicacion (Sin espacios)\n";
                    std::cin>>ubicacion_;
                    if(valor!=1){
                        break;
                    }
                case 5:
                    std::cout<<"Introduzca el precio de la actividad:\n";
                    std::cin>>precio;
                    precio_=precio;
                    if(valor!=1){
                        break;
                    }
                case 6:
                    std::cout<<"Introduzca el aforo maximo de la actividad:\n";
                    std::cin>>aforomax;
                    aforomax_=aforomax;
                    if(valor!=1){
                        break;
                    }
                case 7:
                    std::cout<<"Introduzca a la carrera que se quiere asignar la actividad:\n";
                    std::cout<<"Si no se incluye una carrera especifica escriba todas\n";
                    std::cin>>carrera;
                    carrera_= carrera;
                    break;
                case 8:
                    std::cout<<"Saliendo de la asignacion de valores.\n";
                    break;
                default:
                    std::cout<<"Dato incorrecto, seleccione de nuevo\n";
                    break;
            }
        }
        if(valor!=8){
            std::cout<<"¿Que desea realizar ahora?\n 1. Editar titulo\n 2. Editar ponentes\n";
            std::cout<<" 3. Editar fecha\n 4. Editar ubicacion\n";
            std::cout<<" 5. Editar precio\n 6. Editar aforo maximo\n 7. Editar carrera\n 8. Guardar cambios\n";
            std::cin>>valor;
            fin= 1;
            modo= 0;
        }
    }
    std::cout<<"\n";
}


bool Act_academica::RellenarDatosFAc(int id_act){
    std::ifstream DataAct("src/BD/ActAcademicas.txt");
    if(!DataAct.is_open()){
        std::cout<<"Error al abrir el fichero ActAcademicas.txt\n";
        return false;
    }

    std::string linea;
    std::getline(DataAct,linea);
    while(std::getline(DataAct,linea)){
        std::string l_titulo, l_ponentes, l_carrera, l_precio, l_aforo, l_identific_str;
        std::string ponente, l_fecha, l_ubicacion; 
        std::istringstream ss(linea);
        ss.ignore(1);
        if(std::getline(ss, l_identific_str, '|')){
            int l_identific= std::stoi(l_identific_str);
            if(l_identific==id_act){
                id_= l_identific;
                std::getline(ss,l_titulo, '|');
                titulo_= l_titulo;
                std::getline(ss,l_ponentes, '|');
                std::istringstream ss2(l_ponentes);
                ponentes_.clear();
                while(std::getline(ss2, ponente, ' ')){
                    ponentes_.push_back(ponente);
                }
                std::getline(ss,l_fecha, '|');
                fecha_= l_fecha;
                std::getline(ss,l_ubicacion, '|');
                ubicacion_= l_ubicacion;
                std::getline(ss,l_precio, '|');
                precio_= std::stof(l_precio);
                std::getline(ss,l_aforo, '|');
                aforomax_= std::stoi(l_aforo);
                std::getline(ss,l_carrera,'|');
                carrera_= l_carrera;
                DataAct.close();
                return true;
            }
        }
    }
    DataAct.close();
    return false;
}

bool Act_academica::RellenarDatosFCom(int id_act){
    std::ifstream DataAct("src/BD/comunicacion.txt");
    if(!DataAct.is_open()){
        std::cout<<"Error al abrir el fichero comunicacion.txt\n";
        return false;
    }

    std::string linea;
    std::getline(DataAct,linea);
    while(std::getline(DataAct,linea)){
        std::string l_titulo, l_ponentes, l_carrera, l_precio, l_aforo, l_identific_str;
        std::string ponente, l_fecha, l_ubicacion; 
        std::istringstream ss(linea);
        ss.ignore(1);
        if(std::getline(ss, l_identific_str, '|')){
            int l_identific= std::stoi(l_identific_str);
            if(l_identific==id_act){
                id_= l_identific;
                std::getline(ss,l_titulo, '|');
                titulo_= l_titulo;
                std::getline(ss,l_ponentes, '|');
                std::istringstream ss2(l_ponentes);
                ponentes_.clear();
                while(std::getline(ss2, ponente, ' ')){
                    ponentes_.push_back(ponente);
                }
                std::getline(ss,l_fecha, '|');
                fecha_= l_fecha;
                std::getline(ss,l_ubicacion, '|');
                ubicacion_= l_ubicacion;
                std::getline(ss,l_precio, '|');
                precio_= std::stof(l_precio);
                std::getline(ss,l_aforo, '|');
                aforomax_= std::stoi(l_aforo);
                std::getline(ss,l_carrera,'|');
                carrera_= l_carrera;
                DataAct.close();
                return true;
            }
        }
    }
    DataAct.close();
    return false;
}

bool Act_academica::ModificarActFCom(){
    std::ifstream DataAct("src/BD/comunicacion.txt");
    std::ofstream DataAux("src/BD/aux.txt");
    std::string linea;
    bool fnd= false;
    if(!DataAct.is_open() || !DataAux.is_open()){
        std::cout<<"No se han podido abrir los ficheros necesarios\n";
        return false;
    }
    
    std::getline(DataAct,linea);
    DataAux<<linea;

    while(std::getline(DataAct,linea)){
        std::istringstream ss(linea);
        std::string id_str;
        ss.ignore(1);
        std::getline(ss, id_str, '|');
        int id= std::stoi(id_str);
        if(id_==id){
            DataAux<<"\n|"<<id_<<"|"<<titulo_<<"|";
            for(auto j: ponentes_){
                DataAux<<j<<" ";
            }
            DataAux<<"|"<<fecha_<<"|"<<ubicacion_<<"|"<<precio_<<"|"<<aforomax_<<"|"<<carrera_<<"|";
            fnd= true;
        }
        else{
            DataAux<<"\n";
            DataAux<<linea;
        }
    }

    DataAct.close();
    DataAux.close();

    remove("src/BD/comunicacion.txt");
    rename("src/BD/aux.txt","src/BD/comunicacion.txt");
    return fnd;
}

void Act_academica::ImprimirDatos(){
    std::cout<<"\n  ACT ACADEMICA ID= "<<id_<<"\n";
    std::cout<<"  TITULO: "<<titulo_<<"\n";
    std::cout<<"  PONENTES: ";
    for(auto j : ponentes_){
        std::cout<<j<<" ";
    }
    std::cout<<"\n  FECHA: "<<fecha_<<"\n";
    std::cout<<"  UBICACION: "<<ubicacion_<<"\n";
    std::cout<<"  PRECIO: "<<precio_<<"\n";
    std::cout<<"  AFORO: "<<aforomax_<<"\n";
    std::cout<<"  CARRERA: "<<carrera_<<"\n";
    Lista_asistencia l1;
    l1.RecogerListaAct(id_);
    std::cout<<"  INSCRITOS: ";
    for(auto i : l1.GetInscritos()){
        std::cout<<i<<" ";
    }
    std::cout<<"\n\n";
}

bool Act_academica::EliminarActCom(int id_act){
    std::ifstream DataAct("src/BD/comunicacion.txt");
    std::ofstream DataAux("src/BD/aux.txt");
    std::string linea, id_str;
    bool fnd= false;
    std::getline(DataAct,linea);
    DataAux<<linea;
    while(std::getline(DataAct,linea)){
        std::istringstream ss(linea);
        ss.ignore(1);
        std::getline(ss,id_str,'|');
        int id= std::stoi(id_str);
        if(id==id_act){
            fnd= true;
            id_= id;
            std::string titulo, ponentes, ponente, carrera, fecha, ubicacion, precio_str, aforo_str;
            std::getline(ss,titulo,'|');
            titulo_=titulo;
            std::getline(ss,ponentes,'|');
            std::istringstream ss2(ponentes);
            ponentes_.clear();
            while(std::getline(ss2,ponente,' ')){
                ponentes_.push_back(ponente);
            }
            std::getline(ss,fecha,'|');
            fecha_= fecha;
            std::getline(ss,ubicacion,'|');
            ubicacion_= ubicacion;
            std::getline(ss,precio_str,'|');
            precio_= std::stof(precio_str);
            std::getline(ss,aforo_str,'|');
            aforomax_= std::stoi(aforo_str);
            std::getline(ss,carrera,'|');
            carrera_= carrera;
        }
        else{
            DataAux<<"\n"<<linea;
        }
    }
    DataAct.close();
    DataAux.close();

    remove("src/BD/comunicacion.txt");
    rename("src/BD/aux.txt","src/BD/comunicacion.txt");
    return fnd;
}

void Act_academica::ImprimirFAc(){
    std::ofstream DataAct("src/BD/ActAcademicas.txt", std::ios::app);
    DataAct<<"\n|"<<id_<<"|"<<titulo_<<"|";
    for(auto j : ponentes_){
        DataAct<<j<<" ";
    }
    DataAct<< "|" << fecha_<<"|"<<ubicacion_<<"|"<<precio_<<"|"<<aforomax_<<"|"<<carrera_<<"|";
    DataAct.close();

}

void Act_academica::ImprimirFCom(){
    std::ofstream DataCom("src/BD/comunicacion.txt", std::ios::app);
    DataCom<<"\n|"<<id_<<"|"<<titulo_<<"|";
    for(auto j : ponentes_){
        DataCom<<j<<" ";
    }
    DataCom<< "|" << fecha_<<"|"<<ubicacion_<<"|"<<precio_<<"|"<<aforomax_<<"|"<<carrera_<<"|";
    DataCom.close();
}