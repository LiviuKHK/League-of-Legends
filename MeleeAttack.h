#ifndef PROIECTPOO_MELEEATTACK_H
#define PROIECTPOO_MELEEATTACK_H

#include "AttackStrategy.h"

class MeleeAttack : public AttackStrategy{
public:
    void attack(Champion* champion);
};


#endif //PROIECTPOO_MELEEATTACK_H
