#include <iostream>
#include "Container.h"
#include "types.h"
using namespace std;

int main() {

Container<Producto> inventario;
inventario.agregarElemento(Producto("Laptop", "LP123", 1500.00, 0));
inventario.agregarElemento(Producto("Smartphone", "SP456", 800.00, 0));
T0 opcion;
do { 
   
PrintMenu();
cin >> opcion;

if (opcion == 1) {
    string nombre, codigo;
    T1 precio;
    T0 stock;

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

} while (opcion != 3);

cout << "Vuelva pronto..." << endl;

return 0; 
}
