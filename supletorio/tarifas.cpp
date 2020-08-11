#include "tarifas.h"

void tarifas::crear_tarifas(){
/*esta funcion se encarga de crear las nuevas tarifas en el txt "tarifas"*/
string nivel,temporal,mensual,datos="";
   for(int i=1;i<6;i++){
    cout<<  "       __________________________________\n"
            "       |Tarifa temporal(T) nivel "<<i<<": ";
    cin>>temporal;
    cout<<  "       |Tarifa mensual (M) nivel "<<i<<": ";
    cin>>mensual;

    datos= datos + to_string(i)+';'+ temporal + ';' + mensual+'\n';
    }
   cout<<   "       |________________________________|"<<endl;
   escribir_txt(datos,"tarifas.txt");
}



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

//funciones de la practica 3
string tarifas::leer_Txt(string arch){
    //esta funcion abre el archivo dado y regresa un string con el contenido del archivo
    long long int tam;
    string salida, s2;
    char s;
    fstream k_1(arch, ios::in | ios::ate);
    tam=k_1.tellg();
    k_1.close();
    fstream k(arch.c_str(), ios::in | ios::binary);
    for(long long int i=0;i<tam;i++){
        k.get(s);
        salida.push_back(s);
    }
    k.close();
    return salida;
}

void tarifas::escribir_txt(string texto,string arch){
//Escribe en arch el texto del string texto
    ofstream k(arch.c_str(), ios::out | ios::binary);
    k<<texto<<endl;
    k.close();
}


void tarifas::text2bin(string texto,bool *cod){
    //Esta funcion convierte un string dado a binario segunla tabla ASCII, y lo devuelve en un array binario dado
    char s;
    for(unsigned long long int i=0;i<(texto.length());i++){
        s=char(texto[i]);
        for(int j=0;j<8;j++) cod[8*i+j]=(((s<<j)&0x80)==0x80);
    }
}

string tarifas::bin2text(bool *cod,unsigned long long int l){
    //Esta funcion convierte el array binario de la funcion anterior en un string y lo devuelve
    string text="";
    string s;
    int sum=0,c=0;
    for(unsigned long long int i=0;i<l;i+=8){
        c=0;
        sum=0;
        for(int j=7;j>=0;j--){
            sum+=cod[i+j]*pow(2,c);
            c++;
        }
        s=sum;
        text.append(s);
    }
    return text;
}



//De la practica 2

void tarifas::devolver(int long long a){
//esta funcion se encarga de mostrar al usuario la cantidad que se le devuelve
    int long long c;
    int long long b[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    cout<<"\nDevolucion\n";
    for(int long long i=0;i<10;i++){
        c=a/b[i];
        a%=b[i];
        cout<<b[i]<<": "<<c<<endl;
    }
    cout<<"Faltante: "<<a<<endl;
}

long int tarifas::str2int(string a){
    //esta funcion recibe un string y lo convierte en un entero
    int b,l,d=1,c=0;
    l=a.length();
    for(int i=l-1;i>=0;i--){
        b=a[i]-48;
        c+=b*d;
        d*=10;
    }
    return c;
}

template <typename t>
string tarifas::int2str(t a){
    //esta funcion recibe un numero entero y lo devuelve en string
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








