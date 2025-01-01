#ifndef CREATURE_H
#define CREATURE_H

class World; // 前向聲明

class Creature{
    public:
        Creature();
        Creature(int newR, int newC);
        Creature(int newR, int newC, int curAge);
        virtual ~Creature() {}

        /* An abstract function that defines 
        the behavior of the creature in 
        each simulation pass. 
        This should be overridden in the subclasses.*/
        virtual void act(World & world) = 0;

        /* Returns a boolean indicating 
        if the creature is still alive. 
        This might consider age and 
        other factors specific to the creature type.
        Constructors, getters, and setters as
         needed for the variables.*/
        virtual bool isAlive() = 0;
        /* A pair of integers (x, y coordinates) 
        representing the creature's location in the world.*/
        int position_r;
        int position_c;

        // An integer to track the creature's age.
        int age;

};

#endif // CREATURE_H