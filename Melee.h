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
    /*  @brief Constructor of the Melee class.
 *  @param name ->Shows the name of the champion.
 *  @param role ->Shows the type of the champion.
 *  @param health ->Shows the health of the champion.
     *  @param atackRange indicates a bonus damage because he has no range in fights.
*/
    Melee(const std::string& name, const std::string& role, int health, int attackRange);
    ~Melee();

    [[nodiscard]] int getAttackRange() const;

    void useAbility(const Ability& ability) const override;
    [[nodiscard]] Melee* clone() const override;
};

#endif //PROIECTV0_2_MELEE_H
