#ifndef PROIECTPOO_CHAMPIONWITHSTRATEGY_H
#define PROIECTPOO_CHAMPIONWITHSTRATEGY_H

#include "Champion.h"
#include "AttackStrategy.h"

class ChampionWithStrategy {
private:
    Champion* champion;
    AttackStrategy* strategy;
public:
    ChampionWithStrategy(Champion* champ, AttackStrategy* strat);

    void setStrategy(AttackStrategy* strat);

    void executeAttack();
};


#endif //PROIECTPOO_CHAMPIONWITHSTRATEGY_H
