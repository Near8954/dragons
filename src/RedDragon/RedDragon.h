//
// Created by near on 24.09.24.
//

#ifndef REDDRAGON_H
#define REDDRAGON_H

#include <utility>

#include "../Dragon/Dragon.h"

class RedDragon final : public Dragon {
public:
    RedDragon() = delete;

    RedDragon(int health, int damage, int answer, std::string question) : Dragon(
        health, damage, Color::Red, answer,
        question) {
    };

    RedDragon(int health, int max_health, int damage, int answer, std::string question) : Dragon(
        health, max_health, damage, Color::Red, answer, question) {
    };

    void attack(Unit &target) const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void change_question() override;

    ~RedDragon() = default;

private:
};


#endif //REDDRAGON_H
