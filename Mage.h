#ifndef PROIECTV0_2_MAGE_H
#define PROIECTV0_2_MAGE_H
#include <iostream>
#include "Champion.h"

///@class Mage class is a subclass of champion,representing a champion who use te magical power in fights.
class Mage : public Champion{
public:
    /*  @brief Constructor of the Mage class.
 *  @param name ->Shows the name of the mage champion.
 *  @param role ->Shows the type of the mage champion.
 *  @param health ->Shows the health of the mage champion.
     *  @param energy indicates the level of the magical power of the champion.
*/
    Mage(const std::string& name, const std::string& role, int health, int energy);
    void useAbility(const Ability& ability) const override;
private:
    int energy;
};


#endif //PROIECTV0_2_MAGE_H
