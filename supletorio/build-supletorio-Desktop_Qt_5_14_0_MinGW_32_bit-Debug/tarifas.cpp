#include "tarifas.h"



string tarifas::int2str(int long a){
    //esta funncion se usa para convertir las caracteristicas int a string y poder manejarlas mejor
    int c=0,i=1;
    char e;
    string b;
    for(;(a/i);i=i*10)
        c++;
    for(int j=0;j<c;j++){
        i/=10;
        e=(a/i)+48;
        b.push_back(e);
        a-=(a/i)*i;
    }
    return b;
}







