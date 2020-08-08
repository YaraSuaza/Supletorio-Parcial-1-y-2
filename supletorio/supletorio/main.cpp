
#include <iostream>

using namespace std;

int main()
{   bool var=1;
    int opcion;
    cout<<    "      _____________________________________________\n"
              "      |   Bienvenido a su Parqueadero Multinivel  |\n";
    while (var==1){
        cout<<"      |___________________________________________|\n"
              "      |Que le gustaria hacer?                     |\n"
              "      |    1)Entrar como administrador            |\n"
              "      |    2)Crear un usuario                     |\n"
              "      |Si ya tiene un usuario                     |\n"
              "      |    3)Comprar un tiquete                   |\n"
              "      |___________________________________________|\n"
              "\nDigite el numero de la opcion a realizar o 0 para salir: ";
        cin>>opcion;
        switch(opcion){
        case 1:
            //iniciar_admi(inv,com);
            cout << "Hello World!" << endl;
            break;
        case 2:
                cout << "jaja!" << endl;
            //ingresar_usu(inv,com);
            break;
        case 3:
            //registrar_usu();
            break;
        case 0:
            var=0;
            break;
        default:
            break;
        }
        if(opcion!=0)system("pause");

    }
    return 0;
}
