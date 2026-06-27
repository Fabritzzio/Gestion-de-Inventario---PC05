#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H
#include <string>
#include <iostream>
#include <fstream>
#include "Container.h"

class Archivo {
public:
// Constructor y destructor
    Archivo() {};
    ~Archivo() {};
// Métodos para guardar datosdesde un archivo
    void guardarDatos(const Container<Producto>& contenedor, 
        const std::string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo, ios::out);
        if (!archivo) {
            std::cerr << "Error al abrir el archivo para guardar datos." << std::endl;
            return;
        }

        for (size_t i = 0; i < contenedor.getCantidad(); ++i) {
            const Producto& producto = contenedor[i];
            archivo << producto.getNombre() << ","
                    << producto.getCodigo() << ","
                    << producto.getPrecio() << ","
                    << producto.getStock() << std::endl;
        }

        archivo.close();
    }
// Métodos para cargar datos desde un archivo
    void cargarDatos(Container<Producto>& contenedor, 
        const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo,ios::in);
        if (!archivo) {
            std::cerr << "Error al abrir el archivo para cargar datos." << std::endl;
            return;
        }

        std::string nombre, codigo;
        T1 precio;
        size_t stock;

        while (std::getline(archivo, nombre, ',')) {
            std::getline(archivo, codigo, ',');
            archivo >> precio;
            archivo.ignore(); 
            archivo >> stock;
            archivo.ignore(); 

            contenedor.agregarElemento(Producto(nombre, codigo, precio, stock));
        }

        archivo.close();
    }


} ;
#endif // GESTOR_ARCHIVOS_H