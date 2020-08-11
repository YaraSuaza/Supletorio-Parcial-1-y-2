#include "nivel.h"

void nivel::setlevel(int level1){
    level= level1;
    calc_parqueo(level);
}
void nivel::calc_parqueo(int level){
    switch(level){
    case 1:
        cant_parqueo=70;
        tipo_vehiculo="Moto";
        break;
    case 2:
        cant_parqueo=70;
        tipo_vehiculo="Moto";
        break;
    case 3:
       cant_parqueo=50;
       tipo_vehiculo="Carro";
        break;
    case 4:
        cant_parqueo=50;
        tipo_vehiculo="Carro";
        break;
    case 5:
        cant_parqueo=50;
        tipo_vehiculo="Bicicleta";
        break;
    default:
        break;
        }
  parqueo_disp=cant_parqueo;
}

void nivel::disminuir_parqueo(){
    parqueo_disp--;
}

void nivel::aumentar_parqueo(){
    parqueo_disp++;
}

float nivel::cal_porc(){
    //se calcula el porcentaje de celdas disponibles por nivel
    return ((cant_parqueo-parqueo_disp)/cant_parqueo)*100;
}



void nivel::ver_nivel(){
    //En esta función se muestra la tabla de ocupación por nivel
    string ver="   |        "+to_string(cant_parqueo-parqueo_disp)+"          "+'|'+ "        "+ to_string(cant_parqueo)+"        "+'|' + "   "+to_string(this->cal_porc())+"    "+'|'+"     "+tipo_vehiculo+"     ";
    cout<<ver;
}

int nivel::disponibilidad(){
    return parqueo_disp;
}

void nivel::alquilar_parqueo(map<int, tarifas> &valor){
    //esta funcion se ejecuta cuando se alquila un parqueadero, lo que hace es ocupar una celda
//    map <int,int>::iterator it;
//    valor[it->first].disminuir_parqueo(it->second);

}




