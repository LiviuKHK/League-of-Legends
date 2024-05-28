#include "ChampionWithStrategy.h"

ChampionWithStrategy::ChampionWithStrategy(Champion *champ, AttackStrategy *strat): champion(champ), strategy(strat) {}

void ChampionWithStrategy::setStrategy(AttackStrategy *strat) {
    strategy = strat;
}

void ChampionWithStrategy::executeAttack() {
    strategy->attack(champion);
}