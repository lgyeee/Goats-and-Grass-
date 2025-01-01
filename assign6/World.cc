#include "World.h"
#include "Goat.h"
#include "Grass.h"
#include <unistd.h>
#include "AnsiPrint.h"
#include <iostream>
using namespace std;

World::World(int _numPasses,int _seed):numPasses(_numPasses), seed(_seed){
    
    RandomNum randGen(seed); 
    
    //Inittialize the all the pointer ont the map to nullptr 
    for (int r = 0; r < maxY; ++r) {
        for (int c = 0; c < maxX; ++c) {
            map[r][c] = nullptr;
        }
    }
    // Scatter 10 baldes of grass
    for(int i = 0; i < 10; ++i){
        placeRandomly(new Grass());
    }
    //Scatter 5 goats
    for (int i = 0; i < 5; ++i) {
        placeRandomly(new Goat());
    }
    //set each cell ont the recordinggoatmap and recordinggrassmap to 0
    //means that any creature on the map can only act once in each pass
    resetActrecordingMap();
}

World::~World(){
    //free all the memories the map points to
    for(int r = 0; r < maxY; ++r) {
        for (int c = 0; c < maxX; ++c) {
            if (map[r][c] != nullptr) {
                delete map[r][c];
                map[r][c] = nullptr;
            }
        }
    }
}

void
World::resetActrecordingMap(){
    for(int r = 0; r < maxY; r++){
        for(int c = 0; c < maxX; c++){
            recordgoatmap[r][c] = 0;
        }
    }
    for(int r = 0; r < maxY; r++){
        for(int c = 0; c < maxX; c++){
            recordgrassmap[r][c] = 0;
        }
    }
}

void
World::placeRandomly(Creature * creature){
    int r = randGen.getRandomNum(0, maxY - 1);
    int c = randGen.getRandomNum(0, maxX - 1);
    do{ 
        if(isPositionValid(r, c)){
            r = randGen.getRandomNum(0, maxY - 1);
            c = randGen.getRandomNum(0, maxX - 1);
        }
    }while(map[r][c] != nullptr);// Ensure the cell is empty

    //Remember to update the creature object's variables(position_x, position_y)
    creature -> position_r = r;
    creature -> position_c = c;

    map[r][c] = creature;
}

void 
World::born(Creature * creature){
    map[creature->position_r][creature -> position_c] = creature;
}

bool
World::isPositionValid(int r, int c){
    return(c >= 0 && c < maxX) && (r >= 0 && r < maxY);
}

bool
World::isEmpty(int r, int c){
    if (!isPositionValid(r, c)) { return false; }
    return map[r][c] == nullptr;
}

bool
World::isGoat(int r, int c) {
    Creature* creature = map[r][c];
    Goat* goat = dynamic_cast<Goat*>(creature);
    if (goat != nullptr) {
        return true; // 如果轉換成功，則指針非空，表示這是一隻 Goat
    }
    else false;
}

bool 
World::isGrass(int r, int c) {
    Creature* creature = map[r][c];
    Grass* grass = dynamic_cast<Grass*>(creature);
    if (grass != nullptr) {
        return true; // 如果轉換成功，則指針非空，表示這是一株Grass
    }
    else false;
}

void 
World::removeCreature(int r, int c) {
    if (isPositionValid(r, c)) {
        delete map[r][c];
        map[r][c] = nullptr;
    }
}

void 
World::update(){
    resetActrecordingMap();
    for(int r = 0; r < maxY; ++r){
        for(int c = 0; c < maxX; ++c){
            if(map[r][c] != nullptr){
                map[r][c] -> act(*this);
            }
        }
    }
}

void 
World::mainLoop(int displayInterval){
    for(int i = 1; i <= numPasses; i++){
        this -> update();
        if (i % displayInterval == 0 || i == 1) {
            system("clear");
            displayWorld(displayInterval);
            usleep(50000);
        }
    }
}

void
World::displayWorld(int displayInterval){
    static int i = 0;
    cout << "[       " << i << "]" << endl;
    i += displayInterval;
    cout << "  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4" << endl;
    for(int r = 0; r < maxY; r++){ 
        if(r == 0)cout << 0;
        else cout << r % 10;

        for(int c = 0; c < maxX; c++){
            if(map[r][c] == nullptr){
                AnsiPrint("  ", black, nochange, false, true); ;
            }
            else if(isGoat(r, c)){
                AnsiPrint(" X", red, nochange ,false, true); 
            }
            else if(isGrass(r,c)){
                 AnsiPrint(" I", green, nochange ,false, true); 
            }

        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------" << endl << flush;
    return;
}