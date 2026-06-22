#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include "Producto.h"
#include <iostream>
#include "types.h"
#include <cstddef>
using namespace std;

template<typename T>
class Container {
    private:
    T* elementos;
    size_t size;
    size_t capacidad;

    public:
    Container() : size(0), capacidad(100) {
        elementos = new T[capacidad];
    }

    ~Container() {
        delete[] elementos;
    }

    void agregarElemento(const T& elemento) {
        if (size < capacidad) {
            elementos[size++] = elemento;
        } else {
            cout << "No se pueden agregar más elementos. Capacidad llena." << endl;
        }
    }

    void mostrarElementos() const {
        for (size_t i = 0; i < size; ++i) {
            cout << elementos[i];
        }
    }
    void eliminarElemento(const string& codigo, size_t cantidad) {
        for (size_t i = 0; i < size; ++i) {
            if (elementos[i].getCodigo() == codigo) {
                if (elementos[i].getStock() >= cantidad) {
                    elementos[i] -= Producto("", "", 0, cantidad);
                    cout << "Venta realizada...Stock actualizado: " << elementos[i].getStock() << endl;
                } else {
                    cout << "Stock insuficiente..." << endl;
                }
                return;
            }
        }
        cout << "Producto no encontrado. Intente nuevamente." << endl;
    }

    void AumentarStock(const string& codigo, size_t cantidad) {
        for (size_t i = 0; i < size; ++i) {
            if (elementos[i].getCodigo() == codigo) {
                elementos[i] += Producto("", "", 0, cantidad);
                cout << "Stock aumentado...Stock actualizado: " << elementos[i].getStock() << endl;
                return;
            }
        }
        cout << "Producto no encontrado.Intente nuevamente." << endl;
    }

    size_t getCantidad() const {
        return size;
    }

} ;

void PrintMenu( ) {
        cout << "\n------------Menu--------------" << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Mostrar Productos disponibles" << endl;
        cout << "3. Venta del Producto" << endl;
        cout << "4. Aumentar Stock del Producto" << endl;
        cout << "5. Salir" << endl;
    }     



#endif // CONTENEDOR_H