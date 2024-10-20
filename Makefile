# Nombre del ejecutable
TARGET = Tarea1

# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++11 -Wall -pthread

# Archivos fuente
SRC = Tarea1.cpp

# Regla por defecto: compilar el programa
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Limpiar los archivos generados
clean:
	rm -f $(TARGET)