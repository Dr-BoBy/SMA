#include "Pray.h"
#include <random>

//Constructor
Pray::Pray(int x, int y) : Entity(x,y){}

//Functions
void Pray::CreateMoveTarget(int* targetX, int* targetY) {
    std::random_device rd; // Permet d'initialiser le générateur aléatoire
    std::mt19937 gen(rd()); // Générateur aléatoire utilisant l'algorithme de Mersenne Twister
    std::uniform_int_distribution<> distrib(0, 2); // Distribution que devront respecter les nombres générés -> uniforme de 1 à 6

    *targetX = distrib(gen)-1;
    *targetY = distrib(gen)-1;
};