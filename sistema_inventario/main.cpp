#include "Inventario.h"
#include "Producto.h"
#include <string>
#include <iostream>
using namespace std;


void agregarMenu(Inventario& inv)
{
    int id;
    string nombre;
    double precio;
    int stock;

    cout << "\n--- DAR DE ALTA PRODUCTO ---" << endl;
    cout << "Ingrese el ID: "; 
    cin >> id;
    cout << "Ingrese el Nombre: "; 
    cin >> nombre;
    cout << "Ingrese el Precio: "; 
    cin >> precio;
    cout << "Ingrese el Stock: "; 
    cin >> stock;

    // Creamos el producto con tus validaciones de seguridad
    Producto nuevo(id, nombre, precio, stock);
    
    
    inv.agregarProducto(nuevo);
    
    cout << "¡Producto agregado con exito!\n" << endl;
}

void buscarMenu(Inventario& inv) 
{
    int idBuscado;
    cout << "\n--- BUSCAR PRODUCTO ---" << endl;
    cout << "Ingrese el ID del producto a buscar: ";
    cin >> idBuscado;

    // Usamos tu función del cerebro que devuelve el puntero
    Producto* encontrado = inv.buscarProductoPorId(idBuscado);

    // Validación resolutiva con el puntero
    if (encontrado == nullptr) 
    {
        cout << "[ERROR]: El producto con ID " << idBuscado << " no existe.\n" << endl;
    } 
    else 
    {
        cout << "¡Producto Encontrado!" << endl;
        cout << "Nombre: " << encontrado->getNombre() << " | Stock Actual: " << encontrado->getStock() << endl;
        
        int cambioStock;
        cout << "Ingrese cantidad a modificar (positivo para reponer, negativo para vender): ";
        cin >> cambioStock;
        
        
        encontrado->modificarStock(cambioStock); 
    }
}


int main()
{
    Inventario inventario;
    int opcion;

    do
    {
   
    cout << "\n--- SISTEMA DE INVENTARIO ---" << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Mostrar Inventario" << endl;
        cout << "3. Buscar/Modificar Producto" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
   

        switch(opcion)
        {
            case 1:
            agregarMenu(inventario);
            break;

            case 2:
            inventario.mostrarInventario();
            break;

            case 3:
            cout<<"Saliendo del programa ";
            break;

            default:
            cout<<"Opcion invalida";
            break;
        }

    } while(opcion != 4);
    
    return 0;
}