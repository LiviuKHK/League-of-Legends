#ifndef PROIECTV0_2_ASSASSIN_H
#define PROIECTV0_2_ASSASSIN_H
#include "Champion.h"

///@class Assassin reprezenting an assassin champion

class Assassin : public Champion {
public:
    /*  @brief Constructor of the Assassin class.
*  @param name ->Shows the name of the assassin champion.
*  @param role ->Shows the type of the assassin champion.
*  @param health ->Shows the health of the assassin champion.
     *  @param agility->All assassins have extra agility for movement.
*/
    Assassin(const std::string& name, const std::string& role, int health, int extraDamage);

    void useAbility(const Ability& ability) const override;

    Assassin* clone() const override {
        return new Assassin(*this);
    }

private:
    int agility = 0;
};

#endif //PROIECTV0_2_ASSASSIN_H
