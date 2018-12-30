#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Contacto.h"
#include "Menu.h"
#include "Definiciones.h"
#include "Presentacion.h"
using namespace std;
void Menu::menu_ingresar(Agenda_Telf *la_agenda) {
    cout<<"\t\t\t\tINGRESO DE NUEVO CONTACTO"<<endl;
    Contacto nuevo = Pedir_datos();
    string operacion;
    cout<<"\t\t\tSeguro que desea registrar el contacto?"<<endl;
    do{
        cout<<"\t\t\tSI[1]....NO[2]: "; cin>>operacion;
        if(validar(operacion) && atoi(operacion.c_str())==1){
            la_agenda->Ingresar_contacto(nuevo);
            cout<<"\t\t\t    ****Contacto agregado con exito****"<<endl;
			getch();
            break;
        }
        else if(validar(operacion) && atoi(operacion.c_str())==2){
            cout<<"\t\t\t    ****Contacto no agregado****"<<endl;
            getch();
            break;
        }
        else {
            cout<<"\t\t\tOpcion incorrecta\n"<<endl;
        }
    }while(true);
}

void Menu::menu_listado(Agenda_Telf *la_agenda) {
    cout<<"\t\t\t\tLISTA DE CONTACTOS ("<<la_agenda->getNumero_contactos()<<")"<<endl;
    la_agenda->Mostrar_contactos();
    cout<<"\t\t\tSALIR DE LA LISTA             ---> [0]"<<endl;
    cout<<"\t\t\tVER MAS DETALLES DEL CONTACTO ---> [NUMERO]"<<endl;
    string operacion;
    do{
        cout<<"\t\t\tOPCION: "; getline(cin,operacion);
        if(validar(operacion) && (atoi(operacion.c_str())>0 && atoi(operacion.c_str())<=la_agenda->getNumero_contactos())){
                cout<<endl;
                la_agenda->getMis_contactos()[atoi(operacion.c_str())-1].Mostrar_datos();
                getch();
                break;
        }
        else if(validar(operacion) && atoi(operacion.c_str())==0){
            break;
        }
        else{
            cout<<"\t\t\tOPCION INCORRECTA"<<endl;
        }
    }while(true);
}

void Menu::menu_busqueda(Agenda_Telf *la_agenda) {
    string busqueda;
    cout<<"\t\t\t\tBUSCAR CONTACTO"<<endl;
    cout<<"\t\t\tBuscar contacto: "; getline(cin,busqueda);
    Contacto* temporal=new Contacto[MAX_CONTACTOS];
    int num=la_agenda->Buscar_contactos(busqueda,temporal);
    if(num!=0){
        string operacion;
        cout<<"\t\t\tSALIR DE LA LISTA             ---> [0]"<<endl;
        cout<<"\t\t\tVER MAS DETALLES DEL CONTACTO ---> [NUMERO]"<<endl;
        do{
            cout<<"\t\t\tOPCION: ";getline(cin,operacion);
            if(validar(operacion) && (atoi(operacion.c_str())>0 && atoi(operacion.c_str())<=num)){
                    cout<<endl;
                    temporal[atoi(operacion.c_str())-1].Mostrar_datos();
                    getch();
                    break;

            }
            else if(validar(operacion) && atoi(operacion.c_str())==0){
                break;
            }
            else{
                cout<<"\t\t\tOPCION INCORRECTA"<<endl;
            }
        }while(true);
    }
    else{
        cout<<"\t\t\tNO SE ENCUENTRA"<<endl;
        getch();
    }
    delete[] temporal;

}

