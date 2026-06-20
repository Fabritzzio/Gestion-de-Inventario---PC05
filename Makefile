# Nombre del ejecutable final
TARGET = test

# Archivo de código fuente
SRC = main.cpp

# Compilador y banderas
CXX = g++
CXXFLAGS = -Wall -g

# Regla principal para compilar
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Regla para limpiar el ejecutable
clean:
	rm -f $(TARGET)
