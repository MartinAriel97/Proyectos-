#include "Producto.h" //Para archivos con comillas
#include<iostream>  //Solo <> para librerias 

Producto::Producto(int _id, std:: string _nombre, double _precio, int _stock){

id = _id;
nombre = _nombre;

if(_precio > 0)
{
    precio = _precio;
}
else
{
    precio = 0.0;
}

if(_stock > 0)
{
    stock = _stock;
}
else
{
    stock = 0.0;
}

}

void Producto:: setPrecio(double nuevo_precio)
{
    if(nuevo_precio >0)
    {
        precio = nuevo_precio;

    }
    else
    {
        std:: cout<<"Intente de nuevo. Precio negativo ";
    }

}

void Producto:: modificarStock(int cantidad)
{
    if(cantidad >= 0)
    {
        stock += cantidad;
    }
    else
    {
        std:: cout<<"Cantidad negativa o cero...";
    }
}

int Producto::getId() const { 
    return id; 
}

std::string Producto::getNombre() const { 
    return nombre; 
}

double Producto::getPrecio() const { 
    return precio; 
}

int Producto::getStock() const { 
    return stock; 
}


