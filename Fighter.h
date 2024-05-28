#ifndef PROIECTV0_2_FIGHTER_H
#define PROIECTV0_2_FIGHTER_H
#include "Ability.h"
#include "Champion.h"

///@class Fighter is a subclass of Champion which shows that the champion is more human then other champions,using the power of his body
class Fighter : public Champion{
public:
    /*  @brief Constructor of the Fighter class.
 *  @param name ->Shows the name of the champion.
 *  @param role ->Shows the type of the champion.
 *  @param health ->Shows the health of the champion.
     *  @param sustain -> Shows the bonus damage and bonus armor the fighter have.
*/
    Fighter(const std::string& name, const std::string& role, int health, int sustain);
    void useAbility(const Ability& ability) const override;
private:
    int sustain;
};


#endif //PROIECTV0_2_FIGHTER_H
