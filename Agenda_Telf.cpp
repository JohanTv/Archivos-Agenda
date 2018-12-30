#include <iostream>
#include <cstring>
#include <fstream>
#include "Agenda_Telf.h"
#include "Definiciones.h"
#include "Contacto.h"
#include "Presentacion.h"
using namespace std;
Agenda_Telf::~Agenda_Telf() {
    delete[] mis_contactos;
}

Agenda_Telf::Agenda_Telf(std::string _lista_contactos)  {
    setNombre_lista(_lista_contactos);

    Archivo Mi_Archivo(true);
    Mi_Archivo.Obtener_Lineas();

    mis_contactos= new Contacto[MAX_CONTACTOS];
    ifstream entrada;
    entrada.open(DATOS);

    string relleno;
    string linea;

    if (entrada.good()) {
        
        for(int i=0;i<Mi_Archivo.getLineas();i+=6){
            getline(entrada,relleno);
            getline(entrada,linea); mis_contactos[numero_contactos].setNombre(linea);
            getline(entrada,linea); mis_contactos[numero_contactos].setApellido(linea);
            getline(entrada,linea); mis_contactos[numero_contactos].setEdad(linea);
            getline(entrada,linea); mis_contactos[numero_contactos].setNumero_telf(linea);
            getline(entrada,linea); mis_contactos[numero_contactos].setEmail(linea);
            numero_contactos++;
            
        }

    }
    
    
    entrada.close();

}

void Agenda_Telf::Ingresar_contacto(Contacto x) {

    mis_contactos[numero_contactos]=x;
    numero_contactos++;

    Archivo Mi_Archivo(true);
    Mi_Archivo.Obtener_Lineas();

    ofstream salida;
    salida.open(DATOS,ios::app | ios::out);
    if(salida.good()){
        salida<<"Contacto ["<<numero_contactos+1<<"]:"<<"\n";
        salida << x.getNombre()<<"\n";
        salida << x.getApellido()<<"\n";
        salida <<x.getEdad()<<"\n";
        salida << x.getNumero_telf()<<"\n";
        salida <<x.getEmail()<<"\n";
 	}
    salida.close();
}

void Agenda_Telf::Mostrar_contactos() {
    for(int i=0;i<numero_contactos;i++){
        cout<<"Contacto "<<"["<<i+1<<"]: "<<endl;
        mis_contactos[i].Mostrar_datos_especificos();
        cout<<"\n"<<endl;
    }

}

int Agenda_Telf::Buscar_contactos(std::string busqueda, Contacto* temporal) {
    int contador=0;
    for(int i=0;i<numero_contactos;i++){
        if(mis_contactos[i].Encontrar(busqueda)){
            cout<<"Contacto "<<"["<<contador+1<<"]: "<<endl;
            mis_contactos[i].Mostrar_datos_especificos();
            cout<<"\n";
            temporal[contador]=mis_contactos[i];
            contador++;
        }
    }
    return contador;
}

int Agenda_Telf::Encontrar_posicion_contacto(Contacto x) {
    int contador=0;
    for(int i=0; i<numero_contactos;i++){
        contador=i;
        if(Corroborar_contacto(x,mis_contactos[i])){
            break;
        }

    }
    return contador;
}

bool Agenda_Telf::Corroborar_contacto(Contacto x, Contacto y) {
    if(strcmp(x.getNumero_telf().c_str(),y.getNumero_telf().c_str())==0 &&
       strcmp(x.getEdad().c_str(),y.getEdad().c_str())==0 &&
       strcmp(x.getApellido().c_str(),y.getApellido().c_str())==0 &&
       strcmp(x.getEmail().c_str(),y.getEmail().c_str())==0 &&
       strcmp(x.getNombre().c_str(),y.getNombre().c_str())==0){
        return true;
    }
    return false;
}

void Agenda_Telf::Eliminar_contacto(Contacto borrar) {

    Archivo Mi_Archivo(true);
    Mi_Archivo.Obtener_Lineas();

    Contacto* nueva_lista=new Contacto[MAX_CONTACTOS];

    int contador=0;
    for(int i=0; i<numero_contactos;i++){
        if(!Corroborar_contacto(mis_contactos[i],borrar)){
            nueva_lista[contador]=mis_contactos[i];
            contador++;
        }
    }

    delete[] mis_contactos;
    mis_contactos=nueva_lista;
    numero_contactos--;

    ifstream entrada;
    ofstream temporal;
    entrada.open(DATOS);
    temporal.open("temporal.txt");
    if(entrada.good()){
        for(int i=0;i<numero_contactos;i++){
            temporal<<"Contacto ["<<i+1<<"]:"<<"\n";
            temporal<< mis_contactos[i].getNombre()<<"\n";
            temporal<< mis_contactos[i].getApellido()<<"\n";
            temporal<< mis_contactos[i].getEdad()<<"\n";
            temporal<< mis_contactos[i].getNumero_telf()<<"\n";
            temporal<< mis_contactos[i].getEmail()<<"\n";
        }
    }
    entrada.close();
    temporal.close();
    remove(DATOS);
    rename("temporal.txt",DATOS);

}

void Agenda_Telf::Actualizar_Contacto(int posicion, char cual_atributo, std::string nuevo_atributo) {

    mis_contactos[posicion].Actualizar_atributo(cual_atributo,nuevo_atributo);

    Archivo Mi_Archivo(true);
    Mi_Archivo.Obtener_Lineas();

    ifstream entrada;
    ofstream temporal;
    entrada.open(DATOS);
    temporal.open("temporal.txt");
    if(entrada.good()){
        for(int i=0;i<numero_contactos;i++){
            temporal<<"Contacto ["<<i+1<<"]:"<<"\n";
            temporal<< mis_contactos[i].getNombre()<<"\n";
            temporal<< mis_contactos[i].getApellido()<<"\n";
            temporal<< mis_contactos[i].getEdad()<<"\n";
            temporal<< mis_contactos[i].getNumero_telf()<<"\n";
            temporal<< mis_contactos[i].getEmail()<<"\n";
        }
    }

    entrada.close();
    temporal.close();
    remove(DATOS);
    rename("temporal.txt",DATOS);


}

Contacto *Agenda_Telf::getMis_contactos() {
    return mis_contactos;
}

