//
// Created by near on 24.09.24.
//

#ifndef HERO_H
#define HERO_H
#include <utility>
#include <iostream>
#include "../Attacker/Attacker.h"

class Hero : public Attacker {
public:
    Hero();

    explicit Hero(std::string name) : Attacker(50, 10, 1), name_(std::move(name)), experience_(0) {
    }

    Hero(std::string name, const int experience) : Attacker(50, 10, 1), name_(std::move(name)),
                                                   experience_(experience) {
    }

    Hero(std::string name, const int experience, const int health, const int damage) : Attacker(health, damage, 1),
        name_(std::move(name)),
        experience_(experience) {
    }

    ~Hero() = default;

    void level_up();

    uint32_t get_experience() const {
        return experience_;
    }

    void set_experience(uint32_t exp) {
        experience_ = exp;
    }

    void attack(Unit &target) const;

    bool isEnemy() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::string name_;
    uint32_t experience_;
};
#endif //HERO_H
