#ifndef PROIECTV0_2_MELEE_H
#define PROIECTV0_2_MELEE_H
#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "Proiectpoo.h"

using namespace std;

class Melee : public Champion {
private:
    int attackRange;

public:
    Melee(const std::string& name, const std::string& role, int health, int attackRange);
    ~Melee();

    int getAttackRange() const;

    void useAbility(const Ability& ability) const override;
    Melee* clone() const override;
};

#endif //PROIECTV0_2_MELEE_H
