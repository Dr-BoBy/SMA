#include "SMAManager.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc == 3){
        char * pEnd;
        SMAManager smaManager = SMAManager();
        for(int i=0; i<strtol(argv[1],&pEnd,10); i++){
            smaManager.SummonPray();
        }
        for(int i=0; i<strtol(argv[2],&pEnd,10); i++){
            smaManager.SummonPredator();
        }
        smaManager.Run();
    }else{
        std::cout << "Correct use is : ./SMA <nbPray> <nbPredator>\n";
    }
}