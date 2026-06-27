#include <iostream>
#include "types.h"
#include <string>
#include <cstddef>
using namespace std;

class Producto {
    // Atributos de la clase Producto
    private:    
    string nombre;
    string codigo;
    T1 precio;
    size_t stock;

    public:
// Constructor por defecto y constructor parametrizado
   Producto() : nombre(""), codigo(""), precio(0), stock(0) {}
   Producto(string nombre, string codigo, T1 precio, size_t stock) : nombre(nombre), codigo(codigo), precio(precio), stock(stock) {}

// Sobrecarga de operadores para la clase Producto
   Producto& operator+= (const Producto& otro) {
        stock += otro.stock;
        return *this;
    }
    Producto& operator-= (const Producto& otro) {
        if (this->stock >= otro.stock) {
            this->stock -= otro.stock;
        } else {
            this->stock = 0; 
        }
        return *this;
    }
   Producto& operator= (const Producto& otro) {
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
// Sobrecarga del operador << para imprimir los detalles del producto
friend std::ostream& operator<<(std::ostream& os, const Producto& producto) {
    os << "[ " << producto.nombre << " | "
       << producto.codigo << " | "
       <<"S/."<< producto.precio <<" | "
       << producto.stock << " ]" << endl ;

    return os;

}  
// Métodos de acceso para los atributos de la clase Producto
    size_t getStock() const {
        return stock;
    }
    string getCodigo() const {
          return codigo;
     }
    T1 getPrecio() const {
        return precio;
    }
    string getNombre() const {
        return nombre;
    }

// Metodo de acceso al detalle de los productos
void mostrarDetalles() const {
    std::cout << "\n--- Datos del Producto ---\n"
              << "\nNombre: " << nombre
              << "\nCodigo: " << codigo
              << "\nPrecio: S/." << precio
              << "\nStock : " << stock << "\n";
}

} ;