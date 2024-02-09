#include "SMAManager.h"
#include <random>
#include <iostream>

std::vector<Pray> SMAManager::prays;
std::vector<Predator> SMAManager::predators;

SMAManager::SMAManager(){}

void SMAManager::GenerateRandomPos(int* x, int* y){
    std::random_device rd; // Permet d'initialiser le générateur aléatoire
    std::mt19937 gen(rd()); // Générateur aléatoire utilisant l'algorithme de Mersenne Twister
    std::uniform_int_distribution<> distrib(0, 24); // Distribution que devront respecter les nombres générés -> uniforme de 1 à 6

    *x = distrib(gen);
    *y = distrib(gen);
}

void SMAManager::SummonPray(){
    int x = 0;
    int y = 0;
    int* px = &x;
    int* py = &y;
    GenerateRandomPos(px, py);
    prays.push_back(Pray(*px,*py));
}

void SMAManager::SummonPredator(){
    int x = 0;
    int y = 0;
    int* px = &x;
    int* py = &y;
    GenerateRandomPos(px, py);
    predators.push_back(Predator(*px,*py));
}

void SMAManager::RunCycle(){
    for(int i=0; i<prays.size(); i++){
        prays[i].Update();
    }
    for(int i=0; i<predators.size(); i++){
        predators[i].Update();
    }
    this->cycleNumber++;
}

void SMAManager::Display(){
    int map[625] = {0};
    for(int i=0; i<prays.size(); i++){
        map[25*prays[i].GetY()+prays[i].GetX()]=1;
    }
    for(int i=0; i<predators.size(); i++){
        map[25*predators[i].GetY()+predators[i].GetX()]=2;
    }

    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            if(map[i*25+j]==0){
                std::cout << ". ";
            }else if(map[i*25+j]==1){
                std::cout << "0 ";
            }else{
                std::cout << "& ";
            }
        }
        std::cout << "\n";
    }
}

void SMAManager::Run(){
    int a =1;
    Display();
    while(a!=0 && prays.size()>0){
        std::cin >> a;
        RunCycle();
        Display();
    }
}

