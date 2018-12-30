#ifndef POO_AGENDA_TELF_H
#define POO_AGENDA_TELF_H

#include <iostream>
#include "Contacto.h"
#include "Definiciones.h"

class Agenda_Telf {
private:
    int numero_contactos=0;
    std::string nombre_lista;
    Contacto* mis_contactos;
public:
    //Constructores
    Agenda_Telf(){};

    Contacto *getMis_contactos();

    Agenda_Telf(std::string _lista_contactos);
    //Destructor
    ~Agenda_Telf();
    //Funciones de la Agenda Telefónica

    void Ingresar_contacto(Contacto x);
    void Mostrar_contactos();
    int Buscar_contactos(std::string busqueda, Contacto* temporal);
    void Actualizar_Contacto(int posicion,char cual_atributo,std::string nuevo_atributo);
    bool Corroborar_contacto(Contacto x, Contacto y);
    void Eliminar_contacto(Contacto borrar);
    int Encontrar_posicion_contacto(Contacto x);

    //Setters
    void setNombre_lista(std::string _lista_contactos){nombre_lista=_lista_contactos;}
    //Getters
    int getNumero_contactos(){return numero_contactos;}
    std::string getNombre_lista(){return nombre_lista;}

};



#endif //POO_AGENDA_TELF_H

