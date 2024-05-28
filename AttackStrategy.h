#ifndef PROIECTPOO_ATTACKSTRATEGY_H
#define PROIECTPOO_ATTACKSTRATEGY_H
#include "Champion.h"

// Strategy Design Pattern
class AttackStrategy {
public:
    virtual ~AttackStrategy() = default;
    virtual void attack(Champion* champion) = 0;
};

#endif //PROIECTPOO_ATTACKSTRATEGY_H
