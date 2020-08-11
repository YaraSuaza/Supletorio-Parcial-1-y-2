#include "tarifas.h"
#include <iostream>

using namespace std;
#include <fstream>
#include <list>
#include <ctime>
#include <math.h>
#include <map>

class nivel
{
public:
    long long int costo;
    void setlevel(int level1);
    void calc_parqueo(int level);
    void disminuir_parqueo();
    void aumentar_parqueo();
    float cal_porc();
    void ver_nivel();
    int disponibilidad();

    void alquilar_parqueo(map <int,tarifas> &valor);


private:
    int level;
    string tipo_vehiculo;
    int cant_parqueo;
    int parqueo_disp;
};
