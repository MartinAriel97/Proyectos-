/******************************************************************************

Listas enlazadas. Nodo. punteros. Heap. memoria dinamica.struct
Listas simplemenete enlazadas. 

*******************************************************************************/
#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente = nullptr;
};

void agregar_nodo(Nodo*& cabeza, int valor)
{
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = cabeza;
    cabeza = nuevo_nodo;
}

void eliminar_nodo(Nodo*& cabeza, int valor)
    {
    if (cabeza == nullptr) 
    {
        cout << "La lista esta vacia ..." << endl;
        return;
    }

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->dato != valor)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) 
    {
        cout << "El valor " << valor << " no se encuentra en la lista." << endl;
        return;
    }

    if (anterior == nullptr) 
    {
        cabeza = actual->siguiente;
    }
    else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    cout << "Nodo eliminado: " << valor << endl;
    }


bool buscar_nodo(Nodo* cabeza, int valor) 
{
    Nodo* actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->dato == valor) 
        {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}


void mostrar_datos(Nodo* cabeza)
{
    Nodo* actual = cabeza;
    while (actual != nullptr)
    {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}

int main() 
{
    Nodo* cabeza = nullptr;

    agregar_nodo(cabeza, 101);
    agregar_nodo(cabeza, 102);
    agregar_nodo(cabeza, 103);

    eliminar_nodo(cabeza, 103);

    mostrar_datos(cabeza);

    eliminar_nodo(cabeza, 102);

    if (buscar_nodo(cabeza, 20)) 
    {
        cout << "Nodo 20 encontrado." << endl;
    } 
    else 
    {
        cout << "Nodo 20 no encontrado." << endl;
    }

    eliminar_nodo(cabeza, 20);

    mostrar_datos(cabeza); 

    return 0;
}