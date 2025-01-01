#include"Creature.h"

Creature::Creature(): position_r(0), position_c(0), age(0){}

Creature::Creature(int newR, int newC): position_r(newR),position_c(newC), age(0){}

Creature::Creature(int newR, int newC, int curAge): position_r(newR),position_c(newC), age(curAge){}