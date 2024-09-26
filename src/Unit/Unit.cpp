//
// Created by near on 22.09.24.
//

#include "Unit.h"

void Unit::set_health(int health) {
    health_ = health;
}

int Unit::get_health() const {
    return health_;
}

int Unit::get_max_health() const {
    return max_health_;
}

void Unit::set_max_health(int max_health) {
    max_health_ = max_health;
}

void Unit::setMaxHealth(int Max_health) {
    max_health_ = Max_health;
}
