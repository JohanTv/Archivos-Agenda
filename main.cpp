//Librerias Generales
#include <iostream>
//Librerias mias
#include "Definiciones.h"
#include "Agenda_Telf.h"
#include "Contacto.h"
#include "Presentacion.h"

int main() {
    Menu Compila("POO");
    Agenda_Telf Mi_Agenda("Mis_Contactos");
    llamar_presentacion(&Mi_Agenda, &Compila);
    return 0;
}
