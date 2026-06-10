#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Producto.h"
#include <vector>

class Inventario {
private:
    // Atributo privado: Una lista dinámica que va a guardar objetos de tipo Producto
    std::vector<Producto> listaProductos;

public:
    // Funciones públicas (El plano de lo que va a poder hacer el inventario)
    void agregarProducto(const Producto& nuevoProducto);
    void mostrarInventario() const;
    
    // Función avanzada: busca un producto por su ID y devuelve su dirección de memoria
    Producto* buscarProductoPorId(int idBuscado);
};

#endif