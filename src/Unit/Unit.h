//
// Created by near on 22.09.24.
//
#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <SFML/Graphics.hpp>
#include <random>


inline int gen(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

class Unit : public sf::Drawable, public sf::Transformable {
public:
    Unit() = delete;

    explicit Unit(int health) : health_(health), max_health_(health) {
    };

    Unit(int health, int max_health) : health_(health), max_health_(max_health) {
    };

    ~Unit() = default;

    virtual void set_x(int x) { x_ = x; }

    virtual void set_y(int y) { y_ = y; }

    int agility() const {
        return agility_;
    }

    void set_health(int health);

    int get_health() const;

    int get_max_health() const;

    void set_max_health(int max_health);

    void setMaxHealth(int maxHealth);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

private:
    int health_{};
    int max_health_{};
    int x_, y_;
    int agility_ = 0;
};


#endif //UNIT_H
