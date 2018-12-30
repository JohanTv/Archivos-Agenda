#ifndef POO_PRESENTACION_H
#define POO_PRESENTACION_H

#include <iostream>
#include "Agenda_Telf.h"
#include "Menu.h"
#include "Definiciones.h"

void llamar_presentacion(Agenda_Telf *Mi_Agenda, Menu *Compila);
bool validar(std::string entrada);
bool encontrar(std::string primero,std::string segundo);
std::string mayusculas(std::string entrada);
Contacto Pedir_datos();

#endif //POO_PRESENTACION_H

