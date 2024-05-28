#ifndef PROIECTV0_2_SUPPORT_H
#define PROIECTV0_2_SUPPORT_H
#include "Champion.h"

///@class Support class reprezing a champion who helps the teammates winning the game.
class Support : public Champion{
public:
    /*  @brief Constructor of the Support class.
 *  @param name ->Shows the name of the champion.
 *  @param role ->Shows the type of the champion.
 *  @param health ->Shows the health of the champion.
     *  @param protection indicates the level of healing,shielding and buffing the teammate.
*/
    Support(const std::string& name,const std::string& role, int health, int protection);
    void useAbility(const Ability& ability) const override;
private:
    int protection;
};


#endif //PROIECTV0_2_SUPPORT_H
