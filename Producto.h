#include <iostream>
#include "types.h"
#include <string>
using namespace std;

class Producto {
    private:    
    string nombre;
    string codigo;
    T precio;
    T1 stock;
    public:

    Producto(string nombre, string codigo, T1 precio, T1 stock) :
    nombre(nombre), codigo(codigo), precio(precio), stock(stock) {} ;

    ~Producto() {};

    void mostrarProductos() {
        cout << "Producto: " << nombre << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl;
    
    



}

} ;