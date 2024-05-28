#ifndef PROIECTPOO_RANGEDATTACK_H
#define PROIECTPOO_RANGEDATTACK_H

#include "AttackStrategy.h"
#include "Champion.h"

class RangedAttack : public AttackStrategy {
public:
    void attack(Champion* champion) override;
};


#endif //PROIECTPOO_RANGEDATTACK_H
