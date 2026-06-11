#include "Inventario.h"
#include <iostream>

void Inventario:: agregarProducto(const Producto& nuevo_producto)
{
    listaProductos.push_back(nuevo_producto);

}

void Inventario:: mostrarInventario()const
{
    if(listaProductos.empty())
        {
            std::cout<<"Inventario vacio ";
        }
    for(const Producto& p : listaProductos)
    {
       std:: cout<<"ID: " <<  p.getId() << 
        "nOMBRE:" << p.getNombre() <<
        "sTOCK: " << p.getStock() << std:: endl;
    }

}

Producto* Inventario :: buscarProductoPorId(int idBuscado)
{
    for(size_t i = 0; i < listaProductos.size();i++)
    {
        if(listaProductos[i].getId() ==idBuscado)
        {
            return &listaProductos[i];
        }
    }

    return nullptr;

}