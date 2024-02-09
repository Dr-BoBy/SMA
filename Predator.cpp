#include <cmath>
#include "SMAManager.h"

//Constructor
Predator::Predator(int x, int y) : Entity(x,y){}

Pray Predator::CalculNearestPray(){
    int min = CalculDistance(SMAManager::prays[0]);
    int minId = 0;
    for (int i = 1; i < SMAManager::prays.size(); i++)
    {
        int dist = CalculDistance(SMAManager::prays[i]);
        if(dist<=min){
            min = dist;
            minId = i;
        }
    }
    return SMAManager::prays[minId];
}

int Predator::CalculDistance(Pray pray){
    int xDiff = this->GetX()-pray.GetX();
    int yDiff = this->GetY()-pray.GetY();
    return sqrt(xDiff*xDiff + yDiff*yDiff);
}

void Predator::CreateMoveTarget(int* targetX, int* targetY){
    Pray pray = CalculNearestPray();
    int xDiff = pray.GetX()-this->GetX();
    int yDiff = pray.GetY()-this->GetY();
    *targetX = xDiff/abs(xDiff);
    *targetY = yDiff/abs(yDiff);
}   

void Predator::Move(){
    int x = 0;
    int y = 0;
    int* px = &x;
    int* py = &y;
    this->CreateMoveTarget(px, py);
    this->x = this->x + *px;
    this->y = this->y + *py;

    this->x = (this->x>24) ? 24 : this->x;
    this->y = (this->y>24) ? 24 : this->y;
    this->x = (this->x<0) ? 0 : this->x;
    this->y = (this->y<0) ? 0 : this->y;

    for(int i=0; i<SMAManager::prays.size(); i++){
        if(SMAManager::prays[i].GetX()==this->x && SMAManager::prays[i].GetY()==this->y){
            SMAManager::prays.erase(SMAManager::prays.begin()+i);     
        }
    }
}