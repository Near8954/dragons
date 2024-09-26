//
// Created by near on 25.09.24.
//

#ifndef BLUEDRAGON_H
#define BLUEDRAGON_H
#include "../Dragon/Dragon.h"


class BlueDragon : public Dragon {
public:
    BlueDragon() = delete;

    BlueDragon(int health, int damage, int answer, std::string question) : Dragon(
        health, damage, Color::Black, answer, question) {
    };

    BlueDragon(int health, int max_health, int damage, int answer, std::string &question) : Dragon(
        health, max_health, damage, Color::Black, answer, question) {
    };

    ~BlueDragon() = default;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void change_question() override;
};


#endif //BLUEDRAGON_H
