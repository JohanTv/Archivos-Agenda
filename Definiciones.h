#ifndef POO_DEFINICIONES_H
#define POO_DEFINICIONES_H

#include <iostream>
#include <fstream>
using namespace std;
const char DATOS[]="datos_agenda.txt";
const int MAX_CONTACTOS=100;

class Archivo{
private:
    int numero_lineas=0;
    bool compilar=false;
public:
    Archivo(){};
    Archivo(bool _compilar){compilar=_compilar;}

    void setLineas(int _lineas) {numero_lineas=_lineas;}
    int getLineas(){return numero_lineas;}
    void Obtener_Lineas(){
        string relleno;
        ifstream entrada;
        entrada.open(DATOS);
        int contador=0;
        
		if(entrada.good()){
            while(!entrada.eof()){
                getline(entrada,relleno);
                contador++;
            }
        }
        
        entrada.close();
        
		if(contador==0){
            numero_lineas=0;
        }
        else{
            numero_lineas=contador-1;
        }
    }

};

#endif //POO_DEFINICIONES_H

