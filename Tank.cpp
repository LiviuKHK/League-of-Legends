#include "Tank.h"

Tank::Tank(const std::string &name, const std::string &role,int health, int armor): Champion(name,role,health), armor(armor) {}
void Tank::useAbility(const Ability &ability) const {
    std::cout << name << " uses " << ability.getName() << " to shield and reduce damage by " << ability.getDamage() << "!\n";
}