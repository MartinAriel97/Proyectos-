#include <iostream>
using namespace std;

struct Empleado
{
    string nombre;
    int edad;
    long telefono;
    double salario;
};

void insertarEmpleado(Empleado &e)
{
    cout << "INGRESE SU NOMBRE: ";
    cin >> e.nombre;
    cout << "INGRESE SU EDAD: ";
    cin >> e.edad;
    cout << "INGRESE SU TELEFONO: ";
    cin >> e.telefono;
    cout << "INGRESE SU SALARIO: ";
    cin >> e.salario;
}

float calcularSalarioPromedio(Empleado empleados[], int cantidad)
{
    double sumatoria = 0;
    for (int i = 0; i < cantidad; i++)
    {
        sumatoria += empleados[i].salario;
    }
    return cantidad > 0 ? sumatoria / cantidad : 0;
}

void mostrarDatosEmpleado(const Empleado &e)
{
    cout << "Nombre: " << e.nombre << endl;
    cout << "Edad: " << e.edad << endl;
    cout << "Telefono: " << e.telefono << endl;
    cout << "Salario: " << e.salario << endl;
}

int main()
{
    const int MAX_EMPLEADOS = 100;
    Empleado empleados[MAX_EMPLEADOS];
    int cantidadEmpleados = 0;
    int opcion;

    do
    {
        cout << "\nMENU:\n";
        cout << "1- INGRESAR DATOS DEL EMPLEADO\n";
        cout << "2- CALCULAR EL SALARIO PROMEDIO\n";
        cout << "3- MOSTRAR LOS DATOS DE TODOS LOS EMPLEADOS\n";
        cout << "4- SALIR DEL PROGRAMA\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (cantidadEmpleados < MAX_EMPLEADOS)
            {
                insertarEmpleado(empleados[cantidadEmpleados]);
                cantidadEmpleados++;
            }
            else
            {
                cout << "No se pueden agregar más empleados." << endl;
            }
            break;

        case 2:
            cout << "El salario promedio es: " << calcularSalarioPromedio(empleados, cantidadEmpleados) << endl;
            break;

        case 3:
            for (int i = 0; i < cantidadEmpleados; i++)
            {
                cout << "\nEmpleado " << i + 1 << ":" << endl;
                mostrarDatosEmpleado(empleados[i]);
            }
            break;

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
        }

    } while (opcion != 4);

    return 0;
}