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
    // Array dinámico para almacenar los elementos
     T* elementos;
     size_t size;
     size_t capacidad;
    // "Capacidad infinita"
     void redimensionar(){
         capacidad = capacidad * 2 ;
         T* nuevoElementos = new T[capacidad] ;
         for (size_t i = 0; i < size; ++i) {
            nuevoElementos[i] = elementos[i];
          }
         delete[] elementos;
         elementos = nuevoElementos;    
    }

    public:
    // Constructor y destructor
      Container() : size(0), capacidad(100) {
          elementos = new T[capacidad];
        }
      ~Container() {
          delete[] elementos;
        }
// Clase "Amiga"
      friend class Archivo;

 // Metodo de agregar producto
        void agregarElemento(const T& elemento) {
            if (size == capacidad) {
            redimensionar();  
             }
            elementos[size++] = elemento;
            }
// Metodo de mostrar productos disponibles
        void mostrarElementos() const {
              cout << endl;
              for (size_t i = 0; i < size; ++i) {
               cout << elementos[i];
               }  
            }
// Metodo de venta de producto    
        void ventaElemento(const string& codigo, size_t cantidad) {
             for (size_t i = 0; i < size; ++i) {
                  if (elementos[i].getCodigo() == codigo) {
                      if (elementos[i].getStock() >= cantidad) {
                       elementos[i] -= Producto("", "", 0, cantidad);
                        cout << "Venta realizada...Stock actualizado: " << elementos[i].getStock()<< endl;
                     } else {
                        cout << "Stock insuficiente..." << endl;
                    }
                       return;
                    }
                }
             cout << "Producto no encontrado. Intente nuevamente." << endl;
        }
// Metodo de Aumento de Stock
    void aumentarStock(const string& codigo, size_t cantidad) {
        for (size_t i = 0; i < size; ++i) {
            if (elementos[i].getCodigo() == codigo) {
                elementos[i] += Producto("", "", 0, cantidad);
                cout << "Stock aumentado...Stock actualizado: " << elementos[i].getStock() << endl;
                return;
            }
        }
        cout << "Producto no encontrado.Intente nuevamente." << endl;
    }
//Metodo de eliminacion de Producto (No confundir con Venta)
    void eliminarProducto(const string& codigo){
        size_t pos = -1;
        for(size_t i = 0;i < size; ++i){
            if(elementos[i].getCodigo()== codigo){
                pos = i;
                break;
            }
        }
        if(pos == (size_t)-1) {
              cout <<  "[Error] El producto con codigo " << codigo << " no existe." << endl;
        return;
    }
        T* nuevoElemento = new T[capacidad] ;
        size_t nuevoSize = 0;

            for (size_t i = 0; i < size; ++i) {
                if (i != pos) {
                   nuevoElemento[nuevoSize++] = elementos[i];
                  }
             }
         delete[] elementos;
    elementos = nuevoElemento;
    size = nuevoSize;
    cout << "[OK] El producto fue eliminado del sistema." << endl;
    }  

// Metodo de Encontrar producto
          Producto* buscarPorCodigo(string codigo) {
              for (size_t i = 0; i < size; i++) {
                    if (elementos[i].getCodigo() == codigo) {
                   return &elementos[i]; 
                    }
                }
               return nullptr;
            }

// Sobrecarga del operador [] para acceder a los elementos
    T& operator[](size_t index) {
        return elementos[index];
    }
// Sobrecarga del operador [] para acceder a los elementos de forma constante
   const T& operator[](size_t index) const {
    return elementos[index];
}
// Método para obtener la cantidad de elementos en el contenedor
    size_t getCantidad() const {
        return size;
    }

} ;

 
#endif // CONTENEDOR_H