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
       std:: cout<<"ID: " <<  p.getId();
       std:: cout<<"nOMBRE:" << p.getNombre();
       std:: cout<<"sTOCK: " << p.getStock();
    }

}