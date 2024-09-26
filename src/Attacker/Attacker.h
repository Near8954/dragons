//
// Created by near on 20.09.24.
//

#ifndef ATTACKER_H
#define ATTACKER_H
#include <cstdint>
#include "../Unit/Unit.h"


class Attacker : public Unit {
public:
    Attacker() = delete;

    Attacker(int health, int damage, uint32_t level) : Unit(health, health), damage_(damage), level_(level) {
    }

    Attacker(int health, int max_health, int damage, uint32_t level) : Unit(health, max_health), damage_(damage),
                                                                       level_(level) {
    }

    ~Attacker() = default;

    virtual void attack(Unit &target) const;

    virtual bool isAlive() const;

    virtual bool isEnemy() = 0;

    int get_damage() const {
        return damage_;
    }

    void set_damage(int damage) {
        damage_ = damage;
    }

    uint32_t get_level() const {
        return level_;
    }

    void set_level(uint32_t level) {
        level_ = level;
    }

private:
    int damage_;
    uint32_t level_;
};


#endif //ATTACKER_H
