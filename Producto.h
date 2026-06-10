#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    int id;
    std::string nombre;
    double precio;
    int stock;

public:
    // Constructor
    Producto(int _id, std::string _nombre, double _precio, int _stock);

    // Métodos Getters (Para leer los datos de forma segura)
    int getId() const;
    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;

    // Métodos Setters con capacidad resolutiva (Validaciones)
    void setPrecio(double nuevoPrecio);
    void modificarStock(int cantidad); 
};

#endif