void Menu::menu_borrar(Agenda_Telf *la_agenda){
    string busqueda;
    string opcion;
    cout<<"\t\t\t\tELIMINAR CONTACTO"<<endl;
    cout<<"\t\t\tBuscar contacto: "; getline(cin,busqueda);
    Contacto* temporal=new Contacto[MAX_CONTACTOS];
    int num=la_agenda->Buscar_contactos(busqueda,temporal);
    if(num!=0){
        cout<<"\t\t\tNO BORRAR NINGUN CONTACTO      ----> [0]"<<endl;
        cout<<"\t\t\tBORRAR EL CONTACTO             ----> [NUMERO]"<<endl;
        do{
            cout<<"\t\t\tOPCION: ";
            getline(cin, opcion);
            if (validar(opcion) && (atoi(opcion.c_str()) >= 1 && atoi(opcion.c_str()) <= num)) {
                    string operacion;
                    cout << "\n\n\t\t\tSeguro que desea eliminar el siguiente contacto?";
                    temporal[atoi(opcion.c_str())-1].Mostrar_datos();
                    do{
                        cout << "\n\t\t\tSI[1]....NO[2]: ";
                        getline(cin, operacion);
                        if (validar(operacion) && atoi(operacion.c_str())==1) {
                            la_agenda->Eliminar_contacto(temporal[atoi(opcion.c_str())-1]);
                            cout << "\t\t\tContacto eliminado con exito" << endl;
                            getch();
                            break;
                        }
                        else if(validar(operacion)&& atoi(operacion.c_str())==2){
                            cout << "\t\t\tContacto NO eliminado" << endl;
                            getch();
                            break;
                        }
                        else{
                            cout << "\t\t\tOPCION INCORRECTA" << endl;
                        }
                    }while(true);
                    break;
            }
            else if (validar(opcion) && atoi(opcion.c_str())==0) {
                    cout<<"\t\t\tContacto NO eliminado"<<endl;
                    getch();
                    break;
            }
            else {
                    cout << "\t\t\tOPCION INCORRECTA" << endl;

            }
            }while(true);
    }
    else{
        cout<<"\t\t\tNO EXISTE EL CONTACTO"<<endl;
        getch();
    }
    delete[] temporal;
}

