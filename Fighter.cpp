#include <iostream>
#include "Fighter.h"
#include "Ability.h"
#include "Champion.h"

Fighter::Fighter(const std::string &name,const std::string &role, int health, int sustain): Champion(name,role,health), sustain(sustain){}

void Fighter::useAbility(const Ability &ability) const {
    std::cout << name << " activates offensive ability " << ability.name << "!" << std::endl;
    ability.activate();
}
