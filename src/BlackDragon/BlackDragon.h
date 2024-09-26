//
// Created by near on 25.09.24.
//

#ifndef BLACKDRAGON_H
#define BLACKDRAGON_H
#include "../Dragon/Dragon.h"


class BlackDragon : public Dragon {
public:
    BlackDragon() = delete;

    BlackDragon(int health, int damage, int answer, std::string question) : Dragon(
        health, damage, Color::Black, answer, question) {
    };

    BlackDragon(int health, int max_health, int damage, int answer, std::string &question) : Dragon(
        health, max_health, damage, Color::Black, answer, question) {
    };

    ~BlackDragon() = default;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void change_question() override;
};


#endif BLACKDRAGON_H
