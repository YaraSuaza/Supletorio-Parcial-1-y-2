#include "functions.h"

void mostrar_ocupaciones(map <int,nivel> &nive){
    //esta funcion recibe el map que contiene nivel, algunos de sus atributos
    map <int,nivel>::iterator jj;
    cout<<"\n|Nivel|  Celdas ocupadas  |  Celdas Totales  |  % Ocupacion  |   Tipo de Vehiculo  |\n";
    for(int i=0;i<85;i++) cout<<'-';
    cout<<endl;
    for(jj=nive.begin();jj!=nive.end();jj++){
        if(jj->first<6)
            cout<<"| "<<jj->first;
        else
            cout<<'|'<<jj->first;
        jj->second.ver_nivel();
        cout<<endl;
        for(int i=0;i<85;i++) cout<<'-';
        cout<<endl;}

}
void mostrar_tarifas(){
    string temp="",nivel,t,m,datos=leer_Txt("tarifas.txt");
    int j;
    for(unsigned long int i=0;i<datos.length();i++){
        j=0;
        while(i<datos.length()){
            if(datos[i]==';' || datos[i]=='\n' || i+1==datos.length()){
                if(i+1==datos.length()) temp.push_back(datos[i]);
                if(j==0){
                    if(nivel!=""){

                    cout<<"       __________________________________\n"
                          "       |Tarifa temporal(T) nivel "<<nivel<<": "<<t<<endl;
                    cout<<"       |Tarifa Mensual (M) nivel "<<nivel<<": "<<m<<endl;
                    }
                  nivel=temp;
                }
                else if(j==1)
                    t=temp;
                else if(j==2)
                    m=temp;
                temp="";
                if(datos[i]=='\n') break;
                j++;
            }
            else
                temp.push_back(datos[i]);
            i++;
        }
    }

}

void Nuevo_usu(){
    /*esta funcion se encarga de registrar a los nuevos usuarios en el txt "usuarios"*/
    map <string,string> users;
    cargar_usuarios(users);
    string clave,usuario,datos=leer_Txt("usuarios.txt");
    int chequeo=users.size();
    if (chequeo==0){
        cout<<"\nIngrese el numero de su cedula: ";
        cin>>usuario;
        cout<<"\nIngrese la clave de su nuevo usuario: ";
        cin>>clave;
        datos= usuario + ';' + clave + '\n';
        escribir_txt(datos,"usuarios.txt");

    }
    else{
        usuario=(users.begin())->first;
        while(users.find(usuario)!=users.end()){
            cout<<"\nIngrese el numero de su cedula: ";
            cin>>usuario;
            if(users.find(usuario)!=users.end())cout<<"\nLa cedula ingresada ya esta en el sistema\n";}
        cout<<"\nIngrese la clave de su nuevo usuario: ";
        cin>>clave;
        datos= datos+usuario + ';' + clave+'\n';
        escribir_txt(datos,"usuarios.txt");
    }
}

void inicio_usu(){
//Esta es la funcion que se encarga de pedir la cedula y la clave del usuario
    string user,clave;
    map <string,string> users;//aqui se almacena la cedula y contraseña del usuario
    map <string,string>::iterator it;
    cargar_usuarios(users);
    for(int i=1;i<=3;i++){
        cout<<"\nIngrese su numero de cedula: ";
        cin>>user;
        if(users.find(user)==users.end())
            cout<<"\nEl numero de cedula ingresada no se encuentra registada intento "<<i<<" de 3\n";
        else{
            for(int j=1;j<=3;j++){
                cout<<"\nIngrese su clave: ";
                cin>>clave;
                if(clave==users[user]){
                    j=4;
                    i=4;

                    usuario();
                }
                else
                    cout<<"\nLa clave ingresada no coincide intento "<<i<<" de 3\n";
            }
        }
    }
}


void cargar_usuarios(map <string,string> &usu){
/*Esta funcion extrae los usuarios y claves del archivo "usuarios.txt"
para devolverlo al sistema en un map por referencia*/
    map <string,string>::iterator is;
    string tempc,temp="",datos=leer_Txt("usuarios.txt");
    for(unsigned int i=0;i<datos.length();i++){
        if(datos[i]==';'){
            tempc=temp;
            temp="";}
        else if(datos[i]=='\n' || i+1==datos.length()){
            if(i+1==datos.length()) temp.push_back(datos[i]);
            if(temp[temp.length()-1]=='\r')
                temp.pop_back();
            usu.insert(pair<string,string>(tempc,temp));
            temp="";
        }
        else
            temp.push_back(datos[i]);
    }
}

void iniciar_nive(map <int,nivel> &nive){
/*Esta funcion es para inicializar el mapa nive
la clave es el nivel*/
    nivel a;
    for(int i=1;i<6;i++){
        a.setlevel(i);
        a.calc_parqueo(i);
        nive.insert(pair<int,nivel>(i,a));
        }

}

void iniciar_admi(map <int,tarifas> &valor,map <int,nivel> &nive){
    //Se pide la clave y se compara con la decodificación en el archivo sudo.txt
    //recibe los mapas de tarifas y nivel
    string clave;
    cout<<"\nIngrese la clave de administrador: ";
    cin>>clave;
    if(clave!=descifrar()){
        cout<<"\nCLAVE INCORRECTA\n";
        return;}
    else{
        cout<<"       _____________________________________\n"
              "       |                                    |\n"
              "       |       Bienvenido administrador     |\n"
              "       |____________________________________|\n";
        administrador(valor,nive);}
}

