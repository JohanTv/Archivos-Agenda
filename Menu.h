#ifndef POO_MENU_H
#define POO_MENU_H

#include <iostream>
#include "Agenda_Telf.h"
class Menu {
private:
    std::string nombre_menu;
public:
    //Constructores
    Menu(){};
    Menu(std::string _nombre_menu){
		setNombre_menu(_nombre_menu);
	}
    //Funciones de Menu

    void menu_ingresar(Agenda_Telf *la_agenda); // LISTO
    void menu_busqueda(Agenda_Telf *la_agenda); //LISTO
    void menu_listado(Agenda_Telf *la_agenda); //LISTO
    void menu_borrar(Agenda_Telf *la_agenda); //LISTO
    void menu_actualizar(Agenda_Telf *la_agenda); //LISTO

    //Setters
    void setNombre_menu(std::string _nombre_menu){nombre_menu= _nombre_menu;}
    //Getters
    std::string getNombre_menu(){return nombre_menu;}
};
#endif //POO_MENU_H

