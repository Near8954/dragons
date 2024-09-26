//
// Created by near on 20.09.24.
//

#include "Attacker.h"

void Attacker::attack(Unit &target) const {
    target.set_health(target.get_health() - damage_);
}

bool Attacker::isAlive() const {
    return (get_health() > 0);
}