void administrador(map <int,tarifas> &valor,map <int,nivel> &nive){
    tarifas *obejto= new tarifas; //Este objeto permite llamar a la funcion crear_tarifas
    short op;
    bool var=1;
    while(var==1){
        cout<<"       |                                    |\n"
              "       |Que le gustaria hacer?              |\n"
              "       |    1)Ver tabla de ocupaciones      |\n"
              "       |    2)Crear Tarfias                 |\n"
              "       |    3)Ver un el reporte de ventas   |\n"
              "       |    0)Salir                         |\n"
              "       |____________________________________|\n"
              "Digite el numero de la opcion a realizar ";
        cin>>op;
        switch(op){
        case 1:
            mostrar_ocupaciones(nive);
            break;
        case 2:
            obejto->crear_tarifas();
            break;
        case 3:
            cout<<leer_Txt("reporte.txt");
        case 0:
            var=0;
            break;
        default:
            cout<<"\nLa opcion digitada es invalida intente otra vez\n"<<endl;
            break;
        }
        system("pause");
    }
}



void save_reporte(string hist){
//Generar un reporte con el historial del dia.
    string fecha,datos=leer_Txt("reporte.txt");
    time_t now= time(0);
    tm *time= localtime(&now);
    fecha=int2str(time->tm_mday)+ "/" + int2str(time->tm_mon+1) + '/' + int2str(1900+time->tm_year);
    fecha=fecha + "   " + int2str(time->tm_hour) + ':' + int2str(time->tm_min) + ':' + int2str(time->tm_sec) + '\n';
    fecha=datos + fecha + hist + "\n\n";
    escribir_txt((fecha),"reporte.txt");
}


void usuario(){
/*Esta funcion permite que el usuario compre tiquete del parqueadero y
archiva esa informacion*/
    int temp;
    bool var=1;
    list <int>::iterator lit;
    string history;
    while (var){
        cout<<"       __________________________________\n"
              "       |         TABLA DE TARIFAS       |\n"
              "       |                                |\n"
              "       |           nivel                |\n"
              "       |  MOTOS:   1 y 2                |\n"
              "       |  CARROS:  3 Y 4                |\n"
              "       |  BICICLETAS: 5                 |\n"
              "       |                                |\n";
        mostrar_tarifas();
        cout<<"\nDigite el numero de nivel en que desea parquear: ";
        cin>>temp;
        var=0;

}
}

//funciones de la practica 3
string leer_Txt(string arch){
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

void escribir_txt(string texto,string arch){
//Escribe en arch el texto del string texto
    ofstream k(arch.c_str(), ios::out | ios::binary);
    k<<texto<<endl;
    k.close();
}
string descifrar(){
/*Esta funcion se utiliza para desifrar la clave del administrador,
esta recompila las otras funciones de la practica 3 para desifrar el
archivo "sudo.dat" donde se guarda la clave, la cual esta cifrada con
el metodo 1 y semilla 5 de la practica 3*/
    string texto;
    texto=leer_Txt("sudo.txt");
    bool *cod= new bool [8*(texto.length())];
    text2bin(texto,cod);
    separacion(5,cod,8*(texto.length()),0);
    texto=bin2text(cod,8*(texto.length()));
    return texto;
}

void text2bin(string texto,bool *cod){
    //Esta funcion convierte un string dado a binario segunla tabla ASCII, y lo devuelve en un array binario dado
    char s;
    for(unsigned long long int i=0;i<(texto.length());i++){
        s=char(texto[i]);
        for(int j=0;j<8;j++) cod[8*i+j]=(((s<<j)&0x80)==0x80);
    }
}

string bin2text(bool *cod,unsigned long long int l){
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
void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam,bool dec){
    //Esta funcion se encarga de separar el array de bool en la partes de la semilla y le pasa los segmentos a la funcion que los decifra
    short *seg = new short[semilla];
    long long int j=0;
    unsigned short tp=0;
    for(unsigned long long int i=0;i<semilla;i++) seg[i]=-1;
    for(unsigned long long int i=0,l=0; i<tam; i++,j++){
        seg[j]=cod[i];
        if((i+1)%semilla==0 || i==(tam-1)){
            tp=regla_1(seg,&cod[semilla*l],tp,semilla,dec);
            for(unsigned long long int k=0;k<semilla;k++) seg[k]=-1;
            l++;
            j=-1;
        }
    }
}

unsigned short regla_1(short *seg, bool *data, unsigned short regla, unsigned long long int semilla,bool dec){
    //En esta funcion se implementan las reglas para decodificar
    int contador[2]={0,0};
    unsigned short reg=0;
    for(unsigned long long int i=0; i<semilla; i++){
        if(seg[i]!=-1){
            switch (regla){
                case 0: data[i]=1-seg[i];

                break;

                case 1: if(i%2!=0) data[i]=1-seg[i];

                break;

                default: if((i+1)%3==0) data[i]=1-seg[i];
            }
          if(dec) contador[seg[i]]++;
          else contador[data[i]]++;
        }
    }
    if(contador[0]>contador[1]) reg=1;
    else if(contador[0]<contador[1]) reg=2;
    return reg;
}



//De la practica 2

void devolver(int long long a){
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

long int str2int(string a){
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
string int2str(t a){
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

