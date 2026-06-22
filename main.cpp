#include <iostream>
#include "Container.h"
#include "types.h"
using namespace std;

int main() {

Container<Producto> inventario;
inventario.agregarElemento(Producto("Laptop", "LP123", 1500.00, 10));
inventario.agregarElemento(Producto("Smartphone", "SP456", 800.00, 5));

size_t opcion;

do { 
   
PrintMenu();
cin >> opcion;

if (opcion == 1) {
    string nombre, codigo;
    T1 precio;
    size_t stock;

    cout << "Ingrese el nombre del producto: ";
    cin >> nombre;
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    cout << "Ingrese el stock del producto: ";
    cin >> stock;

    inventario.agregarElemento(Producto(nombre, codigo, precio, stock));
} 
else if (opcion == 2) {
    inventario.mostrarElementos();
}
else if (opcion == 3) {
    string codigo;
    size_t cantidad;

    cout << "Ingrese el codigo del producto a vender: ";
    cin >> codigo;
    cout << "Ingrese la cantidad a vender: ";
    cin >> cantidad;
    inventario.eliminarElemento(codigo, cantidad);
}
else if (opcion == 4) {
    string codigo;
    size_t cantidad;

    cout << "Ingrese el codigo del producto para aumentar stock: ";
    cin >> codigo;
    cout << "Ingrese la cantidad a aumentar: ";
    cin >> cantidad;
    inventario.AumentarStock(codigo, cantidad);
}
else if (opcion != 5) {
    cout << "Opcion no valida. Intente nuevamente." << endl;
}

} while (opcion != 5);

cout << "\nSaliendo..." << endl;

return 0; 
}