void Menu::menu_actualizar(Agenda_Telf *la_agenda) {
    string busqueda;
    cout<<"\t\t\t\tACTUALIZAR CONTACTO"<<endl;
    cout<<"\t\t\tBuscar contacto: "; getline(cin,busqueda);
    Contacto* temporal=new Contacto[MAX_CONTACTOS];
    int num=la_agenda->Buscar_contactos(busqueda,temporal);
    if(num!=0){
        string opcion;
        cout<<"\t\t\tNO ACTUALIZAR NINGUN CONTACTO  ----> [0]"<<endl;
        cout<<"\t\t\tACTUALIZAR EL CONTACTO         ----> [NUMERO]"<<endl;
        do{
            cout<<"\t\t\tOPCION: "; getline(cin,opcion);
            if(validar(opcion) && (atoi(opcion.c_str())>0 && atoi(opcion.c_str())<=num)){
                    string operacion;
                    temporal[atoi(opcion.c_str())-1].Mostrar_datos();
                    cout<<endl;
                    cout<<"\t\t\tCual atributo actualizar?"<<endl;
                    cout<<"\t\t\tNombre................[1]"<<endl;
                    cout<<"\t\t\tApellido..............[2]"<<endl;
                    cout<<"\t\t\tEdad..................[3]"<<endl;
                    cout<<"\t\t\tNumero telefonico.....[4]"<<endl;
                    cout<<"\t\t\tCorreo electronico....[5]"<<endl;
                    cout<<"\t\t\tNinguno...............[0]"<<endl;
                    do{
                        cout<<"\t\t\tOPCION: "; getline(cin,operacion);
                        if(validar(operacion) && (atoi(operacion.c_str())>=1 && atoi(operacion.c_str())<=5)){
                                string actualizar;
                                string op;
                                int posicion=la_agenda->Encontrar_posicion_contacto(temporal[atoi(opcion.c_str())-1]);
                                switch(atoi(operacion.c_str())){
                                    case 1:
                                    {
                                        cout<<"\n\t\t\tNUEVO Nombre: "; getline(cin,actualizar);
                                        cout<<"\t\t\tSeguro? ";
                                        do{
                                            cout<<"SI[1]....NO[2]:"; getline(cin,op);
                                            if(validar(op) && atoi(op.c_str())==1){
                                                la_agenda->Actualizar_Contacto(posicion,'n',actualizar);
                                                cout<<"\t\t\tContacto actualizado con exito"<<endl;
                                                getch();
                                                break;
                                            }
                                            else if(validar(op) && atoi(op.c_str())==2){
                                                cout<<"\t\t\tNO SE ACTUALIZO"<<endl;
                                                getch();
                                                break;
                                            }
                                            else{
                                                cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                                            }
                                        }while(true);
                                        break;
                                    }
                                    case 2:
                                    {
                                        cout<<"\t\t\tNUEVO Apellido: "; getline(cin,actualizar);
                                        cout<<"\t\t\tSeguro? ";
                                        do{
                                            cout<<"SI[1]....NO[2]:"; getline(cin,op);
                                            if(validar(op) && atoi(op.c_str())==1){
                                                    la_agenda->Actualizar_Contacto(posicion,'a',actualizar);
                                                    cout<<"\t\t\tContacto actualizado con exito"<<endl;
                                                    getch();
                                                    break;
                                            }
                                            else if(validar(op) && atoi(op.c_str())==2){
                                                cout<<"\t\t\tNO SE ACTUALIZO"<<endl;
                                                getch();
                                                break;
                                            }
                                            else{
                                                cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                                            }}while(true);
                                        break;
                                    }
                                    case 3:
                                    {
                                        do{
                                            cout<<"\t\t\tNUEVA Edad: "; getline(cin,actualizar);
                                            if(validar(actualizar) && (atoi(actualizar.c_str())>0 && atoi(actualizar.c_str())<=120)){
                                                cout<<"\t\t\tSeguro? ";
                                                do{
                                                    cout<<"SI[1]....NO[2]:"; getline(cin,op);
                                                    if(validar(op) && atoi(op.c_str())==1){
                                                            la_agenda->Actualizar_Contacto(posicion,'e',actualizar);
                                                            cout<<"\t\t\tContacto actualizado con exito"<<endl;
                                                            getch();
                                                            break;
                                                    }
                                                    else if (validar(op) && atoi(op.c_str())==2){
                                                        cout<<"\t\t\tNO SE ACTUALIZO"<<endl;
                                                        getch();
                                                        break;
                                                    }
                                                    else{
                                                        cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                                                    }
                                                }while(true);
                                                break;
                                            }
                                            else{
                                                cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                                            }
                                        }while(true);

                                        break;
                                    }
                                    case 4:
                                    {
                                        do{
                                            cout<<"\t\t\tNUEVO numero Telefonico: "; getline(cin,actualizar);
                                            if(validar(actualizar) && actualizar.length()==9){
                                                cout<<"\t\t\tSeguro? ";
                                                do{
                                                    cout<<"SI[1]....NO[2]:"; getline(cin,op);
                                                    if(validar(op) && atoi(op.c_str())==1){
                                                        la_agenda->Actualizar_Contacto(posicion,'t',actualizar);
                                                        cout<<"\t\t\tContacto actualizado con exito"<<endl;
                                                        getch();
                                                        break;
                                                    }
                                                    else if(validar(op)&& atoi(op.c_str())==2){
                                                        cout<<"\t\t\tNO SE ACTUALIZO"<<endl;
                                                        getch();
                                                        break;
                                                    }
                                                    else{
                                                        cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                                                    }
                                                }while(true);
                                            break;
                                            }
                                            else{
                                                cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                                            }
                                        }while(true);
                                        break;
                                    }
                                    case 5:
                                    {
                                        cout<<"\t\t\tNUEVO correo electronico: "; getline(cin,actualizar);
                                        cout<<"\t\t\tSeguro? ";
                                        do{
                                            cout<<"SI[1]....NO[2]:"; getline(cin,op);
                                            if(validar(op) && atoi(op.c_str())==1){
                                                la_agenda->Actualizar_Contacto(posicion,'c',actualizar);
                                                cout<<"\t\t\tContacto actualizado con exito"<<endl;
                                                getch();
                                                break;
                                            }
                                            else if(validar(op) && atoi(op.c_str())==2){
                                                cout<<"\t\t\tNO SE ACTUALIZO"<<endl;
                                                getch();
                                                break;
                                            }
                                            else{
                                                cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                                            }
                                        }while(true);

                                        break;
                                    }
                                }
                                break;
                        }
                        else if (validar(operacion) && atoi(operacion.c_str())==0) break;
                        else cout<<"\t\t\tOPCION INCORRECTA"<<endl;
                    }while(true);

                    break;

            }
            else if(validar(opcion) && atoi(opcion.c_str())==0){
                break;
            }
            else{
                cout<<"\t\t\tOPCION INCORRECTA"<<endl;
            }
        }while(true);
    }
    else{
        cout<<"\t\t\tNO EXISTE EL CONTACTO"<<endl;
        getch();
    }
    delete[] temporal;
}

