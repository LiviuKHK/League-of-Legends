#include "Champion.h"
#include "Ability.h"
#include "AbilityNotFoundException.h"
#include <iostream>
Champion::Champion() : name(""), role(""), health(0){}
Champion::Champion(const std::string &name, const std::string &role, int health): name(name), role(role), health(health) {}
Champion::Champion(const Champion &other):name(other.name), role(other.role), health(other.health){}
Champion::~Champion(){
    std::cout << "Destroyed champion: " << name << std::endl;
}

Champion &Champion::operator=(Champion& other) {
    swap(*this, other);
    return *this;
}
void swap(Champion& first, Champion& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.role, second.role);
    swap(first.health, second.health);
}
std::ostream& operator<<(std::ostream& os, const Champion& champion){
    os << "Name: " << champion.name << ", Role: " << champion.role << ", Health: " << champion.health << std::endl;
    return os;
}

void Champion::setName(const std::string &newName) {
    name = newName;
}
std::string Champion::getName() const {return name;}
std::string Champion::getRole() const {return role;}
int Champion::getHealth() const {return health;}

void Champion::addAbility(const Ability &ability) {abilities.push_back(ability);}
void Champion::displayAbilities() const {
    //std::cout << "Abilities of " << name << ":" << std::endl;
    for (const Ability& ability : abilities) {
        std::cout << ability<<std::endl;
    }
}
int Champion::calculateDamage() const {
    int totalDamage = 0;
    for (const Ability& ability : abilities) {
        totalDamage += ability.getDamage();
    }
    return totalDamage;
}
void Champion::simulateBattle(const Champion &opponent) const {
    int damageDealt = calculateDamage();
    int damageTaken = opponent.calculateDamage();

    std:: cout << name << " attacks " << opponent.name << " and deals " << damageDealt << " damage." << std::endl;
    std::cout << opponent.name << " counterattacks and deals " << damageTaken << " damage." << std::endl;

    int remainingHealth = health - damageTaken;

    int remainingOpponentHealth = opponent.health - damageDealt;

    std::cout << name << " has " << remainingHealth << " health remaining." << std::endl;
    if(remainingHealth <= 0) std::cout << name << " is dead!\n";
    std::cout << opponent.name << " has " << remainingOpponentHealth << " health remaining." << std::endl;
    if(remainingOpponentHealth <= 0) std::cout << opponent.name << " is dead!\n";
}
void Champion::useAbility(const Ability &ability) const {
    bool abilityFound = false;
    for (const auto& ab : abilities) {
        if (ab.getName() == ability.getName()) {
            abilityFound = true;
            break;
        }
    }
    if (!abilityFound) {
        throw AbilityNotFoundException();
    }
    std::cout << name << " uses " << ability.name << "!" << std::endl;
    ability.activate();
}
Champion *Champion::clone() const {
    return new Champion(*this);
}
