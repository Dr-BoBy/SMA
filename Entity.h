#define ENTITY_H

class Entity{
    public:
        //Constructor
        Entity(int x, int y);
        //Getter
        int GetX();
        int GetY();
        //Function
        void Update();
        virtual void CreateMoveTarget(int* targetX, int* targetY);
        virtual void Move();   
        //Data
        int x;
        int y;    
};      