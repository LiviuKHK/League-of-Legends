#include "Support.h"

Support::Support(const std::string &name,const std::string &role, int health, int protection): Champion(name,role,health), protection(protection){}
void Support::useAbility(const Ability &ability) const {
    std::cout << name << " activates sustaining ability " << ability.name << "!" << std::endl;
    ability.activate();
}
