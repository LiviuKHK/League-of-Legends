#include "AbilityNotFoundException.h"

const char *AbilityNotFoundException::what() const noexcept {
    return "Ability not found!";
}