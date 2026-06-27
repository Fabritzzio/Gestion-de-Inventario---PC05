#include <iostream>
#include "Sistema.h"
#include "Container.h"
#include "types.h"
#include "Gestor_Archivos.h"

using namespace std;
    
int main() {
    Container<Producto> inventario;
    Archivo gestor;
    Sistema sistema;
    T0 opcion;

    gestor.cargarDatos(inventario, "inventario.txt");

    do { 
        cout << "\n=======================================" << endl;       
        sistema.PrintMenu();
        
        while (!(cin >> opcion)) {
            cout << "\n[Error] Debe ingresar una opcion numerica valida." << endl;
            cout << "\n=======================================" << endl;
            sistema.PrintMenu();
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "\n=======================================" << endl;

        if (opcion == 1) {
            string nombre, codigo;
            T1 precio;
            size_t stock;

            cin.ignore(10000, '\n');
            cout << "Ingrese el nombre del producto: ";
            getline(cin,nombre);
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
            sistema.BuscarProducto(inventario);
        }
        else if (opcion == 4) {
            size_t n;
            cout << "Ingrese la cantidad de productos diferentes a vender: ";
            
            while (!(cin >> n)) {
                cout << "[Error] Ingrese un numero valido: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (n > 0) {
                sistema.SumaPrecios(n, inventario);
            }   
        } 
        else if (opcion == 5) {
            size_t n;
            cout << "Ingrese la cantidad de productos diferentes a aumentar: ";
            
            while (!(cin >> n)) {
                cout << "[Error] Ingrese un numero valido: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (n > 0) {
                sistema.M_Aumento(n, inventario);   
            }
        }
        else if(opcion == 6 ){ 
            sistema.M_eliminar(inventario);
        }
        
        else if (opcion != 7) {
            cout << "Opcion no valida. Intente nuevamente." << endl; 
        }

    } while (opcion != 7);

    gestor.guardarDatos(inventario, "inventario.txt");
    cout << "\nSaliendo..." << endl;

    return 0; 
}



