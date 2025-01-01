#ifndef GRASS_H
#define GRASS_H
#include "Creature.h"
class World;

class Grass: public Creature{
    public:
        Grass();
        Grass(int, int);
        Grass(int newR, int newC, int curAge);
        virtual ~Grass(){}
        
        /* Override the act() function from Creature. 
        This should handle the grass's growth
        and reproduction. */
        virtual void act(World& world);
        virtual bool isAlive();

        void grow();
        
        void sprout(World& world);

        int getAge();
};

#endif