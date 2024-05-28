#ifndef PROIECTPOO_DUPLICATEABILITYEXCEPTION_H
#define PROIECTPOO_DUPLICATEABILITYEXCEPTION_H

#include <stdexcept>

class DuplicateAbilityException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif //PROIECTPOO_DUPLICATEABILITYEXCEPTION_H
