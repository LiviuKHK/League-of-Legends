#ifndef PROIECTV0_2_TANK_H
#define PROIECTV0_2_TANK_H
#include "Champion.h"

///@class Tank is champion who can protect the team,having more armor and magic rezist,being a frontline for the team.
class Tank : public Champion {
private:
    int armor;
public:
    /*  @brief Constructor of the Tank class.
*  @param name ->Shows the name of the champion.
*  @param role ->Shows the type of the champion.
*  @param health ->Shows the health of the champion.
*/
    Tank(const std::string& name, const std::string& role, int health,int armor);

    void useAbility(const Ability& ability) const override;

    Tank* clone() const override {
        return new Tank(*this);
    }
};
#endif //PROIECTV0_2_TANK_H
