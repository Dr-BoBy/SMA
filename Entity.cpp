#include "Entity.h"

//Constructor
Entity::Entity(int x, int y) : x(x), y(y) {}

//Getter
int Entity::GetX(){return this->x;}
int Entity::GetY(){return this->y;}

//Function
void Entity::Update(){
    this->Move();
}

void Entity::CreateMoveTarget(int* targetX, int* targetY){};

void Entity::Move(){
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
}