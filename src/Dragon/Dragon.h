//
// Created by near on 22.09.24.
//

#ifndef DRAGON_H
#define DRAGON_H
#include <utility>

#include "../Enemy/Enemy.h"

enum Color {
    Red,
    Green,
    Black,
};


class Dragon : public Enemy {
public:
    Dragon() = delete;

    Dragon(int health, int damage, const Color color, int answer, std::string question) : Enemy(health, damage, answer,
            std::move(question)),
        color_(color) {
    };

    Dragon(int health, int max_health, int damage, Color color, int answer,
           std::string &question) : Enemy(health, max_health, damage, answer, question), color_(color) {
    };

    std::string ask_question();

    virtual void change_question() = 0;

    ~Dragon() = default;

private:
    Color color_;
};


#endif //DRAGON_H
