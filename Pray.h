#define PRAY_H
#include "Entity.h"

class Pray : public Entity{ 
    public :
        //Constructor
        Pray(int x, int y);
        //Function
        void CreateMoveTarget(int* targetX, int* targetY) override;
};