#ifndef GOAT_H
#define GOAT_H

#include "Creature.h"
class World;

class Goat: public Creature{
    private:
        //An integer to track the goat’s current food points.
        int foodPoints;

    public:
        Goat();
        Goat(int newR, int newC);
        Goat(int newR, int newC, int curFoodpts, int curAge);
        virtual ~Goat(){}
        
        /**
         Override the act() function from Creature.
         This should implement the goat's behaviorin each pass,
        including moving, eating, aging, and reproducing.
        */
        virtual void act(World& world) ;
        virtual bool isAlive();

        /*
        Goats grows one day older 
        with each pass until it dies 
        (disappear) at the age of 70 days. 
        */
        void aging();

        /**
         During each pass goats move around 
         When a goat moves to a new cell, 
         it gets to eat any grass on the cell.
        */
        void move(World& world);

        /*
        Every time the goat eats a grass,
        it gains 5 points.
        */
        void eatGrass();

        /*
         between the ages of 50 ~ 55, 
         a goat can have a baby goat for each pass.
         Mommy goat picks a random direction
         and generates a baby goat one cell in that direction, 
         provided that the cell is legal. 
         If the square contains a blade of grass, 
         the mommy goat also gets to eat the grass
         and acquires the usual food points.
         the mommy goat does not move during this process. 
         */
        void reproduce(World & world);

        /**
         Each goat consumes I point with each pass
        */
        void consumeFood();

};

#endif