#include <iostream>
#include "Contacto.h"
#include "Presentacion.h"
#include <string>
using namespace std;
Contacto::Contacto(std::string _nombre, std::string _apellido, std::string _edad, std::string _email,
                   std::string _numero_telf) {
    setNombre(_nombre);
    setApellido(_apellido);
    setEdad(_edad);
    setNumero_telf(_numero_telf);
    setEmail(_email);
}


void Contacto::Mostrar_datos() {
    cout<<endl;
    cout<<"\t\t\t NOMBRE            : "<<nombre<<endl;
    cout<<"\t\t\t APELLIDO          : "<<apellido<<endl;
    cout<<"\t\t\t EDAD              : "<<edad<<endl;
    cout<<"\t\t\t NUMERO TELEFONICO : "<<numero_telf<<endl;
    cout<<"\t\t\t CORREO            : "<<email<<endl;
    cout<<endl;
}

void Contacto::Mostrar_datos_especificos() {
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Telefono: "<<numero_telf<<endl;
}

bool Contacto::Encontrar(std::string busqueda) {
    if(encontrar(mayusculas(nombre),mayusculas(busqueda))){
        return true;
    }
    else if(encontrar(mayusculas(apellido),mayusculas(busqueda))){
        return true;
    }
    else if(encontrar(mayusculas(edad),mayusculas(busqueda))){
        return true;
    }
    else if(encontrar(mayusculas(email),mayusculas(busqueda))){
        return true;
    }
    else if(encontrar(mayusculas(numero_telf),mayusculas(busqueda))){
        return true;
    }
    return false;

}

void Contacto::Actualizar_atributo(char atributo, std::string nuevo_atributo) {
    switch(atributo){
        case 'n': setNombre(nuevo_atributo); break;
        case 'a': setApellido(nuevo_atributo); break;
        case 'e': setEdad(nuevo_atributo); break;
        case 't': setNumero_telf(nuevo_atributo); break;
        case 'c': setEmail(nuevo_atributo); break;
    }

}

