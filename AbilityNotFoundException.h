#ifndef PROIECTV0_2_ABILITYNOTFOUNDEXCEPTION_H
#define PROIECTV0_2_ABILITYNOTFOUNDEXCEPTION_H
#include <iostream>

class AbilityNotFoundException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};


#endif //PROIECTV0_2_ABILITYNOTFOUNDEXCEPTION_H
