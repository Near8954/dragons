//
// Created by near on 20.09.24.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../Attacker/Attacker.h"


class Enemy : public Attacker {
public:
    Enemy() = delete;

    Enemy(int health, int damage, int answer, std::string question) : Attacker(health, damage, 1), answer_(answer),
                                                                      question_(std::move(question)) {
    }

    Enemy(int health, int max_health, int damage, int answer, std::string question) : Attacker(health, max_health,
        damage, 1), answer_(answer), question_(std::move(question)) {
    }

    ~Enemy() = default;

    bool isEnemy() final;

    int get_answer() const {
        return answer_;
    };

    void set_answer(const int answer) {
        answer_ = answer;
    }

    std::string get_question() {
        return question_;
    };

    void set_question(const std::string question) {
        question_ = question;
    }

private:
    int answer_;
    std::string question_;
};


#endif //ENEMY_H
