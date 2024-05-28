#include "Ability.h"
#include <iostream>

Ability::Ability() : name(""), type(""), damage(0), cooldown(0) {};
Ability::Ability(const std::string &name, const std::string &type, int damage, int cooldown) : name(name), type(type), damage(damage), cooldown(cooldown) {}
Ability::Ability(const Ability &other): name(other.name), type(other.type), damage(other.damage), cooldown(other.cooldown){}
Ability::~Ability(){std::cout << "Destroyed ability: " << name << std::endl;}

Ability &Ability::operator=(Ability other) {
    swap(*this, other);
    return *this;
}
void swap(Ability& first, Ability& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.type, second.type);
    swap(first.damage, second.damage);
    swap(first.cooldown, second.cooldown);
}
std::ostream& operator<<(std::ostream& os, const Ability& ability) {
    os << "Name: " << ability.name << ", Type: " << ability.type << ", Damage: " << ability.damage << ", Cooldown: " << ability.cooldown;
    return os;
}

std::string Ability::getName() const {return name;}
std::string Ability::getType() const {return type;}
int Ability::getDamage() const {return damage;}
int Ability::getCooldown() const {return cooldown;}

void Ability::activate() const {std::cout << "Ability " << name << " activated!" << std::endl;}