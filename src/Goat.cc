#include "Goat.h"
#include "World.h"
#include "Grass.h"
#include<iostream>
using namespace std;

Goat::Goat():Creature(),foodPoints(20){}
Goat::Goat(int newR, int newC) : Creature(newR, newC), foodPoints(20) {}
Goat::Goat(int newR, int newC, int curFoodpts, int curAge):Creature(newR, newC, curAge), foodPoints(curFoodpts){}

/**
Each goat starts with 20 food points.
*/
bool
Goat::isAlive(){
    return age <= 70 && foodPoints > 0;
}

void
Goat::act(World& world){ 
    if(isAlive() && world.recordgoatmap[position_r][position_c] == 0){
        consumeFood(); // Consume FoodPoints for each pass
        aging();
        if(age >= 50 && age <= 55){
            if(world.randGen.getRandomNum(0,10000) % 2 == 1){
                reproduce(world);
            }
            else move(world);
        }
        else{
            move(world);
        }
    }
    else if(world.recordgoatmap[position_r][position_c] == 0){      
        world.removeCreature(position_r, position_c);
    }
}

void 
Goat::aging(){
    age++;
}

//each goat is allowed to move in a randomly selected direction, 
//provided the square is not currently occupied by another
//goat or outside the boundaries of the world. 
//When the attempt is not legal, 
//the goat does not get another chance to try again. 
//That is, a goat has only one chance to move in each pass. 
void 
Goat::move(World& world){
    int dr[4] = {-1, 1, 0, 0}; // Changes in r for up, down, right, left
    int dc[4] = {0, 0, -1, 1}; // Changes in c for up, down, right, left
    int direction = world.randGen.getRandomNum(0, 3);
    
    // (newR, newC) is the cell we want to move to
    int newR = position_r + dr[direction]; 
    int newC = position_c + dc[direction];

    if (world.isPositionValid(newR, newC) && (!(world.isGoat(newR, newC)) || world.isEmpty(newR, newC))) {
        //Eat grass of present
        if(world.isGrass(newR, newC)){
            eatGrass();
            world.removeCreature(newR, newC); //Remove the eaten grass
        }
        Goat * goat = new Goat(newR, newC, foodPoints, age);
        world.removeCreature(position_r, position_c); //Remove the goat
        world.born(goat);
        world.recordgoatmap[newR][newC] = 1;  
    }
}

void
Goat::eatGrass(){
    foodPoints += 5; // Each blade of grass gives 5 points
}

void
Goat::reproduce(World & world){
    int dr[4] = {-1, 1, 0, 0}; // Changes in r for up, down, right, left
    int dc[4] = {0, 0, -1, 1}; // Changes in c for up, down, right, left
    int direction = world.randGen.getRandomNum(0, 3);
    // (newR, newC) is the cell we want to born a new goat
    int newR = position_r + dr[direction]; 
    int newC = position_c + dc[direction];

    //Check if the new position is within bounds and empty
    if(world.isPositionValid(newR, newC) && ((world.isGrass(newR, newC)) || world.isEmpty(newR, newC))){
        //Eat grass of present
        if(world.isGrass(newR, newC)){
            eatGrass();
            world.removeCreature(newR, newC); //Remove the eaten grass
        }
        Goat * goat = new Goat(newR, newC);
        world.born(goat);
        world.recordgoatmap[newR][newC] = 1; 
    }
}

void
Goat::consumeFood() {
    --foodPoints;
}