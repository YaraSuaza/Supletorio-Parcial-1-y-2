#include <iostream>
#include "nivel.h"

using namespace std;
#include <fstream>
#include <list>
#include <ctime>
#include <map>
#include <math.h>


void Nuevo_usu();
void cargar_usuarios(map <string,string> &usu);
void iniciar_admi(map <int,tarifas> &valor,map <int,nivel> &nive);
void administrador(map <int,tarifas> &inv,map <int,nivel> &com);


//código usado en la practica 3
unsigned short regla_1(short *seg,bool *data,unsigned short regla, unsigned long long semilla,bool dec);
string leer_Txt(string arch);
string bin2text(bool *cod,unsigned long long int l);
string descifrar();
void escribir_txt(string texto,string arch);
void text2bin(string texto,bool *cod);
void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam,bool dec);



//código de la práctica 2
template <typename t>
string int2str(t a);
void devolver(int long long a);
long int str2int(string a);




