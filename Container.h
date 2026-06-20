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
    Container() : size(0), capacidad(50) {
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

 

    size_t getCantidad() const {
        return size;
    }
} ;

void PrintMenu( ) {
        cout << "------------Menu--------------" << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Mostrar Productos disponibles" << endl;
        cout << "3. Salir" << endl;
    } 



#endif // CONTENEDOR_H