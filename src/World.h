#include "RandomNum.h"
#include "Creature.h"
const int maxX=35;
const int maxY=20;

/**
The "world" consists of a 35x20 array.
All creatures live in cells of this array. 
The world does not wrap around, 
i.e., there are firm boundaries at the edges of the array.
Initially there are 5 goats and 10 blades of grass scattered randomly. 
*/
class World{
    public:
        World(int _numPasses,int _seed);
        ~World();

        int recordgoatmap[maxY][maxX];
        int recordgrassmap[maxY][maxX];
        void resetActrecordingMap();

        RandomNum randGen; // Assuming this is your random number generator

        /** 
        Initialization: function to place a 
        creature at a random position 
        **/
        void placeRandomly(Creature* creature);

        /**
        Adds the creature to the map 
        at the specified coordinates.
        */
        void born(Creature * creature);
        /**
        Removes a creature from the map
        at the given coordinates,
        handling memory deallocation
        */
        void removeCreature(int r, int c);

        /**
        Checks if the specified coordinates 
        are within the map boundaries.
        */
        bool isPositionValid(int r, int c);
        /**
        Determines if a map cell is empty 
        (no creature present).
        */
        bool isEmpty(int r, int c);
        /**
        Checks if a cell contains a goat.
        */
        bool isGoat(int r, int c);
        /**
        Checks if a cell contains a grass.
        */
        bool isGrass(int r, int c);

        /**
        Updates the state of the map, 
        triggering each creature's actions.
        */
        void update();

        /**
        Displays the current state of the world map.
        */
        void displayWorld(int displayInterval);

        /*
        Main simulation loop, 
        controlling the overall flow and display updates.
        */
        void mainLoop(int displayInterval);

   private:
        int numPasses;
        int seed;
        Creature* map[maxY][maxX];
};