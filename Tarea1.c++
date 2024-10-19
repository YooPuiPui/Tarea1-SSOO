#include <iostream>     
#include <thread>       
#include <vector>      
#include <chrono>       
#include <mutex>        
#include <string>
#include <random>

std::mutex race_mutex;

// Vector para guardar el orden de llegada de los autos.
std::vector<int> results;


int position = 1;

void raceCar(int carId, int totalDistance){
    //? variable que guarda la distancia total del recorrido
    int distanceCovered = 0;

    //? inicializar generador de numeros alatorios para distancia y tiempos de espera
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1,10);

    std::uniform_int_distribution<> speed(100, 500);

    while(distanceCovered < totalDistance){

        int distance = dist(gen);

        distanceCovered += distance;

        if(distanceCovered > totalDistance){
            distanceCovered = totalDistance;
        }

        {
            std::lock_guard<std::mutex> lock(race_mutex);
            std::cout << "Auto " << carId << " avanza " << distance << " metros (total: " << distanceCovered << " metros)\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(speed(gen)));
    }
}