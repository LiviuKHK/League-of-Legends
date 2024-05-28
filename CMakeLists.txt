cmake_minimum_required(VERSION 3.27)
project(ProiectPOO)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProiectPOO main.cpp
        Champion.h
        Champion.cpp
        Assassin.h
        Assassin.cpp
        Ability.cpp
        Fighter.cpp
        Item.cpp
        Mage.cpp
        Melee.cpp
        Support.cpp
        Tank.cpp
        Team.cpp
        Menu.h
        Menu.cpp
        DuplicateAbilityException.h
        DuplicateAbilityException.cpp
        AbilityNotFoundException.cpp
        InvalidTeamMemberException.h
        InvalidTeamMemberException.cpp
        AttackStrategy.h
        MeleeAttack.h
        MeleeAttack.cpp
        RangedAttack.h
        RangedAttack.cpp
        ChampionWithStrategy.h
        ChampionWithStrategy.cpp
)
