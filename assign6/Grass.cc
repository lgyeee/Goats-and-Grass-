#include "Grass.h"
#include "World.h"

Grass::Grass():Creature(){}
Grass::Grass(int newR, int newC) : Creature(newR, newC) {}

/* 
Goats die if their food points reach zero 
or their lives are over 70 days.*/
bool 
Grass::isAlive(){return age <= 6;}

void
Grass::act(World& world) {
    if(isAlive() && world.recordgrassmap[position_r][position_c] == 0){
        grow();
        if(age >= 3 && age <= 5){
            sprout(world);
        }
    }
    else if(world.recordgrassmap[position_r][position_c] == 0){
        world.removeCreature(position_r, position_c);
    }
}

void 
Grass::grow(){
    age++; 
}

void 
Grass::sprout(World &world){

    int dr[4] = {-1, 1, 0, 0}; // Changes in r for up, down, left, right
    int dc[4] = {0, 0, 1, -1}; // Changes in c for up, down, left, right
    int direction = world.randGen.getRandomNum(0, 3);
    world.recordgrassmap[position_r][position_c] = 1;
    

    //Caculate the new position
    int newR = position_r + dr[direction];
    int newC = position_c + dc[direction];

    Grass * grass = new Grass(newR, newC);

    //Check if the new position is within bounds and empty
    if(world.isPositionValid(newR, newC) && world.isEmpty(newR, newC)){
        world.born(grass);
        world.recordgrassmap[newR][newC] = 1;
    }
    return;
}

int
Grass::getAge(){
    return age;
}
