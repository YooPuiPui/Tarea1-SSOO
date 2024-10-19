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

void carRace(int carId, int totalDistance){
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

    {
        std::lock_guard<std::mutex> lock(race_mutex);

        // mensaje que indica que el auto a terminado la carrera y en que posicion quedo
        std::cout << "Auto " << carId << " termina la carrera en el lugar " << position++ <<"!\n";

        // guarda el id para registrar el orden de llegada
        results.push_back(carId);
    }

}

int main(int argc, char* argv[]){

    if(argc !=3){
        std::cerr << "Uso: " << argv[0] << "ingrese distancia total y numero de autos \n";
        return 1;
    }

    //? convertir los parametros de entrada de tipo string a enteros
    int totalDistance = std::stoi(argv[1]);
    int numberCars = std::stoi(argv[2]);

    //? vector que va a almacenar los hilos correspondientes de cada auto
    std::vector<std::thread> cars;

    // crear un hilo para cada auto
    for(int i=0; i<numberCars; i++){
        cars.emplace_back(carRace,i,totalDistance);
    }

    // espera a que todos los hilos terminen su ejecucion
    for(auto&car : cars){
        car.join();
    }

    std::cout << "\nResultado de la carrera:\n";
    for(size_t i = 0; i< results.size(); ++i){
        std::cout << i + 1 << " lugar: Auto " << results[i] << "\n";
    }

    return 0;
}