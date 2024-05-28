#include "DuplicateAbilityException.h"

const char* DuplicateAbilityException::what() const noexcept {
    return "Duplicate ability found.";
}