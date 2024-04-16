#include "Melee.h"
#include <iostream>
#include <vector>
#include <string>

Melee::Melee(const std::string& name, const std::string& role, int health, int attackRange)
        : Champion(name, role, health), attackRange(attackRange) {}

Melee::~Melee() {}

int Melee::getAttackRange() const {
    return attackRange;
}

void Melee::useAbility(const Ability& ability) const {
    std::cout << name << " uses melee ability " << ability.name << "!" << std::endl;
    ability.activate();
}

Melee* Melee::clone() const {
    return new Melee(*this);
}
