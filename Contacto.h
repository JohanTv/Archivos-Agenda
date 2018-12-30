#ifndef POO_CONTACTO_H
#define POO_CONTACTO_H

#include <iostream>
class Contacto {
private:
    std::string nombre;
    std::string apellido;
    std::string edad;
    std::string email;
    std::string numero_telf;
public:
    //Constructores
    Contacto(){};
    Contacto(std::string _nombre,
             std::string _apellido,
             std::string _edad,
             std::string _email,
             std::string _numero_telf);
    //Funciones de Contacto

    void Mostrar_datos();
    void Mostrar_datos_especificos();
    bool Encontrar(std::string busqueda);
    void Actualizar_atributo(char atributo,std::string nuevo_atributo);
    //Setters
    void setNombre(std::string _nombre){nombre=_nombre;}
    void setApellido(std::string _apellido){apellido=_apellido;}
    void setEdad(std::string _edad){edad=_edad;}
    void setEmail(std::string _email){email=_email;}
    void setNumero_telf(std::string _numero_telf){numero_telf=_numero_telf;}
    //Getters
    std::string getNombre(){return nombre;}
    std::string getApellido(){return apellido;}
    std::string getEdad(){return edad;}
    std::string getEmail(){return email;}
    std::string getNumero_telf(){return numero_telf;}

};

#endif //POO_CONTACTO_H

