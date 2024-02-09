#include "Predator.h"
#include <vector>

class SMAManager{
    public :
        //Constructor
        SMAManager();
        //Function
        void SummonPray();
        void SummonPredator();
        void RunCycle();
        void Display();
        void Run();
        void GenerateRandomPos(int* x, int* y);
        //Data
        static std::vector<Pray> prays;
        static std::vector<Predator> predators;
    private :
        //Data
        int cycleNumber;
        
};