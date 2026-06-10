
#include<iostream>
using namespace std;

struct Barco
{
    string nombre;
    int designacion;
    double carga;

};

void agregarBarco(Barco &bar)
{
    cout<<"Ingrese el nombre del barco " <<endl;
    cin>>bar.nombre;
    cout<<"Ingrese la designacion del barco: "<<endl;
    cin>>bar.designacion;
    cout<<"Ingrese la cantidad de carga que lleva el barco: "<<endl;
    cin>>bar.carga;

}


void mostrar_datos(Barco &bar)
{
    cout<<"Nombre del barco:"<< bar.nombre<< endl;
    cout<<"Designacion: "<< bar.designacion<< endl;
    cout<<"Cantidad de carga : "<< bar.carga<< endl;
}

double calcular_carga_promedio(Barco barcos[],int cantidad_barcos)
{
    double carga_total = 0.0;
    for(int i = 0; i<cantidad_barcos; i++)
    {
        carga_total += barcos[i].carga;
    }
    return carga_total / cantidad_barcos;
}




int main()
{
    Barco barcos[5];
    int cantidad = 0; //Cantidad de barcos ingresados 
    int opcion;
    
  

    do
    {

        cout<<"1-INGRESAR LOS DATOS DEL BARCO "<<endl;
        cout<<"2-MOSTRAR LOS DATOS DEL BARCO "<<endl;
        cout<<"3-CALCULAR CARGA TOTAL PROMEDIO DE LOS BARCOS QUE LLEGAN AL PUERTO "<<endl;
        cout<<"4- SALIR DEL PROGRAMA "<<endl;
        cout<<"Ingrese una opcion: "<<endl;

        cin>>opcion;

        switch(opcion)
        {
            case 1:
            if(cantidad < 5)
            {
                agregarBarco(barcos[cantidad]);
                cantidad++;
            }
            else
            {
                cout<<"Ya se ingresaron los barcos: "<<endl;

            }
            
            break;

            case 2: 
            for(int i = 0; i< cantidad; i++)
            {
                cout<<"Barco: "<< (i +1) << endl;
                mostrar_datos(barcos[i]);
                
            }
            if(cantidad == 0)
            {
                cout<<"No hay barcos ingresados en el historial"<<endl;
            }
            
            break;

            case 3:
            //Si cantidad es mayor a cero, entonces calcular la carga total 
            if(cantidad > 0)
            {
                double promedio = calcular_carga_promedio(barcos, cantidad);
                cout<<"La carga promedio total de los barcos es de: "<< promedio <<endl;
            }
            else 
            {
                cout<<"No hay barcos para calcular la carga total..."<<endl;
            }
            break;


            case 4:
            cout<<"Saliendo del programa ... "<<endl;
        }
    } while (opcion != 4);
    
    return 0;
}