#include <iostream>
#include "types.h"
#include <string>
#include <cstddef>
using namespace std;

class Producto {
    private:    
    string nombre;
    string codigo;
    T1 precio;
    size_t stock;

    public:

   Producto() : nombre(""), codigo(""), precio(0), stock(0) {}
   Producto(string nombre, string codigo, T1 precio, size_t stock) : nombre(nombre), codigo(codigo), precio(precio), stock(stock) {}

   Producto operator+= (const Producto& otro) {
        precio += otro.precio;
        stock += otro.stock;
        return *this;
    }
   Producto operator-= (const Producto& otro) {
        precio -= otro.precio;
        stock -= otro.stock;
        return *this;
    }
   Producto operator= (const Producto& otro) {
        if (this != &otro) {
            nombre = otro.nombre;
            codigo = otro.codigo;
            precio = otro.precio;
            stock = otro.stock;
        }
        return *this;
    }

   bool operator==(const Producto& otro) const {
        return codigo == otro.codigo ;
    }

friend std::ostream& operator<<(std::ostream& os, const Producto& producto) {
    os << "[ " << producto.nombre << " | "
       << producto.codigo << " | "
       <<"S/."<< producto.precio <<" | "
       << producto.stock << " ]" << endl ;

    return os;

}  
    size_t getStock() const {
        return stock;
    }
    string getCodigo() const {
          return codigo;
     }
    
    T1 getPrecio() const {
        return precio;
    }

} ;