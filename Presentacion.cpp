#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include "Presentacion.h"
#include "Menu.h"
#include "Agenda_Telf.h"
#include "Contacto.h"
using namespace std;


void llamar_presentacion(Agenda_Telf *Mi_Agenda, Menu *Compila){
    string operacion;
    do{
        system("cls");
        cout<<"\t\t\t\t\tAGENDA"<<endl;
        cout<<"\t\t\tIngresar contacto............[1]"<<endl;
        cout<<"\t\t\tBuscar contacto..............[2]"<<endl;
        cout<<"\t\t\tVer listado..................[3]"<<endl;
        cout<<"\t\t\tEliminar contacto............[4]"<<endl;
        cout<<"\t\t\tActualizar contacto..........[5]"<<endl;
        cout<<"\t\t\tSALIR........................[6]"<<endl;
        cout<<"\t\t\tIngrese una opcion ->:";
        cin>>operacion;
        cin.ignore();
        if(validar(operacion) && (atoi(operacion.c_str())>=1 && atoi(operacion.c_str())<=5)){
            switch(atoi(operacion.c_str())){
                case 1 : system("cls");
                    Compila->menu_ingresar(Mi_Agenda);
                    break;
                case 2 : system("cls");
                    Compila->menu_busqueda(Mi_Agenda);
                    break;
                case 3 : system("cls");
                    Compila->menu_listado(Mi_Agenda);
                    break;
                case 4 : system("cls");
                    Compila->menu_borrar(Mi_Agenda);
                    break;
                case 5 : system("cls");
                    Compila->menu_actualizar(Mi_Agenda);
                    break;
            }
        }
        else if(validar(operacion) && atoi(operacion.c_str())==6){
            cout<<"\n\t\t\tAdios\n"<<endl;
            break;
        }
        else {
            cout<<"\t\t\tOpcion incorrecta\n"<<endl;
            getch();
        }
    }while(true);
}

bool validar(string entrada){
    for(int i=0; i<entrada.length();i++){
        if(entrada[i]<48 || entrada[i]>57) return false;
    }
    return true;
}

bool encontrar(std::string primero,std::string segundo){
    size_t found=primero.find(segundo);
    if(found!=std::string::npos){
        return true;
    }
    return false;
}
string mayusculas(string entrada){
    for(int i = 0; i < entrada.length(); i++)
        entrada[i] = toupper(entrada[i]);
    return entrada;
}

Contacto Pedir_datos() {
    Contacto nuevo;
    string nombre,apellido,edad,email,numero_telf;
    cout<<"\t\t\tNOMBRE            : "; getline(cin,nombre); nuevo.setNombre(nombre);
    cout<<"\t\t\tAPELLIDO          : "; getline(cin,apellido); nuevo.setApellido(apellido);

    do{
        cout<<"\t\t\tEDAD              : "; getline(cin,edad);
        if(validar(edad) && (atoi(edad.c_str())>=0 && atoi(edad.c_str())<120)){
            nuevo.setEdad(edad);
            break;
        }
        else{
            cout<<"\t\t\tValor incorrecto\n"<<endl;
        }
    }while(true);

    do{
        cout<<"\t\t\tNUMERO TELEFONICO : "; getline(cin,numero_telf);
        if(validar(numero_telf) && numero_telf.length()==9){
            nuevo.setNumero_telf(numero_telf);
            break;
        }
        else{
            cout<<"\t\t\tInvalido\n"<<endl;
        }
    }while(true);

    cout<<"\t\t\tCORREO            : "; getline(cin,email); nuevo.setEmail(email);

    return nuevo;
}

