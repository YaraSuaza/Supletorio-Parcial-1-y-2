#include <iostream>

using namespace std;
#include <fstream>
#include <math.h>
#include <map>
#include <list>
#include <ctime>

class tarifas
{
public:

    //código usado en la practica 3
    unsigned short regla_1(short *seg,bool *data,unsigned short regla, unsigned long long semilla,bool dec);
    string leer_Txt(string arch);
    string bin2text(bool *cod,unsigned long long int l);
    string descifrar();
    void crear_tarifas();
    void escribir_txt(string texto,string arch);
    void text2bin(string texto,bool *cod);
    void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam,bool dec);



    //código de la práctica 2
    template <typename t>
    string int2str(t a);
    void devolver(int long long a);
    long int str2int(string a);

private:
    int long long costo;
    string int2str(int long a);
};


