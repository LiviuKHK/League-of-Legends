#include <iostream>
#include "Mage.h"
#include "Ability.h"

Mage::Mage(const std::string &name,const std::string &role, int health, int energy): Champion(name,role,health), energy(energy){}
void Mage::useAbility(const Ability &ability) const {
    std::cout << name << " activates magic ability " << ability.name << "!" << std::endl;
    ability.activate();
}
