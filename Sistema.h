#include <iostream>
#include "types.h"
#include "Container.h"
using namespace std;

class Sistema {
    public:
// Funcion del Menu Principal    
    void PrintMenu(){
        cout << "\n------------ Tienda FMIA --------------\n\n" 
          << "1. Agregar Producto\n"
          << "2. Mostrar Productos disponibles\n"
          << "3. Buscar Producto\n"
          << "4. Venta del Producto\n"
          << "5. Aumentar Stock del Producto\n"
          << "6. Eliminar Producto del Sistema\n"
          << "7. Salir\n\n" 
          << "Seleccione una opcion: ";
    } ;

// Precio Total de Venta de Productos 
    void SumaPrecios(size_t n_produc, Container<Producto>& contenedor) {
    T1 total = 0; 
    string codigo;
    size_t cantidad;

    for (size_t i = 0; i < n_produc; ++i) {
        cout << "Ingrese el codigo del producto: ";
        cin >> codigo;
        
        Producto* prod = contenedor.buscarPorCodigo(codigo);
        
        if (prod != nullptr) { 
            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidad;
            
            if (prod->getStock() >= cantidad) {
                total += prod->getPrecio() * cantidad;
                contenedor.ventaElemento(codigo, cantidad);
            } else {
                contenedor.ventaElemento(codigo, cantidad);
                --i; 
            }
        } else {
            cout << "[Error] El codigo " << codigo << " no existe." << endl;
            --i; 
        }
    }
    
    cout << "\n=======================================" << endl;
    cout << "VENTA FINALIZADA. Total a pagar: S/." << total << endl;
    cout << "=======================================" << endl;
} ;
 
// Muestra el producto establecido        
    void BuscarProducto(Container<Producto>& contenedor) {
    string codigo;
    cout << "\nIngrese el codigo del producto a buscar: ";
    cin >> codigo;

    Producto* produc = contenedor.buscarPorCodigo(codigo);

    if (produc != nullptr) {
        produc -> mostrarDetalles();        
    } else {
        cout << "\n[Error] El producto con codigo " << codigo << " no existe.\n";
    }
} ;
 // Aumento del Stock   
    void M_Aumento(size_t n_produc, Container<Producto>& contenedor ){
    TS codigo;
    size_t cantidad;

    for (size_t i = 0; i < n_produc; ++i) {        
        cout << "Ingrese el codigo del producto: ";
        cin >> codigo;

        Producto* prod = contenedor.buscarPorCodigo(codigo);

        if (prod != nullptr) {
            cout << "Producto: " << prod -> getNombre() << " (Stock actual: " << prod->getStock() << ")" << endl;
            cout << "Ingrese la cantidad a aumentar: ";
            
            while (!(cin >> cantidad)) {
                cout << "[Error] Ingrese un numero valido: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        contenedor.aumentarStock(codigo, cantidad);
        } else {
            cout << "[Error] El codigo " << codigo << " no existe." << endl;
            --i;
        }
    }
} ; 
// Eliminar Producto
    void M_eliminar(Container<Producto>& contenedor){
        TS codigo;
         cout << "Ingrese el codigo del producto a dar de baja: ";
         cin >> codigo;
        
        Producto* prod = contenedor.buscarPorCodigo(codigo);
        
        if(prod != nullptr){
            char respuesta; 
            cout << "Esta seguro de eliminar el producto ? (S/N)"<< endl;
            cin >> respuesta;
            cin.ignore(10000, '\n');

            if( respuesta == 's' || respuesta == 'S' ){
                contenedor.eliminarProducto(codigo);
            } else {
                cout << "Cancelado...Producto no eliminado"<< endl;
            }
        } else { cout << "[Error] El codigo " << codigo 
                      << " no existe en el inventario." << endl;}
    }

};
    
