#ifndef PROIECTPOO_INVALIDTEAMMEMBEREXCEPTION_H
#define PROIECTPOO_INVALIDTEAMMEMBEREXCEPTION_H

#include <stdexcept>

class InvalidTeamMemberException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //PROIECTPOO_INVALIDTEAMMEMBEREXCEPTION_H
