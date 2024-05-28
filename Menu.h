//
// Created by andre on 5/26/2024.
//

#ifndef PROIECTPOO_MENU_H
#define PROIECTPOO_MENU_H
#include <iostream>
#include <vector>
#include <string>

///@class Menu is a class which helps the user of the project to select more options.
class Menu {
private:
    std::vector<std::string> options;

public:
    /*  @brief Constructor of the Menu class.
 *  @param options let us know the options for the menu.
*/
    Menu(const std::vector<std::string> &options);

///@brief shows the options
    void display() const;
///@brief let the user to select the options he wants
    int getUserChoice() const;
///@brief let the user knowing if the option is valid or not,letting him picking another one.
    bool isValidChoice(int choice) const;
};

#endif //PROIECTPOO_MENU_H
