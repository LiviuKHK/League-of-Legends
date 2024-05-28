#include "InvalidTeamMemberException.h"

const char* InvalidTeamMemberException::what() const noexcept {
    return "Invalid team member!";
}