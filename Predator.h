#define PREDATOR_H
#include "Pray.h"


class Predator : public Entity{
    public:
        //Constructor
        Predator(int x, int y);
        //Function
        Pray CalculNearestPray();
        int CalculDistance(Pray pray);
        void CreateMoveTarget(int* targetX, int* targetY) override;
        void Move() override;
};