# Simulador Carrera de Autos

Este proyecto simula una carrera de autos utilizando programacion multihebras en C++,
cada automovil competidor corre en una hebra distinta, avanzando distancias aleatorias en intervalos de tiempo
tambien aleatorios. La carrera termina cuando todos los autos han completado el recorrido.

## Objetivos
- Reforzar conceptos de procesos/hebras, comunicacion entre procesos y sincronizacion.
- Implementar concurrenci y paralelismo mediante el uso de hebras (threads).

## Requisitos
- **Lenguaje**: C++ (estandar C++11 o superior)
- **Compilador**: GNU g++
- **Plataforma**: Sistema operativo Linux.

## Funcionamiento
- Cada auto tiene un identificador único.
- Avanza y se detiene aleatoriamente.
- En cada iteración, los autos avanzan una distancia aleatoria (máximo 10 metros) y se detienen por 
  un tiempo aleatorio (entre 100 y 500 ms), simulando velocidades diferentes.
- El programa muestra el progreso en tiempo real y finaliza cuando todos los autos llegan.

### Pasos 

1. Clonar el repositorio:

    ```bash
    git clone https://github.com/YooPuiPui/Tarea1-SSOO.git
    ```

2. Moverse a la carpeta Tarea1-SSOO:
    ```bash
    cd Tarea1-SSOO
    ```
   
3. Ejecutar make en la terminal:
    ```bash
    make
    ```
   ```
4. Luego de ejecutar "make" siga los siguientes pasos:

    ```bash
    En la terminal ingrese lo siguiente:
    
    ./Tarea1 "Distancia total en metros" "Número de autos en la carrera"
    
    Ejemplo:
    ./Tarea1 100 5

    ```

### Archivos
- Makefile: Para compilar con make.
- Tarea1.cpp: Codigo fuente del programa

## Nombres de Estudiantes

Francisca Huaique y Nicolas Muñoz
