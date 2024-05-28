#include <iostream>
#include "Assassin.h"

Assassin::Assassin(const std::string &name, const std::string &role, int health, int agility): Champion(name,role,health),agility(agility){}
void Assassin::useAbility(const Ability &ability) const {
    std::cout << name << " stealthily uses " << ability.getName() << " to deal " << ability.getDamage() + agility << " damage!\n";
}